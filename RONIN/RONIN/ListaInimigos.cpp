#include "ListaInimigos.h"

ListaInimigos::ElementoInimigo::ElementoInimigo():
	pInimigo(NULL), pProx(NULL), pAnte(NULL)
{
}

ListaInimigos::ElementoInimigo::~ElementoInimigo()
{
	pInimigo = NULL; pProx = NULL; pAnte = NULL; 
}

void ListaInimigos::ElementoInimigo::setarInimigo(Inimigo* pI)
{
	pInimigo = pI;
}

Inimigo* ListaInimigos::ElementoInimigo::retornarInimigo()
{
	return pInimigo;
}
ListaInimigos::ListaInimigos():
	pPrim(NULL), pAtual(NULL), pIterador(NULL), contador(0)
{
}

ListaInimigos::~ListaInimigos()
{
	limpaLista();
}

Inimigo* ListaInimigos::percorreLista()
{
	if (pPrim)
	{
		ElementoInimigo* pAux;

		pAux = pIterador;
		if (pAux)
		{
			if (pAux->pProx == NULL)
				pIterador = pPrim;
			else
				pIterador = pAux->pProx;
			return pAux->retornarInimigo();
		}
	}
	return NULL;
}

void ListaInimigos::incluiInimigo(Inimigo* pI)
{
	ElementoInimigo* novoInimigo;
	novoInimigo = new ElementoInimigo();
	novoInimigo->setarInimigo(pI);

	if (pI != NULL)
	{
		if (pPrim == NULL)
		{
			pPrim = novoInimigo;
			pAtual = novoInimigo;
			pIterador = pPrim;
		}
		else
		{
			pAtual->pProx = novoInimigo;
			novoInimigo->pAnte = pAtual;
			pAtual = novoInimigo;
		}
		contador++;
	}
}

void ListaInimigos::atualizaInimigo(float deltaT)
{
}

void ListaInimigos::limpaLista()
{
	ElementoInimigo* paux1, * paux2;

	paux1 = pPrim;
	paux2 = paux1;

	while (paux1 != NULL)
	{
		paux2 = paux1->pProx;
		delete (paux1);
		paux1 = paux2;
	}

	pPrim = NULL;
	pAtual = NULL;
	pIterador = NULL;
}

int ListaInimigos::retornarContador()
{
	return contador;
}
