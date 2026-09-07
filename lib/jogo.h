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
// Retorna 1 se aceitar e 0 se recusar.
int pedirTruco();
int aumentarTruco(int valorMao);
// Soma o valor da mão apenas ao vencedor; altera os placares por referência.
void atualizarPontuacao(int vencedorMao, int valorMao,
                       int &pontosJogador1, int &pontosJogador2);
// Retorna 0 para continuar, 1 ou 2 para o vencedor da partida (12 pontos).
int verificarFimJogo(int pontosJogador1, int pontosJogador2);
int jogarRodada(Carta carta1, Carta carta2, Carta coringa);

// cria os dois jogadores com a mão inicial vazia
std::array<Jogador, 2> setarJogadores();

// pendências
// Guilherme: mostrarMao()
// Vitor: integrar o fluxo da partida e fechar as regras de empate

#endif
