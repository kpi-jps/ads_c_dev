#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.c"

#define INPUT 100
#define TAM 100

//Inicia a matriz de adjacência (grafo)
void inicia_grafo(int grafo[TAM][TAM]);
//Insere um aresta no grafo
void insere_aresta(int grafo[TAM][TAM], int i, int j);
//Recebe um vetor de caracteres e o converte ao correspondente inteiro positivo. retornando
//o vetor como inteiro se a conversão é possível oi "-1" se não pe possível
int val_pos_int(char input[]);
//Procura por um número em um vetor, devolvendo 1 se o número foi encontrado e 0 se não
int checar_vetor(int vetor[], int tam, int n);
//Cadastra nova pessoa no sistema
int cadastrar(ArvAVL* avl, int id);
//Imprime todas as pessoas contidas pela árvore
int imprime_todos(ArvAVL* avl, int id);
//Cadastra amizades entre duas pessoas
void cadastra_amizade(int grafo[TAM][TAM], int controle_id);
//Imprime as informações dos amigos de uma pessoa com tal id
int imprimindo_amigos(ArvAVL* avl, int grafo[TAM][TAM], int id);
//Inicia o processo de impressão das informações deum amigo de uma dada pessoa
void amigos(ArvAVL* avl, int grafo[TAM][TAM]);
//Inicia o processo de impressão dos amigos dos amigos
void amigos_dos_amigos(ArvAVL* avl, int grafo[TAM][TAM]);

