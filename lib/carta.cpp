#include "carta.h"

// naipes
const int OURO = 0;
const int ESPADAS = 1;
const int COPAS = 2;
const int PAUS = 3;

const char *NAIPES[4] = {
    "♦",
    "♠",
    "♥",
    "♣"};

// 12 valores: 4, 5, 6, 7, 8, 9, Q, J, K, A, 2, 3
const char VALORES[13] = "456789QJKA23";

const int NUM_VALORES = sizeof(VALORES) - 1;      // 12
const int NUM_NAIPES = 4;
const int TAMANHO_BARALHO = NUM_VALORES * NUM_NAIPES; // 48

char mostrarNumeroDaCarta(int valor)
{
    return VALORES[valor];
}

const char *mostrarNaipe(int naipe)
{
    return NAIPES[naipe];
}

std::string mostrarCarta(Carta carta)
{
    return std::string(1, mostrarNumeroDaCarta(carta.valor)) + mostrarNaipe(carta.naipe);
}
