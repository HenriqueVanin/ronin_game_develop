#include "Kage.h"

Kage::Kage(Texture* textura, Vector2u contQuadro, float mudaT, float aceleracao, float alturaPulo, Vector2f tamCorpo, Vector2f tamQuadro, Vector2f posicao):
	Inimigo(textura, contQuadro, mudaT, aceleracao, alturaPulo, 1)
{
	this->quadro.setSize(tamQuadro);
	this->quadro.setOrigin(this->quadro.getSize() / 2.0f);
	this->quadro.setPosition(posicao);

	this->corpo.setSize(tamCorpo);
	this->corpo.setOrigin(this->corpo.getSize() / 2.0f);
	this->corpo.setPosition(posicao);
}

Kage::Kage()
{
}

Kage::~Kage()
{
}

void Kage::movimentar(float deltaT)
{
		temporizador = tempo.getElapsedTime().asSeconds();
		//atualizarAnimacao(deltaT);
		animacao.atualizarAnimacao(2, deltaT, faceDireita);
		quadro.setTextureRect(animacao.uvRect);
		quadro.setPosition(corpo.getPosition());

		//Para o personagem ( em caso de 0.0f : para instantaneamente )
		velocidade.x *= 0.5f;

		if (temporizador < 1)
		{
			if (vira == 1)
			{
				velocidade.x += aceleracao;
				passos++;
				corpo.move(velocidade * 2.0f);
			}

			else
			{
				velocidade.x -= aceleracao;
				passos++;
				corpo.move(velocidade * 2.0f);
			}

			if (passos == 50)
			{
				passos = 0;
				vira *= -1;
				tempo.restart();
			}
		}
		if (velocidade.x > 0.0f)
			faceDireita = false;
		else
			faceDireita = true;

	desenhar();
}

void Kage::atacarKage(float deltaT)
{
	RectangleShape corpoTemporario = retornarCorpo();
	setarCorpo(ataque);
	setarCorpo(corpoTemporario);
}
