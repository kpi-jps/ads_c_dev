/* Elabore um programa para ler as notas dos 22 alunos
da turma, calcule a média da turma, e calcule também
quantos alunos tiveram notas abaixo da média, e quantos
tiveram notas acima da média.
*/
#define ALUNOS 5

#include <stdio.h>

int main() {
    int notas[ALUNOS];
    double media = 0;
    int abaixo_media = 0;
    int acima_media = 0;
    int i;
    for (i=0; i<ALUNOS; i++) {
        printf("Digite a nota do aluno %d: ", i);
        scanf("%d", &notas[i]);
        media+=notas[i];
    }

    media=media/ALUNOS;

    for (i=0; i<ALUNOS; i++) {
        if (notas[i] < media) abaixo_media++;
        if (notas[i] > media) acima_media++;
    }

    printf("Media: %.2f\n", media);
    printf("Alunos abaixo da media: %d\n", abaixo_media);
    printf("Alunos acima da media: %d\n", acima_media);

}
