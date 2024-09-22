#include "Akaname.h"

Akaname::Akaname(Texture* textura, Vector2u contQuadro, float mudaT, float aceleracao, float alturaPulo, Vector2f tamCorpo, Vector2f tamQuadro, Vector2f posicao, int vira):
	Inimigo(textura, contQuadro, mudaT, aceleracao, alturaPulo, vira)
{
	this->quadro.setSize(tamQuadro);
	this->quadro.setOrigin(this->quadro.getSize() / 2.0f);
	this->quadro.setPosition(posicao);

	this->corpo.setSize(tamCorpo);
	this->corpo.setOrigin(this->corpo.getSize() / 2.0f);
	this->corpo.setPosition(posicao);
}

Akaname::Akaname()
{
}

Akaname::~Akaname()
{
}

void Akaname::movimentar(float deltaT)
{
	if (!morto)
	{
		setarLinha(0);
		//Para o personagem ( em caso de 0.0f : para instantaneamente )

		if (vira == 1)
		{
			velocidade.y += aceleracao;
			passos++;
		}

		else
		{
			velocidade.y -= aceleracao;
			passos++;
		}

		if (passos == 2)
		{
			passos = 0;
			vira *= -1;
		}
	}
}
