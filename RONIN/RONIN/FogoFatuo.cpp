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
	// Caso o fogo ainda não estiver "aceso" ( presente na fase ) a primeira linha de animação é usada
	// Após ele estar aceso, entra num loop de animação

	if (aceso)
	{
		animarFogo(deltaT);
	}

	else
	{
		aceso = acenderFogo(deltaT);
	}

	// Seta retângulo relativo ao frame atual e mostra na tela
	quadro.setTextureRect(animacao.uvRect);
	TELA->desenhar(quadro);
}

void FogoFatuo::animarFogo(float deltaT)
{
	// Chamada da função de animação
	animacao.atualizarAnimacao2(0, deltaT, true);
}


bool FogoFatuo::acenderFogo(float deltaT)
{
	// Chamada da função de animação
	return animacao.atualizarAnimacao2(1, deltaT, true);
}

void FogoFatuo::manifestarObstaculo(Jogador* pJogador, Vector2f direcao, float deltaT)
{
	checarColisao(pJogador, direcao, deltaT);
}

void FogoFatuo::checarColisao(Jogador* pJogador, Vector2f direcao, float deltaT)
{
	// Verifica se o fogo fátuo esta aceso e se o jogador está vivo, se for o caso, verifica colisão e computa o dano
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