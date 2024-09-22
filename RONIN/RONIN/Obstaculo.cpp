#include "Obstaculo.h"
#include "Jogador.h"

Obstaculo::Obstaculo(Texture* textura, Vector2u contQuadro, float mudaT):
	Entidade(textura, contQuadro, mudaT)
{
}

Obstaculo::Obstaculo()
{
}

Obstaculo::~Obstaculo()
{
}

bool Obstaculo::retornarColisao(Jogador* jogador, Vector2f direcao, float empurro, bool repulsao)
{
	if (jogador->retornarColisorCorpo().checarColisao(this->retornarColisorCorpo(), direcao, empurro, repulsao))
	{
		jogador->emColisao(direcao);
		if(repulsao)
			jogador->setarPodePular(true);
		return true;
	}
	return false;
}
