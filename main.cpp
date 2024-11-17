#include <iostream>
#include <string>
#include <list>
#include <string>
#include <fstream>

using namespace std;
#include "Casino.h"
#include "Maquina.h"
#include "User.h"
#include "Classic_Slots.h"
#include "Craps.h"
#include "Roleta.h"

int Id_player_global=100;//defeni o id começar em 100 para atribuir automaticamente

int main()
{
	
	Casino MC("Casino Monte Carlo");
	//MC.Show();
	//MC.carregarDadosDeXML("pessoas.txt");
	//User *user1 = new User("Jacinta",19,"viseu");
	//MC.Add_USER(user1);
	

	User *user2 = new User("Jacinta",19,"viseu", 1, 10.0, 0, 100.0);
	MC.Add_USER(user2);
	
	Maquina *X1 = new Classic_Slots(1,2,1,"Classic_Slots",10.0,0,30.0);
	MC.Add_MAQUINA(X1);
	//X1->Show();
	//X1->Jogar(user2);
	

	//MC.PesquisarMaquina(2);
	//X->Jogar(user2);
	
	//MC.pessoas_entrando_aleatorio();
	
	
	Maquina *X2 = new Roleta(1,1,2,"Roleta",0.0, 0.0, 30.0);
	MC.Add_MAQUINA(X2);
	X2->Show();
//	X2->Jogar(user2);


	//MC.Relatorio("aize.xml");
	
	Maquina *X3 = new Craps(3,"Craps",0.0,0.0, 30.0, 1,3);
	MC.Add_MAQUINA(X3);
	X3->Show();
	X3->Jogar(user2);
	
	
	
	//user->Show();
	//MC.Listar_Probabilidade_Premio();
	
/*	MC.Listar_Tipo("Roleta", std::cout);
 	MC.Listar_Tipo("Classic_Slots", std::cout);
	MC.Listar_Tipo("Craps", std::cout);*/
	
	
	//X1->Jogar(user2);
	
	Maquina *X4 = new Craps(4,"Craps",0.0,0.0, 30.0, 2,5);
	MC.Add_MAQUINA(X4);
	//X4->Show();	
	
	
	//MC.Show();
	
	Maquina *X5 = new Craps(5,"Craps",0.0,0.0, 30.0, 5,7);
	MC.Add_MAQUINA(X5);
	//X5->Show();	
	//X5->Jogar(user2);

	/*list<Maquina *> lmvizinhas;
	MC.SubirProbabilidadeVizinhas(X2,3,lmvizinhas);
	BEMMMMMMMMMMMMMMM*/
	
	
	//maquina1->Desligar();
	//MC.Show();
}
	
	
