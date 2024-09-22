#pragma once
#include "Obstaculo.h"

class Estatua : public Obstaculo
{
private:

public:
	Estatua(Texture* textura, Vector2f posicao);
	Estatua();
	~Estatua();
	
	void atualizar(float deltaT);
	void manifestarObstaculo(Jogador* pJogador, Vector2f direcao, float deltaT);
};
