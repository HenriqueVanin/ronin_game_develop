#pragma once
#include "Inimigo.h"


class Kage : public Inimigo
{
private:
public:
	Kage(Texture* textura, Vector2u contQuadro, float mudaT, float aceleracao, float alturaPulo, Vector2f tamCorpo, Vector2f tamQuadro, Vector2f posicao);
	Kage();
	~Kage();

	void movimentar(float deltaT);
	void atacarKage(float deltaT);
};
