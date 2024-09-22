#pragma once
#include <list>
#include "Obstaculo.h"
#include "Plataforma.h"

class Jogador; class Inimigo;

using namespace std;

class ListaObstaculos
{
private:
	list <Obstaculo*> listaObstaculos;
	list <Obstaculo*> ::iterator iterador;

public:
	ListaObstaculos();
	~ListaObstaculos();

	void percorreLista(Jogador* pJogador, Vector2f direcao, float deltaT);
	void limpaLista();
	void incluiObstaculo(Obstaculo* pO);
	void excluiObstaculo();
};

