//Teste função checaSeAnoBissexto(int ano)

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

//------------------------------------
//protótipo de funções
//------------------------------------
//Valida a entrada para números inteiros positivos usando como parâmetro a entrada na forma
//de um vetor de caracteres. Retorna a entrada na forma de um inteiro positivo se todos os 
//caracteres digitados são números entre 0 e 9, ou retorna -1 se ao menos um dos caracteres 
//digitados não for um número entre 0 e 9.
int validaInteiro(char num[]); 
//Checa se um ano é bissexto ou não recebendo como parâmetro um inteiro representado 
//o ano. Retorna 1 se o ano usado como parâmetro é bissexto, ou 0 se não.
int checaSeAnoBissexto(int ano);
//Checa se um data é válida, usando como parâmetro inteiros para o dia, mês e ano. Retorna 
//1 se a data for válida e 0 se não
int validaData(int dia, int mes, int ano);

int main()
{
    
    char ano[10], mes[10], dia[10];
    int d, m, a; //dia (d), mês (m), ano (a)
    printf("Entre com o dia: ");
    fgets(dia, 10, stdin);
    printf("Entre com o mês: ");
    fgets(mes, 10, stdin);
    printf("Entre com o ano usando 4 digítos: ");
    fgets(ano, 10, stdin);
    d = validaInteiro(dia);
    m = validaInteiro(mes);
    a = validaInteiro(ano);
    if (d == -1 || m == -1 || a == -1 ) 
    {
        printf("Valores digitados inválidos!");
    } else
    {
        if (validaData(d, m, a) == 0) 
        {
            printf("Data inválida");
        } else
        {
            printf("A data digitada foi %d/%d/%d", d, m, a);
        }
        
    }
    
    return 0;
}

int validaData(int dia, int mes, int ano) 
{
    if (ano <= 0 || dia <= 0 || dia > 31 || mes <= 0 || mes > 12) 
    {
        return 0;
    } else  
    {
        if (mes == 2) 
        {
            if (checaSeAnoBissexto(ano) == 1) 
            {
                if (dia > 29) 
                {
                    return 0;
                } else 
                {
                    return 1;
                }
            } else 
            {
                if (dia > 28) 
                {
                    return 0;
                } else 
                {
                    return 1;
                }
            }
        } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) 
        {
            if (dia > 30) 
                {
                    return 0;
                } else 
                {
                    return 1;
                }  
        } else 
        {
           return 1; 
        }
    }   
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









