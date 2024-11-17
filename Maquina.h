#ifndef MAQUINA_H
#define MAQUINA_H
using namespace std;
#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <vector>

#include "User.h"


enum ESTADO {
        OFF,
        ON,
        AVARIADA
    };
    
enum TIPO {
	ROLETA,
	SLOTS,
	BLACKJACK,
	CRAPS,
};    

    
class User;
class Casino;

class Maquina
{
	private:
	int ID_MAQUINA;
	string NOME_MAQUINA;
	float ProbabilidadePREMIO;
	float ProbabilidadeAVARIA;
	float TEMPERATURA;
	int x,y;
	
	Casino *Ptr_casino;//para a maquina saber qual é o casino
	
	public:
		Maquina(int _idMaquina,string _nomeMaquina, float _probabilidadePremio, float _probabilidadeAvaria, float _temperatura,int x,int y);
		virtual ~Maquina();
		void Show();
		int GET_ID_MAQUINA(){ return ID_MAQUINA;}
		float GetProbPremio() {return ProbabilidadePREMIO;}
		float GET_PROBABILIDADE_AVARIA(){return ProbabilidadeAVARIA;}
		float GET_TEMPERATURA(){return TEMPERATURA;}
		virtual void SET_TEMPERATURA(int temperatura){TEMPERATURA=temperatura;}
		string GET_NOME_MAQUINA(){return NOME_MAQUINA;}
		int GetX(){ return x; };
        int GetY(){return y; };
		vector<int> GET_POSICAO_MAQUINA(){ return {x,y};}
		void Aumentar_Probabilidade(){ProbabilidadePREMIO+=10;}
		void Aumentar_Temperatura(){TEMPERATURA+=10;}
		string GET_TIPO(){return NOME_MAQUINA;}
		void Run();
	
		
		
		void Ligar(){estado = ON;};
		void Desligar(){estado = OFF;};
		ESTADO estado;
	    virtual void Jogar(User* pessoa);
	    int Spin(){ return rand()%6 + 1;};
	    bool VerificarProbabilidade();
        bool VerificarAvaria();
		void Classic_Slots();
		void Roleta();
		 
		
	//12+12+16+16= 56
};

	
#endif
