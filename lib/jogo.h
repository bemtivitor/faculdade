#ifndef JOGO_H
#define JOGO_H

#include "carta.h"

// a mão de cada jogador (3 cartas)
struct Jogador
{
    Carta mao[3];
};

// regras e fluxo do jogo
int definirForcaCarta(Carta carta, Carta coringa);
int compararCartas(Carta carta1, Carta carta2, Carta coringa);
int verificarVencedorMao(int rodada1, int rodada2, int rodada3);
int pedirTruco(int valorMao);
int jogarRodada(Carta carta1, Carta carta2, Carta coringa);

// pendências
// Guilherme: mostrarMao()
// Você: aumentarTruco(), atualizarPontuacao(), verificarFimJogo()

#endif
