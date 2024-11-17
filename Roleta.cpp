#include "Roleta.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

Roleta::Roleta(int a, int b, int _idMaquina,string _nomeMaquina, float _probabilidadePremio, float _probabilidadeAvaria, float _temperatura)
:Maquina(_idMaquina, _nomeMaquina,  _probabilidadePremio,  _probabilidadeAvaria,  _temperatura,a,b){
	
}

Roleta::~Roleta()
{
	
}

void Roleta::Jogar(User* pessoa)
{
	srand(static_cast<unsigned int>(time(NULL)));
	int numero;
	char resp;
	cout << "BEM-VINDO/A A ROLETA" << endl;
	cout << "- - - - -  - - - -  - - - - - - -" << endl;
    cout << "|                               |" << endl;
    cout << "|  R   O   L   E   T   A  |" << endl;
    cout << "|                               |" << endl;
    cout << "- - - - -  - - - -  - - - - - - -" << endl;
	
	while(pessoa->GET_SALDO()>0)
	{
	cout << "Tem  " <<  pessoa->GET_SALDO() << " Euros disponiveis para jogar" << endl;
		cout << "Pressione 'J' para jogar ou 'S' para sair" << endl;
	   	cin >> resp;
	   	
	if(resp=='S' || resp=='s')
	   	{
	   		cout << "Obrigado por jogar no Casino Montecarlo. Restam-lhe "<<  pessoa->GET_SALDO() << " moedas" << "\nA sair..." << endl;
	   		this_thread::sleep_for(chrono::seconds(2));
	   		break;
		}

	
	int aleatorio = rand()%37;
	
	   	if(resp=='J' || resp=='j')
	   	{
	   		
	   	Aumentar_Temperatura();	
	   	  cout <<"BOA SORTE!"<< endl;
	   	  cout <<"....................ROLETA A GIRAR................" << endl;
	   	  this_thread::sleep_for(chrono::seconds(1));
		  pessoa->SET_SALDO(pessoa->GET_SALDO() - 50);
		  do{
			cout << "Digite um numero entre 0 e 36" << endl;
			cin >> numero;
		}while(numero <0 || numero>36);
		
	   	  cout << "Resultado:  " << aleatorio <<endl;
	   	  if(numero==aleatorio){
	   	  	cout<< "Parabens! Acertou no numero. Ganhou 20 moedas" <<endl;
	   	  	pessoa->SET_SALDO(pessoa->GET_SALDO() + 20);
	   	  	Aumentar_Probabilidade();
		  }
		  else {
		  	cout <<"Ups, tente outra vez" <<endl;
		  
		  	}	
		  	
		}
		
		
	}
	
	if(pessoa->GET_SALDO()<=0)
	{
		cout <<"\nTem neste momento 0 euros"<<endl;
		cout<<"Deseja recarregar o seu saldo? Pressione 'S' ou 'N' "<<endl;
		cin>>resp;
		
		if(resp=='s' || resp=='S')
		{
			float quantia,valor;
			cout << "Qual a quantia?  "<<endl;
			cin >> quantia;
			
			//caso seja inserido um float, passa pra int
			valor = static_cast<int>(round(quantia));
			pessoa->RecarregarSaldo(quantia);
			cout <<"------------A RECARREGAR-----------";
			this_thread::sleep_for(chrono::seconds(1));
			cout <<"-";
			this_thread::sleep_for(chrono::seconds(1));
			cout <<"-";
		 	this_thread::sleep_for(chrono::seconds(1));
			cout <<"-";
			this_thread::sleep_for(chrono::seconds(1));
			cout <<"-";
			
			
			cout<<"\nRecarregamento concluido! O seu saldo atual corresponde a "<< pessoa->GET_SALDO()<<" euros" <<endl;
			pessoa->SET_SALDO(pessoa->GET_SALDO());
			cout<<"Quer voltar a jogar?"<<endl;
			cin >> resp;
			if(resp=='s' || resp=='S')
			{
				Jogar(pessoa);
			}	
			
		}else if(resp=='N' || resp=='n')
		{
			cout << "Ok, vais sair do jogo brokie no money left" << endl;
			this_thread::sleep_for(chrono::seconds(2));
		}

	}
}

