

#include "baralho.h"

// Jogador precisa estar completo aqui (acessamos jogadores[].mao)
#include "jogo.h"

#include <cstdlib> // rand

Baralho criarBaralho()
{
    Baralho baralho;
    int posicao = 0;

    // loop externo: valores (i)
    for (int i = 0; i < NUM_VALORES; i++)
    {
        // loop interno: naipes (j)
        for (int j = 0; j < NUM_NAIPES; j++)
        {
            baralho.cartas[posicao].valor = i;
            baralho.cartas[posicao].naipe = j;
            posicao++;
        }
    }

    // todas as cartas estão disponíveis no início
    baralho.quantidade = TAMANHO_BARALHO;

    return baralho;
}

// distribui 3 cartas para cada jogador, sem repetir carta alguma:
// cada carta sorteada é removida de verdade do baralho antes do próximo sorteio
void distribuirCartas(Baralho &baralho, Jogador jogadores[], int quantidadeJogadores)
{
    for (int jogador = 0; jogador < quantidadeJogadores; jogador++)
    {
        for (int posicao = 0; posicao < 3; posicao++)
        {
            // limite dinâmico: só as cartas ainda disponíveis entram no sorteio
            int sorteio = rand() % baralho.quantidade;

            // entrega a carta sorteada ao jogador
            jogadores[jogador].mao[posicao] = baralho.cartas[sorteio];

            // remove a carta do baralho: a última carta disponível ocupa o
            // lugar da sorteada e a quantidade disponível diminui
            baralho.cartas[sorteio] = baralho.cartas[baralho.quantidade - 1];
            baralho.quantidade--;
        }
    }
}

// sorteia e remove uma carta do baralho (usada para o coringa/vira)
Carta sortearCoringa(Baralho &baralho)
{
    int sorteio = rand() % baralho.quantidade;

    Carta coringa = baralho.cartas[sorteio];

    baralho.cartas[sorteio] = baralho.cartas[baralho.quantidade - 1];
    baralho.quantidade--;

    return coringa;
}
