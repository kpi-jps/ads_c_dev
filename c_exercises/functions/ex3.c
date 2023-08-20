/******************************************************************************

Ex.3 - Criar um programa capaz de ler duas notas de cada
um dos 10 alunos de uma turma, calculando a média
geral da primeira e da segunda prova. Em seguida,
informe quantos alunos tiraram notas acima da média,
tanto na primeira como na segunda prova.
*******************************************************************************/
#include <stdio.h>

float calcMedia (int quantNotas, int numAlunos, float vetorNotas[numAlunos][quantNotas]) 
{
    int i, j; //variáveis de controle
    float media;
    float medias [quantNotas]; //medias das provas 
    for (i = 0; i < quantNotas; i++) 
    {
        for (j = 0; j < numAlunos; j++) 
        {
            media += (vetorNotas[j][i] / numAlunos);  
        }
        medias[i] = media;
    }
    //return medias;
}
int main()
{   
    int i, j; //variáveis de controle
    int alunos = 2; //são 10 alunos
    int notas = 2; //são duas notas por alunos
    float nota; //recebe o valor de uma nota
    float listaNotas[alunos][notas]; //vetor com as notas dos alunos
    for (i = 0; i < alunos; i++) 
    {
        
        for (j = 0; j < notas; j++) 
        {
            printf("Entre com a nota %i do aluno %i:", j+1, i+1);
            scanf("%f", &nota);
            while (nota < 0 || nota > 10) 
            {
                printf("Valor inválido!");
                printf("Entre com a nota %i do aluno %i:", j+1, i+1);
                scanf("%f", &nota);
            }
            listaNotas[i][j] = nota;
        }
    }
    
    
    printf("%f", listaNotas[0][0]);

    return 0;
}


