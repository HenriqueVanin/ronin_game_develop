#pragma once

#include "Jogador.h"
#include "Umibozu.h"
#include "Akaname.h"
#include "Kage.h"

#include "Menu.h"
#include "Plataforma.h"
#include "Estatua.h"
#include "FogoFatuo.h"
#include "PlataformaSuspensa.h"

#include "ListaEntidades.h"
#include "ListaPlataformas.h"
#include "ListaInimigos.h"
#include "ListaObstaculos.h"

class Fase : public Entidade
{
protected:
	// JOGADORES //
	Jogador* jogador1;
	Jogador* jogador2;

	// LISTAS //
	ListaEntidades   listaEntidades;	// Responsável pela chamada da função atualizar das entidades
	ListaPlataformas listaPlataformas;	//		|
	ListaObstaculos  listaObstaculos;	//		>    Listas responsáveis pelas colisões
	ListaInimigos    listaInimigos;	    //		|

	// OBJETOS DE FASE //
	Music musica;						// Música de Fundo
	float deltaT;						// Tempo de cada iteração no laço principal
	Clock relogio;						// Contador do tempo de cada iteração no laço principal
	float temporizadorDeFase;		    // Temporizador usado como parâmtro para calcular a pontuação
	Clock tempoDeFase;					// Contador do tempo de cada iteração no laço principal
	bool  rodandoFase;					// Parâmetro para iniciar e parar o laço principal
	bool  coop;							// Parâmetro para determinar coperativo
	bool faseAberta;					// Parâmetro condicional para o laço principal
	bool venceu;				     	// Parâmetro condicional para passar de fase
	bool jogadoresMortos;				// Parâmtro para determinar se os jogadores estão mortos

	/// REVISAR ///
	Menu menuPausa;						// Objeto de menu para a chamada do menu de pausa

	// ---- TEXTURAS ----- //

	// TEXTURAS PERSONAGENS //
	Texture tJogador1;
	Texture tJogador2;

	// TEXTURAS INIMIGOS //
	Texture tUmibozu;
	Texture tAkaname;
	Texture tKage;
	
	// FASE //
	Texture fundo;
	Sprite imagemFundo;

	// OBSTACULOS //
	Texture tEstatua;
	Texture tFogo;
	Texture tPlataforma;

public:
	Fase();
	~Fase();

	void pausar();			
	void tocarMusica();

	virtual void executar() = 0;

	void checarJogadores();
	void setarCoop(bool c);
	void desenharTela();
	void ajustarTela();
	void setarTextura();
	void pararMusica();
	void eventoTela();

	// FUNÇÕES DE COMPORTAMENTO DE ENTIDADES //

	void laçoFasePrincipal(float deltaT, Vector2f direcao);
	void atualizarEntidades(float deltaT);
	void checarColisaoPlataformas(Vector2f direcao);
	void checarColisaoInimigo(float deltaT, Vector2f direcao);
	void checarColisaoObstaculo(float deltaT, Vector2f direcao);
	void checarAtaque1(float deltaT, Vector2f direcao);
	void checarAtaque2(float deltaT, Vector2f direcao);
	void manifestaObstaculos(Jogador* jogador, Vector2f direcao, float deltaT);
	void interagirEntidades(Jogador* jogador1, Jogador* jogador2, Vector2f direcao, float deltaT);
	void eventosTeclas(float deltaT, Vector2f direcao);
	void atualizarJogadores(float deltaT);
	void desenharListaPlataformas();
	void temporizarRelogio();
	bool passouDeFase();

	void inicializarJogadores();
	void inicializarInimigos();
	void inicializarObstaculos();

	bool retornarVenceu();
	void verificarVenceu();
	void setarFaseAberta(bool f);

	virtual void setarTexturaFundo() = 0;
};