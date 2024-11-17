#include "Maquina.h"
#include "Casino.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

Maquina::Maquina(int _idMaquina,string _nomeMaquina, float _probabilidadePremio, float _probabilidadeAvaria, float _temperatura,int x,int y)
{
	ID_MAQUINA = _idMaquina;
	NOME_MAQUINA = _nomeMaquina;	
	ProbabilidadePREMIO = _probabilidadePremio;
	ProbabilidadeAVARIA = _probabilidadeAvaria ;
	TEMPERATURA = _temperatura ;
	estado = ON;
	this->x=x;
	this->y=y;
	//cout << "Maquina" << NOME_MAQUINA << " construinda em " << x << "," << y << "\n";
}

Maquina::~Maquina()
{
	/*	for(list<User *>::iterator it = LUS.begin(); it != LUS.end(); ++it)
        delete (*it);*/
	
}

void Maquina::Show()
{
	cout << "\nMAQUINA ID: " << ID_MAQUINA << " NOME: " << NOME_MAQUINA << " PROBABILIDADE PREMIO: " << ProbabilidadePREMIO<< " PROBABILIDADE AVARIA:" << ProbabilidadeAVARIA << " TEMPERATURA: " << TEMPERATURA << " ESTADO: " << estado<< endl;
	cout << " X:  " << x << " Y: "<<y;
}

void Maquina::Jogar(User *user)
{
    cout << "--->Que comece os jogos!<----" << endl;
}

bool Maquina::VerificarProbabilidade()
{
    return ProbabilidadePREMIO > 60;
}

bool Maquina::VerificarAvaria()
{
    return ProbabilidadeAVARIA > 20;
}

void Maquina::Run()
{
    if (VerificarProbabilidade())
    {
        cout << "Maquina com alta probabilidade de  premios---> AVISAR O GESTOR ------------" << endl;
        Ptr_casino->AltaProbabilidadePremio(this);
    }
    if(VerificarAvaria())
    {
        cout << "Maquina com alta probabilidade de avaria---> AVISAR O GESTOR ------------" << endl;
        Ptr_casino->AltaAvaria(this);
    }

}


