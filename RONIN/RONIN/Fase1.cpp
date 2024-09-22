#include "Fase1.h"

#define MUSICA_FASE_1       "Musicas/fase1.wav"
#define TEXTURA_FASE_1      "Texturas/fase1.jpg"

Fase1::Fase1()
{
	setarTextura();
	inicializarJogadores();
	inicializarInimigos();
	inicializarObstaculos();	
	inicializarMusica();
	setarTextura();
	setarTexturaFundo();	
}

Fase1::~Fase1()
{
}

void Fase1::atualizar(float deltaT)
{
	tocarMusica();
	while (faseAberta)
	{
		temporizarRelogio();
		Vector2f direcao;

		deltaT = relogio.restart().asSeconds();
		//Determina o mínimo de frame rate
		if (deltaT > 1.0f / 40.0f)
			deltaT = 1.0f / 40.0f;

		laçoFasePrincipal(deltaT, direcao);
		if (jogador1->retornarPosicao().y > 1500.0f)
			faseAberta = false;
		if (jogador1->retornarPosicao().x > 5000.0f)
		{
			cout << " Você Venceu! Pontuacao : " << jogador1->retornarPontuacao() << endl;
			venceu = true;
		}
	}
	//TELA->setarCentroCamera(menuPausa.retornarQuadro().getPosition().x, menuPausa.retornarQuadro().getPosition().y);
}

void Fase1::executar()
{
	atualizar(deltaT);
}

int Fase1::inicializarMusica()
{
	if (!musica.openFromFile(MUSICA_FASE_1))
	{
		return -1;
	}
	return 0;
}

void Fase1::setarTexturaFundo()
{
	// Inicialização das Texturas
	fundo.loadFromFile(TEXTURA_FASE_1);
	imagemFundo.setTexture(fundo);
	imagemFundo.setOrigin(0, 0);
	imagemFundo.setScale(2, 2);
}