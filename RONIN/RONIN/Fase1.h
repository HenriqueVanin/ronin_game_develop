#pragma once
#include "Fase.h"

class Fase1 : public Fase
{
private:
public:
	Fase1();
	~Fase1();

	void atualizar(float deltaT);
	void executar();

	int inicializarMusica();
	void setarTexturaFundo();
};

