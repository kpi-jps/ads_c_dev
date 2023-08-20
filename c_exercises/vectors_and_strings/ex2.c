/******************************************************************************

Ex2- Elabore um programa para ler as notas dos 22 alunos
da turma, calcule a média da turma, e calcule também
quantos alunos tiveram notas abaixo da média, e quantos
tiveram notas acima da média.
*******************************************************************************/
#include <stdio.h>

int main()
{
    float notas[22], media = 0;
    int i, alunos = 0;
    for (i = 0; i < 22; i++) 
    {
        printf("Entre com a notas do aluno %i: ", i+1);
        scanf("%f", &notas[i]);
    }
    
    for (i = 0; i < 22; i++) 
    {
        media += notas[i];
    
    }
    
    media /= (i+1);
    
    for (i = 0; i < 22; i++) 
    {
        if (notas[i] < media)
        {
            alunos++;
        }
    }
     
    
    printf("A média da turma é %.2f. \n", media);
    printf("%i aluno(s) obtiveram média menor que %.2f \n", alunos, media);
    printf("%i alunos(s) obtiveram média maior que %.2f ", i + 1 - alunos, media);
    
    return 0;
}
