#pragma once
#include "GerenciadorGrafico.h"
#include "Menu.h"
#include "Fase1.h"
#include "Fase2.h"

class Jogo
{
private:
	Fase1 fase1;
	Fase2 fase2;
	// MENU //
	Menu menu;

public:
	Jogo();
	~Jogo();

	// FUNÇÕES //
	void atualizar();
	void rodar();
	
};