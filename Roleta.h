#ifndef ROLETA_H
#define ROLETA_H

#include <string>
#include <cstdlib>
#include <list>
#include "Maquina.h"


class Roleta : public Maquina
{
	
    public:
        Roleta(int a, int b, int _idMaquina,string _nomeMaquina, 
		float _probabilidadePremio, float _probabilidadeAvaria, 
		float _temperatura);
        virtual ~Roleta();
		void Jogar(User* pessoa);

    protected:

    private:
};

#endif // ROLETA_H
