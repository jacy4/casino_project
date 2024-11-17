#ifndef CRAPS_H
#define CRAPS_H

#include "Maquina.h"
#include <cstdlib>   // Para a função sleep
#include <ctime>     // Para a função time

#include <Windows.h>
class Craps: public Maquina//funcção filha
{
	public:
		Craps(int _idMaquina,string _nomeMaquina, float _probabilidadePremio, float _probabilidadeAvaria, float _temperatura,int x, int y);
		virtual ~Craps();
		void Jogar(User* pessoa);
	protected:
};

#endif
