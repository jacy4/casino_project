#ifndef CASINO_H
#define CASINO_H

#include <string>
#include <list>
#include <iostream>
#include <cmath>

using namespace std;
#include "User.h"
#include "Maquina.h"
#include "Blackjack.h"
#include "Roleta.h"



class Casino
{
	string NOME;
	list<Maquina *> LM; 
    list<User *> LUS;
    list<Maquina *> L_Alta_Pb;
    list<Maquina *> L_Avaria;
    int hora_inicio;
    int hora_fim;
    int max_jog;
	public:
		Casino(string nome);
		~Casino();	
		bool Add_USER(User *u);
		bool Add_MAQUINA(Maquina *m);
		void Show();
		void pessoas_entrando_aleatorio();
		list<User *> Jogadores_Mais_Frequentes();
        list<User *> Jogadores_Mais_Ganhos();
        list<Maquina*>* Listar_Tipo(string Tipo, ostream &f);
        void Listar(float X, ostream &f = cout);
		void Desligar(int id_maq);
		Maquina *PesquisarMaquina(int id_maq);	
		void carregarDadosDeXML(const string& caminhoDoArquivo);
		ESTADO Get_Estado(int id_maq);
		int MemoriaTotal();
		void Listar_Probabilidade_Premio();
		void SubirProbabilidadeVizinhas(Maquina *M_ganhou, float R,list<Maquina *> &lmvizinhas);
		list<Maquina*> MaquinasVizinhas(int x, int y);
		void AltaProbabilidadePremio(Maquina *M);
        void AltaAvaria(Maquina *M);
		void Relatorio(string fich_xml);
		void Run();

};
	
#endif
