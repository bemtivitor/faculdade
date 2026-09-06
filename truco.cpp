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
// ~mostrarCarta(✓)~

// Você
// definirForcaCarta(✓)
// compararCartas(✓)
// jogarRodada(✓)
// verificarVencedorMao(✓)
// pedirTruco(✓)
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

int definirForcaCarta(Carta carta, Carta coringa)
{
    int valorCartaMaisForte = (coringa.valor + 1) % 12;
    if (carta.valor == valorCartaMaisForte)
    {
        return 12;
    }
    else
    {
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
        if (carta1.naipe > carta2.naipe)
        {
            return 1; // carta1 é mais forte
        }
        else if (carta1.naipe < carta2.naipe)
        {
            return 2; // carta2 é mais forte
        }
        else
        {
            return 0; // empate
        }
    }
}

int verificarVencedorMao(int rodada1, int rodada2, int rodada3)
{
    int vitoriasJogador1 = 0;
    int vitoriasJogador2 = 0;

    if (rodada1 == 1)
        vitoriasJogador1++;
    else if (rodada1 == 2)
        vitoriasJogador2++;

    if (rodada2 == 1)
        vitoriasJogador1++;
    else if (rodada2 == 2)
        vitoriasJogador2++;

    if (rodada3 == 1)
        vitoriasJogador1++;
    else if (rodada3 == 2)
        vitoriasJogador2++;

    if (vitoriasJogador1 > vitoriasJogador2)
        return 1; // Jogador 1 venceu a mão
    else if (vitoriasJogador2 > vitoriasJogador1)
        return 2; // Jogador 2 venceu a mão
    if (rodada3 == 1)
        vitoriasJogador1++;
    else if (rodada3 == 2)
        vitoriasJogador2++;

    if (vitoriasJogador1 >= 2)
        return 1;

    if (vitoriasJogador2 >= 2)
        return 2;

    return 0; // Empata
}

int pedirTruco(int valorMao)
{
    char resposta;

    cout << "Truco!" << endl;
    cout << "Deseja pedir truco? (s/n): ";
    cin >> resposta;

    if (resposta == 's' || resposta == 'S')
    {
        return 3; // Jogador pediu truco
    }
    else
    {
        return valorMao; // Jogador não pediu truco
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

int jogarRodada(Carta carta1, Carta carta2, Carta coringa)
{
    cout << "Carta do Jogador 1: " << mostrarCarta(carta1) << endl;
    cout << "Carta do Jogador 2: " << mostrarCarta(carta2) << endl;

    int vencedor = compararCartas(carta1, carta2, coringa);

    if (vencedor == 1)
    {
        cout << "Jogador 1 venceu a rodada!" << endl;
    }
    else if (vencedor == 2)
    {
        cout << "Jogador 2 venceu a rodada!" << endl;
    }
    else
    {
        cout << "Empate na rodada!" << endl;
    };

    return 0;
}
