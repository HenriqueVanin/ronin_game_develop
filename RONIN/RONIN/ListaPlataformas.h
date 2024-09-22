#pragma once
#include <vector>
#include "Plataforma.h"

class Personagem;

class ListaPlataformas
{
private:
	vector<Plataforma> plataformas;

public:
	ListaPlataformas();
	~ListaPlataformas();

	void incluirPlataforma(Plataforma pP);
	Plataforma* retornarListaPlataformas();
	void limparLista();
	void checarColisoesPlataformas(Personagem* pPersonagem, Vector2f direcao);
};