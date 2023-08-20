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

node *max_node(node *root_node) {
    node *aux_p = root_node;
    while(aux_p != NULL && aux_p->right != NULL) aux_p = aux_p->right;
    return aux_p;
    
}
/*
node* min_node(node *tree_node) {
    if(tree_node != NULL && tree_node->left != NULL) {
        tree_node = tree_node->left;
    }
}
*/
void destroy(node* tree_node) {

}

node* search_node(node *root_node, int data) {
    node *aux_p = root_node;
    while(aux_p != NULL && aux_p->id != data) 
        if(data < aux_p->id) aux_p = aux_p->left;
        else aux_p = aux_p->right;
    return aux_p; 
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
            if(aux_p1->parent == NULL) aux_p2 = aux_p1;
            else aux_p2 = aux_p1->parent;
            if(id > aux_p1->id)  {
                aux_p1 = aux_p1->right;
                if(aux_p1 == NULL) {
                    aux_p2->right = new_node;
                    new_node->parent = aux_p2->parent;
                }
            } else {
                aux_p1 = aux_p1->left;
                if(aux_p1 == NULL) {
                    aux_p2->left = new_node;
                    new_node->parent = aux_p2->parent;
                }
            }
        }
    }
    return root_node;
}
void print_node(node *tree_node) {
    printf("id: %d \n", tree_node->id);
    printf("Nome: %s\n", tree_node->name);
    printf("Sobrenome: %s\n", tree_node->surname);
}
void print_node_by_id(node *tree_node, int id) {
    node *aux_p = search_node(tree_node, id);
    if(aux_p != NULL) print_node(aux_p);
    else printf("Nó não existe!");
}

//o trabalho não pede remoção implementar depois
void remove_node(node *root_node, int id) {
    if(root_node != NULL) {
        node *aux_p1 = search_node(root_node, id);
        if(aux_p1 == NULL) return;
        if(aux_p1->parent->id > id){ //vai estar na direita
            if(aux_p1->right == NULL && aux_p1->left != NULL) {
                aux_p1->parent->right = aux_p1->left;
                aux_p1->left->parent = aux_p1->parent->right;
                free(aux_p1);
            }
            else if(aux_p1->right != NULL && aux_p1->left == NULL) {
                aux_p1->parent->right = aux_p1->right;
                aux_p1->right->parent = aux_p1->right;
                free(aux_p1);
            }          
            else if(aux_p1->right == NULL && aux_p1->left == NULL) {
                aux_p1->parent->right = NULL;
                free(aux_p1);
            }
            else { //tem que achar o sucessor
                node *aux_p2 = NULL;
                int i = 1;
                while (aux_p2 == NULL) aux_p2 = search_node(root_node, id+(i++));
                aux_p1->parent->right = aux_p2;
                aux_p2->parent = aux_p1->parent->right;


            } 
            
            
            
        } else { //vai estar na esquerda

        }
    }
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

    avl_tree = insert_node(avl_tree, 1, person2);
    avl_tree = insert_node(avl_tree, 3, person3);
    avl_tree = insert_node(avl_tree, 0, person4);
    avl_tree = insert_node(avl_tree, 2, person5);
    avl_tree = insert_node(avl_tree, 4, person1);
    

    print_node_by_id(avl_tree, 2);
    print_node_by_id(avl_tree, 4);
    print_node_by_id(avl_tree, 0);
    print_node_by_id(avl_tree, 1);
    print_node_by_id(avl_tree, 3);    
    return 0;
}