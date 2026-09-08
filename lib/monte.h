#ifndef MONTE_H
#define MONTE_H

#include "carta.h"

// nó do monte: guarda a carta jogada, quem a jogou (1 ou 2) e o próximo nó
struct NoMonte
{
    Carta carta;
    int jogador;
    NoMonte *proximo;
};

// o monte é uma lista encadeada mantida em ordem crescente por (valor, naipe):
// comeco aponta para a MENOR carta e fim aponta para a MAIOR carta
struct Monte
{
    NoMonte *comeco;
    NoMonte *fim;
    int quantidade;
};

// deixa o monte vazio (comeco = fim = nullptr e quantidade = 0)
void inicializarMonte(Monte &monte);

// insere a carta já em ordem crescente (valor primeiro, naipe como desempate);
// "jogador" indica quem a jogou (1 ou 2)
void inserirNoMonte(Monte &monte, Carta carta, int jogador);

// imprime o monte do começo (menor carta) até o fim (maior carta)
void imprimirMonte(const Monte &monte);

// desaloca todos os nós e volta ao estado inicial
void limparMonte(Monte &monte);

#endif
