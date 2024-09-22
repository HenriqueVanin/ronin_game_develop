#pragma once
#include "Entidade.h"

class Personagem : public Entidade
{
protected:
	bool podePular;
	float aceleracao;
	bool faceDireita;
	bool morto;
	bool animacaoMorto;
	int linhaAnimacao;
	
	Vector2f velocidade;
	RectangleShape ataque;

public:
	Personagem(Texture* textura, Vector2u contQuadro, float mudaT, float aceleracao, float alturaPulo);
	Personagem();
	~Personagem();

	virtual void danificar(float deltaT) = 0;
	virtual void morrer(float deltaT) = 0;
	virtual void movimentar(float deltaT) = 0;

	void virarFace(float deltaT);
	void emColisao(Vector2f direcao);
	void atualizarAnimacao(float deltaT);
	void atualizarCorpoAtaque(float deltaT);
	void aplicarGravidade(float deltaT);

	//virtual void atacar(float deltaT, Vector2f direcao, Personagem* inimigo) = 0;

	// SETS //

	void setarVelocidade(Vector2f v);
	void setarAceleracao(float a);
	void setarLinha(float l);
	void setarFace(bool f);
	void setarMorto(bool m);
	void setarAtaque(RectangleShape r);
		
	// GETS //

	Colisor retornarColisorAtaque();
	float retornarAceleracao() const;
	int retornarLinha() const;
	bool retornarFace() const;
	bool retornarMorto() const;
	Vector2f retornarVelocidade() const;
	RectangleShape retornarAtaque() const;	
};