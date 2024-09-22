#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <cstdlib>
#include "BibliotecaSFML.h"
#include <iostream>
#include <vector>
#include <ctime>

#define ALTURA_JANELA 1280
#define LARGURA_JANELA 720
#define TELA GerenciadorGrafico::instancia()
#define TECLA Keyboard::Key::

using namespace sf;
using namespace std;


class GerenciadorGrafico
{
protected:
	GerenciadorGrafico();
	
private:
	static GerenciadorGrafico* _instancia;
	RenderWindow janela;
	View camera;
	Event evento;

public:
	static GerenciadorGrafico* instancia();
	~GerenciadorGrafico();

	void desenhar(Drawable& objeto);
	void limparJanela();
	void fecharJanela();
	void setarCamera();
	void setarCentroCamera(int x, int y);
	void ajustarCamera();
	void mostrarJanela();
	void eventoJanela();
	void telaCheia();

	bool janelaAberta();
	bool avaliaEvento(Event& evento);

	Event retornarEvento();
	Vector2f  retornarPosicaoCamera();

	Vector2u retornarTamanhoJanela();
};

