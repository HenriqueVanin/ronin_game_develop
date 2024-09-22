#include "Animador.h"

Animador::Animador(Texture* textura, Vector2u contQuadro, float mudaT) :
	contQuadro(contQuadro), mudaT(mudaT), tempoTotal(0.0f)
{
	if (textura)
	{
		quadroAtual.x = 0;
		uvRect.width = textura->getSize().x/static_cast <float> (contQuadro.x);
		uvRect.height = textura->getSize().y/static_cast <float> (contQuadro.y);
	}
}

Animador::Animador():
	mudaT(0), tempoTotal(0.0f)
{
}

Animador::~Animador()
{
}

bool Animador::atualizarAnimacao(int linhaAnimacao, float deltaT, bool faceDireita)
{
	quadroAtual.y = linhaAnimacao;
	tempoTotal += deltaT;

	if (tempoTotal >= mudaT)
	{
		tempoTotal -= mudaT;
		quadroAtual.x++;

		switch (linhaAnimacao)
		{
		case 0:
		{
			if (quadroAtual.x > 3)
				quadroAtual.x = 0;
			break;
		}
		case 1:
		{
			if (quadroAtual.x > 5)
				quadroAtual.x = 0;
			break;
		}
		case 2:
		{
			if (quadroAtual.x > 1)
				quadroAtual.x = 0;
			break;
		}
		case 3:
		{
			if (quadroAtual.x > 2)
				quadroAtual.x = 0;
			break;
		}
		case 4:
		{
			if(quadroAtual.x > 2)
				quadroAtual.x = 0;
			break;
		}
		case 5:
		{
			if (quadroAtual.x > 2)
				quadroAtual.x = 0;
			break;
		}
		default:
			break;
		}

	}

	uvRect.top = quadroAtual.y * uvRect.height;

	if (faceDireita)
	{
		uvRect.left = quadroAtual.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}

	else
	{
		uvRect.left = (quadroAtual.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}

	if (linhaAnimacao == 5 && quadroAtual.x == 2)
		return true;
	if (linhaAnimacao == 2 && quadroAtual.x == 1)
		return true;

	return false;
}

bool Animador::atualizarAnimacao2(int linhaAnimacao, float deltaT, bool faceDireita)
{
	quadroAtual.y = linhaAnimacao;
	tempoTotal += deltaT;
	
	if (tempoTotal >= mudaT)
	{
		tempoTotal -= mudaT;
		quadroAtual.x++;
		
		if (quadroAtual.x > 7)
			quadroAtual.x = 0;
	}

	uvRect.top = quadroAtual.y * uvRect.height;

	if (faceDireita)
	{
		uvRect.left = quadroAtual.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}

	else
	{
		uvRect.left = (quadroAtual.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}


	if (linhaAnimacao == 1 && quadroAtual.x == 7)
		return true;

	return false;
}
