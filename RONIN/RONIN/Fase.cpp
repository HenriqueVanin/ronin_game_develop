#include "Fase.h"

#define TEXTURA_JOGADOR_1  "Texturas/personagem1.png"
#define TEXTURA_JOGADOR_2  "Texturas/personagem2.png"

#define TEXTURA_UMIBOZU    "Texturas/fantasma.png"
#define TEXTURA_AKANAME    "Texturas/morcego.png"
#define TEXTURA_KAGE       "Texturas/chefao.png"

#define TEXTURA_ESTATUA    "Texturas/estatua.png"
#define TEXTURA_PLATAFORMA "Texturas/plataforma.png"
#define TEXTURA_FOGO	   "Texturas/fogo.png"

Fase::Fase() :
	deltaT(0), jogador1(), jogador2(), faseAberta(true), coop(false), rodandoFase(true), menuPausa(), temporizadorDeFase(0), tempoDeFase(), jogadoresMortos(false), venceu(false)
{
}

Fase::~Fase()
{
}

void Fase::pausar()
{
	int contador = 10;
	bool f = true;
	// Entra num loop que aguarda a tecla 'O' ser pressionada
	while (f)
	{
		TELA->eventoJanela();
		TELA->ajustarCamera();
		Sleep(contador);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
			f = false;
	}
}

void Fase::tocarMusica()
{
	musica.play();
	musica.setLoop(true);
	musica.setVolume(10.0f);
}

void Fase::laçoFasePrincipal(float deltaT, Vector2f direcao)
{
	eventoTela();
	interagirEntidades(jogador1, jogador2, direcao, deltaT);
	eventosTeclas(deltaT, direcao);
	ajustarTela();
	desenharTela();
	atualizarJogadores(deltaT);
	checarJogadores();
	verificarVenceu();
}

void Fase::atualizarEntidades(float deltaT)
{
	listaEntidades.atualizarListaUmibozu(deltaT);
	listaEntidades.atualizarListaAkaname(deltaT);
}

void Fase::checarColisaoPlataformas(Vector2f direcao)
{
	listaPlataformas.checarColisoesPlataformas(jogador1, direcao);
	if(coop)
		listaPlataformas.checarColisoesPlataformas(jogador2, direcao);
	for (int i = 0; i < listaInimigos.retornarContador(); i++)
	{
		Inimigo* pInimigo = listaInimigos.percorreLista();
		if(pInimigo)
			listaPlataformas.checarColisoesPlataformas(static_cast<Personagem*> (pInimigo), direcao);
	}
}

void Fase::checarColisaoInimigo(float deltaT, Vector2f direcao)
{
	Inimigo* pInimigo;
	for (int i = 0; i < listaInimigos.retornarContador(); i++)
	{
		pInimigo = listaInimigos.percorreLista();
		
		if (!jogador1->retornarMorto() && !pInimigo->retornarMorto())
		{
			if (jogador1->retornarColisorCorpo().checarColisao(pInimigo->retornarColisorCorpo(), direcao, 0.0f, false))
			{
				jogador1->emColisao(direcao);
				jogador1->danificar(deltaT);
			}
		}

		if (coop)
		{
			if (!jogador2->retornarMorto() && !pInimigo->retornarMorto())
			{
				if (jogador2->retornarColisorCorpo().checarColisao(pInimigo->retornarColisorCorpo(), direcao, 0.0f, false))
				{
					jogador2->emColisao(direcao);
					jogador2->danificar(deltaT);
				}
			}
		}
	}	
}

void Fase::checarColisaoObstaculo(float deltaT, Vector2f direcao)
{
	listaObstaculos.percorreLista(jogador1, direcao, deltaT);
	if (coop)
		listaObstaculos.percorreLista(jogador2, direcao, deltaT);
}

void Fase::checarAtaque1(float deltaT, Vector2f direcao)
{
	Inimigo* pInimigo;
	for (int i = 0; i < listaInimigos.retornarContador(); i++)
	{
		pInimigo = listaInimigos.percorreLista();

		if (!jogador1->retornarMorto() && !pInimigo->retornarMorto())
		{
			jogador1->atacar(deltaT, direcao, pInimigo);
		}
	}
}

