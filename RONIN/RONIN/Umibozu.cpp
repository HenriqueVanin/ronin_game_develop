#include "Umibozu.h"

Umibozu::Umibozu(Texture* textura, Vector2u contQuadro, float mudaT, float aceleracao, float alturaPulo, Vector2f tamCorpo, Vector2f tamQuadro, Vector2f posicao, int vira):
	Inimigo(textura, contQuadro, mudaT, aceleracao, alturaPulo, vira)
{
	this->quadro.setSize(tamQuadro);
	this->quadro.setOrigin(this->quadro.getSize() / 2.0f);
	this->quadro.setPosition(posicao);

	this->corpo.setSize(tamCorpo);
	this->corpo.setOrigin(this->corpo.getSize() / 2.0f);
	this->corpo.setPosition(posicao);
	//this->corpo.setFillColor(Color(100, 100, 100, 100));
}

Umibozu::Umibozu()
{
}

Umibozu::~Umibozu()
{
}
/*
void Umibozu::atualizar(float deltaT)
{
		movimentar(deltaT);	
		//Atualiza posição do personagem
		animacao.atualizar(linhaAnimacao, deltaT, faceDireita);
		quadro.setTextureRect(animacao.uvRect);
		//quadro.move(velocidade * deltaT);
		quadro.setPosition(corpo.getPosition());
		corpo.move(velocidade * deltaT);
		desenhar();
}
*/
void Umibozu::movimentar(float deltaT)
{
	if (!morto)
	{
		setarLinha(0);
		//Para o personagem ( em caso de 0.0f : para instantaneamente )
		velocidade.x *= 0.5f;

		if (vira == 1)
		{
			velocidade.x += aceleracao;
			passos++;
		}

		else
		{
			velocidade.x -= aceleracao;
			passos++;
		}

		if (passos == 500)
		{
			passos = 0;
			vira *= -1;
		}

		if (velocidade.x > 0.0f)
			faceDireita = false;
		else
			faceDireita = true;
	}
	else
		morrer(deltaT);
}
