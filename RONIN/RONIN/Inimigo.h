#pragma once
#include "Personagem.h"
#include "GerenciadorGrafico.h"

class Inimigo : public Personagem
{
protected:
	// Mover variavel 'vivo' para personagem
	int vira;
	int passos;

public:
	Inimigo(Texture* textura, Vector2u contQuadro, float mudaT, float aceleracao, float alturaPulo, int v);
	Inimigo();
	~Inimigo();

	void atualizar(float deltaT);
	void danificar(float deltaT);
	void morrer(float deltaT);
};

