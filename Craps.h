#ifndef CRAPS_H
#define CRAPS_H

#include "Maquina.h"
#include <cstdlib>   // Para a fun��o sleep
#include <ctime>     // Para a fun��o time

#include <Windows.h>
class Craps: public Maquina//func��o filha
{
	public:
		Craps(int _idMaquina,string _nomeMaquina, float _probabilidadePremio, float _probabilidadeAvaria, float _temperatura,int x, int y);
		virtual ~Craps();
		void Jogar(User* pessoa);
	protected:
};

#endif