void Fase::checarAtaque2(float deltaT, Vector2f direcao)
{
	Inimigo* pInimigo;
	for (int i = 0; i < listaInimigos.retornarContador(); i++)
	{
		pInimigo = listaInimigos.percorreLista();

		if (coop)
		{
			if (!jogador2->retornarMorto() && !pInimigo->retornarMorto())
			{
				jogador2->atacar(deltaT, direcao, pInimigo);
			}
		}
	}
}

void Fase::manifestaObstaculos(Jogador* jogador, Vector2f direcao, float deltaT)
{
	listaObstaculos.percorreLista(jogador, direcao, deltaT);
}

void Fase::interagirEntidades(Jogador* jogador1, Jogador* jogador2, Vector2f direcao, float deltaT)
{
	manifestaObstaculos(jogador1, direcao, deltaT);
	atualizarEntidades(deltaT);
	checarColisaoPlataformas(direcao);
	checarColisaoInimigo(deltaT, direcao);
	if (coop)
		manifestaObstaculos(jogador2, direcao, deltaT);
}

void Fase::eventosTeclas(float deltaT, Vector2f direcao)
{
	TELA->eventoJanela();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		pausar();

	if (Keyboard::isKeyPressed(TECLA K))
		checarAtaque1(deltaT, direcao);

	if (Keyboard::isKeyPressed(TECLA Num0))
		checarAtaque2(deltaT, direcao);

	//if (Keyboard::isKeyPressed(TECLA Escape))
	//	menuPausa.menuPrincipal();
}

void Fase::atualizarJogadores(float deltaT)
{
	jogador1->atualizar(deltaT);
	// jogador1->desenhar();
	if (coop)
	{
		jogador2->atualizar(deltaT);
		//jogador2->desenhar();
	}
		
}

void Fase::desenharListaPlataformas()
{
	//listaPlataformas.desenharLista();
}

void Fase::temporizarRelogio()
{
	temporizadorDeFase += tempoDeFase.getElapsedTime().asSeconds();
	tempoDeFase.restart();
}

bool Fase::passouDeFase()
{
	return venceu;
}

void Fase::inicializarJogadores()
{
	jogador1 = new Jogador(&tJogador1, Vector2u(6, 6), 0.2f, 300.0f, 700.0f, Vector2f(40.0f, 70.0f), Vector2f(300.0f, 100.0f), Vector2f(1506.0f, 900.0f), 1);
	if (coop)
		jogador2 = new Jogador(&tJogador2, Vector2u(6, 6), 0.2f, 300.0f, 700.0f, Vector2f(40.0f, 70.0f), Vector2f(300.0f, 100.0f), Vector2f(1506.0f, 900.0f), 2);
}

void Fase::inicializarInimigos()
{
	srand(time(0));
	int randomico;
	for (int i = 1; i < 12; i++)
	{
		int vira;
		randomico = abs(rand() % 3000);
		if (randomico % 2 == 0)
			vira = 1;
		else
			vira = -1;
		Umibozu* novoUmibozu = new Umibozu(&tUmibozu, Vector2u(8, 2), 0.2f, 100.0f, 0.0f, Vector2f(150.0f, 80.0f), Vector2f(80.0f, 80.0f), Vector2f(5200.0f - randomico, 1050.0f), vira);
		listaEntidades.incluirUmibozu(novoUmibozu);
		listaInimigos.incluiInimigo(novoUmibozu);
		randomico = abs(rand() % 100);
		if (randomico % 2 == 0)
			vira = 1;
		else
			vira = -1;
		Akaname* novoAkaname = new Akaname(&tAkaname, Vector2u(8, 2), 0.2f, 100.0f, 0.0f, Vector2f(150.0f, 80.0f), Vector2f(80.0f, 80.0f), Vector2f(35.0f * randomico + 1300.0f, 900.0f - randomico), vira);
		listaEntidades.incluirAkaname(novoAkaname);
		listaInimigos.incluiInimigo(novoAkaname);
	}
}

