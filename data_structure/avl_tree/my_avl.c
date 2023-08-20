//IFSP Campus São Carlos
//Estrutura de Dados
//EAD Árvores AVL
//Aluno: João Pedro da Silva

#include <stdio.h>
#include <stdlib.h>

//Define a "struct" que representa cada nó da arvore AVL
struct NO{
    int info;//armazena o informção no nó
    int altura;//armazena a altura dos ramos do nó
    struct NO *esq;//armazena o endereço do memória do nó da esquerda
    struct NO *dir;//armazena o endereço de memória do nó da direita
};

//Nomeando o tipo de váriavel que define o nó como "ArvAVL"
typedef struct NO* ArvAVL;

//Prótótipo das funções
ArvAVL* cria_ArvAVL();//Função que cria o nó raiz da arvore
void libera_ArvAVL(ArvAVL *raiz); //Função que destrói a árvore
int insere_ArvAVL(ArvAVL *raiz, int data);//Insere um novo nó na árvore
int remove_ArvAVL(ArvAVL *raiz, int valor);//Remove um nó da árvore
int estaVazia_ArvAVL(ArvAVL *raiz);//Checa se a árvore está vazia
int altura_ArvAVL(ArvAVL *raiz);//Calcula a altura da árvore
int totalNO_ArvAVL(ArvAVL *raiz);//Calcula o total de nós da árvore
int consulta_ArvAVL(ArvAVL *raiz, int valor);//Consulta de o valor passado como parâmetro existe na árvore
void preOrdem_ArvAVL(ArvAVL *raiz);//Imprime informações sobre a árvore
void emOrdem_ArvAVL(ArvAVL *raiz);//Imprime informações sobre a árvore
void posOrdem_ArvAVL(ArvAVL *raiz);//Imprime informações sobre a árvore

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
//Imprime recursivamente informações sobre a árvore
void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL) //condição de parada da recurção, que é encontrar um nó folha
        return;
    if(*raiz != NULL){
        //printf("%d\n",(*raiz)->info);
        //printf("No %d: %d\n",(*raiz)->info,fatorBalanceamento_NO(*raiz));
        printf("No %d: %d\n",(*raiz)->info,altura_NO(*raiz));
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}
//Imprime recursivamente informações sobre a árvore
void emOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL) //condição de parada da recurção, que é encontrar um nó folha
        return;
    if(*raiz != NULL){
        emOrdem_ArvAVL(&((*raiz)->esq));
        //printf("%d\n",(*raiz)->info);
        printf("No %d: H(%d) fb(%d)\n",(*raiz)->info,altura_NO(*raiz),fatorBalanceamento_NO(*raiz));
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}
//Imprime recursivamente informações sobre a árvore
void posOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL) //condição de parada da recurção, que é encontrar um nó folha
        return;
    if(*raiz != NULL){
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
    }
}
//Função consulta se existe um determinado valor armazenado na árvore, retornando 1 (true) se sim e 0 (false) se não
int consulta_ArvAVL(ArvAVL *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

//Função realiza rotação simples à direita e atualiza o valor da altura dos ramos nos nós afetados
void RotacaoLL(ArvAVL *A){//LL
    printf("RotacaoLL\n");
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
    printf("RotacaoRR\n");
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
int insere_ArvAVL(ArvAVL *raiz, int valor){
    int res; //armazena o resultado da inserção
    //Bloco de código executado se árvore vazia ou se o nó for um nó folha
    if(*raiz == NULL){//Se árvore vazia ou nó folha (condição de parada para a recursão)
        struct NO *novo; //Instancia novo nó
        novo = (struct NO*)malloc(sizeof(struct NO));//aloca memória para o novo nó
        if(novo == NULL) //checa de o novo nó aponta para NULL, se sim retorna 0
            return 0;

        novo->info = valor;//armazena a informação no nó
        novo->altura = 0;//define altura para um nó folha como 0
        novo->esq = NULL;//como é nó folha, ponteiro tem que apontar para NULL
        novo->dir = NULL;//como é nó folha, ponteiro tem que apontar para NULL
        *raiz = novo;//faz a raiz apontar para o nó inserido
        return 1;
    }
    //Blocos executados quando a árvore não está vazia ou quando não se trata de um nó folha
    struct NO *atual = *raiz;//instanciando um novo nó e fazendo o mesmo apontar para a o nó passado como parâmetro
    if(valor < atual->info){//se o valor a ser inserido for menor que o valor armazenado pelo nó atual, insere o valor nó filho a esquerda
        if((res = insere_ArvAVL(&(atual->esq), valor)) == 1){//insere recursivamente novo valor e checa se inserção ocorre
            if(fatorBalanceamento_NO(atual) >= 2){//se a inserção ocorreu, checa balenceamento do nó, se maior que 2 realiza rotações adequadas
                if(valor < (*raiz)->esq->info ){
                    RotacaoLL(raiz);//roração simples à direita
                }else{
                    RotacaoLR(raiz);//rotação dupla iniciada por rotação simples à direita e seguida por rotaçao simples à esquerda
                }
            }
        }
    }else{
        if(valor > atual->info){//se o valor a ser inserido for maior que o valor armazenado pelo nó atual, insere o valor nó filho a direita
            if((res = insere_ArvAVL(&(atual->dir), valor)) == 1){//insere recursivamente novo valor e checa se inserção ocorre
                if(fatorBalanceamento_NO(atual) >= 2){//se a inserção ocorreu, checa balenceamento do nó, se maior que 2 realiza rotações adequadas
                    if((*raiz)->dir->info < valor){
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
	if(valor < (*raiz)->info){//se valor menor que o valor do nó passado como parâmetro executa este bloco de código
	    if((res = remove_ArvAVL(&(*raiz)->esq,valor)) == 1){//se operação de remoção retorna 1, elemento foi removido
            if(fatorBalanceamento_NO(*raiz) >= 2){//se o fator de balanceamento foi alterado para valor igual ou maior que 2 rotações adequadas serão realizadas
                if(altura_NO((*raiz)->dir->esq) <= altura_NO((*raiz)->dir->dir)) //checando se ramo da esquerda é maior ou igual ao ramo da direita
                    RotacaoRR(raiz);//se sim realiza rotação simples à esquerda
                else
                    RotacaoRL(raiz);//se não realiza rotação dupla iniciada por rotação simples à esquerda seguida por rotação simples à direita
            }
	    }
	}

	if((*raiz)->info < valor){//se valor maior que o valor do nó passado como parâmetro executa este bloco de código
	    if((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1){ //se operação de remoção retorna 1, elemento foi removido
            if(fatorBalanceamento_NO(*raiz) >= 2){//se o fator de balanceamento foi alterado para valor igual ou maior que 2 rotações adequadas serão realizadas
                if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq) )//checando se ramo da direita é maior ou igual ao ramo da esquerda
                    RotacaoLL(raiz);//se sim realiza rotação simples à direita
                else
                    RotacaoLR(raiz);//se não realiza rotação dupla iniciada por rotação simples à direita seguida por rotação simples à esquerda
            }
	    }
	}

	if((*raiz)->info == valor){//valor a ser removido foi encontrado
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
			(*raiz)->info = temp->info;//troca os valores entre o nó passado como parâmetro e o nó folha encontrado
			remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);//remove o nó a direita do nó passado como parâmetro
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

int main(){
    ArvAVL* avl;
    int res,i;
    int N = 10, dados[10] = {1,2,3,10,4,5,9,7,8,6}; //dados a serem inseridos na árvore

    avl = cria_ArvAVL();//cria a árvore

     //checando se árvore está vazia
    if(estaVazia_ArvAVL(avl)) printf("Árvore está vazia!\n\n");
    else printf("Árvore não está está vazia, ela tem %d nó(s)!\n\n", totalNO_ArvAVL(avl));


    //inserindo dados na árvore e imprimindo os valores inseridos, seguindo a ordem do vetor com os dados
    for(i=0;i<N;i++){
        printf("========================\n");
        printf("Inserindo: %d\n",dados[i]);
        res = insere_ArvAVL(avl,dados[i]);
        printf("\n\n");
    }

    //checando se árvore está vazia novamente
    if(estaVazia_ArvAVL(avl)) printf("Árvore está vazia!\n\n");
    else printf("Árvore não está está vazia, ela tem %d nó(s)!\n\n", totalNO_ArvAVL(avl));
    //Imprime as informações da árvore a cada operação de remoção de elementos
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(avl);
    printf("\n\n");

    remove_ArvAVL(avl,6);//remove o nó com o dado 6
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(avl);//imprime informações da árvore após remoção
    printf("\n\n");

    remove_ArvAVL(avl,7);//remove o nó com o dado 7
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(avl);//imprime informações da árvore após remoção
    printf("\n\n");

    remove_ArvAVL(avl,4);//remove o nó com o dado 4
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(avl);//imprime informações da árvore após remoção
    printf("\n\n");

    //verificando a altura da árvore
    printf("\nAltura da árvore = ");
    printf("%d\n",altura_ArvAVL(avl));

    //verificando a quantidade de nós da árvore
    printf("\nQuantidade de nós da árvore = ");
    printf("%d\n",totalNO_ArvAVL(avl));


    libera_ArvAVL(avl);//Destroi a árvore

    getchar();
    return 0;
}