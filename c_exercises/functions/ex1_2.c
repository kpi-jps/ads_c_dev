#include <stdio.h>

// Lê n lados, verificando se a entrada é positiva e coloca os lados no vetor lados[].
void lerLados(int lados[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        do
        {
            printf("Digite o lado %d: ", i + 1);
            scanf("%d", &lados[i]);
            if (lados[i] < 0)
                printf("Entrada inválida, entre um número não negativo!\n");
        } while (lados[i] < 0);
    }
}

// Calcula a área do quadrado.
int areaQuadrado(int lado)
{
    return lado * lado;
}

// Calcula a área do retângulo.
int areaRetangulo(int lados[])
{
    return lados[0] * lados[1];
}

// Calcula a área do triângulo retângulo.
double areaTrianguloRetangulo(int lados[])
{
    return (lados[0] * lados[1]) / 2.0;
}


// Função principal do programa.
int main()
{
    int figura = 0;
    int lados[2];
    printf("Programa de cálculo de área\n");
    while (figura != 4)
    {
        printf("\nEscolha a figura:\n");
        printf("1 - Quadrado\n");
        printf("2 - Retângulo\n");
        printf("3 - Triângulo retângulo\n");
        printf("4 - Sair do programa\n");
        printf("Digite o número correspondente: ");
        scanf("%d", &figura);
        switch (figura)
        {
        case 1:
            lerLados(lados, 1);
            printf("A área do quadrado é: %d\n", areaQuadrado(lados[0]));
            break;
        case 2:
            lerLados(lados, 2);
            printf("A área do retângulo é: %d\n", areaRetangulo(lados));
            break;
        case 3:
            lerLados(lados, 2);
            printf("A área do triângulo retângulo é: %0.2f\n", areaTrianguloRetangulo(lados));
            break;
        case 4:
            printf("Encerrando o programa!\n");
            break;
        default:
            printf("Entrada inválida!\n");
        }
    }
}
