#include "Estatua.h"

Estatua::Estatua(Texture* textura, Vector2f posicao) :
	Obstaculo(textura, Vector2u(0,0), 0.0f)
{
	this->corpo.setSize(Vector2f( 80.0f, 80.0f ));
	this->corpo.setOrigin(this->corpo.getSize() / 2.0f);
	this->corpo.setPosition(Vector2f(posicao));
	//this->corpo.setFillColor(Color(125, 125, 125));
	this->corpo.setTexture(textura);
}

Estatua::Estatua()
{
}

Estatua::~Estatua()
{
}

void Estatua::atualizar(float deltaT)
{
	TELA->desenhar(corpo);
}

void Estatua::manifestarObstaculo(Jogador* pJogador, Vector2f direcao, float deltaT)
{
	atualizar(deltaT);
	retornarColisao(pJogador, direcao, 50.0f, true);
}


