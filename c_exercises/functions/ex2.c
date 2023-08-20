/******************************************************************************

Ex. 2 - Criar um programa capaz de calcular o tempo entre
dois horários quaisquer de um determinado dia.
– O programa deve ler dois horários, compostos por três
números inteiros, representando horas, minutos e
segundos. O programa deve verificar se o horário é
válido(horas entre 0 e 23, minutos entre 0 e 59, e
segundos entre 00 e 59).
– O programa deve ter uma função para calcular a
quantidade de segundos em um horário, e outra função
para calcular e imprimir a quantidade de horas, minutos
e segundos em uma quantidade de segundos;
*******************************************************************************/
#include <stdio.h>

//Calcula e retorna os segundos correspondetes ao um determinado horário 
//informado como hh:mm:ss. Recebe como parâmetros:
//th = tempo em horas (hh) e varia entre 0 e 23
//tm = tempo em minutos (mm) e varia entre 0 e 59
//ts = tempo em segundos (ss) e varia entre 0 e 59
int calcSegundos(int th, int tm, int ts) 
{
    return (th * 3600) + (tm * 60) + ts;
}
//Transforma segundos para o formato hh:mm:ss e imprime o resultado. 
//Usa como parâmetro o valor dos segundos (ts)
void calcHorario (int ts) 
{
    int h, m, s;
    h = (ts - (ts%3600))/3600;
    m = ((ts - h*3600) - ((ts - h*3600)%60))/60;
    s = ts - h*3600 - m*60;
    printf("%i s é igual a ", ts);
    if (h < 10) 
    {
        printf("0%i:", h); 
    }
    else 
    {
        printf("%i:", h);
    }
    if (m < 10)
    {
        printf("0%i:", m);
    }
    else 
    {
        printf("%i:", m);
    }
    if (s < 10)
    {
        printf("0%i", s);
    }
    else 
    {
        printf("%i", s);
    }
   
}


int main()
{
    
    int hora1, hora2, min1, min2, seg1, seg2, t1, t2, difT;
    printf("Digite as informações do primeiro horário\n");
    printf("Entre com o valor das horas: ");
    scanf("%i", &hora1);
    while (hora1 < 0 || hora1 > 23)
    {
        printf("Valor inválido!\n");
        printf("Entre com o valor das horas: ");
        scanf("%i", &hora1);
    }
    printf("Entre com o valor dos minutos: ");
    scanf("%i", &min1);
    while (min1 < 0 || min1 > 60)
    {   
        printf("Valor inválido!\n");
        printf("Entre com o valor dos minutos: ");
        scanf("%i", &min1);
    }
    printf("Entre com o valor dos segundos: ");
    scanf("%i", &seg1);
    while (seg1 < 0 || seg1 > 60)
    {   
        printf("Valor inválido!\n");
        printf("Entre com o valor dos segundos: ");
        scanf("%i", &seg1);
    }
    printf("Digite as informações do primeiro horário\n");
    printf("Entre com o valor das horas: ");
    scanf("%i", &hora2);
    while (hora2 < 0 || hora2 > 23)
    {
        printf("Valor inválido!\n");
        printf("Entre com o valor das horas: ");
        scanf("%i", &hora2);
    }
    printf("Entre com o valor dos minutos: ");
    scanf("%i", &min2);
    while (min2 < 0 || min2 > 60)
    {   
        printf("Valor inválido!\n");
        printf("Entre com o valor dos minutos: ");
        scanf("%i", &min2);
    }
    printf("Entre com o valor dos segundos: ");
    scanf("%i", &seg2);
    while (seg2 < 0 || seg2 > 60)
    {   
        printf("Valor inválido!\n");
        printf("Entre com o valor dos segundos: ");
        scanf("%i", &seg2);
    }
    t1 = calcSegundos(hora1, min1, seg1);
    t2 = calcSegundos(hora2, min2, seg2);
    if (t1 > t2)
    {
        difT = t1 - t2;
    }
    else 
    {
        difT = t2 - t1;
    }
    printf("%i", difT%3600);
    calcHorario (difT);
    return 0;
}




