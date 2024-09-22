#include "Menu.h"

#define TELA_INICIAL  "Texturas/fundomenu.jpg"

#define MENU_INICIAR  "Texturas/menu1.jpg"
#define MENU_FASE_I   "Texturas/menu2.jpg"
#define MENU_FASE_II  "Texturas/menu3.jpg"
#define MENU_SAIR     "Texturas/menu4.jpg"

Menu::Menu() :
	Entidade(NULL, { 1 , 1 }, 0),
	evento(), botaoSelecionado(1)
{
	this->quadro.setSize(Vector2f (1280.0f, 720.0f));
	this->quadro.setOrigin(Vector2f(0.0f, 0.0f));
	this->quadro.setPosition(0.0f, 0.0f);

	this->telaInicialQuadro.setSize(Vector2f(1280.0f, 720.0f));
	this->telaInicialQuadro.setOrigin(Vector2f(0.0f, 0.0f));
	this->telaInicialQuadro.setPosition(0.0f, 0.0f);
	setarTexturas();
	inicializarMusica();
}

Menu::~Menu()
{
}

int Menu::executar()
{
	musicamenu.play();
	musicamenu.setLoop(true);
	musicamenu.setVolume(10.0f);
	TELA->setarCentroCamera(quadro.getPosition().x + quadro.getSize().x/2, quadro.getPosition().y + quadro.getSize().y / 2);
	TELA->setarCamera();
	
	menuPrincipal();
	//telaInicial();
	musicamenu.stop();
	return botaoSelecionado;
}

void Menu::menuPrincipal()
{
	bool b = false;
	while (!b)
	{
		temporizador = relogio.getElapsedTime().asMilliseconds();
		atualizar(0);
		switch (TELA->retornarEvento().type)
		{
		case Event::KeyPressed:
		{
			if (temporizador > 150)
			{
			switch (TELA->retornarEvento().key.code)
			{
			case Keyboard::Up:
			{
				if (botaoSelecionado != 1)
					botaoSelecionado--;
				relogio.restart();
				break;
			}
			case Keyboard::Down:
			{
				if (botaoSelecionado != 7)
					botaoSelecionado++;
				relogio.restart();
				break;
			}
			default:
				break;
			}
			}
		}
		case Keyboard::Return:
		{
			switch (botaoSelecionado)
			{
			case 1:
			{
				quadro.setTexture(&menuIniciar);
				break;
			}
			case 2:
			{
				quadro.setTexture(&menuFaseI);
				break;
			}
			case 3:
			{
				quadro.setTexture(&menuFaseII);
				break;
			}
			case 4:
			{
				quadro.setTexture(&menuSair);
				break;
			}
			default:
				break;
			}
		}
		default:
			break;
		}
		if(temporizador > 200)
			if (Keyboard::isKeyPressed(Keyboard::Key::Enter))
			{
				b = true;
			}
		TELA->desenhar(quadro);
	}
}

void Menu::telaInicial()
{
	bool b = false;
	while (!b)
	{
		atualizar(0);
		TELA->desenhar(telaInicialQuadro);
		if (Keyboard::isKeyPressed(TECLA Enter))
		{
			b = true;
			relogio.restart();
			menuPrincipal();
		}
	}
}


int Menu::inicializarMusica()
{
	if (!musicamenu.openFromFile("Musicas/menu.wav"))
	{
		return -1;
	}	
	return 0;
}

void Menu::atualizar(float deltaT)
{
	TELA->mostrarJanela();
	TELA->limparJanela();
	TELA->eventoJanela();
	TELA->ajustarCamera();
}

void Menu::moverCima()
{
}

void Menu::moverBaixo()
{
}

int Menu::retornarBotaoSelecionado()
{
	return botaoSelecionado;
}


void Menu::selecionarBotao(int botao)
{

}

void Menu::setarTexturas()
{
	tTelaInicial.loadFromFile(TELA_INICIAL);
	telaInicialQuadro.setTexture(&tTelaInicial);

	menuIniciar.loadFromFile(MENU_INICIAR);
	menuFaseI.loadFromFile(MENU_FASE_I);
	menuFaseII.loadFromFile(MENU_FASE_II);
	menuSair.loadFromFile(MENU_SAIR);

	quadro.setTexture(&menuIniciar);
}
