#pragma once
#include <string>

template <class TL>
class Lista
{
private:
	template <class TE>
	class Elemento
	{
	private:
		Elemento<TE>* pProx;

		TE* pEl;

	public:
		Elemento(TE* novoElemento = NULL) : pProx(NULL) { pEl = novoElemento; }
		~Elemento() {}

		friend class Lista;
	};

	Elemento<TL>* pPrim;
	Elemento<TL>* pIterador;
	Elemento<TL>* pAtual;

	int nElementos;

public:
	    Lista(): pPrim(NULL), pAtual(NULL), pIterador(NULL), nElementos(0) {}
		~Lista() {}

		void incluirElemento(Elemento<TL>* pElemento)
		{ 
			if (NULL != pElemento)
			{
				if (NULL == pPrim)
				{
					pPrim = pElemento;
					pPrim->pProx = NULL;
					pAtual = pPrim;
					pIterador = pPrim;
				}
				else
				{
					pElemento->pProx = NULL;
					pAtual->pProx = pElemento;
					pAtual = pAtual->pProx;
				}
				nElementos++;
				
			}
		}

		template<class TE>
		void incluirInfo(TE* pNovo)
		{
			if (NULL != pNovo)
			{
				Elemento<TL>* novoElemento  = new Elemento<TL>(pNovo);
				novoElemento->pEl = pNovo;
				incluirElemento(novoElemento);
			}
		}

		void limpaLista() 
		{
			Elemento<TL>* paux1;
			Elemento<TL>* paux2;
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
		}

		TL* retornarElemento()
		{
			if (pPrim)
			{
				Elemento<TL>* pAux;

				pAux = pIterador;
				if(pAux)
				{
					if (pAux == pPrim)
					{
						pIterador = pAux->pProx;
						return pAux->pEl;
					}
					else
					{
						pIterador = pAux->pProx;
						if (pAux->pProx == NULL)
							pIterador = pPrim;
						return pAux->pEl;
					}
				}
			}
			return NULL;
		}
		int retornarNElementos() { return nElementos; }
};