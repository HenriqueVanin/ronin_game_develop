#include "ListaObstaculos.h"

ListaObstaculos::ListaObstaculos() :
	listaObstaculos(NULL)
{
}

ListaObstaculos::~ListaObstaculos()
{
}

void ListaObstaculos::percorreLista(Jogador* pJogador, Vector2f direcao, float deltaT)
{
	if (!listaObstaculos.empty())
	{
		for (iterador = listaObstaculos.begin(); iterador != listaObstaculos.end(); iterador++)
		{
			Obstaculo* pO = *iterador;
			//cout << " Animou Obstaculo " << endl;
			pO->manifestarObstaculo(pJogador, direcao, deltaT);
			pO = NULL;
		}
	}
}

void ListaObstaculos::limpaLista()
{
	if (!listaObstaculos.empty())
	{
		for (iterador = listaObstaculos.begin(); iterador != listaObstaculos.end(); iterador++)
		{
			delete *iterador;
		}
	}
}

void ListaObstaculos::incluiObstaculo(Obstaculo* pO)
{
	listaObstaculos.push_back(pO);
}

void ListaObstaculos::excluiObstaculo()
{
	listaObstaculos.pop_front();
}