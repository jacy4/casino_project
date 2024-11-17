#include "User.h"
#include <iostream>

extern int Id_player_global;//é uma varivel extrena que ta no main

User::User(string _nome,int _idade,string local,int id_pessoa,float temp,int Npremios,int saldo)
{
	
	NJOGADOR = Id_player_global;
	NOME_USER =_nome;
	IDADE = _idade;
	LOCAL=local;
	ID_PESSOA=id_pessoa;
	SALDO=saldo;
	tempoJogando=temp;
	
	//incremeta o id jogador para o proximo
	Id_player_global+=1;	
}

void User::Show()
{
	
	cout << "NJOGADOR  " << NJOGADOR << "| NOME: " << NOME_USER << "| IDADE :" << IDADE <<  "| SALDO : " << SALDO<<endl;
}
