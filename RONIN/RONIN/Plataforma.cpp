#include "Plataforma.h"

Plataforma::Plataforma(Texture* textura, Vector2f tamanho, Vector2f posicao)
{
	corpo.setSize(tamanho);
	corpo.setOrigin(tamanho / 2.0f);
	corpo.setTexture(textura);
	corpo.setPosition(posicao);
	corpo.setOutlineThickness(1.0f);
	corpo.setOutlineColor(Color::Green);
}

Plataforma::~Plataforma()
{
}

void Plataforma::atualizar(float deltaT)
{
}

Colisor Plataforma::retornarColisor()
{
	return Colisor(corpo);
}

RectangleShape Plataforma::retornarForma()
{
	return corpo;
}
