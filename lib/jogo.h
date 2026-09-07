#ifndef JOGO_H
#define JOGO_H

#include "baralho.h"
#include "carta.h"
#include <array>

// a mão de cada jogador (3 cartas)
struct Jogador
{
    Carta mao[3];
};

struct Jogo
{
    Baralho baralho;
    std::array<Jogador, 2> jogadores;

    Carta coringa;
};

// regras e fluxo do jogo
int definirForcaCarta(Carta carta, Carta coringa);
int compararCartas(Carta carta1, Carta carta2, Carta coringa);
int verificarVencedorMao(int rodada1, int rodada2, int rodada3);
int pedirTruco(int valorMao);
int jogarRodada(Carta carta1, Carta carta2, Carta coringa);

// cria os dois jogadores com a mão inicial vazia
std::array<Jogador, 2> setarJogadores();

// pendências
// Guilherme: mostrarMao()
// Você: aumentarTruco(), atualizarPontuacao(), verificarFimJogo()

#endif
