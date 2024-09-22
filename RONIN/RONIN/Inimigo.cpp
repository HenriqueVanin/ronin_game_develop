#include "Inimigo.h"

Inimigo::Inimigo(Texture* textura, Vector2u contQuadro, float mudaT, float aceleracao, float alturaPulo, int v):
	Personagem(textura, contQuadro, mudaT, aceleracao, alturaPulo),
	vira(1), passos(0)
{
	vira = v;
}

Inimigo::Inimigo()
{
}

Inimigo::~Inimigo()
{
}

void Inimigo::atualizar(float deltaT)
{		
	if (!morto)
	{
		movimentar(deltaT);
		corpo.move(velocidade * deltaT);
	}

	else
		morrer(deltaT);

	if (!animacaoMorto)
	{
		if(linhaAnimacao == 1)
			animacaoMorto = animacao.atualizarAnimacao2(linhaAnimacao, deltaT, faceDireita);
		else
			animacao.atualizarAnimacao2(linhaAnimacao, deltaT, faceDireita);
		quadro.setTextureRect(animacao.uvRect);
		quadro.setPosition(corpo.getPosition());
	}
	desenhar();
}

void Inimigo::danificar(float deltaT)
{
}

void Inimigo::morrer(float deltaT)
{
	if (!animacaoMorto)
		setarLinha(1);
}