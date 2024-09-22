#include "Colisor.h"

Colisor::Colisor(RectangleShape& corpo):
	corpo(corpo)
{
}

Colisor::~Colisor()
{
}

bool Colisor::checarColisao(Colisor outro, Vector2f& direcao, float empurra, bool repulsao)
{
	Vector2f outroPosicao = outro.retornarPosicao();
	Vector2f outroMetadeTam = outro.retornarMetadeTam();
	Vector2f atualPosicao = retornarPosicao();
	Vector2f atualMetadeTam = retornarMetadeTam();

	float deltaX = outroPosicao.x - atualPosicao.x;
	float deltaY = outroPosicao.y - atualPosicao.y;
	float interseptaX = abs(deltaX) - (outroMetadeTam.x + atualMetadeTam.x);
	float interseptaY = abs(deltaY) - (outroMetadeTam.y + atualMetadeTam.y);

	if (interseptaX < 0.0f && interseptaY < 0.0f)
	{
		empurra = min(max(empurra, 0.0f), 1.0f);
		if (repulsao)
		{
			if (interseptaX > interseptaY)
			{
				if (deltaX > 0.0f)
				{
					mover(interseptaX * (1.0f - empurra), 0.0f);
					outro.mover(-interseptaX * empurra, 0.0f);

					direcao.x = 1.0f;
					direcao.y = 0.0f;
				}
				else
				{
					mover(-interseptaX * (1.0f - empurra), 0.0f);
					outro.mover(interseptaX * empurra, 0.0f);

					direcao.x = -1.0f;
					direcao.y = 0.0f;
				}
			}
			else
			{
				if (deltaY > 0.0f)
				{
					mover(0.0f, interseptaY * (1.0f - empurra));
					outro.mover(0.0f, -interseptaY * empurra);

					direcao.x = 0.0f;
					direcao.y = 1.0f;
				}
				else
				{
					mover(0.0f, -interseptaY * (1.0f - empurra));
					outro.mover(0.0f, interseptaY * empurra);

					direcao.x = 0.0f;
					direcao.y = -1.0f;
				}
			}
		}
		return true;
	}
	return false;
}

Vector2f Colisor::retornarMetadeTam()
{
	return corpo.getSize()/2.0f;
}

Vector2f Colisor::retornarPosicao()
{
	return corpo.getPosition();
}

void Colisor::mover(float dx, float dy)
{
	return corpo.move(dx,dy);
}