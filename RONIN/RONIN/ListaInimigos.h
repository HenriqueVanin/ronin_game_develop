#pragma once
#include "Inimigo.h"

class ListaInimigos
{
public:
	class ElementoInimigo
	{
	private:
		Inimigo* pInimigo;

	public:
		ElementoInimigo();
		~ElementoInimigo();

		void setarInimigo(Inimigo* pI);
		Inimigo* retornarInimigo();

		ElementoInimigo* pProx;
		ElementoInimigo* pAnte;
	};
private:
	ElementoInimigo* pPrim;
	ElementoInimigo* pAtual;
	ElementoInimigo* pIterador;
	
	int contador;

public:
	ListaInimigos();
	~ListaInimigos();

	Inimigo* percorreLista();
	void incluiInimigo(Inimigo* pI);
	void atualizaInimigo(float deltaT);
	void limpaLista();
	int retornarContador();
};