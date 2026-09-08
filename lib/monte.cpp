#include "monte.h"

#include <iostream>

// retorna verdadeiro se a carta "a" vem antes da carta "b" na ordem do monte:
// o valor é o critério principal e o naipe é o desempate
static bool cartaMenorQue(Carta a, Carta b)
{
    if (a.valor != b.valor)
        return a.valor < b.valor;

    return a.naipe < b.naipe;
}

void inicializarMonte(Monte &monte)
{
    monte.comeco = nullptr;
    monte.fim = nullptr;
    monte.quantidade = 0;
}

void inserirNoMonte(Monte &monte, Carta carta, int jogador)
{
    NoMonte *novo = new NoMonte;
    novo->carta = carta;
    novo->jogador = jogador;
    novo->proximo = nullptr;

    // monte vazio: o novo nó é o começo e o fim ao mesmo tempo
    if (monte.comeco == nullptr)
    {
        monte.comeco = novo;
        monte.fim = novo;
    }
    // carta maior ou igual à última: entra direto no fim (O(1))
    else if (!cartaMenorQue(carta, monte.fim->carta))
    {
        monte.fim->proximo = novo;
        monte.fim = novo;
    }
    // carta menor que a primeira: entra no começo
    else if (cartaMenorQue(carta, monte.comeco->carta))
    {
        novo->proximo = monte.comeco;
        monte.comeco = novo;
    }
    // carta do meio: percorre até achar a posição correta
    else
    {
        NoMonte *atual = monte.comeco;
        while (atual->proximo != nullptr &&
               cartaMenorQue(atual->proximo->carta, carta))
        {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }

    monte.quantidade++;
}

void imprimirMonte(const Monte &monte)
{
    std::cout << "Monte (menor -> maior):";

    if (monte.comeco == nullptr)
    {
        std::cout << " vazio" << std::endl;
        return;
    }

    for (NoMonte *atual = monte.comeco; atual != nullptr; atual = atual->proximo)
    {
        std::cout << " " << mostrarCarta(atual->carta)
                  << "(J" << atual->jogador << ")";
    }
    std::cout << std::endl;
}

void limparMonte(Monte &monte)
{
    NoMonte *atual = monte.comeco;
    while (atual != nullptr)
    {
        NoMonte *proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }

    inicializarMonte(monte);
}
