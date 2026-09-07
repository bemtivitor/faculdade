#ifndef CARTA_H
#define CARTA_H

#include <string>

// naipes
extern const int OURO;
extern const int ESPADAS;
extern const int COPAS;
extern const int PAUS;

// nomes exibidos de cada naipe (índices 0 a 3)
extern const char *NAIPES[4];

// força dos valores do baralho (índices 0 a 11)
extern const char VALORES[13];

// tamanho do baralho: quantidade de valores x quantidade de naipes
extern const int NUM_VALORES;
extern const int NUM_NAIPES;
extern const int TAMANHO_BARALHO;

// uma carta: valor (índice em VALORES) e naipe (índice em NAIPES)
struct Carta
{
    int valor, naipe;
};

// funções de exibição da carta
char mostrarNumeroDaCarta(int valor);
const char *mostrarNaipe(int naipe);
std::string mostrarCarta(Carta carta);

#endif
