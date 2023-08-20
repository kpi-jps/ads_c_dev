/******************************************************************************

Ex.3 Elabore um programa que manipule os dados para uma sala de 40 alunos. O
programa deve receber como entrada (via leitura de teclado):
- Os nomes dos alunos (máximo 50 caracteres).
- As duas notas parciais.
O programa deve calcular e imprimir, numa mesma linha, para cada aluno:
- O nome, a média final e a freqüência.
E também deve apresentar:
- A maior média da turma, e a menor média da turma.
- A quantidade de alunos aprovados, reprovados e em exame.
- Uma listagem com o nome dos alunos que irão para a final.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
    char nomes[40][50]; // 40 linhas e 50 coluna
    char nome[50];
    float notas[40][4]; //40 linhas e 4 colunas (coluna 1 nota1, coluna 2 nota2, coluna 3 média, coluna4 frequência)
    int i, j, k; //contadores
    
    //entrada de valores
    for (i = 0; i < 2; i++) 
    {
        printf("Entre com o nome do aluno %i: ", i+1);
        
        gets(nome);
        // transferindo a nome para nomes
        for (j = 0; j < 49; j++) 
        {
            nomes[i][j] = nome[j];
        }
        
        //nomes[i][50] = '\0';
        /*
        //limpado a variável nome
        for (k = 0; k < 49; k++) 
        {
            nome[k] = "";
        }
        */
        
        printf("Entre com a nota parcial 1: ");
        scanf("%f", &notas[i][0]);
        printf("Entre com a nota parcial 2: ");
        scanf("%f", &notas[i][1]);
        notas[i][2] = (notas[i][0] + notas[i][1])/2;
        printf("Entre com o percentual de frequência: ");
        scanf("%f", &notas[i][3]);
        getchar(); //limpa o buffer retira '\n'
    }
    
    //imprimindo nomes
    for (i = 0; i < 2; i++) 
    {
        for (j = 0; j < 49; j++) 
        {
           nome[j] = nomes[i][j]; 
           
        }
        printf("%s | nota 1: %.2f | nota 2: %.2f | média: %.2f | frequência: %.2f % \n", nome, notas[i][0], notas[i][1], notas[i][2], notas[i][3]);
        /*
        //limpado a variável nome
        for (k = 0; k < 49; k++) 
        {
            nome[k] = "";
        }
        */
    }

    return 0;
}







