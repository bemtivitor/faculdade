#include "jogo.h"

#include <cstdlib> // atoi
#include <iostream>
#include <string>

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

// mostra as cartas da mão do jogador, numeradas de 1 a 3 (marcando as usadas)
void mostrarMao(const Jogador &jogador, int numeroJogador)
{
    std::cout << "Jogador " << numeroJogador << " - suas cartas:\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << "  [" << i + 1 << "] ";
        if (jogador.mao[i].valor == -1)
            std::cout << "(ja jogada)\n";
        else
            std::cout << mostrarCarta(jogador.mao[i]) << "\n";
    }
}

// negociação de truco: quem propõe sobe o valor e o adversário pode aceitar,
// aumentar ou desistir. "Aumentar" aceita implicitamente o valor proposto e
// inverte os papéis; desistir dá a mão ao proponente pelo valor vigente.
// Retorna 0 se a mão continua (valorMao já atualizado) ou o vencedor (1/2).
static int tratarAumentos(int &valorMao, int jogadorInicial)
{
    if (valorMao >= 12)
        return 0; // já está no valor máximo: não há como aumentar

    int proponente = jogadorInicial;
    int adversario = (proponente == 1) ? 2 : 1;

    while (true)
    {
        int proposta = aumentarTruco(valorMao);
        if (proposta <= valorMao)
            return 0; // sem próximo nível disponível

        std::cout << "\nJogador " << proponente
                  << " pede que a mao valha " << proposta << " ponto(s).\n";

        bool podeAumentar = aumentarTruco(proposta) > proposta;
        std::cout << "Jogador " << adversario << ": [a]ceitar";
        if (podeAumentar)
            std::cout << " | [u]mentar";
        std::cout << " | [d]esistir: ";

        std::string resposta;
        while (true)
        {
            if (!(std::cin >> resposta))
                resposta = "d"; // fim da entrada vira desistência

            if (resposta == "a" || resposta == "A")
            {
                valorMao = proposta;
                std::cout << "Aceito! A mao agora vale " << valorMao
                          << " ponto(s).\n";
                return 0;
            }
            if (resposta == "d" || resposta == "D")
            {
                std::cout << "Jogador " << adversario << " desistiu.\n";
                return proponente; // quem propôs vence a mão
            }
            if (podeAumentar && (resposta == "u" || resposta == "U"))
            {
                // aumentar aceita implicitamente a proposta e inverte os papéis
                valorMao = proposta;
                int aux = proponente;
                proponente = adversario;
                adversario = aux;
                break;
            }
            std::cout << "Resposta invalida. Digite a, u ou d: ";
        }
    }
}

// um turno: o jogador escolhe uma carta (1 a 3) ou pede truco/aumento.
// Retorna 0 se a carta foi jogada (preenchida em cartaEscolhida e marcada
// como usada na mão) ou o vencedor da mão (1/2) se o adversário desistiu.
static int realizarTurno(Jogo &jogo, int jogador, int &valorMao,
                         Carta &cartaEscolhida)
{
    while (true)
    {
        std::cout << "\n=== Turno do Jogador " << jogador << " ===\n";
        mostrarMao(jogo.jogadores[jogador - 1], jogador);

        bool podeAumentar = valorMao < 12;
        std::cout << "Escolha o numero da carta (1 a 3)";
        if (podeAumentar)
            std::cout << " ou digite T para pedir truco/aumento";
        std::cout << ": ";

        std::string entrada;
        if (!(std::cin >> entrada))
            entrada = "";

        // pedido de truco/aumento
        if (podeAumentar && (entrada == "T" || entrada == "t"))
        {
            int vencedor = tratarAumentos(valorMao, jogador);
            if (vencedor != 0)
                return vencedor; // mão encerrada por desistência

            continue; // aumento aceito: o jogador ainda escolhe a carta
        }

        // escolha da carta pelo número mostrado
        int indice = atoi(entrada.c_str());
        if (indice >= 1 && indice <= 3 &&
            jogo.jogadores[jogador - 1].mao[indice - 1].valor != -1)
        {
            cartaEscolhida = jogo.jogadores[jogador - 1].mao[indice - 1];
            jogo.jogadores[jogador - 1].mao[indice - 1].valor = -1; // jogada
            return 0;
        }

        std::cout << "Opcao invalida. ";
    }
}

