//Teste função checaSeAnoBissexto(int ano)

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

//------------------------------------
//protótipo de funções
//------------------------------------
//Valida a entrada para núumeros inteiros positivos usando como parâmetro o entrada na forma
//de um vetor de caracteres, retornando o entrada na forma de um inteiro positivo, se todos os 
//caracteres digitados são números entre 0 e 9, ou retorna -1 se ao menos um dos caracteres 
//digitados não for um número entre 0 e 9
int validaInteiro(char num[]); 
//Checa se um ano é bissexto ou não, recebendo como parâmetro um inteiro de 4 dígitos representado 
//o ano, retornando 1 se o ano usado como parâmetro é bissexto, ou 0 se não.
int checaSeAnoBissexto(int ano);


int main()
{
    
    char ano[10];
    int n;
    printf("Entre com o ano usando 4 digítos: ");
    fgets(ano, 5, stdin);
    n = validaInteiro(ano);
    if (n == -1) 
    {
        printf("Valor inválido!");
    } else
    {
        if (checaSeAnoBissexto(n) == 0) 
        {
            printf("O %d não é ano bissexto!", n);
        } else
        {
            printf("O %d é ano bissexto!", n);
        }
        
    }
    return 0;
}

int checaSeAnoBissexto(int ano) 
{
    if (ano % 4 == 0) 
    {
        if (ano % 100 == 0) 
        {
            if (ano % 400 == 0) 
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        } else 
        {
            return 1;
        }
    } else 
    {
        return 0;
    }
}

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






