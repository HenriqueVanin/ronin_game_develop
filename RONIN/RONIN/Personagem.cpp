#include "Personagem.h"
#include "Inimigo.h"

Personagem::Personagem(Texture* textura, Vector2u contQuadro, float mudaT, float aceleracao, float alturaPulo) :
	Entidade(textura, contQuadro, mudaT), animacaoMorto(false),
	podePular(false), linhaAnimacao(0), morto(false), faceDireita(true), aceleracao (aceleracao)
{	
}

Personagem::Personagem()
{
}

Personagem::~Personagem()
{
}

void Personagem::emColisao(Vector2f direcao)
{
	if (direcao.x < 0.0f)
	{
		//Colisão à esquerda
		velocidade.x = 0.0f;
	}
	else if (direcao.x > 0.0f)
	{
		//Colisão à direita
		velocidade.x = 0.0f;
	}

	if (direcao.y < 0.0f)
	{
		//Colisão abaixo
		velocidade.y = 0.0f;
		podePular = true;
	}
	else if (direcao.y > 0.0f)
	{
		//Colisão acima
		velocidade.y = 0.0f;
	}
}

void Personagem::setarVelocidade(Vector2f v)
{
	velocidade = v;
}


void Personagem::setarAceleracao(float a)
{
	aceleracao = a;
}

void Personagem::setarLinha(float l)
{
	linhaAnimacao = l;
}

void Personagem::setarFace(bool f)
{
	faceDireita = f;
}

void Personagem::setarMorto(bool m)
{
	morto = m;
}

void Personagem::setarAtaque(RectangleShape r)
{
	ataque = r;
}


void Personagem::virarFace(float deltaT)
{
}

Colisor Personagem::retornarColisorAtaque()
{
	return Colisor(ataque);
}


void Personagem::atualizarAnimacao(float deltaT)
{
	if (linhaAnimacao == 5)
		animacaoMorto = animacao.atualizarAnimacao(linhaAnimacao, deltaT, faceDireita);
	else
		animacao.atualizarAnimacao(linhaAnimacao, deltaT, faceDireita);
	quadro.setTextureRect(animacao.uvRect);
	quadro.setPosition(corpo.getPosition());
}

void Personagem::atualizarCorpoAtaque(float deltaT)
{
	//Atualiza Hitbox do ataque
	ataque.setOrigin(corpo.getOrigin().x + corpo.getSize().x / 4.0f, corpo.getOrigin().y);
	if (retornarFace())
		ataque.setPosition(corpo.getPosition().x + corpo.getSize().x * 2.0f, corpo.getPosition().y - corpo.getSize().y / 2.0f);
	else
			ataque.setPosition(corpo.getPosition().x - corpo.getSize().x * 2.0f, corpo.getPosition().y - corpo.getSize().y / 2.0f);
}

void Personagem::aplicarGravidade(float deltaT)
{
	velocidade.y += 981.0f * deltaT;
}

float Personagem::retornarAceleracao() const
{
	return aceleracao;
}

int Personagem::retornarLinha() const
{
	return linhaAnimacao;
}

bool Personagem::retornarFace() const
{
	return faceDireita;
}

bool Personagem::retornarMorto() const
{
 	return morto;
}

Vector2f Personagem::retornarVelocidade() const
{
	return velocidade;
}

RectangleShape Personagem::retornarAtaque() const
{
	return ataque;
}

