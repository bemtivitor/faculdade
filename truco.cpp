#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// Guilherme
// criarBaralho()
// embaralharBaralho()
// distribuirCartas()
// sortearCoringa()
// mostrarMao()
// ~mostrarCarta()~

// Você
// definirForcaCarta()
// compararCartas()
// jogarRodada()
// verificarVencedorMao()
// pedirTruco()
// aumentarTruco()
// atualizarPontuacao()
// verificarFimJogo()

// variáveis imutáveis reutilizadas no código

const int PAUS = 3;
const int COPAS = 2;
const int ESPADAS = 1;
const int OURO = 0;
const char *NAIPES[4] = {
    "♦",
    "♠",
    "♥",
    "♣"};
const char VALORES[13] = "456789QJKA23";

struct Carta
{
    int valor, naipe;
};

struct Jogador
{
    Carta mao[3];
};

char mostrarNumeroDaCarta(int valor)
{
    return VALORES[valor];
}

const char *mostrarNaipe(int naipe)
{
    return NAIPES[naipe];
}

string mostrarCarta(Carta carta)
{
    return string(1, mostrarNumeroDaCarta(carta.valor)) + mostrarNaipe(carta.naipe);
}

// O = 1
// E = 2
// C = 3
// P = 4

// 4  = 0
// 5  = 1
// 6  = 2
// 7  = 3
// Q  = 4
// J  = 5
// K  = 6
// A  = 7
// 2  = 8
// 3  = 9

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Carta carta;
    carta.naipe = 0;
    carta.valor = 0;

    cout << mostrarCarta(carta) << endl;
    return 0;
}
