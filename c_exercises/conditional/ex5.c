/*
Ex.5 - E Dados 3 valores X, Y, Z verificar se eles podem ser os
comprimentos dos lados de um triângulo e, se forem, verificar
se é triângulo equilátero, isósceles ou escaleno. 
Propriedades 
- o comprimento de cada lado de um triângulo é menor do que a soma dos outros 2 lados
- Equilátero - 3 lados iguais
- Isósceles - 2 lados iguais
- Escaleno - 3 lados diferentes
*/
#include <stdio.h>

int main()
{
    float x, y, z; 
    printf("Digite um valor para x: ");
    scanf("%f", &x);
    printf("Digite um valor para y: ");
    scanf("%f", &y);
    printf("Digite um valor para z: ");
    scanf("%f", &z);
    if (x < y+z || y < x+z || z < x+y) 
    {
        if (x == y && x == z && y == z) 
        {
           printf("x, y e z podem ser os lados de um triangulo Equilátero"); 
        } else if (x == y || y == z || z == x) 
        {
            printf("x, y e z podem ser os lados de um triangulo Isósceles");
        } else 
        {
           printf("x, y e z podem ser os lados de um triangulo Escaleno"); 
        }
    } else 
    {
        printf("x, y e z não podem ser os lados de um triangulo"); 
    }
    return 0;
}
