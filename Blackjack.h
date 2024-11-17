#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Maquina.h"
#include <vector>
class Blackjack : public Maquina
 {
public:
    Blackjack(int _idMaquina, std::string _nomeMaquina, float _probabilidadePremio,float _probabilidadeAvaria, float _temperatura, int x, int y);        
    virtual ~Blackjack();
    void Jogar() ;
    int ObterValorCarta(int carta);
};

#endif // BLACKJACK_H

