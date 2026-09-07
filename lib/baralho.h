#ifndef BARALHO_H
#define BARALHO_H

#include "carta.h"

// o baralho completo do jogo
struct Baralho
{
    Carta cartas[48];
};

// cria o baralho com todas as combinações de valor e naipe
Baralho criarBaralho();

// pendências (Guilherme)
// distribuirCartas()
// sortearCoringa()

#endif
