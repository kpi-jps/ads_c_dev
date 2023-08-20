//IFSP Campus São Carlos
//Aluno: João Pedro da Silva

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR 200
#define CPF 12

//estrutura que armazena as inmações das pessoas
typedef struct data
{
   char cpf[12];
   char nome[200]; 
   char sobrenome[200]; 
} data;


//Define a "struct" que representa cada nó da arvore AVL
struct NO{
    int id;//armazena o idrmção no nó
    struct data pessoa;
    int altura; //armazena a altura dos ramos do nó
    struct NO *esq;//armazena o endereço do memória do nó da esquerda
    struct NO *dir;//armazena o endereço de memória do nó da direita
};

//Nomeando o tipo de váriavel que define o nó como "ArvAVL"
typedef struct NO* ArvAVL;

//Prótótipo das funções
//Funções já existentes
ArvAVL* cria_ArvAVL();//Função que cria o nó raiz da arvore
void libera_ArvAVL(ArvAVL *raiz); //Função que destrói a árvore
int remove_ArvAVL(ArvAVL *raiz, int valor);//Remove um nó da árvore
int estaVazia_ArvAVL(ArvAVL *raiz);//Checa se a árvore está vazia
int altura_ArvAVL(ArvAVL *raiz);//Calcula a altura da árvore
int totalNO_ArvAVL(ArvAVL *raiz);//Calcula o total de nós da árvore
int consulta_ArvAVL(ArvAVL *raiz, int valor);//Consulta de o valor passado como parâmetro existe na árvore
void preOrdem_ArvAVL(ArvAVL *raiz);//Imprime idrmações sobre a árvore
void emOrdem_ArvAVL(ArvAVL *raiz);//Imprime idrmações sobre a árvore
void posOrdem_ArvAVL(ArvAVL *raiz);//Imprime idrmações sobre a árvore

//Função adaptada para o trabalho
int insere_ArvAVL(ArvAVL *raiz, int id, data pessoa);//Insere um novo nó na árvore

//Funções criadas por mim
data cria_pessoa(char cpf[CPF], char nome[CHAR], char sobrenome[CHAR]); //Cria uma pessoas para inserir na árvore
struct NO *busca_ArvAVL(ArvAVL *raiz, int id);//Busca por um nó na árvore
void imprime(struct NO *no);//Imprime os dados armazenados em um nó da árvore

//Cria o nó raiz da arvore e retorna seu endereço
ArvAVL* cria_ArvAVL(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL)); //cria e aloca memória para o nó
    if(raiz != NULL)//certificando que o nó tenha valor NULL
        *raiz = NULL;
    return raiz;//retorna o endereço do nó raiz
}
//Função que libera recursivamente cada nó da árvore
void libera_NO(struct NO* no){
    if(no == NULL) //condição de para da recursão
        return;
    libera_NO(no->esq);//uso recursivo da função
    libera_NO(no->dir);//uso recursivo da função
    free(no);//desalocando memória do nó
    no = NULL;
}
//Função que destrói a árvore 
void libera_ArvAVL(ArvAVL* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó recursivamente
    free(raiz);//libera mémoria alocada para a árvore
}

//Retorna a altura dos ramos do nó passado como parâmetro ou -1 se o nó for um nó folha
int altura_NO(struct NO* no){
    if(no == NULL)
        return -1;
    else
    return no->altura;
}

//Calcula o fator de balanceamento do nó passado como parâmetro
int fatorBalanceamento_NO(struct NO* no){
    return labs(altura_NO(no->esq) - altura_NO(no->dir)); //retorna um valor absoluto para a operação
}

//Retorna o valor maior entre dois inteiros
int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}
//Verifica se a árvore está vazia, retornando 1 (true) se sim e 0 (false) se não
int estaVazia_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}
//Retorna a quantidade de nós na árvore usando recursão
int totalNO_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL) //condição da parada da recursão 
        return 0;
    if (*raiz == NULL) //condição da parada da recursão 
        return 0;
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}
//Retorna a altura da arvoré usando recursão
int altura_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL) //condição da parada da recursão 
        return 0;
    if (*raiz == NULL) //condição da parada da recursão 
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if (alt_esq > alt_dir) //checando qual ramo será usado na determinação da altura, sempre utiliza o maior
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}
//Imprime recursivamente idrmações sobre a árvore
void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL) //condição de parada da recurção, que é encontrar um nó folha
        return;
    if(*raiz != NULL){
        //printf("%d\n",(*raiz)->id);
        //printf("No %d: %d\n",(*raiz)->id,fatorBalanceamento_NO(*raiz));
        printf("No %d: %d\n",(*raiz)->id,altura_NO(*raiz));
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}
//Imprime recursivamente idrmações sobre a árvore
void emOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL) //condição de parada da recurção, que é encontrar um nó folha
        return;
    if(*raiz != NULL){
        emOrdem_ArvAVL(&((*raiz)->esq));
        //printf("%d\n",(*raiz)->id);
        printf("No %d: H(%d) fb(%d)\n",(*raiz)->id,altura_NO(*raiz),fatorBalanceamento_NO(*raiz));
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}
//Imprime recursivamente idrmações sobre a árvore
void posOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL) //condição de parada da recurção, que é encontrar um nó folha
        return;
    if(*raiz != NULL){
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("%d\n",(*raiz)->id);
    }
}
//Função consulta se existe um determinado valor armazenado na árvore, retornando 1 (true) se sim e 0 (false) se não
int consulta_ArvAVL(ArvAVL *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->id){
            return 1;
        }
        if(valor > atual->id)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

