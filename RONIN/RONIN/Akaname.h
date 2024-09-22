#pragma once
#include "Inimigo.h"

	class Akaname : public Inimigo
	{
	private:
	public:
		Akaname(Texture* textura, Vector2u contQuadro, float mudaT, float aceleracao, float alturaPulo, Vector2f tamCorpo, Vector2f tamQuadro, Vector2f posicao, int vira);
		Akaname();
		~Akaname();

		void movimentar(float deltaT);
	};