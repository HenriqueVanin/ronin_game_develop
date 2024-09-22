#include "PlataformaSuspensa.h"
#include "Jogador.h"

PlataformaSuspensa::PlataformaSuspensa(Texture* textura, Vector2f posicao) :
	Obstaculo(textura, Vector2u(0,0), 0.0f),
	gravidade(Vector2f(0.0f, 0.0f)), primeiraColisao(false)
{
	this->corpo.setSize(Vector2f(800.0f, 20.0f));
	this->corpo.setOrigin(this->corpo.getSize().x / 2.0f, this->corpo.getSize().y / 2.0f);
	this->corpo.setPosition(posicao);
	//this->corpo.setFillColor(Color(255, 255, 255));
	this->corpo.setTexture(textura);
}


PlataformaSuspensa::PlataformaSuspensa()
{
}

PlataformaSuspensa::~PlataformaSuspensa()
{
}

void PlataformaSuspensa::atualizar(float deltaT)
{
	quadro.setTextureRect(animacao.uvRect);
	quadro.setPosition(corpo.getPosition());
	TELA->desenhar(corpo);
	corpo.move(gravidade * deltaT);
}

void PlataformaSuspensa::manifestarObstaculo(Jogador* pJogador, Vector2f direcao, float deltaT)
{
	atualizar(deltaT);
	cairPlataforma(pJogador, direcao);
}

void PlataformaSuspensa::cairPlataforma(Jogador* pJogador, Vector2f direcao)
{
	if (primeiraColisao)
	{
		temporizador = tempo.getElapsedTime().asSeconds();
		if (temporizador > 1)
		{
			gravidade.y = 800.0f;
		}
	}
	if (retornarColisao(pJogador, direcao, 0.0f, true) && 
		(pJogador->retornarPosicao().x > (corpo.getPosition().x - corpo.getSize().x - pJogador->retornarPosicao().x/2 )  ||
		(pJogador->retornarPosicao().x < (corpo.getPosition().x + corpo.getSize().x + pJogador->retornarPosicao().x / 2) &&
		 pJogador->retornarPosicao().y < (pJogador->retornarPosicao().y/2 + corpo.getPosition().y + corpo.getSize().y))))
	{
		if (!primeiraColisao)
		{
			tempo.restart();
			primeiraColisao = true;
		}
		
	}
}