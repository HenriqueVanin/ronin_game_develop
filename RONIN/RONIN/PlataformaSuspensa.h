#pragma once
#include "Obstaculo.h"

class PlataformaSuspensa : public Obstaculo
{
private:
	bool primeiraColisao;
	Vector2f gravidade;

public:
	PlataformaSuspensa(Texture* textura, Vector2f posicao);
	PlataformaSuspensa();
	~PlataformaSuspensa();

	void atualizar(float deltaT);
	void manifestarObstaculo(Jogador* pJogador, Vector2f direcao, float deltaT);
	void cairPlataforma(Jogador* pJogador, Vector2f direcao);
};

