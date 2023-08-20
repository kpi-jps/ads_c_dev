#include <stdio.h>
#include <stdlib.h>

//Definindo a "struct" que representará cada nó da árvore binária
typedef struct node {
    int data; //conteúdo do nó
    struct node* left, right, parent; //ponteiro para o nó filho da esquerda, direita e para o nó pai
    int bf; //"balance factor" fator de balanceamento do nó
} node;

//Função que cria um nó para a árvore e retorna um ponteiro para o mesmo. A função já insere informação no nó e 
//e seta como nulo os ponteiro para os nós da esquerda e direita, e define como 0 o fator de balanço para o nó
node* create_node(int data);


node* create_node(int data) {
    node* avl = malloc(sizeof(node));
    avl->bf = 0;
    avl->data = data;
    avl->left = NULL;
    avl->right = NULL;
    avl->parent = NULL;
    return avl;
}




int main() {
    return 0;
}