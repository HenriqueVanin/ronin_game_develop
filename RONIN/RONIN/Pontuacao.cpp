#include "Pontuacao.h"

Pontuacao::Pontuacao():
	pontuacao(0)
{
}

Pontuacao::~Pontuacao()
{
	this->pontuacao = 0;
}

void Pontuacao::incrementaPontuacao()
{
	this->pontuacao++;
}

void Pontuacao::zerarPontuacao()
{
	pontuacao = 0;
}

int Pontuacao::retornarPontuacao()
{
	return pontuacao;
}
