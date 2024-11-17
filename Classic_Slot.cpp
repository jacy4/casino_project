#include "Classic_Slots.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

Classic_Slots::Classic_Slots(int a, int b, int _idMaquina,string _nomeMaquina, float _probabilidadePremio, float _probabilidadeAvaria, float _temperatura)
:Maquina(_idMaquina, _nomeMaquina,  _probabilidadePremio,  _probabilidadeAvaria,  _temperatura,a,b)
{
	
}

Classic_Slots::~Classic_Slots()
{
}


void Classic_Slots::Jogar(User* pessoa)
{
	  srand(static_cast<unsigned int>(time(NULL))); //srand(time(NULL)) em c
	  char resp;
	  pessoa->GET_SALDO();
	cout << "BEM-VINDO/A A CLASSIC SLOTS" << endl;
	   
	   while(pessoa->GET_SALDO()>0)
	   {
	   	cout << "Tem  " << pessoa->GET_SALDO() << " Euros disponiveis para jogar" << endl;
	   	cout << "Pressione 'J' para jogar ou 'S' para sair" << endl;
	   	cin >> resp;
	   	
	   
	   	if(resp=='S' || resp=='s')
	   	{
	   		cout << "Obrigado por jogar no Casino Montecarlo. Restam-lhe "<< pessoa->GET_SALDO() << " moedas" << "\nA sair..." << endl;
	   		this_thread::sleep_for(chrono::seconds(2));
	   		break;
		}
	   	
	   	int saida1 = Spin();
	   	int saida2 = Spin();
	   	int saida3 = Spin();
	   	
	   	
	   	if(resp=='J' || resp=='j')
	   	{
	   	  cout <<"BOA SORTE!"<< endl;
		   pessoa->SET_SALDO(pessoa->GET_SALDO() - 10);	 
	   	  cout << "Resultados:  " << saida1 << " " <<saida2 << " " << saida3 << " " <<endl;
	   	  if(saida1==saida2 && saida2==saida3){
	   	  	cout<< "Parabens! Tres numeros iguais. Ganhou 10 moedas" <<endl;
	   	  	pessoa->SET_SALDO(pessoa->GET_SALDO() + 20);
	   	  	Aumentar_Probabilidade();
	   	  	//ProbabilidadePREMIO+=10;
	   	  	//TEMPERATURA+=1;
		  }
		  else {
		  	cout <<"Ups, tente outra vez" <<endl;
		  
		  	}
		}
	}
	
		if(pessoa->GET_SALDO()<=0){
			cout <<"Esta sem moedas! Jogo a terminar..." <<endl;
			this_thread::sleep_for(chrono::seconds(2)); //sleep(3) em c
		}	  
}
	
