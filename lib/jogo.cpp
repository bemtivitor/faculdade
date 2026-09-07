#include "jogo.h"

#include <iostream>

// Ordem de força dos valores (índices em VALORES):
// 4=0, 5=1, 6=2, 7=3, 8=4, 9=5, Q=6, J=7, K=8, A=9, 2=10, 3=11

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
    // Primeiro compara a força; se for igual, compara o naipe.
    int forcaCarta1 = definirForcaCarta(carta1, coringa);
    int forcaCarta2 = definirForcaCarta(carta2, coringa);

    if (forcaCarta1 != forcaCarta2)
    {
        return forcaCarta1 > forcaCarta2 ? 1 : 2;
    }
    else if (carta1.naipe != carta2.naipe)
    {
        return carta1.naipe > carta2.naipe ? 1 : 2;
    }

    return 0; // Mesma força e mesmo naipe: empate.
}

// Gui: Acho que essa função não vai ser usada, não acho bom as rodadas serem
// presentadas por números ou algo do tipo, acho melhor criar algo dinâmico,
// assim poderemos aumentar o número de rodadas e essas coisas.
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

    // Duas vitórias já encerram a mão, sem considerar a terceira rodada.
    if (vitoriasJogador1 == 2)
        return 1;
    if (vitoriasJogador2 == 2)
        return 2;

    // Conta a terceira rodada apenas uma vez.
    if (rodada3 == 1)
        vitoriasJogador1++;
    else if (rodada3 == 2)
        vitoriasJogador2++;

    if (vitoriasJogador1 >= 2)
        return 1;

    if (vitoriasJogador2 >= 2)
        return 2;

    return 0; // Ninguém chegou a duas vitórias nesta regra simplificada.
}

// Pergunta ao adversário se aceita. O valor da mão é tratado separadamente.
int pedirTruco()
{
    char resposta;

    while (true)
    {
        std::cout << "Jogador adversario aceita o aumento? (s/n): ";
        if (!(std::cin >> resposta))
            return 0; // Sem entrada disponível, não confirma o aumento.

        if (resposta == 's' || resposta == 'S')
            return 1;
        if (resposta == 'n' || resposta == 'N')
            return 0;

        std::cout << "Resposta invalida. Digite s ou n." << std::endl;
    }
}

// Devolve o próximo valor; quem chama precisa guardar o resultado.
int aumentarTruco(int valorMao)
{
    switch (valorMao)
    {
    case 1:
        return 3;
    case 3:
        return 6;
    case 6:
        return 9;
    case 9:
        return 12;
    default:
        return valorMao; // Em 12, não aumenta; outros valores são preservados.
    }
}

int jogarRodada(Carta carta1, Carta carta2, Carta coringa)
{
    std::cout << "Carta do Jogador 1: " << mostrarCarta(carta1) << std::endl;
    std::cout << "Carta do Jogador 2: " << mostrarCarta(carta2) << std::endl;

    int vencedor = compararCartas(carta1, carta2, coringa);

    if (vencedor == 1)
    {
        std::cout << "Jogador 1 venceu a rodada!" << std::endl;
    }
    else if (vencedor == 2)
    {
        std::cout << "Jogador 2 venceu a rodada!" << std::endl;
    }
    else
    {
        std::cout << "Empate na rodada!" << std::endl;
    }

    return vencedor;
}

// Chamar uma única vez ao encerrar a mão. As referências alteram o placar original.
void atualizarPontuacao(int vencedorMao, int valorMao,
                       int &pontosJogador1, int &pontosJogador2)
{
    if (valorMao <= 0)
        return; // Uma mão precisa valer pontos positivos.

    if (vencedorMao == 1)
        pontosJogador1 += valorMao;
    else if (vencedorMao == 2)
        pontosJogador2 += valorMao;
    // Sem vencedor (0), nenhum placar muda.
}

// Consultar após pontuar cada mão e encerrar a partida se retornar 1 ou 2.
int verificarFimJogo(int pontosJogador1, int pontosJogador2)
{
    if (pontosJogador1 >= 12)
        return 1;
    if (pontosJogador2 >= 12)
        return 2;

    return 0; // A partida continua.
}

// cria e inicializa os dois jogadores, deixando as mãos vazias
std::array<Jogador, 2> setarJogadores()
{
    std::array<Jogador, 2> jogadores{};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // -1 indica que a carta ainda não foi distribuída
            jogadores[i].mao[j].valor = -1;
            jogadores[i].mao[j].naipe = -1;
        }
    }

    return jogadores;
}
