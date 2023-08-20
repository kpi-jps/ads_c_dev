#include <stdio.h>
#include <math.h>

/*
Os códigos abaixo representam a resolução dos exercícios da
semana 2 da disciplina de AP2 do curso ADS do IFSP São Carlos.
Os códigos estão entre comentários, para rodar, remova os caracteres
"barra asterisco" e "asterisco barra" que envolvem cada main,
um por vez. 
*/

/*
Fazer um programa para ler um número e imprimir uma
mensagem informando se ele é positivo, negativo ou igual a
zero.
*/

/*
int main()
{
    int numero;
    printf("Digite o número: ");
    scanf("%d", &numero);
    if (numero > 0)
    {
        printf("O número é postivo!\n");
    }
    else
    {
        if (numero < 0)
        {
            printf("O número é negativo!\n");
        }
        else
        {
            printf("O número é igual a zero!");
        }
    }
}
*/

/*
Refaça o programa para calcular as raizes de uma equação do
segundo grau através da fórmula de Báscara, dando respostas
diferentes para os casos: delta menor que zero, igual ao zero
ou maior que zero. 
*/

/*
int main()
{
    int a, b, c, delta;
    printf("Entre com os valores de a, b e c da equação \"ax^2 + bx + c = 0\" separados por espaço:");
    scanf("%d %d %d", &a, &b, &c);
    delta = pow(b, 2) - 4 * a * c;
    if (delta > 0)
    {
        printf("Delta: %d, 2 raízes!\n", delta);
    }
    else
    {
        if (delta < 0)
        {
            printf("Delta: %d, 0 raízes!\n", delta);
        }
        else
        {
            printf("Delta: %d, 1 raiz!\n", delta);
        }
    }
}
*/

/*
Ler um número de 1 a 7 indicando o dia da semana.O programa
deve imprimir o dia em extenso e uma mensagem dizendo se é
dia útil ou final de semana. Por exemplo, se for digitado 1, o
programa imprime: Domingo - final de semana. Se for digitado
2, o programa imprime: Segunda - dia útil e assim por diante.
*/

/*
int main()
{
    int dia;
    printf("Digite o número que representa o dia: ");
    scanf("%d", &dia);
    switch (dia)
    {
    case 1:
        printf("Domingo");
        break;
    case 2:
        printf("Segunda");
        break;
    case 3:
        printf("Terca");
        break;
    case 4:
        printf("Quarta");
        break;
    case 5:
        printf("Quinta");
        break;
    case 6:
        printf("Sexta");
        break;
    case 7:
        printf("Sabado");
        break;
    default:
        printf("Dia inválido!\n");
    }
    if (dia == 1 || dia == 7)
    {
        printf(" - final de semana.\n");
    }
    else
    {
        if (dia > 1 && dia < 7)
            printf(" - dia útil.\n");
    }
}
*/

/*
Escreva um programa que receba um número e responda se é
par ou impar.
*/

/*
int main() {
    int numero;
    printf("Entre com o número: ");
    scanf("%d", &numero);
    if (numero % 2 == 0) {
        printf("O número %d é par!", numero);
    } else {
        printf("O número %d é ímpar!", numero);
    }
}

*/

/*
 Dados 3 valores X, Y, Z verificar se eles podem ser os
comprimentos dos lados de um triângulo e, se forem, verificar
se é triângulo equilátero, isósceles ou escaleno.
• Propriedades - o comprimento de cada lado de um triângulo é
menor do que a soma dos outros 2 lados
• Equilátero - 3 lados iguais
• Isósceles - 2 lados iguais
• Escaleno - 3 lados diferentes
*/

/*
int main() {
int X, Y, Z;
    printf("Entre com os 3 lados do triângulo: ");
    scanf("%d %d %d", &X, &Y, &Z);
    if (X == Y && Y == Z) {
        printf("Triângulo Equilátero\n");
    } else {
        if (X != Y && Y != Z && X != Z) {
            printf("Triângulo Escaleno\n");

        } else {
            printf("Triângulo Isósceles");
        }
    }
}
*/

/*
Faça um programa em C que receba 3 números inteiros
digitados pelo usuário e os mostre de forma ordenada na tela.
Essa versão usa apenas estruturas de seleção, objeto da aula,
sem nenhuma estrutura de repetição e nem vetores.
*/

/*
int main() {
    int X, Y, Z;
    printf("Digite 3 números: ");
    scanf("%d %d %d", &X, &Y, &Z);
    if (X < Y && X < Z) {
        printf("%d ", X);
        if (Y < Z) {
            printf("%d %d\n", Y, Z);
        } else {
            printf("%d %d\n", Z, Y);
        }
    } else {
        if (Y < Z) {
            printf("%d ", Y);
            if (X < Z) {
                printf("%d %d\n", X, Z);
            } else {
                printf("%d %d\n", Z, X);
            }
        } else {
            printf ("%d ", Z);
            if (X < Y) {
                printf("%d %d\n", X, Y);
            } else {
                printf("%d %d\n", Y, X);
            }
        }
    }
}
*/
