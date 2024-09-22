#pragma once
#include "Obstaculo.h"

// Obstaculo que aparece na fase após ela ser instanciada e depois de um certo intervalo de tempo, checa colisões com
// com o jogador e computa dano se for o caso.

class FogoFatuo : public Obstaculo
{
private:
	// Atributo sinalizador do período de animação
	bool aceso;

public:
	// Métodos de Classe
	FogoFatuo(Texture* textura, Vector2f posicao, Vector2u contQuadro, float mudaT);
	FogoFatuo();
	~FogoFatuo();

	// Métodos de Atualização
	void atualizar(float deltaT);											     // Atualiza animação
	bool acenderFogo(float deltaT);										    	 // Método de chamada de animação inicial
	void animarFogo(float deltaT);											     // Método de chamada da animação principal

	void manifestarObstaculo(Jogador* pJogador, Vector2f direcao, float deltaT); // Método de chamada do comportamento do Obstaculo
	void checarColisao(Jogador* pJogador, Vector2f direcao, float deltaT);	     // Método de verificação de colisão
};																					/* 
																					   O método checarColisao não pertence à classe 
																					   Obstaculo pois depende de variáveis
																					   específicas de FogoFatuo.
																					*/


