#define SIZE 30

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int heap_parent(int i) {
	return (i-1)/2;
}

int heap_left(int i) {
	return 2*i+1;
}

int heap_right(int i) {
	return (2*i+1)+1;
}

void swap (int *a, int i, int j) {
	int aux;
	aux = a[i];
	a[i] = a[j];
	a[j] = aux;
}

void max_heapify(int *a, int i, int size) {
	int l, r, max;
	l = heap_left(i);
	r = heap_right(i);
	if (l < size && a[l] > a[i]) {
		max = l;
	} else {
		max = i;
	}
	if (r < size && a[r] > a[max]) {
		max = r;
	}
	if (max != i) {
		swap(a, i, max);
		max_heapify(a, max, size);
	}
}

void build_max_heap (int *a, int size) {
	int i;
	for (i=size/2-1; i >=0; i--) {
		max_heapify(a, i, size);
	}
}

void heapsort(int *a, int size) {
	int i,pos;
	build_max_heap(a, size);
	for (i = size-1; i>=2; i--) {
		swap(a, 0, i);
		max_heapify(a,0,i);
	}
	swap(a, 0, 1);
}

void init_vet(int *a) {
	int i;
	srand(time(NULL));
	for (i=0; i<SIZE; i++) {
		a[i] = i;
	}
	for (i=0; i<SIZE*2; i++) {
		swap(a, rand() % SIZE, rand()%SIZE);
	}
}

void print_vet(int *a) {
	int i;
	for (i=0; i<SIZE; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main(void) {
	int a[SIZE];
	init_vet(a);
	print_vet(a);
	heapsort(a, SIZE);
	print_vet(a);
	return EXIT_SUCCESS;
}
