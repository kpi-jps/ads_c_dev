/*
Structs Ex 4

Criar um programa em C que leia 4 pontos num plano cartesiano, e
o armazene na estrutura “quadrilatero” definida abaixo, verificando
se os 4 pontos formam um retângulo, um quadrado ou um losango
(Losango é um quadrilátero cujos lados são de igual
comprimento. Trançando-se suas diagonais é possível dividí-lo
em quatro triângulos retângulos simétricos.).

struct ponto {
    int x;
    int y;
};

struct quadrilatero {
    struct pontos p[4];
} quadrilatero1;

*/

// Valor muito pequeno.
#define EPSILON 0.00000001

#include <stdio.h>
#include <math.h>

// Definição de um ponto no espaço bidimensional.
struct ponto
{
    int x;
    int y;
};

// Definição de um quadrilátero, possui 4 pontos.
struct quadrilatero
{
    struct ponto p[4];
} quadrilatero1;

// Calcula a hipotenusa dos catetos passados como parâmetro. 
double hipotenusa(double catetoA, double catetoB)
{
    double temp = sqrt(pow(catetoA, 2) + pow(catetoB, 2));
    return temp;
}

// Considera dois valores double iguais quando a diferença entre eles é menor do que EPSILON.
int igual(double A, double B)
{
    return (fabs(A - B) < EPSILON);
}

int main()
{
    int i;
    double tlado[4], diagonal1, diagonal2; //Tamanho dos 4 lados e das diagonais.

    for (i = 0; i < 4; i++)
    {
        printf("Digite o ponto %d no formato X,Y:", i);
        scanf("%d,%d", &quadrilatero1.p[i].x, &quadrilatero1.p[i].y);
    }

    for (i = 0; i < 4; i++)
    {
        tlado[i] = hipotenusa(quadrilatero1.p[i].x - quadrilatero1.p[(i + 1)%4].x, quadrilatero1.p[i].y - quadrilatero1.p[(i + 1)%4].y);
        printf("Tamanho do Lado %d (%d,%d - %d,%d) = %f\n", i, quadrilatero1.p[i].x, quadrilatero1.p[i].y, quadrilatero1.p[(i + 1)%4].x, quadrilatero1.p[(i + 1)%4].y, tlado[i]);
    }
    diagonal1 = hipotenusa(quadrilatero1.p[0].x - quadrilatero1.p[2].x,quadrilatero1.p[0].y - quadrilatero1.p[2].y);
    diagonal2 = hipotenusa(quadrilatero1.p[1].x - quadrilatero1.p[3].x,quadrilatero1.p[1].y - quadrilatero1.p[3].y);
    printf("Diagonal 1 = %f\nDiagonal 2 = %f\n", diagonal1, diagonal2);

    if (igual(tlado[0], tlado[1]) && igual(tlado[1], tlado[2]) && igual(tlado[2], tlado[3]) && igual(tlado[3], tlado[0]))
    {
        if (igual(diagonal1,diagonal2)) {
            printf("É um quadrado!\n");
        } else {
            printf("É um losango!\n");
        }
    } else {
        if (igual(tlado[0],tlado[2]) && igual(tlado[1],tlado[3])) {
            if (igual(diagonal1,diagonal2)) {
                printf("É um retângulo!\n");
            } else {
                printf("É um paralelogramo!\n");
            }
        } else {
            printf("Não é um paralelogramo!\n");
        }
    }
}