// joga uma mão (até alguém vencer 2 rodadas ou o adversário desistir de um
// aumento). Devolve o vencedor e o valor final da mão em valorMao.
int jogarMao(Jogo &jogo, int quemComeca, int &valorMao)
{
    int vitorias[2] = {0, 0}; // vitorias[0] = Jogador 1
    int primeiro = quemComeca;
    valorMao = 1;

    int rodada = 0;
    while (vitorias[0] < 2 && vitorias[1] < 2 && rodada < 3)
    {
        rodada++;
        std::cout << "\n========== RODADA " << rodada << " ==========\n";
        std::cout << "A mao vale " << valorMao << " ponto(s).\n";

        Carta cartas[3]; // cartas jogadas nesta rodada ([1] e [2] por jogador)

        // cada jogador age uma vez, começando por "primeiro"
        for (int vez = 0; vez < 2; vez++)
        {
            int jogador = (vez == 0) ? primeiro : (primeiro == 1 ? 2 : 1);

            Carta carta;
            int resultado = realizarTurno(jogo, jogador, valorMao, carta);
            if (resultado != 0)
                return resultado; // adversário desistiu: mão encerrada

            inserirNoMonte(jogo.monte, carta, jogador);
            cartas[jogador] = carta;
        }

        int vencedor = jogarRodada(cartas[1], cartas[2], jogo.coringa);
        if (vencedor > 0)
        {
            vitorias[vencedor - 1]++;
            primeiro = vencedor; // o vencedor começa a próxima rodada
        }

        std::cout << "Vitorias: Jogador 1 = " << vitorias[0]
                  << " | Jogador 2 = " << vitorias[1] << "\n";
        imprimirMonte(jogo.monte);
    }

    if (vitorias[0] == 2)
        return 1;
    if (vitorias[1] == 2)
        return 2;
    return 0; // não ocorre: sem empates de rodada toda mão tem vencedor
}

// joga a partida completa: mãos sucessivas até alguém chegar a 12 pontos.
int jogarPartida(Jogo &jogo)
{
    int quemComeca = 1; // alterna a cada mão

    while (verificarFimJogo(jogo.jogadores) == 0)
    {
        // prepara uma nova mão: baralho novo embaralhado e cartas distribuídas
        jogo.baralho = criarBaralho();
        distribuirCartas(jogo.baralho, jogo.jogadores.data(),
                         static_cast<int>(jogo.jogadores.size()));
        jogo.coringa = sortearCoringa(jogo.baralho);

        std::cout << "\n############ NOVA MAO ############\n";
        std::cout << "Carta vira: " << mostrarCarta(jogo.coringa)
                  << " -> manilha: "
                  << mostrarNumeroDaCarta((jogo.coringa.valor + 1) % NUM_VALORES)
                  << "\n";
        std::cout << "Comeca a jogar: Jogador " << quemComeca << "\n";

        int valorMao = 1;
        int vencedorMao = jogarMao(jogo, quemComeca, valorMao);

        atualizarPontuacao(vencedorMao, valorMao, jogo.jogadores);
        std::cout << "\nJogador " << vencedorMao << " venceu a mao ("
                  << valorMao << " ponto(s)).\n";
        std::cout << "Placar: Jogador 1 = " << jogo.jogadores[0].pontos
                  << " | Jogador 2 = " << jogo.jogadores[1].pontos << "\n";

        // o monte pertence à mão: libera antes da próxima
        limparMonte(jogo.monte);

        quemComeca = (quemComeca == 1) ? 2 : 1;
    }

    return verificarFimJogo(jogo.jogadores);
}

// Chamar uma única vez ao encerrar a mão; soma apenas ao vencedor.
void atualizarPontuacao(int vencedorMao, int valorMao,
                        std::array<Jogador, 2> &jogadores)
{
    if (valorMao <= 0)
        return; // Uma mão precisa valer pontos positivos.

    if (vencedorMao == 1)
        jogadores[0].pontos += valorMao;
    else if (vencedorMao == 2)
        jogadores[1].pontos += valorMao;
    // Sem vencedor (0), nenhum placar muda.
}

// Consultar após pontuar cada mão e encerrar a partida se retornar 1 ou 2.
int verificarFimJogo(const std::array<Jogador, 2> &jogadores)
{
    if (jogadores[0].pontos >= 12)
        return 1;
    if (jogadores[1].pontos >= 12)
        return 2;

    return 0; // A partida continua.
}

// cria e inicializa os dois jogadores, deixando mãos vazias e pontos zerados
std::array<Jogador, 2> setarJogadores()
{
    std::array<Jogador, 2> jogadores{};

    for (int i = 0; i < 2; i++)
    {
        jogadores[i].pontos = 0;

        for (int j = 0; j < 3; j++)
        {
            // -1 indica que a carta ainda não foi distribuída
            jogadores[i].mao[j].valor = -1;
            jogadores[i].mao[j].naipe = -1;
        }
    }

    return jogadores;
}
