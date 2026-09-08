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

    // mãos vazias e pontos zerados no início da partida
    jogo->jogadores = setarJogadores();
    inicializarMonte(jogo->monte);

    // partida completa até alguém alcançar 12 pontos
    int vencedor = jogarPartida(*jogo);

    std::cout << "\n############ FIM DE JOGO ############" << std::endl;
    std::cout << "Jogador " << vencedor << " venceu a partida!" << std::endl;

    limparMonte(jogo->monte);
    delete jogo;

    return 0;
}
