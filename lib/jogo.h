#ifndef JOGO_H
#define JOGO_H

#include "baralho.h"
#include "carta.h"
#include "monte.h"
#include <array>

// a mão de cada jogador (3 cartas) e seus pontos na partida
struct Jogador
{
    Carta mao[3];
    int pontos; // placar individual
};

struct Jogo
{
    Baralho baralho;
    std::array<Jogador, 2> jogadores;

    Carta coringa;

    // monte: lista encadeada ordenada das cartas jogadas na mão atual
    Monte monte;
};

// regras e fluxo do jogo
int definirForcaCarta(Carta carta, Carta coringa);
int compararCartas(Carta carta1, Carta carta2, Carta coringa);
// Retorna 1 se aceitar e 0 se recusar.
int pedirTruco();
int aumentarTruco(int valorMao);

// mostra as cartas da mão do jogador numeradas (1 a 3), marcando as já jogadas
void mostrarMao(const Jogador &jogador, int numeroJogador);

// joga uma rodada (uma carta de cada), imprime o resultado e devolve o vencedor
int jogarRodada(Carta carta1, Carta carta2, Carta coringa);

// Soma o valor da mão apenas ao vencedor (pontos de cada Jogador).
void atualizarPontuacao(int vencedorMao, int valorMao,
                        std::array<Jogador, 2> &jogadores);
// Retorna 0 para continuar, 1 ou 2 para o vencedor da partida (12 pontos).
int verificarFimJogo(const std::array<Jogador, 2> &jogadores);

// joga uma mão inteira (até alguém vencer 2 rodadas ou o adversário desistir);
// devolve o vencedor (1 ou 2) e atualiza valorMao com o valor final da mão
int jogarMao(Jogo &jogo, int quemComeca, int &valorMao);

// joga a partida completa (mãos até alguém chegar a 12 pontos); devolve 1 ou 2
int jogarPartida(Jogo &jogo);

// cria os dois jogadores com a mão inicial vazia e pontos zerados
std::array<Jogador, 2> setarJogadores();

#endif
