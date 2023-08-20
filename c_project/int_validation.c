//Teste função validaInteiro(char nun[ ])

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

//Valida a entrada para números inteiros positivos, recebendo como parâmetro um
//vetor de caracteres. Se os caracteres digitados correspondem a um inteiro positivo
//retorna o inteiro digitado, caso não retorna -1

int validaInteiro(char num[]) 
{ 
    int checagem = 1; //variável de checagem (1 = true, 0 = false)
    int i;
    //Como a inserção da string termina com a tecla "enter" a função "fgets" adiciona ao final da string
    //o caracter '\n', o que ocasiona mal funcionamento da função, o que pode ser evitado usando como final para
    //o laço "for" strlen(string) - 1. Isso evita o acesso ao último caracter da string, que no caso é '\n'. 
    for (i = 0; i < strlen(num) - 1; i++) 
    {
        if (num[i] < '0' || num[i] > '9') 
        {
            checagem = 0;
        }
    }
    if (checagem == 1) 
    {
        return atoi(num); //converte os caracteres de num[] para inteiro
    } else
    {
        return -1;
    }
}


int main()
{
    
    char numero[1024];
    int n;
    printf("Entre com o valor de um inteiro: ");
    fgets(numero, 1024, stdin);
    n = validaInteiro(numero);
    if (n == -1) 
    {
        printf("Valor inválido!");
    } else
    {
        printf("O inteiro digitado é igual a %d", n);
    }
    return 0;
}







