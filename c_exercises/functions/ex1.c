/******************************************************************************

Ex.1 - Fazer um programa capaz de calcular a área de um quadrado, um retângulo
ou um triângulo retângulo.
– O programa deve perguntar qual a figura geométrica, e então pedir para o
usuário digitar os tamanhos dos lados.
– Um quadrado só tem um tamanho de lado, o retângulo tem dois, e o triângulo
retângulo também tem dois lados(mais a hipotenusa, mas neste caso não é
necessário digitar este valor).
– Após a digitação, o programa deve calcular a área e apresentar ao usuário.
– Utilizar uma função para a leitura dos lados (verificando se não é digitado um
valor negativo para o lado), e uma função para o cálculo de cada área. As
fórmulas são
• Área_quadrado = lado * lado
• Área_retângulo = lado1 * lado2
• Área_triângulo = (lado 1 * lado 2)/2
*******************************************************************************/
#include <stdio.h>

//calcula a área do quadrado (parâmetro l = lado do quadrado)
float areaQuadrado(float l) 
{
    return l * l;
}
//calcula a área do retângulo (parâmetros l1 e l2 são os lados do retângulo)
float areaRetangulo(float l1, float l2)
{
    return l1 * l2;
}
//calcula a área do triângulo retângulo(parâmetro b = base e h = altura do triângulo retângulo)
float areaTriangulo (float b, float h)
{
    return b * h;
}

int main()
{   int op; //número inteiro que corresponde a um opção
    float lado; //lado do retângulo
    float lado1, lado2; //lados do retângulo
    float base, altura; //base e altura do triângulo retângulo
    printf("# Cálculo de área para figuras geométricas # \n");
    printf("#1 para área do quadrado \n#2 para área do retângulo \n#3 para área do triângulo\n");
    scanf("%i", &op);
    /*
    Este trecho não valida corretamente a entrada, pois se for digitado algo diferente de
    um número o código roda infinitamente até travar. Solução é colocar um default no switch case
    while (op < 1 || op > 3) 
    {   op = 0;
        printf("Valor inválido!!!\n");
        printf("# Cálculo de área para figuras geométricas # \n");
        printf("#1 para área do quadrado \n#2 para área do retângulo \n#3 para área do triângulo\n");
        scanf("%i", &op);
    }
    */
    switch (op)
    {
        case 1:
            printf("Digite um valor em cm correpondente ao lado do quadrado: ");
            scanf("%f", &lado);
            printf("A área do quadrado é %.2f cm².\n", areaQuadrado(lado));
            break;
        case 2:
            printf("Digite um valor em cm correpondente a um dos lados do retângulo: ");
            scanf("%f", &lado1);
            printf("Digite um valor em cm correpondente a o outro lado do retângulo: ");
            scanf("%f", &lado2);
            printf("A área do retângulo é %.2f cm².\n", areaRetangulo(lado1, lado2));
            break;
        case 3:
            printf("Digite um valor em cm correpondente a base do triângulo retângulo: ");
            scanf("%f", &base);
            printf("Digite um valor em cm correpondente a altura do triângulo retângulo: ");
            scanf("%f", &altura);
            printf("A área do triângulo retângulo é %.2f cm².\n", areaTriangulo(base, altura));
            break; 
        default:
            printf("Opção inválida!");
            break;
    }
    return 0;
}


