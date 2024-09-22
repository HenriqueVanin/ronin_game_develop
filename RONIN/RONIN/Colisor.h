#pragma once
#include "GerenciadorGrafico.h"

class Colisor
{
private:
	RectangleShape& corpo;

public:
	Colisor(RectangleShape& corpo);
	~Colisor();

	bool checarColisao(Colisor outro, Vector2f& direcao, float empurra, bool repulsao);
	Vector2f retornarMetadeTam();
	Vector2f retornarPosicao();
	void mover(float dx, float dy);
};

