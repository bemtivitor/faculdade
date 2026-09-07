#ifndef BARALHO_H
#define BARALHO_H

#include "carta.h"

// o baralho completo do jogo
struct Baralho
{
    Carta cartas[48];

    // quantas cartas ainda estão disponíveis para distribuição
    // (48 ao criar o baralho e diminui conforme as cartas são entregues)
    int quantidade;
};

// Jogador é definido em jogo.h (que inclui baralho.h). A declaração
// antecipada basta aqui, pois jogadores é usado como ponteiro.
struct Jogador;

// cria o baralho com todas as combinações de valor e naipe
Baralho criarBaralho();
void distribuirCartas(Baralho &baralho, Jogador jogadores[], int quantidadeJogadores);
Carta sortearCoringa(Baralho &baralho);

#endif
