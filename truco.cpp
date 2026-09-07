#include <iostream>
#include <windows.h>

#include <cstdlib> // srand
#include <ctime>   // time

#include "lib/baralho.h"
#include "lib/carta.h"
#include "lib/jogo.h"

int main()
{
    // garante que os símbolos dos naipes apareçam corretamente no console do Windows
    SetConsoleOutputCP(CP_UTF8);

    // semente aleatória para as cartas serem diferentes a cada execução
    srand(static_cast<unsigned>(time(nullptr)));

    Jogo *jogo = new Jogo;

    jogo->baralho = criarBaralho();
    jogo->jogadores = setarJogadores();

    distribuirCartas(jogo->baralho, jogo->jogadores.data(),
                     static_cast<int>(jogo->jogadores.size()));

    jogo->coringa = sortearCoringa(jogo->baralho);

    // mostra as mãos para conferir que nenhuma carta se repete
    for (int i = 0; i < 2; i++)
    {
        std::cout << "Jogador " << i + 1 << ": ";
        for (int j = 0; j < 3; j++)
        {
            std::cout << mostrarCarta(jogo->jogadores[i].mao[j]) << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << "Carta coringa: " << mostrarCarta(jogo->coringa) << std::endl;
    std::cout << "Cartas restantes no baralho: " << jogo->baralho.quantidade << std::endl;

    delete jogo;

    return 0;
}
