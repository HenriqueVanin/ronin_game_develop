#pragma once
#include "GerenciadorGrafico.h"
#include "Entidade.h"
#include "Botao.h"

#define NOVO_JOGO 1
#define COOP_JOGO 2
#define FASE_1    3
#define FASE_2    4
#define RANKING   5
#define SAIR      6

class Menu: public Entidade
{
private:
	Event evento;
	Music musicamenu;
	int botaoSelecionado;
	Texture selecaoBotao;
	Texture tTelaInicial;
	RectangleShape telaInicialQuadro;

	Clock relogio;
	int temporizador;

	Texture menuIniciar;
	//Texture menuCoop;
	Texture menuFaseI;
	Texture menuFaseII;
	//Texture menuSalvar;
	//Texture menuCarregar;
	Texture menuSair;

public:
	Menu();
	~Menu();

	int  executar();
	void menuPrincipal();
	void telaInicial();
	/// int  menuPausa();

	int  inicializarMusica();
	void selecionarBotao(int botao);
	void setarTexturas();

	void atualizar(float deltaT);

	void moverCima();
	void moverBaixo();

	int retornarBotaoSelecionado();

};

