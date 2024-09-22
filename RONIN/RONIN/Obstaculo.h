#pragma once
#include "Entidade.h"

class Jogador;

class Obstaculo : public Entidade
{
protected:
	Clock tempo;
	int temporizador;

public:
	Obstaculo(Texture* textura, Vector2u contQuadro, float mudaT);
	Obstaculo();
	~Obstaculo();

	virtual void manifestarObstaculo(Jogador* pJogador, Vector2f direcao, float deltaT) = 0;

	bool retornarColisao(Jogador* pJogador, Vector2f direcao, float empurro, bool repulsao);
};