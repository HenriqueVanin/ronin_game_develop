#pragma once
class Pontuacao
{
private:
	int pontuacao;
public:
	Pontuacao();
	~Pontuacao();

	void incrementaPontuacao();
	void zerarPontuacao();
	int  retornarPontuacao();
};

