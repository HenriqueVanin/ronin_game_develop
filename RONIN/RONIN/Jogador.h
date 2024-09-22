#pragma once
#include "Personagem.h"
#include "Pontuacao.h"

class Inimigo;

	class Jogador : public Personagem
	{
	protected:
		int nPulos;
		float alturaPulo;
		unsigned int nJogador;
	

		Pontuacao pontuacaoJogador;

	public:
		Jogador(Texture* textura, Vector2u contQuadro, float mudaT, float aceleracao, float alturaPulo, Vector2f tamCorpo, Vector2f tamQuadro, Vector2f posicao, unsigned int nJogador);
		Jogador();
		~Jogador();

	
		void danificar(float deltaT);
		void morrer(float deltaT);
		void movimentar(float deltaT);
		void atacar(float deltaT, Vector2f direcao, Inimigo* inimigo);

		void atualizar(float deltaT);
		void pular(float deltaT);
		void animacaoAtaque(float deltaT);
		void virarFace(float deltaT);
	
		void setarPodePular(bool p);

		int retornarPontuacao();
};


