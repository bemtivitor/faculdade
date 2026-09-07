#include "jogo.h"

#include <iostream>

// Ordem de força dos valores (índices em VALORES):
// 4=0, 5=1, 6=2, 7=3, 8=4, 9=5, Q=6, J=7, K=8, A=9, 2=10, 3=11

int definirForcaCarta(Carta carta, Carta coringa)
{
    int valorCartaMaisForte = (coringa.valor + 1) % 12;
    if (carta.valor == valorCartaMaisForte)
    {
        return 12;
    }
    else
    {
        return carta.valor;
    }
}

int compararCartas(Carta carta1, Carta carta2, Carta coringa)
{
    // descartei o caso das cartas terem naipes iguais, no criar baralho não pode ter
    int forcaCarta1 = definirForcaCarta(carta1, coringa);
    int forcaCarta2 = definirForcaCarta(carta2, coringa);

    if (forcaCarta1 != forcaCarta2)
    {
        return forcaCarta1 > forcaCarta2 ? 1 : 2;
    }
    else if (carta1.naipe != carta2.naipe)
    {
        return carta1.naipe > carta2.naipe ? 1 : 2;
    }
}

// Gui: Acho que essa função não vai ser usada, não acho bom as rodadas serem
// presentadas por números ou algo do tipo, acho melhor criar algo dinâmico,
// assim poderemos aumentar o número de rodadas e essas coisas.
int verificarVencedorMao(int rodada1, int rodada2, int rodada3)
{
    int vitoriasJogador1 = 0;
    int vitoriasJogador2 = 0;

    if (rodada1 == 1)
        vitoriasJogador1++;
    else if (rodada1 == 2)
        vitoriasJogador2++;

    if (rodada2 == 1)
        vitoriasJogador1++;
    else if (rodada2 == 2)
        vitoriasJogador2++;

    if (rodada3 == 1)
        vitoriasJogador1++;
    else if (rodada3 == 2)
        vitoriasJogador2++;

    if (vitoriasJogador1 > vitoriasJogador2)
        return 1; // Jogador 1 venceu a mão
    else if (vitoriasJogador2 > vitoriasJogador1)
        return 2; // Jogador 2 venceu a mão
    if (rodada3 == 1)
        vitoriasJogador1++;
    else if (rodada3 == 2)
        vitoriasJogador2++;

    if (vitoriasJogador1 >= 2)
        return 1;

    if (vitoriasJogador2 >= 2)
        return 2;

    return 0; // Empata
}

int pedirTruco(int valorMao)
{
    char resposta;

    std::cout << "Truco!" << std::endl;
    std::cout << "Deseja pedir truco? (s/n): ";
    std::cin >> resposta;

    if (resposta == 's' || resposta == 'S')
    {
        return 3; // Jogador pediu truco
    }
    else
    {
        return valorMao; // Jogador não pediu truco
    }
}

int jogarRodada(Carta carta1, Carta carta2, Carta coringa)
{
    std::cout << "Carta do Jogador 1: " << mostrarCarta(carta1) << std::endl;
    std::cout << "Carta do Jogador 2: " << mostrarCarta(carta2) << std::endl;

    int vencedor = compararCartas(carta1, carta2, coringa);

    if (vencedor == 1)
    {
        std::cout << "Jogador 1 venceu a rodada!" << std::endl;
    }
    else if (vencedor == 2)
    {
        std::cout << "Jogador 2 venceu a rodada!" << std::endl;
    }
    else
    {
        std::cout << "Empate na rodada!" << std::endl;
    }

    return 0;
}
