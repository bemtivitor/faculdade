#include <iostream>
#include <windows.h>

#include "lib/baralho.h"
#include "lib/carta.h"
#include "lib/jogo.h"

int main()
{
    // garante que os símbolos dos naipes apareçam corretamente no console do Windows
    SetConsoleOutputCP(CP_UTF8);

    Baralho baralho = criarBaralho();

    // teste: exibe todas as cartas criadas
    for (int i = 0; i < TAMANHO_BARALHO; i++)
    {
        std::cout << mostrarCarta(baralho.cartas[i]) << ' ';
    }
    std::cout << std::endl;

    // TODO: implementar aqui o fluxo principal do jogo

    return 0;
}
