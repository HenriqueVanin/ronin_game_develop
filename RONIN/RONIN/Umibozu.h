#pragma once
#include "Inimigo.h"

	class Umibozu : public Inimigo
	{
	private:
	public:
		Umibozu(Texture* textura, Vector2u contQuadro, float mudaT, float aceleracao, float alturaPulo, Vector2f tamCorpo, Vector2f tamQuadro, Vector2f posicao, int vira);
		Umibozu();
		~Umibozu();

		void movimentar(float deltaT);
	};
