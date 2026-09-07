#include "baralho.h"

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

    return baralho;
}
