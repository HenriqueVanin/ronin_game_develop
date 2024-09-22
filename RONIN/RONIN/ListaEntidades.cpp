#include "ListaEntidades.h"


ListaEntidades::ListaEntidades():
	tamanhoListaUmibozu(0), tamanhoListaAkaname(0)
{
}

ListaEntidades::~ListaEntidades()
{
	limparLista();
}

void ListaEntidades::incluirUmibozu(Umibozu* pU)
{
	if (pU)
	{
		listaUmibozu.push_back(pU);
	}
}

void ListaEntidades::incluirAkaname(Akaname* pA)
{
	if (pA)
	{
		listaAkaname.push_back(pA);
	}
}

void ListaEntidades::atualizarListaUmibozu(float deltaT)
{	
	for (Umibozu* inimigo : listaUmibozu)
	{
		inimigo->atualizar(deltaT);
		inimigo->desenhar();
	}
}

void ListaEntidades::atualizarListaAkaname(float deltaT)
{
	for (Akaname* inimigo : listaAkaname)
	{
		inimigo->atualizar(deltaT);
		inimigo->desenhar();
	}
}

void ListaEntidades::limparLista()
{
	
	listaAkaname.erase(listaAkaname.begin(), listaAkaname.end());
	listaUmibozu.erase(listaUmibozu.begin(), listaUmibozu.end());
}

/*
ListaEntidades::ListaEntidades():
	listaAkaname(), listaUmibozu()
{
}

ListaEntidades::~ListaEntidades()
{
}

void ListaEntidades::incluirUmibozu(Umibozu* pU)
{
	this->listaUmibozu.incluirInfo(pU);
}

void ListaEntidades::incluirAkaname(Akaname* pA)
{
	this->listaAkaname.incluirInfo(pA);
}

void ListaEntidades::limparLista()
{
	this->listaUmibozu.limpaLista();
	this->listaAkaname.limpaLista();
}

void ListaEntidades::atualizarAkaname(float deltaT)
{
	int tamanhoLista = listaAkaname.retornarNElementos();
	for (int i = 0; i < tamanhoLista; i++)
	{
		Akaname* pAux;
		pAux = listaAkaname.retornarElemento();
		if (pAux != NULL)
		{
			pAux->atualizar(deltaT);
			pAux->desenhar();
		}
		else
			cout << " Sem elementos na lista de entidades " << endl;
	}
}

void ListaEntidades::atualizarUmibozu(float deltaT)
{
	int tamanhoLista = listaUmibozu.retornarNElementos();
	for (int i = 0; i < tamanhoLista; i++)
	{
		Umibozu* pAux;
		pAux = listaUmibozu.retornarElemento();
		if (pAux != NULL)
		{
			pAux->atualizar(deltaT);
			pAux->desenhar();
		}
		else
			cout << " Sem elementos na lista de entidades " << endl;
	}
}
*/