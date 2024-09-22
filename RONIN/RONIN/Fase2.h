#pragma once
#include "Fase.h"

class Fase2 : public Fase
{
private:
	Kage* chefao;
public:
	Fase2();
	~Fase2();

	void atualizar(float deltaT);
	void executar();

	int  inicializarMusica();
	void inicializarChefao();
	void setarTexturaFundo();
	void atualizarChefao(float deltaT);
};
