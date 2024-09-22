#include "FogoFatuo.h"
#include "Jogador.h"

FogoFatuo::FogoFatuo(Texture* textura, Vector2f posicao, Vector2u contQuadro, float mudaT):
	Obstaculo(textura, contQuadro, mudaT),
	aceso(false)
{	
	// Inicializa Hitbox
	this->corpo.setSize(Vector2f(70.0f, 70.0f));
	this->corpo.setOrigin(this->corpo.getSize().x / 2.0f, this->corpo.getSize().y / 2.0f);
	this->corpo.setPosition(posicao);
	
	// Inicializa Frame
	this->quadro.setSize(Vector2f(70.0f, 70.0f));
	this->quadro.setOrigin(this->corpo.getSize().x / 2.0f, this->corpo.getSize().y / 2.0f);
	this->quadro.setPosition(posicao);

	// Seta Textura
	quadro.setTexture(textura);
}

FogoFatuo::FogoFatuo():
	aceso(false)
{
}

FogoFatuo::~FogoFatuo()
{
	//delete this;
}

void FogoFatuo::atualizar(float deltaT)
{
	// Caso o fogo ainda n�o estiver "aceso" ( presente na fase ) a primeira linha de anima��o � usada
	// Ap�s ele estar aceso, entra num loop de anima��o

	if (aceso)
	{
		animarFogo(deltaT);
	}

	else
	{
		aceso = acenderFogo(deltaT);
	}

	// Seta ret�ngulo relativo ao frame atual e mostra na tela
	quadro.setTextureRect(animacao.uvRect);
	TELA->desenhar(quadro);
}

void FogoFatuo::animarFogo(float deltaT)
{
	// Chamada da fun��o de anima��o
	animacao.atualizarAnimacao2(0, deltaT, true);
}


bool FogoFatuo::acenderFogo(float deltaT)
{
	// Chamada da fun��o de anima��o
	return animacao.atualizarAnimacao2(1, deltaT, true);
}

void FogoFatuo::manifestarObstaculo(Jogador* pJogador, Vector2f direcao, float deltaT)
{
	checarColisao(pJogador, direcao, deltaT);
}

void FogoFatuo::checarColisao(Jogador* pJogador, Vector2f direcao, float deltaT)
{
	// Verifica se o fogo f�tuo esta aceso e se o jogador est� vivo, se for o caso, verifica colis�o e computa o dano
	// no jogador.
	atualizar(deltaT);
	if (!pJogador->retornarMorto() && aceso)
	{
		if (retornarColisao(pJogador, direcao, 0.0f, false))
		{
			pJogador->danificar(deltaT);
		}
	}	
}