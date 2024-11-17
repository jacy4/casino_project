#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

#include <cmath>
#include <iostream>
#include <string>
#include <list>


class User
{
	int NJOGADOR,ID_PESSOA;
	string NOME_USER,LOCAL;
	int IDADE;
	int Npremios;
	float tempoJogando;	
	int SALDO;
	public:
		User(string _nome,int _idade,string local,int id_pessoa,float temp=0,int Npremios=0,int saldo=0);
		//void Jogar();
		void Show();
		/* *Virtual* para tds as classes terem acesso*/
        virtual int GetPremios(){return Npremios;}
        string GET_LOCAL(){return LOCAL;}
        int GET_IDADE(){ return IDADE;}
        int GET_SALDO(){ return SALDO;}
        virtual string GET_NOME(){ return NOME_USER;}
        virtual int GET_IDPLAYER(){ return NJOGADOR;}
        virtual float getTempoJogado(){ return tempoJogando;}
         // void Run();
        
        void aumentarTempoJogado(float tempo){tempoJogando += tempo;}
        void aumentarPremiosGanhos(int num_premios){Npremios += num_premios;}
        virtual void SET_SALDO(int saldo){SALDO=saldo;}
        void teste(){cout<<"teste";};
        
        
        void RecarregarSaldo(int valor){
        	SALDO+=valor;
		}
        
      
	
};

#endif
