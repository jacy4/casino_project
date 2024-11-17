#ifndef CLASSIC_SLOTS_H
#define CLASSIC_SLOTS_H


#include <string>
#include <cstdlib>
#include <list>

#include "Maquina.h"

class Classic_Slots : public Maquina
{
	public:
		Classic_Slots(int a, int b, int _idMaquina,string _nomeMaquina, float _probabilidadePremio, float _probabilidadeAvaria, float _temperatura);
		virtual ~Classic_Slots();
		 void Jogar(User* pessoa);

	protected:
};

#endif
