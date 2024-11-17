#include "Blackjack.h"

Blackjack::Blackjack(int _idMaquina, std::string _nomeMaquina, float _probabilidadePremio,
                     float _probabilidadeAvaria, float _temperatura, int x, int y)
    : Maquina(_idMaquina, _nomeMaquina, _probabilidadePremio, _probabilidadeAvaria, _temperatura, y, x) {
    
}
Blackjack::~Blackjack() 
{
    
}


// Função para iniciar o jogo de Blackjack
void Blackjack::Jogar() 
{
    // Inicia o rand a NULL para ser valores diferentes
    srand(static_cast<unsigned int>(time(nullptr)));

    // Saldo inicial do jogador
    int saldo = 100;
    char escolha;

    cout << "Bem-vindo ao Blackjack!" << endl;

    // Loop principal do jogo
    while (saldo > 0) {
        cout << "Você tem " << saldo << " Euros disponíveis para jogar." << endl;
        cout << "Pressione 'J' para jogar ou 'X' para sair: ";
        cin >> escolha;

        // Verifica se o jogador deseja sair
        if (escolha == 'X' || escolha == 'x') {
            cout << "Obrigado por jogar no Casino. Restam-lhe " << saldo << " Euros. Até mais!" << endl;
            break;
        }

        // Verifica se o jogador deseja jogar
        if (escolha == 'J' || escolha == 'j') {
            cout << "BOA SORTE!" << endl;
            saldo -= 10;  // Aposta inicial

            // Gera duas cartas iniciais
            int carta1 = ObterValorCarta(rand() % 11 + 1);
            int carta2 = ObterValorCarta(rand() % 11 + 1);

            cout << "Carta 1: " << carta1 << endl;
            cout << "Carta 2: " << carta2 << endl;

            int total = carta1 + carta2;

            cout << "Total: " << total << endl;

            char continuar;
            do {
                // Pergunta se o jogador quer mais cartas
                cout << "Deseja pedir mais cartas? (S/N): ";
                cin >> continuar;

                if (continuar == 'S' || continuar == 's') {
                    // Gera e exibe uma nova carta
                    int novaCarta = ObterValorCarta(rand() % 11 + 1);
                    total += novaCarta;
                    cout << "Nova Carta: " << novaCarta << endl;
                    cout << "Total: " << total << endl;
                }
            } while ((continuar == 'S' || continuar == 's') && total <= 21);

            cout << "O jogo acabou!" << endl;

            // Verifica o resultado do jogo
            if (total > 21) {
                cout << "Você estourou! Você perdeu. Ficou com " << saldo << " Euros!" << endl;
            } else {
                cout << "Você ganhou. Tinha " << saldo << " Euros!" << endl;
                saldo += 20;  // Ganha o dobro da aposta
            }
        }
    }
}

// Função para obter o valor de uma carta no Blackjack
int Blackjack::ObterValorCarta(int carta) {
    // No Blackjack, as cartas de 2 a 10 têm seu valor nominal,
    // as figuras (Valete, Rainha, Rei) valem 10 e o Ás pode valer 1 ou 11, dependendo da situação.
    if (carta == 1) {
        cout << "Você obteve um Ás! Deseja que ele valha 1 ou 11? ";
        int valorAs;
        cin >> valorAs;
        return valorAs;
    } else if (carta >= 11 && carta <= 13) {
        return 10;  // Figuras valem 10
    } else {
        return carta;
    }
}

