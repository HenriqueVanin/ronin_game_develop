#pragma once
#include "GerenciadorGrafico.h"

class Animador
{
private:
	// ATRIBUTOS DE ANIMAÇÃO //
	Vector2u contQuadro;
	Vector2u quadroAtual;
	float tempoTotal;
	float mudaT;

public:
	Animador(Texture* textura, Vector2u contQuadro, float mudaT);
	Animador();
	~Animador();

	bool atualizarAnimacao(int linhaAnimacao, float deltaT, bool faceDireita);
	bool atualizarAnimacao2(int linhaAnimacao, float deltaT, bool faceDireita);

public:
	// FRAME //
	IntRect uvRect;
};

