#include <stdio.h>
#include <math.h>

/*
Escrever um programa que lê um conjunto de valores,
imprimindo, para cada valor: seu quadrado, seu cubo e sua raiz
quadrada. O conjunto é finalizado com o valor zero.
*/

void ex1() {
    int valor = 1;
    while (valor != 0) {
        printf("Digite um valor: ");
        scanf("%d", &valor);
        printf("Quadrado: %.2f, Cubo: %.2f, Raiz quadrara: %.2f\n", pow(valor,2), pow(valor, 3), sqrt(valor));
    }
}

/*
Escreva um programa que leia um número inteiro positivo e
mostre o seu fatorial.
*/

void ex2() {
    int numero, i;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);
    for (i=numero-1; i>0; i--) {
        numero = numero*i;
    }
    printf("Fatorial: %d.\n", numero);
}

/*
Escreva um programa que leia um número inteiro e indique se
o mesmo é primo ou não.
*/

void ex3() {
    int numero, i;
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);
    for (i=numero-1; i>1; i--) {
        if (numero % i == 0) break;
    }
    if (i>1) printf("O número não é primo!\n");
    else printf("O número é primo!\n");
}

/*
Aprimore o programa 3, para que ele imprima os 20 primeiros
números primos.
*/

void ex4() {
    int numero, i, count;
    numero = 2;
    count = 0;
    while (count < 20) {
        for (i=numero-1; i>1; i--) {
            if (numero % i == 0) break;
        }
        if (i==1) {
            printf("%d ", numero);
            count++;
        }
        numero++;
    }
}

/*
Escrever um programa que calcula e escreve o produto dos
números primos entre 92 e 1478
*/

void ex5() {
    int i;
    unsigned long long numero, produto;
    numero = 92;
    produto = 1;
    while (numero < 1478) {
        for (i=numero-1; i>1; i--) {
            if (numero % i == 0) break;
        }
        if (i==1) {
            printf("%llu - %llu\n", numero, produto);
            produto = produto * numero;
        }
        numero++;
    }
    //Mesmo com a maior variável inteira do C, não haverá espaço para guardar esse produto.
    printf("\nO produto é %llu\n", produto);
}

/*
Definir um programa que receba uma série de pares de
números, e para cada par calcule a média aritmética,
imprimindo o resultado. A série termina quando for lido o par
0,0.
*/

void ex6() {
    int i,j;
    i = j = 1;
    while (i != 0 && j != 0) {
        printf("Digite um par de números: ");
        scanf("%d %d", &i, &j);
        printf("A média dos números é %.2f\n", (i+j)/2.0f);
    }
}

/*
Ler m e escrever m linhas com i asteriscos alinhadas pela
esquerda, onde i corresponde ao número da linha corrente.
Exemplo: Para m=6 a saída do programa deve ser
 *
 **
 ***
 ****
 *****
 ******
 */

void ex7() {
    int m, i, j;
    printf("Digite um número: ");
    scanf("%d", &m);
    for (i=1; i<=m; i++) {
        for (j=0; j<i; j++)
            printf("*");
        printf("\n");
    }
}

/*
Chico tem 1,50 metro e cresce 2 centímetros por ano,
enquanto Zé tem 1,10 metro e cresce 3 centímetros por ano.
Construa um programa que calcule e imprima quantos anos
serão necessários para que Zé seja maior que Chico.
*/

void ex8() {
    float chico = 1.5f;
    float ze = 1.1f;
    float crescimento_chico = 0.02f;
    float crescimento_ze = 0.03f;
    int tempo = 0;
    while (ze <= chico) {
        chico+=crescimento_chico;
        ze+=crescimento_ze;
        tempo++;
    }
    printf("Serão necessários %d anos para que Zé seja maior que Chico.", tempo);
}

int main() {
    ex1();
    /*
    ex2();
    ex3();
    ex4();
    ex5();
    ex6();
    ex7();
    ex8();
    */
}
