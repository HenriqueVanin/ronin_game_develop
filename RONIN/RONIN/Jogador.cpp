#include "Jogador.h"
#include "Inimigo.h"

Jogador::Jogador(Texture* textura, Vector2u contQuadro, float mudaT, float aceleracao, float alturaPulo, Vector2f tamCorpo, Vector2f tamQuadro, Vector2f posicao, unsigned int nJogador):
	Personagem(textura, contQuadro, mudaT, aceleracao, alturaPulo),
	nPulos(0), alturaPulo (alturaPulo), nJogador(nJogador)
{ 
		this->quadro.setSize(tamQuadro);
		this->quadro.setOrigin(this->quadro.getSize().x / 2.0f, this->quadro.getSize().y / 2.0f + 20.0f);
		this->quadro.setPosition(posicao);

		this->corpo.setSize(tamCorpo);
		this->corpo.setOrigin(this->corpo.getSize().x / 2.0f, this->corpo.getSize().y / 2.0f);
		this->corpo.setPosition(posicao);

		this->ataque.setSize(Vector2f(tamCorpo.x * 3.0f, tamCorpo.y * 1.5f));
		this->ataque.setOrigin(this->corpo.getOrigin());
		this->ataque.setPosition(this->corpo.getPosition());
		//this->ataque.setFillColor(Color(255, 255, 0, 150));
}   

Jogador::Jogador():
	 nPulos(0), alturaPulo(0), nJogador(NULL)
{
}

Jogador::~Jogador()
{

}

void Jogador::atualizar(float deltaT)
{
	if (!morto)
	{
		movimentar(deltaT);
		// Atualiza o lado que o jogador está virado
		virarFace(deltaT);
		
	}
	else
	{
		morrer(deltaT);
	}
	if (!animacaoMorto)
	{
		atualizarAnimacao(deltaT);
		atualizarCorpoAtaque(deltaT);
	}
	corpo.move(velocidade * deltaT);
	desenhar();
}

void Jogador::danificar(float deltaT)
{
	if (!morto)
	{
		setarLinha(4);
		temporizador = tempo.getElapsedTime().asMilliseconds();
		tempo.restart();
		if (temporizador > 50)
		{
			if (pontuacaoJogador.retornarPontuacao() == 0)
				morto = true;
			else
			{				
				pontuacaoJogador.zerarPontuacao();
			}
		}		
	}
}

void Jogador::morrer(float deltaT)
{
	if (!animacaoMorto)
	{
		setarLinha(5);	
	}
}

void Jogador::setarPodePular(bool p)
{
	podePular = p;
}

int Jogador::retornarPontuacao()
{
	return pontuacaoJogador.retornarPontuacao();
}

void Jogador::virarFace(float deltaT)
{
	//Verificar se está parado e para qual lado está virado
	if (velocidade.x == 0.0f && velocidade.y > 0.0f)
	{
		setarLinha(0);
	}
	else if (velocidade.x != 0.0f && velocidade.y > 0.0f)
	{
		setarLinha(1);

		if (velocidade.x > 0.0f)
			setarFace(true);
		else
			setarFace(false);
	}
}

void Jogador::movimentar(float deltaT)
{
	//Para o personagem ( em caso de 0.0f : para instantaneamente )
	velocidade.x *= 0.0f;

	if (nJogador == 1)
	{
		//Movimenta personagem
		if (Keyboard::isKeyPressed(sf::Keyboard::A))
			velocidade.x -= aceleracao;
		if (Keyboard::isKeyPressed(sf::Keyboard::D))
			velocidade.x += aceleracao;
	}

	if (nJogador == 2)
	{
		if (Keyboard::isKeyPressed(sf::Keyboard::Left))
			velocidade.x -= aceleracao;
		if (Keyboard::isKeyPressed(sf::Keyboard::Right))
			velocidade.x += aceleracao;
	}

	pular(deltaT);
	aplicarGravidade(deltaT);
}

void Jogador::pular(float deltaT)
{
	//Algoritmo de Pulo
	if (nJogador == 1 && Keyboard::isKeyPressed(sf::Keyboard::Space) && podePular)
	{
		setarLinha(3);
		podePular = false;

		// Cálculo : Raíz quadrada ( 2.0f * gravidade * alturaPulo);
		velocidade.y = -sqrtf(2.0f * 200.0f * alturaPulo);
	}

	if (nJogador == 2 && Keyboard::isKeyPressed(sf::Keyboard::Up) && podePular)
	{
		setarLinha(3);
		podePular = false;

		velocidade.y = -sqrtf(2.0f * 200.0f * alturaPulo);
	}
}

void Jogador::atacar(float deltaT, Vector2f direcao, Inimigo* inimigo)
{
	//temporizador = tempo.getElapsedTime().asMilliseconds();
	//if (temporizador > 100)
	//{
	if (!morto)
	{
		setarLinha(2);
		if (this->retornarColisorAtaque().checarColisao(inimigo->retornarColisorCorpo(), direcao, 1.0f, false))
		{
			inimigo->setarMorto(true);
			inimigo->emColisao(direcao);
			pontuacaoJogador.incrementaPontuacao();
		}
		tempo.restart();
	}
	//}	
}