void Fase::inicializarObstaculos()
{
	srand(time(0));
	Vector2f posicao;
	for (int i = 1; i < 6; i++)
	{
		int randomico = abs(rand() % 100);
		Estatua* novoEstatua = new Estatua(&tEstatua, Vector2f(30.0f * randomico + 1300.0f, 1050.0f));
		listaObstaculos.incluiObstaculo(novoEstatua);

		randomico = abs(rand() % 400);
		FogoFatuo* novoFogoFatuo = new FogoFatuo(&tFogo, Vector2f(30.0f * randomico + 1600.0f, 1150.0f-randomico), Vector2u(9, 2), 0.2f);
		listaObstaculos.incluiObstaculo(novoFogoFatuo);

		randomico = abs(rand() % 5);
		switch (randomico)
		{
		case 0:
			posicao = Vector2f(900.0f * randomico + 1300.0f, 850.0f);
			break;
		case 1:
			posicao = Vector2f(900.0f * randomico + 1300.0f, 1000.0f);
			break;
		case 2:
			posicao = Vector2f(900.0f * randomico + 1300.0f, 900.0f);
			break;
		case 3:
			posicao = Vector2f(900.0f * randomico + 1300.0f, 950.0f);
			break;
		case 4:
			posicao = Vector2f(900.0f * randomico + 1300.0f, 800.0f);
			break;
		default:
			break;
		}
		PlataformaSuspensa* novoPlataformaSuspensa = new PlataformaSuspensa(&tPlataforma, posicao);
		listaObstaculos.incluiObstaculo(novoPlataformaSuspensa);
	}
}

bool Fase::retornarVenceu()
{
	return venceu;
}

void Fase::verificarVenceu()
{
	/*
	if (coop)
	{
		if ((jogador1->retornarPontuacao() + jogador2->retornarPontuacao()) > 12)
		{
			venceu = true;
			faseAberta = false;
		}
	}
	else
		if (jogador1->retornarPontuacao() > 12)
		{
			venceu = true;
			faseAberta = false;
		}
	*/
}

void Fase::setarFaseAberta(bool f)
{
	faseAberta = f;
}

void Fase::setarCoop(bool c)
{
	coop = true;
}

void Fase::desenharTela()
{
	// Desenha na tela
	TELA->mostrarJanela();
	TELA->limparJanela();
	TELA->setarCamera();
	TELA->desenhar(imagemFundo);
}

void Fase::ajustarTela()
{
	// Centraliza a textura do personagem
	TELA->setarCentroCamera(jogador1->retornarPosicao().x, jogador1->retornarPosicao().y-150);
}

void Fase::setarTextura()
{
	tJogador1.loadFromFile(TEXTURA_JOGADOR_1);
	tJogador2.loadFromFile(TEXTURA_JOGADOR_2);
	tEstatua.loadFromFile(TEXTURA_ESTATUA);
	tPlataforma.loadFromFile(TEXTURA_PLATAFORMA);
	tFogo.loadFromFile(TEXTURA_FOGO);
	tUmibozu.loadFromFile(TEXTURA_UMIBOZU);
	tAkaname.loadFromFile(TEXTURA_AKANAME);
	tKage.loadFromFile(TEXTURA_KAGE);
}

void Fase::pararMusica()
{
	musica.stop();
}

void Fase::eventoTela()
{
	TELA->eventoJanela();
}

void Fase::checarJogadores()
{
	if (!jogadoresMortos)
	{
		if (jogador1->retornarMorto())
		{
			if (coop)
			{
				if (jogador2->retornarMorto())
				{
					tempo.restart();
					jogadoresMortos = true;
				}
			}
			else
			{
				tempo.restart();
				jogadoresMortos = true;

			}
		}
	}
	else
	{
		temporizador = tempo.getElapsedTime().asSeconds();
		if (temporizador > 1)
			faseAberta = false;
	}
	
}
