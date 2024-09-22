#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
};

void Jogo::atualizar()
{
}

void Jogo::rodar()
{
	bool aberto = true;
	menu.telaInicial();
	while (aberto)
	{
		int escolha;
		escolha = menu.executar();
		switch (escolha)
		{
		case 1:
		{
			Fase1* fase1 = new Fase1();
			fase1->executar();
			if (fase1->retornarVenceu())
			{
				Fase2* fase2 = new Fase2();
				fase2->executar();
				delete (fase2);
			}
			delete (fase1);
			break;
		}
		case 2:
		{
			Fase1* fase1 = new Fase1();
			fase1->executar();
			delete (fase1);
			break;
		}
		case 3:
		{
			Fase2* fase2 = new Fase2();
			fase2->executar();
			delete (fase2);
			break;
		}
		case 4:
		{
			aberto = false;
			break;
		}
		default:
			break;
		}
	}
	TELA->fecharJanela();
}
