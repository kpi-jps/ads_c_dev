#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR 200
#define CPF 12

typedef struct node {
    int id;
    char cpf[CPF];
    char name[CHAR]; 
    char surname[CHAR];
    struct node *parent, *left, *right;
} node;

typedef struct data
{
    char cpf[CPF];
    char name[CHAR]; 
    char surname[CHAR];
} data;

//Creates the nodes used to build the tree. Receives as parameter a data struct containg some info (cpf, name and surname)
node* create_node(data data);
//Inserts a node to the tree. Receives as parameter the the root node of the tree and a id (used to identify and organize
// the node in the tree) and the data (tha)
node* insert_node(node *tree_node, int id, data data);
//Searches by a specific node using the node's id. Receives as parameter the root node and the node's id;
node* search_node(node *root_node, int data);


node* create_node(data data) {
    node *new_node = malloc(sizeof(node));
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    strcpy(new_node->cpf, data.cpf);
    strcpy(new_node->name, data.name);
    strcpy(new_node->surname, data.surname);
    return new_node;
} 

node* search_node(node *root_node, int data) {
    node *aux_p = root_node;
    while(aux_p != NULL && aux_p->id != data) 
        if(data < aux_p->id) aux_p = aux_p->left;
        else aux_p = aux_p->right;
    return aux_p; 
}

//fb(pai) = +2 e fb(nó) = +1
void left_rotation(node *tree_node) {
    node *aux_a = tree_node->parent->parent;
    node *aux_b = tree_node->parent;
    aux_a->right = aux_b->left;
    aux_b->left = aux_a;
}

//fb(pai) = -2 e fb(nó) = -1
void right_rotation(node *tree_node) {
    node *aux_a = tree_node->parent->parent;
    node *aux_b = tree_node->parent;
    aux_a->left = aux_b->right;
    aux_b->right = aux_a;
}

int calc_height(node *tree_node) {
    if(tree_node == NULL) return 0;
    int left_height = calc_height(tree_node->left);
    int right_height = calc_height(tree_node->right);
    if(right_height > left_height) return 1 + right_height;
    else return 1 + left_height;
}

int calc_balance_factor(node *tree_node) {
    if(tree_node == NULL) return 0;
    int left_height = calc_height(tree_node->left);
    int right_height = calc_height(tree_node->right);
    return right_height - left_height;
}

node* insert_node(node *root_node, int id, data data) {
    node *new_node = create_node(data);
    new_node->id = id;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    strcpy(new_node->cpf, data.cpf);
    strcpy(new_node->name, data.name);
    strcpy(new_node->surname, data.surname);
    if(root_node == NULL) {
        root_node = new_node;
    } else {
        node *aux_p1 = root_node;
        node *aux_p2;
        while (aux_p1 != NULL) {
            aux_p2 = aux_p1;
            if(id > aux_p1->id)  {
                aux_p1 = aux_p1->right;
                if(aux_p1 == NULL) {
                    aux_p2->right = new_node;
                    new_node->parent = aux_p2;
                }
            } else {
                aux_p1 = aux_p1->left;
                if(aux_p1 == NULL) {
                    aux_p2->left = new_node;
                    new_node->parent = aux_p2;
                }
            }
        }
        if(calc_balance_factor(new_node->parent->parent) == 2 && calc_balance_factor(new_node->parent) == 1)
            left_rotation(new_node);
        //checar fb
    }
    return root_node;
}

void print_node(node *tree_node) {
    printf("id: %d \n", tree_node->id);
    printf("Nome: %s\n", tree_node->name);
    printf("Sobrenome: %s\n", tree_node->surname);
    printf("bf: %d \n", calc_balance_factor(tree_node));
    //printf("bf pai: %d \n", calc_balance_factor(tree_node->parent));
    
    if(tree_node->parent != NULL)  printf("id do pai: %d\n", tree_node->parent->id);
    if(tree_node->right != NULL) printf("id direita: %d\n", tree_node->right->id);
    else printf("id direita: NULL \n");
    if(tree_node->left != NULL) printf("id esquerda: %d\n", tree_node->left->id);
    else printf("id esquerda: NULL \n");
    printf("-----------------\n");
    
}
void print_node_by_id(node *tree_node, int id) {
    node *aux_p = search_node(tree_node, id);
    if(aux_p != NULL) print_node(aux_p);
    else printf("Nó não existe!\n");
}



int main() {
    data person1;
    data person2;
    data person3;
    data person4;
    data person5;

    strcpy(person1.cpf, "11111111111");
    strcpy(person1.name, "Fulano");
    strcpy(person1.surname, "Silva");

    strcpy(person2.cpf, "22222222222");
    strcpy(person2.name, "Ciclano");
    strcpy(person2.surname, "Souza");

    strcpy(person3.cpf, "33333333333");
    strcpy(person3.name, "Beltrana");
    strcpy(person3.surname, "Leal");

    strcpy(person4.cpf, "44444444444");
    strcpy(person4.name, "Ciclana");
    strcpy(person4.surname, "Rodrigues");

    strcpy(person5.cpf, "55555555555");
    strcpy(person5.name, "Fulana");
    strcpy(person5.surname, "Seixas");

    node *avl_tree = NULL;

    avl_tree = insert_node(avl_tree, 0, person2);
    avl_tree = insert_node(avl_tree, 2, person3);
    avl_tree = insert_node(avl_tree, 10, person4);
    //avl_tree = insert_node(avl_tree, 1, person5);
    //avl_tree = insert_node(avl_tree, 5, person1);
    

    print_node_by_id(avl_tree, 0);
    print_node_by_id(avl_tree, 2);
    print_node_by_id(avl_tree, 10);
    print_node_by_id(avl_tree, 1);
    print_node_by_id(avl_tree, 5);    
    return 0;
}