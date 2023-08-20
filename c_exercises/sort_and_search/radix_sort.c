#define SIZE 10
#define SIZE_PLACA 7
#define RANGE 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void countingsort(int *vetor, int tamanho, int R) {
	int *fp, *aux;
	int i, v;
	fp = calloc(R + 1, sizeof(int));
	aux = malloc(tamanho * sizeof(int));
	for (i = 0; i < tamanho; i++) {
		fp[vetor[i]+1]++;
	}
	for (i = 0; i < R; i++) {
		fp[i + 1] += fp[i];
	}
	for (i = 0; i < tamanho; i++) {
		v = vetor[i];
		aux[fp[v]] = v;
		fp[v]++;
	}
	for (i = 0; i < tamanho; i++) {
		vetor[i] = aux[i];
	}
	free(fp);
	free(aux);
}

void radixsort(char vetor[SIZE][SIZE_PLACA], int digitos, int tamanho) {
	int *fp, i, digito, range;
	char aux[SIZE][SIZE_PLACA], *v;
	range = 'Z' - '0';
	fp = malloc((range + 1) * sizeof(int));
	v = malloc(sizeof(char)*digitos);
	for (digito = digitos-1; digito >=0; digito--) {
		for (i=0; i<=range; i++) {
			fp[i] = 0;
		}
		for (i = 0; i < tamanho; i++) {
			fp[vetor[i][digito]-'0'+1]++;
		}
		for (i = 0; i < range; i++) {
			fp[i + 1] += fp[i];
		}
		for (i = 0; i < tamanho; i++) {
			strncpy(v, vetor[i],digitos);
			strncpy(aux[fp[v[digito]-'0']], v, digitos);
			fp[v[digito]-'0']++;
		}
		for (i = 0; i < tamanho; i++) {
			strncpy(vetor[i], aux[i], digitos);
		}
	}
	free(fp);
	free(v);
}

void print_vet(int *a) {
	int i;
	for (i = 0; i < SIZE; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void print_vet_placas(char vet[SIZE][SIZE_PLACA]) {
	int i,j;
	for (i = 0; i< SIZE; i++) {
		for (j=0; j<SIZE_PLACA; j++) {
			printf("%c", vet[i][j]);
		}
		printf("\n");
	}
}

void init_vet(int *a) {
	int i;
	srand(time(NULL));
	for (i = 0; i < SIZE; i++) {
		a[i] = rand() % RANGE;
	}
}

void init_vet_placas(char vet[SIZE][SIZE_PLACA]) {
	int i,j;
	srand(time(NULL));
	for (i=0; i < SIZE; i++) {
		for (j=0; j<SIZE_PLACA; j++) {
			if (j<3) {
				vet[i][j] = (char)('A' + rand()%('Z'-'A'));
			} else {
				vet[i][j] = (char)('0' + rand()%('9'-'0'));
			}
		}
	}
}

int main(void) {
	int a[SIZE];
	char b[SIZE][SIZE_PLACA];
	init_vet(a);
	print_vet(a);
	countingsort(a, SIZE, RANGE);
	print_vet(a);

	init_vet_placas(b);
	print_vet_placas(b);
	printf("-----------\n");
	radixsort(b,SIZE_PLACA, SIZE);
	print_vet_placas(b);
	return EXIT_SUCCESS;
}
