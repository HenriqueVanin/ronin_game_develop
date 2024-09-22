#pragma once
#include "Obstaculo.h"

// Obstaculo que aparece na fase ap�s ela ser instanciada e depois de um certo intervalo de tempo, checa colis�es com
// com o jogador e computa dano se for o caso.

class FogoFatuo : public Obstaculo
{
private:
	// Atributo sinalizador do per�odo de anima��o
	bool aceso;

public:
	// M�todos de Classe
	FogoFatuo(Texture* textura, Vector2f posicao, Vector2u contQuadro, float mudaT);
	FogoFatuo();
	~FogoFatuo();

	// M�todos de Atualiza��o
	void atualizar(float deltaT);											     // Atualiza anima��o
	bool acenderFogo(float deltaT);										    	 // M�todo de chamada de anima��o inicial
	void animarFogo(float deltaT);											     // M�todo de chamada da anima��o principal

	void manifestarObstaculo(Jogador* pJogador, Vector2f direcao, float deltaT); // M�todo de chamada do comportamento do Obstaculo
	void checarColisao(Jogador* pJogador, Vector2f direcao, float deltaT);	     // M�todo de verifica��o de colis�o
};																					/* 
																					   O m�todo checarColisao n�o pertence � classe 
																					   Obstaculo pois depende de vari�veis
																					   espec�ficas de FogoFatuo.
																					*/