int main(){
    ArvAVL* avl; //árvore avl
    int grafo[TAM][TAM]; //grafo de adjacências
    int id = 0; //controla o id dos usuários
    int menu = 1; //controla o menu (1 = true)
    char op[INPUT]; //opção na forma de caracter
    int int_op; //opção na forma de inteiro
    
    avl = cria_ArvAVL();//cria a árvore
    inicia_grafo(grafo);//inicia o grafo

    //criando algumas pessoas
    data p0 = cria_pessoa("11111111111", "José", "Silva");
    data p1 = cria_pessoa("22222222222", "Maria", "Silva");
    data p2 = cria_pessoa("33333333333", "Cleide", "Souza");
    data p3 = cria_pessoa("44444444444", "Roberto", "Freitas");
    data p4 = cria_pessoa("55555555555", "Carlos", "Siqueira");
    data p5 = cria_pessoa("66666666666", "João", "Silva");
    data p6 = cria_pessoa("77777777777", "Fernanda", "Rodrigues");
    data p7 = cria_pessoa("88888888888", "Flavia", "Almeida");
    data p8 = cria_pessoa("99999999999", "Roberta", "Campos");
    data p9 = cria_pessoa("12345678911", "Célio", "Silva");
    
    //inserindo algumas pessoas na árvore
    insere_ArvAVL(avl, id++, p0);
    insere_ArvAVL(avl, id++, p1);
    insere_ArvAVL(avl, id++, p2);
    insere_ArvAVL(avl, id++, p3);
    insere_ArvAVL(avl, id++, p4);
    insere_ArvAVL(avl, id++, p5);
    insere_ArvAVL(avl, id++, p6);
    insere_ArvAVL(avl, id++, p7);
    insere_ArvAVL(avl, id++, p8);
    insere_ArvAVL(avl, id++, p9);

    //inserindo algumas amizades no grafo
    insere_aresta(grafo, 0, 5);
    insere_aresta(grafo, 2, 5);
    insere_aresta(grafo, 3, 4);
    insere_aresta(grafo, 6, 1);
    insere_aresta(grafo, 2, 1);
    insere_aresta(grafo, 6, 9);

    //criando menu
     while(menu) {
        printf("\n#Menu:\n");
        printf("[1] Cadastrar pessoa\n");
        printf("[2] Imprimir pessoas por ordem de ID\n");
        printf("[3] Cadastrar amizades\n");
        printf("[4] Imprimir amigos de uma pessoa\n");
        printf("[5] Imprimir amigos dos amigos de uma pessoa\n");
        printf("[6] Encerrar\n");
        printf("Escolha uma opção:\n");
        fgets(op, INPUT, stdin);
        int_op = val_pos_int(op);
        switch (int_op)
        {
        case 1:
            printf("\n\n");
            id = cadastrar(avl, id);
            break;
        case 2:
            printf("\n\n");
            imprime_todos(avl, id);
            break;
        case 3:
            printf("\n\n");
            cadastra_amizade(grafo, id);
            break;
        case 4:
            printf("\n\n");
            amigos(avl, grafo);
            break;
        case 5:
            printf("\n\n");
            amigos_dos_amigos(avl, grafo);
            break;
        case 6:
            printf("\n\n");
            printf("Aplicação encerrada!\n");
            menu = 0;
            libera_ArvAVL(avl);//Destroi a árvore
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    }
    return 0;
}

void inicia_grafo(int grafo[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for(int j = 0; j < TAM; j++) 
            grafo[i][j] = 0;
}

void insere_aresta(int grafo[TAM][TAM], int i, int j) {
    grafo[i][j] = 1;
    grafo[j][i] = 1;
}

int val_pos_int(char input[]) 
{   
    int check = 1;//true
    int i;
    for (i = 0; i < strlen(input)-1; i++) {
        if(input[i] < '0' || input[i] > '9')
        {
            check = 0;//false
        }
    }
    if(check) {
        return atoi(input);
    } else {
        return -1;
    }
}

int cadastrar(ArvAVL* avl, int id) {
    char cpf[CPF], nome[CHAR], sobrenome[CHAR];
    printf("Cadastrando pessoas\n");
    printf("Obs: Para cancelar a operação deixe qualquer um dos campos em branco e pressione \"ENTER\"!\n");
    printf("Entre com o CPF(apenas os 11 digitos):\n");
    fgets(cpf, CPF, stdin);
    if(strcmp(cpf, "\n") == 0) {
        printf("Operação cancelada!\n");
        return id;
    }
    cpf[strlen(cpf)-1] = ' ';
    printf("Entre com o nome:\n");
    fgets(nome, CHAR, stdin);
    if(strcmp(nome, "\n") == 0) {
        printf("Operação cancelada!\n");
        return id;
    }
    nome[strlen(nome)-1] = ' ';
    printf("Entre com o sobrenome:\n");
    fgets(sobrenome, CHAR, stdin);
    if(strcmp(sobrenome, "\n") == 0) {
            printf("Operação cancelada!\n");
            return id;
    }
    sobrenome[strlen(sobrenome)-1] = ' ';
    data p = cria_pessoa(cpf, nome, sobrenome);
    insere_ArvAVL(avl, id, p);
    printf("Pessoa cadastrada!\n");
    return ++id;
}

int imprime_todos(ArvAVL* avl, int id) {
    printf("Imprimindo todas as pessoas\n");
    for (int i = 0; i < id; i++) 
    {
        ArvAVL no = busca_ArvAVL(avl, i);
        imprime(no);
    }
}

void cadastra_amizade(int grafo[TAM][TAM], int controle_id){
    printf("Cadastrando amizades\n");
    printf("Obs: Para cancelar a operação deixe qualquer um dos campos em branco e pressione \"ENTER\"!\n");
    int id1 = -1, id2 = -1;
    char input[INPUT];
    while(id1 < 0) 
    {
        printf("Entre com o ID de uma pessoa: ");
        fgets(input, INPUT, stdin);
        if(strcmp(input, "\n") == 0) 
        {
            printf("Operação cancelada!\n");
            return;
        }
        id1 = val_pos_int(input);
        if(id1 == -1) printf("Valor inválido!\n");
        
    }
    while(id2 < 0) 
    {
        printf("Entre com o ID de uma pessoa outra pessoa: ");
        fgets(input, INPUT, stdin);
        if(strcmp(input, "\n") == 0) 
        {
            printf("Operação cancelada!\n");
            return;
        }
        id2 = val_pos_int(input);
        if(id2 == -1) printf("Valor inválido!\n");
    }
    if(id1 == id2)
    {
        printf("Os id's tem de ser diferentes!\n");
        return;
    } else if(id1 >= controle_id) {
        printf("Não há pessoa cadastrada com o id = %d\n", id1);
        return;
    } else if(id2 >= controle_id) {
        printf("Não há pessoa cadastrada com o id = %d\n", id2);
        return;
    }
    insere_aresta(grafo, id1, id2);
    printf("Amizade cadastrada!\n");
}

int imprimindo_amigos(ArvAVL* avl, int grafo[TAM][TAM], int id) 
{  

    int ids [TAM];
    int length = 0;
    for(int j = 0; j < TAM; j++) 
            if(grafo[id][j] == 1) ids[length++] = j;
    
    for (int i = 0; i < length; i++) 
    {
        ArvAVL no = busca_ArvAVL(avl, ids[i]);
        imprime(no);
    }
    return length;
}

void amigos(ArvAVL* avl, int grafo[TAM][TAM]) {
    printf("Imprimindo amigos de uma pessoa!\n");
    printf("Obs: Para cancelar a operação deixe qualquer um dos campos em branco e pressione \"ENTER\"!\n");
    int id = -1;
    char input[INPUT];
    int check = 0;
    while(id < 0) 
    {
        printf("Entre com o ID de uma pessoa: ");
        fgets(input, INPUT, stdin);
        if(strcmp(input, "\n") == 0) 
        {
            printf("Operação cancelada!\n");
            return;
        }
        id = val_pos_int(input);
        if(id == -1) printf("Valor inválido!\n");
    }
    if(id >= TAM) {
        printf("O id digitado é inválido!\n");
        return;
    }
    check = imprimindo_amigos(avl, grafo, id);
    if(check == 0) printf("A pessoa não tem amigos cadastrados!\n");
}

int checar_vetor(int vetor[], int tam, int n) {
    for (int i = 0; i < tam; i++) if(vetor[i] == n) return 1;
    return 0;
}

void amigos_dos_amigos(ArvAVL* avl, int grafo[TAM][TAM]) {
    printf("Imprimindo amigos dos amigos de uma pessoa!\n");
    printf("Obs: Para cancelar a operação deixe qualquer um dos campos em branco e pressione \"ENTER\"!\n");
    int id = -1;
    char input[INPUT];
    int lenght1 = 0;
    int ids1[TAM];//vetor com os ids dos amigos
    int lenght2 = 0;
    int ids2[TAM];//vetor com os ids dos amigos dos amigos
    while(id < 0) 
    {
        printf("Entre com o ID de uma pessoa: ");
        fgets(input, INPUT, stdin);
        if(strcmp(input, "\n") == 0) 
        {
            printf("Operação cancelada!\n");
            return;
        }
        id = val_pos_int(input);
        if(id == -1) printf("Valor inválido!\n");
    }
    if(id >= TAM) {
        printf("O id digitado é inválido!\n");
        return;
    }
    for (int i = 0; i < TAM;  i++) 
        if(grafo[id][i] == 1) ids1[lenght1++] = i;
    
    if(lenght1 == 0) {
        printf("A pessoa não tem amigos cadastrados!\n");
        return;
    }

    for (int i = 0; i < lenght1; i++) 
        for (int j = 0; j < TAM; j++)
            if(grafo[ids1[i]][j] == 1 && !checar_vetor(ids2, lenght2, j)) ids2[lenght2++] = j;
    
    for (int i = 0; i < lenght2; i++) {
        ArvAVL no = busca_ArvAVL(avl, ids2[i]);
        imprime(no);
    }

}


