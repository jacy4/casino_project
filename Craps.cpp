#include "Craps.h"
#include <cctype>//para converter para maiusculas

#include <chrono>
#include <thread>
#include <cstdlib>   // Para a função sleep
#include <ctime>     // Para a função time

#include <Windows.h>
Craps::Craps(int _idMaquina,string _nomeMaquina, float _probabilidadePremio, float _probabilidadeAvaria, float _temperatura,int x, int y)
   :Maquina( _idMaquina,_nomeMaquina, _probabilidadePremio,  _probabilidadeAvaria,_temperatura,x, y)
{
   	
}

Craps::~Craps()
{
	
}

void Craps::Jogar(User* pessoa)
{
	system("cls");//VAI LIMPAR O ECRA
	Maquina::Jogar(pessoa);//primeiro entra na classe pai
	
	cout << "- - - - -  - - - -  - - - - - - -" << endl;
    cout << "|                               |" << endl;
    cout << "|   C     R     A     P     S   |" << endl;
    cout << "|                               |" << endl;
    cout << "- - - - -  - - - -  - - - - - - -" << endl;
	
	cout <<endl<< "- - - Inserir 20 coins e GANHE O 100% MAIS!!! - - -" << endl<<endl;
	
	
	//--------Player informaçoes 
	
	cout <<"->PLAYER : "<< pessoa->GET_NOME()<<"  ->ID_JOGADOR :"<<pessoa->GET_IDPLAYER()<<endl;
	cout <<"->SALDO : "<<pessoa->GET_SALDO()<<" $"<<endl;
	
		//------JOGO -----
	char opcao;//o caracter da opca
do 
	{
	cout <<endl<<" -->Pressione 'J' para jogar !<--" << endl;
	cin>>opcao;//guarda o caracter
    opcao=toupper(opcao);//converte para maiucula caso nao esteja
    
    while(opcao !='J')//Cilco apra evitar digitar caracteres errados
    {
    	cout<<"Opcao invalida\n Pressione 'J' para jogar "<<endl;
    	cin>>opcao;
    	opcao=toupper(opcao);
	
	}
	if(opcao=='J')
  	{
  		int saldo =pessoa->GET_SALDO();
  		saldo=saldo-20;
  		pessoa->SET_SALDO(saldo);//atualiza o saldo;
  		cout<<" -20 coin \nSALDO ATUAL "<<saldo<<endl;
  		
  		cout<<"Advinhe qual será ?!"<<endl;
  		cout<<"->3 Short Craps ( >= 3)"<<endl;
  		cout<<"->6 Medium Craps ( >= 6)"<<endl;
  		cout<<"->9 Long Craps ( >= 9)"<<endl;
  		int op;
  		cout<<"Palpite-> "<<endl;
  		cin>>op;
  		while(op!=3&&op!=6&&op!=9)//Cilco apra evitar digitar caracteres errados
        {
    	cout<<"Opcao invalida\n Palpite-> ";
    	cin>>op;
	     }
  		cout<<"PALPITE FEITO !!! QUE ROLEM OS DADOS";
  		//----------------------gerador dos dados---------------------------
	srand(static_cast<unsigned int>(time(nullptr)));//gera a semente de numeros para nao serem os mesmos
	
	int dado1=rand()%6+1;//numeros de 1 a 6
	int dado2=rand()%6+1;
	//vamos verificar se sao mesmo entre estes numeros
	while( (dado1>6||dado1<1)	||	(dado2>6||dado2<1) )//verificação para nao ultrapassar o escopo
   {
   	    dado2=rand()%6+1;
		dado1=rand()%6+1;//volta a fazer
   }
   // Contagem regressiva
    cout << "\nObtendo valores em... \n";
    for (int i = 3; i > 0; i--) 
	{
        cout<<i <<endl;
        Sleep(1000);
    }

   cout << "->Dado 1: " << dado1 << endl;
   cout << "->Dado 2: " << dado2 << endl;
   int resultado_dados=dado1+dado2;
   cout << "  ->RESULTADO: " << resultado_dados << endl;
   
    switch (op) 
	 {
        case 3:
        	if(resultado_dados>=op)
        	{
        		cout << "---PARABENS GANHAS-TE 15 COINS----" << endl;
        		saldo=saldo+15;
        		pessoa->SET_SALDO(saldo);
			}else{
				cout << "---PERDESTE :( MAIS SORTE PARA A POXIMA VEZ !!--" << endl;
			}
            break;
        case 6:
            if(resultado_dados>=op)
        	{
        		cout << "---PARABENS GANHAS-TE 35 COINS----" << endl;
        		saldo=saldo+35;
        		pessoa->SET_SALDO(saldo);
			}else{
				cout << "---PERDESTE :( MAIS SORTE PARA A POXIMA VEZ !!--" << endl;
			}
            break;
        case 9:
            if(resultado_dados>=op)
        	{
        		cout << "---PARABENS GANHAS-TE 100 COINS----" << endl;
        		saldo=saldo+100;
        		pessoa->SET_SALDO(saldo);
			}else{
				cout << "---PERDESTE :( MAIS SORTE PARA A POXIMA VEZ !!--" << endl;
			}
            break;
	    default:
            cout << "algo se passou" <<endl;
    }

	

	}
} while (opcao=='J');
    
  	
	
}
