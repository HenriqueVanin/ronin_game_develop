#include "GerenciadorGrafico.h"


GerenciadorGrafico* GerenciadorGrafico::_instancia = 0;  // INICIALIZA O PONTEIRO COMO 0 //

GerenciadorGrafico* GerenciadorGrafico::instancia()
{
	if (_instancia == 0)
	{
		_instancia = new GerenciadorGrafico;
	}
	return _instancia;
}

GerenciadorGrafico::GerenciadorGrafico() :
	janela(VideoMode(ALTURA_JANELA, LARGURA_JANELA), "RONIN", Style::Close),
	camera(Vector2f(0.0f,0.0f), Vector2f(ALTURA_JANELA, LARGURA_JANELA))
{
}


GerenciadorGrafico::~GerenciadorGrafico()
{
	delete _instancia;
}

void GerenciadorGrafico::desenhar(Drawable& objeto)
{
	janela.draw(objeto);
}

void GerenciadorGrafico::limparJanela()
{
	janela.clear();
}

void GerenciadorGrafico::fecharJanela()
{
	janela.close();
}

void GerenciadorGrafico::setarCamera()
{
	janela.setView(camera);
}

void GerenciadorGrafico::setarCentroCamera(int x, int y)
{
	camera.setCenter(x, y);
}

void GerenciadorGrafico::ajustarCamera()
{
	float proporcao = static_cast <float> (janela.getSize().x) / static_cast <float> (janela.getSize().y);
	camera.setSize(ALTURA_JANELA * proporcao, LARGURA_JANELA);
}

void GerenciadorGrafico::mostrarJanela()
{
	janela.display();
}

void GerenciadorGrafico::eventoJanela()
{
	while (TELA->avaliaEvento(evento))
	{
		switch (evento.type)
		{
		case sf::Event::Closed:
			TELA->fecharJanela();
			break;
		}
	}
}

void GerenciadorGrafico::telaCheia()
{
}

bool GerenciadorGrafico::janelaAberta()
{
	return janela.isOpen();
}

bool GerenciadorGrafico::avaliaEvento(Event& evento)
{
	return janela.pollEvent(evento);
}

Event GerenciadorGrafico::retornarEvento()
{
	return evento;
}

Vector2f GerenciadorGrafico::retornarPosicaoCamera()
{
	return camera.getCenter();
}

Vector2u GerenciadorGrafico::retornarTamanhoJanela()
{
	return Vector2u(LARGURA_JANELA, ALTURA_JANELA);
}

