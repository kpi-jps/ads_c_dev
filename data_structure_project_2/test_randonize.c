#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A função randomize inicializa o gerador
// de números aleatórios de modo que os
// resultados das invocações de randomInteger
// sejam imprevisíveis.

void randomize (void)
{
    srand (time (NULL));
}

// A função randomInteger devolve um inteiro 
// aleatório entre low e high inclusive,
// ou seja, no intervalo fechado low..high.
// Vamos supor que low <= high e que
// high - low <= RAND_MAX. (O código foi copiado
// da biblioteca random de Eric Roberts.)
int randomInteger (int low, int high)
{
    randomize();
    double d;
    d = (double) rand () / ((double) RAND_MAX + 1);
    int k = d * (high - low + 1);
    return low + k;
}


int main()
{
    int num = 100;
    printf("Número aleatório = %d\n" , (rand()%num + 1)); //não fornece números aleatório, o numero sempre se repete
    printf("Número aleatório = %d\n" , randomInteger(1, num));
    return 0;
}