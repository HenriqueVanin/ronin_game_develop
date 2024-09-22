#include "Caixa.h"

Caixa::Caixa(Texture* textura, Vector2f posicao) :
	Obstaculo(textura, Vector2u(0,0), 0.0f)
{
	this->corpo.setSize(Vector2f( 80.0f, 80.0f ));
	this->corpo.setOrigin(this->corpo.getSize() / 2.0f);
	this->corpo.setPosition(Vector2f(posicao));
	//this->corpo.setFillColor(Color(125, 125, 125));
	this->corpo.setTexture(textura);
}

Caixa::Caixa()
{
}

Caixa::~Caixa()
{
}

void Caixa::atualizar(float deltaT)
{
	TELA->desenhar(corpo);
}


