#include "Entidade.h"


Entidade::Entidade(Texture* textura, Vector2u contQuadro, float mudaT):
	animacao(textura, contQuadro, mudaT)
{
	quadro.setTexture(textura);
}

Entidade::Entidade()
{
}

Entidade::~Entidade()
{
}

void Entidade::atualizar(float deltaT)
{
}

void Entidade::desenhar()
{
	TELA->desenhar(this->quadro);
}

void Entidade::setarCorpo(RectangleShape c)
{
	corpo = c;
}

void Entidade::setarQuadro(RectangleShape q)
{
	quadro = q;
}

void Entidade::setarTextura(Texture* t)
{
	quadro.setTexture(t);
}


RectangleShape Entidade::retornarCorpo() const
{
	return corpo;
}

RectangleShape Entidade::retornarQuadro() const
{
	return quadro;
}

Colisor Entidade::retornarColisorCorpo()
{
	return Colisor(corpo);
}

Colisor Entidade::retornarColisorQuadro()
{
	return Colisor(quadro);
}

Vector2f Entidade::retornarPosicao()
{
	return corpo.getPosition();
}