//Função realiza rotação simples à direita e atualiza o valor da altura dos ramos nos nós afetados
void RotacaoLL(ArvAVL *A){//LL
    //printf("RotacaoLL\n");
    struct NO *B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;//redefindo a altura dos ramos após rotação
    B->altura = maior(altura_NO(B->esq),(*A)->altura) + 1;//redefindo a altura dos ramos após rotação
    *A = B;
}
//Função realiza rotação simples à esquerda e atualiza o valor da altura dos ramos nos nós afetados
void RotacaoRR(ArvAVL *A){//RR
    //printf("RotacaoRR\n");
    struct NO *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;//redefindo a altura dos ramos após rotação
    B->altura = maior(altura_NO(B->dir),(*A)->altura) + 1;//redefindo a altura dos ramos após rotação
    (*A) = B;
}
//Função realiza uma rotação dupla, iniciada por uma rotação simples à esquerda e seguida por uma rotação simples a direita
void RotacaoLR(ArvAVL *A){//LR
    RotacaoRR(&(*A)->esq);
    RotacaoLL(A);
}
//Função realiza uma rotação dupla, iniciada por uma rotação simples à direita e seguida por uma rotação simples a esquerda
void RotacaoRL(ArvAVL *A){//RL
    RotacaoLL(&(*A)->dir);
    RotacaoRR(A);
}
//Insere um novo nó na árvore recursivamente, já checando e realizando rotações quando necessário e retornando
//1(true) quando a inserção ocorrer e 0 (false) quando não ocorrer
int insere_ArvAVL(ArvAVL *raiz, int id, data pessoa){
    int res; //armazena o resultado da inserção
    //Bloco de código executado se árvore vazia ou se o nó for um nó folha
    if(*raiz == NULL){//Se árvore vazia ou nó folha (condição de parada para a recursão)
        struct NO *novo; //Instancia novo nó
        novo = (struct NO*)malloc(sizeof(struct NO));//aloca memória para o novo nó
        if(novo == NULL) //checa de o novo nó aponta para NULL, se sim retorna 0
            return 0;

        novo->id = id;//armazena a idrmação no nó
        novo->pessoa = pessoa;
        novo->altura = 0;//define altura para um nó folha como 0
        novo->esq = NULL;//como é nó folha, ponteiro tem que apontar para NULL
        novo->dir = NULL;//como é nó folha, ponteiro tem que apontar para NULL
        *raiz = novo;//faz a raiz apontar para o nó inserido
        return 1;
    }
    //Blocos executados quando a árvore não está vazia ou quando não se trata de um nó folha
    struct NO *atual = *raiz;//instanciando um novo nó e fazendo o mesmo apontar para a o nó passado como parâmetro
    if(id < atual->id){//se o valor a ser inserido for menor que o valor armazenado pelo nó atual, insere o valor nó filho a esquerda
        if((res = insere_ArvAVL(&(atual->esq), id, pessoa)) == 1){//insere recursivamente novo valor e checa se inserção ocorre
            if(fatorBalanceamento_NO(atual) >= 2){//se a inserção ocorreu, checa balenceamento do nó, se maior que 2 realiza rotações adequadas
                if(id < (*raiz)->esq->id ){
                    RotacaoLL(raiz);//roração simples à direita
                }else{
                    RotacaoLR(raiz);//rotação dupla iniciada por rotação simples à direita e seguida por rotaçao simples à esquerda
                }
            }
        }
    }else{
        if(id > atual->id){//se o valor a ser inserido for maior que o valor armazenado pelo nó atual, insere o valor nó filho a direita
            if((res = insere_ArvAVL(&(atual->dir), id, pessoa)) == 1){//insere recursivamente novo valor e checa se inserção ocorre
                if(fatorBalanceamento_NO(atual) >= 2){//se a inserção ocorreu, checa balenceamento do nó, se maior que 2 realiza rotações adequadas
                    if((*raiz)->dir->id < id){
                        RotacaoRR(raiz);//roração simples à esquerda
                    }else{
                        RotacaoRL(raiz);//rotação dupla iniciada por rotação simples à esquerda e seguida por rotaçao simples à direita
                    }
                }
            }
        }else{//caso o valor a ser inserido já existir na árvore imprime mensagem
            printf("Valor duplicado!!\n");
            return 0;
        }
    }

    atual->altura = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;//recalculando a altura da subarvore ligado ao nó

    return res;//retornando o valor de checagem para inserção do novo nó
}
//Procurando pelo nó folha à esquerda mais próximo do nó passado como parâmetro
struct NO* procuraMenor(struct NO* atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}
//Remove recursivamente nós da árvore
int remove_ArvAVL(ArvAVL *raiz, int valor){
    //checa se o nó passado como parâmetro aponta para NULL, retornado 0 (false) e imprimindo mensagem
	if(*raiz == NULL){// valor não existe
	    printf("valor n�o existe!!\n");
	    return 0;
	}

    int res; //armazena resultado da remoção
	if(valor < (*raiz)->id){//se valor menor que o valor do nó passado como parâmetro executa este bloco de código
	    if((res = remove_ArvAVL(&(*raiz)->esq,valor)) == 1){//se operação de remoção retorna 1, elemento foi removido
            if(fatorBalanceamento_NO(*raiz) >= 2){//se o fator de balanceamento foi alterado para valor igual ou maior que 2 rotações adequadas serão realizadas
                if(altura_NO((*raiz)->dir->esq) <= altura_NO((*raiz)->dir->dir)) //checando se ramo da esquerda é maior ou igual ao ramo da direita
                    RotacaoRR(raiz);//se sim realiza rotação simples à esquerda
                else
                    RotacaoRL(raiz);//se não realiza rotação dupla iniciada por rotação simples à esquerda seguida por rotação simples à direita
            }
	    }
	}

	if((*raiz)->id < valor){//se valor maior que o valor do nó passado como parâmetro executa este bloco de código
	    if((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1){ //se operação de remoção retorna 1, elemento foi removido
            if(fatorBalanceamento_NO(*raiz) >= 2){//se o fator de balanceamento foi alterado para valor igual ou maior que 2 rotações adequadas serão realizadas
                if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq) )//checando se ramo da direita é maior ou igual ao ramo da esquerda
                    RotacaoLL(raiz);//se sim realiza rotação simples à direita
                else
                    RotacaoLR(raiz);//se não realiza rotação dupla iniciada por rotação simples à direita seguida por rotação simples à esquerda
            }
	    }
	}

	if((*raiz)->id == valor){//valor a ser removido foi encontrado
	    if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)){// nó tem 1 filho ou nenhum
			struct NO *oldNode = (*raiz);//utilizando uma variável auxiliar para armazernar o nó 
			//fazendo o nó apontar para novo valor, dependendo dos nós apontados à esquerda e a direita
            if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
			free(oldNode); //liberando variável auxiliar da memória
		}else { // nó tem 2 filhos
			struct NO* temp = procuraMenor((*raiz)->dir);//procurando pelo nó folha mais próximo do nó a direita do nó passado como parâmetro
			(*raiz)->id = temp->id;//troca os valores entre o nó passado como parâmetro e o nó folha encontrado
			remove_ArvAVL(&(*raiz)->dir, (*raiz)->id);//remove o nó a direita do nó passado como parâmetro
            if(fatorBalanceamento_NO(*raiz) >= 2){//recalcula o fator de balanceamento e faz rotações necessarias se o novo valor de balanceamento for maior oi igual a 2
				if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq))//define quais tipos de rotação serão necessárias
					RotacaoLL(raiz);//faz uma rotção simples a direita
				else
					RotacaoLR(raiz);//faz uma rotaçao duplas iniciada por rotação simples à direita, seguida por rotação simples à esquerda
			}
		}
		if (*raiz != NULL) //se o nó passado como parâmetro se manter diferente de NULL recalcula a altuta da subarvore e retorna 1
            (*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;
		return 1;
	}

	(*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1; //recalculando a altura da subarvore ligada ao nó

	return res;//retornando o valor de checagem da operação
}

data cria_pessoa(char cpf[CPF], char nome[CHAR], char sobrenome[CHAR]) {
    data pessoa;
    strcpy(pessoa.cpf, cpf);
    strcpy(pessoa.nome, nome);
    strcpy(pessoa.sobrenome, sobrenome);
    return pessoa;
}

struct NO *busca_ArvAVL(ArvAVL *raiz, int id){
    if(raiz == NULL)
        return NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(id == atual->id){
            return atual;
        }
        if(id > atual->id)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return NULL;
}

void imprime(struct NO *no) {
    printf("id: %d \n",no->id);
    printf("Nome: %s\n", no->pessoa.nome);
    printf("Sobrenome: %s\n", no->pessoa.sobrenome);
    if(no->dir != NULL) printf("id direita: %d\n", no->dir->id);
    else printf("id direita: NULL \n");
    if(no->esq != NULL) printf("id esquerda: %d\n", no->esq->id);
    else printf("id esquerda: NULL \n");
    printf("-----------------\n");

}
