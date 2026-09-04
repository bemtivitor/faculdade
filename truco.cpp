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
// definirForcaCarta(check)
// compararCartas(check)
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

int definirForcaCarta(Carta carta, Carta coringa){
    int valorCartaMaisForte = (coringa.valor + 1) % 12;
    if(carta.valor == valorCartaMaisForte)
    {
        return 12;
    }
    else{
        return carta.valor;
    }
}

int compararCartas(Carta carta1, Carta carta2, Carta coringa)
{
    int forcaCarta1 = definirForcaCarta(carta1, coringa);
    int forcaCarta2 = definirForcaCarta(carta2, coringa);

    if (forcaCarta1 > forcaCarta2)
    {
        return 1; // carta1 é mais forte
    }
    else if (forcaCarta1 < forcaCarta2)
    {
        return 2; // carta2 é mais forte
    }
    else
    {
        if(carta1.naipe > carta2.naipe)
        {
            return 1; // carta1 é mais forte
        }
        else if(carta1.naipe < carta2.naipe)
        {
            return 2; // carta2 é mais forte
        }
        else
        {
            return 0; // empate
        }
    }
}

// O = 1
// E = 2
// C = 3
// P = 4

// 4 = 0
// 5 = 1
// 6 = 2
// 7 = 3
// 8 = 4
// 9 = 5
// Q = 6
// J = 7
// K = 8
// A = 9
// 2 = 10
// 3 = 11

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Carta coringa;
    coringa.valor = 3;
    coringa.naipe = 0;

    Carta carta;
    carta.valor =4;
    carta.naipe = 1;

    cout << "Coringa: " << mostrarCarta(coringa) << endl;
    cout << "Carta: " << mostrarCarta(carta) << endl;

    cout << "Força da carta: " << definirForcaCarta(carta, coringa) << endl;

    return 0;
}
