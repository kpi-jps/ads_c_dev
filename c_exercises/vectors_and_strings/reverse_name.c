#include <stdio.h>

int main()
{
    char nome[50]; //Representa o nome completo da pessoa. ex: "Joao Silva"
    char nomeinverso[51]; //Represeta o nome no formato "Sobrenome, Nome"
    int i, j, k, l; // Variaveis de controle

    // Entrada de 10 nomes.
    for (i = 0; i < 10; i++)
    {
        printf("Digite o nome %d: ",i);
        gets(nome); //Lê o nome até o enter.
        j = 0;
        while (nome[j] != ' ')
        {
            j++;
        }
        k = j;
        while (nome[k + 1] != '\0')
        {
            nomeinverso[k - j] = nome[k + 1];
            k++;
        }
        nomeinverso[k - j] = ',';
        k++;
        nomeinverso[k - j] = ' ';
        k++;
        for (l = 0; l < j; l++)
        {
            nomeinverso[k - j] = nome[l];
            k++;
        }
        nomeinverso[k-j] = '\0';

        printf("Nome %d formatado: %s\n", i, nomeinverso);
    }
}
