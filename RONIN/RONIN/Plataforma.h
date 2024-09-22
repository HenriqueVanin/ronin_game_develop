#pragma once
#include "GerenciadorGrafico.h"
#include "Colisor.h"
#include "Entidade.h"

class Plataforma : public Entidade
{
private:
	RectangleShape forma;

public:
	Plataforma(Texture* textura, Vector2f tamanho, Vector2f posicao);
	~Plataforma();

	void atualizar(float deltaT);
	Colisor retornarColisor();
	RectangleShape retornarForma();
};

