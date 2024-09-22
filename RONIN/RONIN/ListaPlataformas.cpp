#include "ListaPlataformas.h"
#include "Personagem.h"

ListaPlataformas::ListaPlataformas():
	plataformas()
{
	// Inicialização das Plataformas
	this->plataformas.push_back(Plataforma(NULL, Vector2f(12000.0f, 1.0f), Vector2f(500.0f, 1100.0f)));
	this->plataformas.push_back(Plataforma(NULL, Vector2f(6000.0f, 1.0f), Vector2f(500.0f, 1.0f)));
	this->plataformas.push_back(Plataforma(NULL, Vector2f(1.0f, 1280.0f), Vector2f(1200.0f, 1100.0f)));
	this->plataformas.push_back(Plataforma(NULL, Vector2f(1.0f, 1280.0f), Vector2f(5100.0f, 1100.0f)));
}

ListaPlataformas::~ListaPlataformas()
{
	limparLista();
}

void ListaPlataformas::incluirPlataforma(Plataforma pP)
{
	if (!&pP)
	{
		plataformas.push_back(pP);
	}
}

Plataforma* ListaPlataformas::retornarListaPlataformas()
{
	return NULL;
}

void ListaPlataformas::limparLista()
{
	plataformas.erase(plataformas.begin(),plataformas.end());
}

void ListaPlataformas::checarColisoesPlataformas(Personagem* pPersonagem, Vector2f direcao)
{
	for (Plataforma plataforma : plataformas)
	{
		if (plataforma.retornarColisor().checarColisao(pPersonagem->retornarColisorCorpo(), direcao, 1.0f, true))
		{
			pPersonagem->emColisao(direcao);
		}
	}
}
