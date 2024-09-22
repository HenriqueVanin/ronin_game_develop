#include "Fase2.h"

#define MUSICA_FASE_2      "Musicas/fase2.wav"
#define TEXTURA_FASE_2     "Texturas/fase2.jpg"

Fase2::Fase2():
	chefao()
{
	setarTextura();
	inicializarJogadores();
	inicializarInimigos();
	inicializarObstaculos();
	inicializarMusica();
	inicializarChefao();
	setarTextura();
	setarTexturaFundo();
}

Fase2::~Fase2()
{
}

void Fase2::atualizar(float deltaT)
{
	tocarMusica();
	while (faseAberta)
	{
		temporizarRelogio();
		Vector2f direcao;
		deltaT = relogio.restart().asSeconds();

		//Determina o mínimo de frame rate
		if (deltaT > 1.0f / 30.0f)
			deltaT = 1.0f / 30.0f;

		atualizarChefao(deltaT);
		if (jogador1->retornarPosicao().y > 1500.0f)
			faseAberta = false;
		if (chefao->retornarMorto())
		{
			cout << " Você Venceu! Pontuacao : " << jogador1->retornarPontuacao() << endl;
			venceu = true;
			faseAberta = false;
		}
		laçoFasePrincipal(deltaT, direcao);
	}
}

void Fase2::executar()
{
	atualizar(deltaT);
}

int Fase2::inicializarMusica()
{
	if (!musica.openFromFile(MUSICA_FASE_2))
	{
		return -1;
	}
	return 0;
}

void Fase2::inicializarChefao()
{
	chefao = new Kage(&tKage, Vector2u(6, 6), 0.3f, 200.0f, 0.0f, Vector2f(40.0f, 70.0f), Vector2f(300.0f, 100.0f), Vector2f(2800.0f, 1050.0f));
	listaInimigos.incluiInimigo(chefao);
}

void Fase2::setarTexturaFundo()
{
	fundo.loadFromFile(TEXTURA_FASE_2);
	imagemFundo.setTexture(fundo);
	imagemFundo.setScale(2, 2);
	imagemFundo.setOrigin(0, 0);
}

void Fase2::atualizarChefao(float deltaT)
{
	chefao->atualizar(deltaT);
}
