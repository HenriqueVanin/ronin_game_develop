#pragma once

#include "Umibozu.h"
#include "Akaname.h"

class ListaEntidades
{
private:
	//Lista <Akaname*> listaAkaname;
	//Lista <Umibozu*> listaUmibozu;

	vector<Umibozu*> listaUmibozu;
	vector<Umibozu*>::size_type tamanhoListaUmibozu;
	
	vector<Akaname*> listaAkaname;
	vector<Akaname*>::size_type tamanhoListaAkaname;

public:
	ListaEntidades();
	~ListaEntidades();
	
	void incluirUmibozu(Umibozu* pU);
	void incluirAkaname(Akaname* pA);
	void limparLista();

	void atualizarListaUmibozu(float deltaT);
	void atualizarListaAkaname(float deltaT);
};

