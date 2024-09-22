#pragma once
#include "Obstaculo.h"

class Caixa : public Obstaculo
{
private:

public:
	Caixa(Texture* textura, Vector2f posicao);
	Caixa();
	~Caixa();
	
	void atualizar(float deltaT);
};

