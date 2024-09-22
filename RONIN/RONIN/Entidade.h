#pragma once
#include "GerenciadorGrafico.h"
#include "Animador.h"
#include "Colisor.h"

class Entidade
{
protected:
	RectangleShape quadro;
	RectangleShape corpo;
	Texture textura;
	Animador animacao;

	Clock tempo;
	int temporizador;

public:
	Entidade(Texture* textura, Vector2u contQuadro, float mudaT);
	Entidade();
	~Entidade();

	// FUNÇÕES //
	
	virtual void atualizar(float deltaT) = 0;
	//virtual void setarTexturas() = 0;
	void desenhar();

	// SETS //

	void setarCorpo(RectangleShape c);
	void setarQuadro(RectangleShape q);
	void setarTextura(Texture* t);

	// GETS //
	
	RectangleShape retornarCorpo() const;
	RectangleShape retornarQuadro() const;
	
	Colisor retornarColisorCorpo();
	Colisor retornarColisorQuadro();
	Vector2f retornarPosicao();
};