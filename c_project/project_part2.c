/*
Instituto Federal de São Paulo - Campus São Carlos
Análise e Desenvolvimento de Sistemas (ADS)
Algorítimos e Programação 2
Aluno: João Pedro da Silva
RA: SC3012964
Trabalho prático 
Especificação do trabalho: 
Criar um programa de cadastro de alunos com os seguintes requisitos:
1) Utilize as seguintes estruturas de dados:
        #define TAMNOME 50
        #define TAMSOBRENOME 50
        typedef struct data {
            int dia;
            int mes;
            int ano;
        } data;

        typedef struct registro {
            char nome [TAMNOME];
            char sobrenome [TAMSOBRENOME];
            data datadenascimento;
            int prontuario;
            char curso [4];
        } aluno;
        aluno alunos[1000];
2) O programa deve possuir um menu que permita selecionar as funções do programa.
3) Deve haver uma função de cadastro de um aluno.
4) Deve haver uma função que imprime todos os alunos do cadastro.
5) Deve haver uma função de busca, que imprime todos os alunos que se enquadrem no
critério de busca especificado pelo usuário. O usuário pode escolher:
Nome e sobrenome, Nome, Sobrenome, Prontuário, Data de nascimento, Curso
6) Ao final da busca, especificada no requisito 5, o sistema deve dar a opção de remover do
cadastro todos os alunos que foram impressos.
7) Deve haver uma função de ordenação do cadastro de alunos por:
Nome e sobrenome, Sobrenome e nome, Data de nascimento, Prontuario, Curso
*/
//-----------------------------------
//bibliotecas
//-----------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
//-----------------------------------
//defiindo constantes
//-----------------------------------
#define QUANTDADOS 1000
#define TAMNOME 50
#define TAMSOBRENOME 50
#define TAMDATA 100
#define TAMSTR 100
#define TAMPRONTUARIO 100
#define NUMCURSOS 4
#define TAMCURSO 4

//-----------------------------------
//tipos de variaveis
//-----------------------------------

//define a o tipo de variável para datas
typedef struct data 
{
    int dia;
    int mes;
    int ano;
} data;

//define o tipo de variável para registros de alunos
typedef struct registro 
{
    char nome [TAMNOME];
    char sobrenome [TAMSOBRENOME];
    data nascimento;
    int prontuario;
    char curso [TAMCURSO];
} aluno;

//-----------------------------------
//protótipo de funções 
//-----------------------------------

//Aciona o menu principal de opções, passando como parâmetro o vetor contendo as informações do
//cadastro de alunos, o vetor com os nomes dos cursos e o tipo de ordenação aplicado no vetor (se 0 significa
//que o vetro está desordenado)
void menu(aluno vetorAlunos[], int numDados, char vetorCursos[][TAMCURSO], int numCursos, int *tipoOrd);
//Inicializa os dados da aplicação, preenchendo o vetor de structs do tipo aluno, zerando as variáveis 
//do tipo inteiros e preenchendo as strings com o valor vazio "".Recebe como parâmetro o vetor 
//contendo as informações do cadastro de alunos
void inicializaDados(aluno vetorAlunos[], int numDados); 
//Valida a entrada para números inteiros positivos usando como parâmetro a entrada na forma
//de um vetor de caracteres. Retorna a entrada na forma de um inteiro positivo se todos os 
//caracteres digitados são números entre 0 e 9, ou retorna -1 se ao menos um dos caracteres 
//digitados não for um número entre 0 e 9.
int validaInteiro(char num[]);
//Checa se um ano é bissexto ou não, recebendo como parâmetro um inteiro representado 
//o ano. Retorna 1 se o ano usado como parâmetro é bissexto ou 0 se não.
int checaSeAnoBissexto(int ano);
//Checa se um data é válida, usando como parâmetro inteiros para o dia, mês e ano. Retorna 
//1 se a data for válida e 0 se não
int validaData(int dia, int mes, int ano);
//Buscar e retorna o index da primeira posição livre do vetor de dados do tipo aluno. Se todas
//as posições estiverem ocupadas a função retorna -1. Recebe como parâmetro o vetor 
//contendo as informações do cadastro de alunos
int indexDados(aluno vetorAlunos[], int numDados);
//Cadastra aluno, adicionando os dados no vetor de dados do tipo aluno. Recebe como parâmetro o vetor 
//contendo as informações do cadastro de alunos, o vetor com os nomes dos cursos e tipo de ordenação 
//aplicado no vetor (se 0 significa que o vetor está desordenado)
void cadastraAluno(aluno vetorAlunos[], int numDados, char vetorCursos[][TAMCURSO], int numCursos, int *tipoOrd);
//Imprime as informações de um aluno específico, recebendo como parâmetro uma "struct" contendo as 
//informações do aluno.
void imprimeDadosAluno (aluno infoAluno);
//Imprime todos os alunos cadastrados. Recebe como parâmetro o vetor contendo as informações 
//do cadastro de alunos.
void imprimeALunosCadastrados(aluno vetorAlunos[], int numDados);
//checa se o cadastro está vazio analisando e retorna 1 se sim e 0 se não. Recebe como parâmetro
//parâmetro o vetor contendo as informações do cadastro de alunos.
int checaSeCadastroVazio(aluno vetorAlunos[], int numDados);
//Cadastra a data de nascimento durante a execução da função "cadastraAluno". Recebe como 
//parâmetro o vetor contendo as informações do cadastro de alunos.
data cadastraDataNascimento();
//Retorna uma "struct" do tipo aluno com todas as variáveis zeradas. Utilizada para apagar dados
aluno zeraDado();
//Deleta um conjunto de dados específicos. Recebe como parâmetros o vetor contendo as informações 
//do cadastro de alunos, e um vetor contendo os indíces dos dados a serem deletados.
void deletaDados(aluno vetorAlunos[], int numDados, int indices[], int numIndices);
//Compara duas datas  e retorna um número maior que 0 se data1 > data2, 0 se data1 = data2 e 
//um número menor que zero se data1 < data2
int comparaDatas(data data1, data data2);
//Compara o valor de dois números inteiro e retorna um número maior que 0 se n1 > n2, 0 se n1 = n2 e 
//um número menor que 0 se n1 < n2
int comparaInteiros(int n1, int n2);
//Compara dois alunos de acordo com um critério de comparação, que é definido pelo valor do parâmetro 
//op, que pode assumir os seguintes valores: 1 = nome e sobrenome, 2 = sobrenome e nome,  3 = curso, 
//4 = data nascimento e 5 = prontuário. 
//A função retorna um número maior que 0, se valores aluno1 > valores aluno2, 0 se valores aluno1 = valores aluno2 
//e um número menor que 0 se se valores aluno1 < valores aluno2,
int comparaAlunos(aluno aluno1, aluno aluno2, int op);




//Imprime dados mediantes busca por nome e sobrenome, permitindo deletar os dados encontrados.
//Recebe como parâmetros o vetor contendo as informações do cadastro de alunos e informação sobre
//o tipo de ordenação do vetor
void imprimeBuscandoNomeSobrenome(aluno vetorAlunos[], int numDados, int *tipoOrd);
//Imprime dados mediantes busca por nome, permitindo deletar os dados encontrados.
//Recebe como parâmetros o vetor contendo as informações do cadastro de alunos e informação sobre
//o tipo de ordenação do vetor
void imprimeBuscandoNome(aluno vetorAlunos[], int numDados, int *tipoOrd);
//Imprime dados mediantes busca por sobrenome, permitindo deletar os dados encontrados.
//Recebe como parâmetros o vetor contendo as informações do cadastro de alunos e informação sobre
//o tipo de ordenação do vetor
void imprimeBuscandoSobrenome(aluno vetorAlunos[], int numDados, int *tipoOrd);
//Imprime dados mediantes busca por prontuário, permitindo deletar os dados encontrados.
//Recebe como parâmetros o vetor contendo as informações do cadastro de alunos e informação sobre
//o tipo de ordenação do vetor
void imprimeBuscandoProntuario(aluno vetorAlunos[], int numDados, int *tipoOrd);
//Imprime dados mediantes busca por data de nascimento, permitindo deletar os dados encontrados.
//Recebe como parâmetros o vetor contendo as informações do cadastro de alunos e informação sobre
//o tipo de ordenação do vetor
void imprimeBuscandoDataNascimento(aluno vetorAlunos[], int numDados, int *tipoOrd);
//Imprime dados mediantes busca por curso, permitindo deletar os dados encontrados.
//Recebe como parâmetros o vetor contendo as informações do cadastro de alunos, um vetor com informações sobre os cursos
//e informação sobre o tipo de ordenação do vetor
void imprimeBuscandoCurso(aluno vetorAlunos[], int numDados, char vetorCursos[][TAMCURSO], int numCursos, int *tipoOrd);
//Mostra o menu de opções de impressão mediante busca
//Recebe como parâmetros o vetor contendo as informações do cadastro de alunos, o vetor com os nomes dos cursos e tipo de ordenação 
//aplicado no vetor (se 0 significa que o vetro está desordenado)
void imprimePorBusca(aluno vetorAlunos[], int numDados, char vetorCursos[][TAMCURSO], int numCursos, int *tipoOrd);


//Mostra o menu de opções para ordenação do cadastro
//Recebe como parâmetros o vetor contendo as informações do cadastro de alunos e um vetor com informações sobre os cursos.
//Recebe também a variável que indica o tipo de ordenação do vetor (0 significa vetor desordenado)
int ordenaCadastro(aluno vetorAlunos[], int numDados, int *tipoOrd);
//Salva os registros e o estado de organização do vetor em arquivos
//Recebe como parâmetros o vetor contendo as informações do cadastro de alunos.
//Recebe também a variável que indica o tipo de ordenação do vetor (0 significa vetor desordenado)
void salvar(aluno vetorAlunos[], int numDados, int *tipoOrd);
//Carrega os registros dos alunos e o estado de organização do vetor de um arquivo
//Recebe como parâmetros o vetor contendo as informações do cadastro de alunos.
//Recebe também a variável que indica o tipo de ordenação do vetor (0 significa vetor desordenado)
void carregar(aluno vetorAlunos[], int numDados, int *tipoOrd);

//---------------------------------------------------------------------
//>>>funções adicionadas na parte 2 do trabalho
//---------------------------------------------------------------------

//Determina o o final de interação para os algorítmos de ordenação.
int delimitaTamVetor(aluno vetorAlunos[], int numDados);
//Ordenação por inserção
//Retorna a posição de um dado elemento no vetor a ser ordenada pelo algorítimo de ordenação por inserção
//op pode ser: 1 = nome e sobrenome, 2 = sobrenome e nome,  3 = curso, 4 = data nascimento e 5 = prontuário 
int posicaoElemento (aluno vetorAlunos[], int ultimaPosicao, aluno elemento, int op);
//Desloca o subvetor para inserir um elemento na posição correta durante a execução do algorítimo
//de ordenação por inserção
void deslocarSubvetor(aluno vetorAlunos[], int primeiraPosicacao, int ultimaPosicao);
//Ordena o vetor que corresponde ao cadastro de alunos usando o algorítimo de ordenação por inserção, onde o 
//parâmetro op pode assumir: 1 = nome e sobrenome, 2 = sobrenome e nome,  3 = curso, 4 = data nascimento e 5 = prontuário
void ordenarInsercao(aluno vetorAlunos[], int tamVetor, int op);

//Ordenação por intercalação
//Intercala os elementos do vetor a ser ordenado no vetor auxiliar. Função usada pelo algorítimo de ordenação por intercalação
//parâmetro op pode assumir 1 = nome e sobrenome, 2 = sobrenome e nome,  3 = curso, 4 = data nascimento e 5 = prontuário)
void intercalar(aluno vetorAlunos[], int inicio, int meio, int fim, int op);
//Ordena o vetor recursivamente usando a intercalação
//parâmetro tipo corresponde ao tipo de ordenação (1 = nome e sobrenome, 2 = sobrenome e nome,  3 = curso, 4 = 
//data nascimento e 5 = prontuário)
void ordenarIntercalacao(aluno vetorAlunos[], int inicio, int fim, int op);

//Ordenação por particionamento
//Realiza troca entre dois elementos do tipo aluno, passados como parâmetro. Função utilizada nos algorítimos
//de ordenação por particionamento e por seleção
void trocaElementos(aluno *a, aluno *b);
//Particiona o vetor em dois outros subvetores, um com valores maiores e outro com valores menores que 
//um valor determinado como pivo. Usado na algorítimo de ordenação por particionamento
int particionarVetor(aluno vetorAlunos[], int inicio, int fim, int op);
//Ordena o vetor recursivamente por particionamento
void ordenarParticionamento(aluno vetorAlunos[], int inicio, int fim, int op);

//Ordenação por seleção
//Retorna a posição do menor elemento ainda não ordenado. Utilizado no algorítimo de ordenação por
//seleção
int menorElemento(aluno vetorAlunos[], int tamVetor, int primeiraPosicao, int op);
//Ordena o vetor por inserção
int ordenarSelecao(aluno vetorAlunos[], int tamVetor, int op);


//-----------------------------------
//função principal
//-----------------------------------
int main() 
{
    aluno infoAluno; 
    aluno alunos[QUANTDADOS];
    char cursos[NUMCURSOS][TAMCURSO];
    char curso[TAMCURSO];
    //Define o tipo de ordenação dos vetor. É sempre iniciado com 0, o que significa
    //que o vetor esta desorganizado. Se valor igual 1 significa que o vetor esta organizado
    //por nome ou nome e sobrenome; 2 organizado por sobrenome ou sobrenome e nome; 3 organizado
    //por curso; 4 por data de nascimento e 5 ordenado por prontuário 
    //Sempre que uma operação altera o vetor, como adição ou deleção o valor desta variável é
    //novamente setado como 0
    int tipoOrdenacao = 0; 
    //inicializando o vetor cursos
    strcpy(cursos[0], "ADS");
    strcpy(cursos[1], "TPG");
    strcpy(cursos[2], "TMA");
    //inicializando o vetor de alunos
    inicializaDados(alunos, QUANTDADOS);
    carregar(alunos, QUANTDADOS, &tipoOrdenacao);
    menu(alunos, QUANTDADOS, cursos, NUMCURSOS, &tipoOrdenacao);
    
    return 0;
}

//-----------------------------------
//declaração de funções 
//-----------------------------------

void menu(aluno vetorAlunos[], int numDados, char vetorCursos[][TAMCURSO], int numCursos, int *tipoOrd) 
{    
    char op[100];
    int intOp, menu = 1;
    int i;//contador
    while (menu == 1) {
        i = 0;//inicializa contador para controle do loop while
        intOp = 0; //inicializa a variável com um valor inválido para o loop while
        while (intOp < 1 || intOp > 6)
        {
            if (i > 0) 
            {
                printf("\nOpção inválida!\n");
            }
            printf("\n--------------------- Menu ----------------------\n\n");
            printf("[1] - Cadastrar aluno\n");
            printf("[2] - Imprimir todos alunos cadastrados\n");
            printf("[3] - Imprime alunos cadastrados mediante busca\n");
            printf("[4] - Ordenar cadastro\n");
            printf("[5] - Salvar registros\n");
            printf("[6] - Finalizar programa\n");
            printf("\n-------------------------------------------------\n");
            printf("Selecione uma opção: ");
            fgets(op, 100, stdin);
            intOp = validaInteiro(op);
            i++;//atualiza contador
        }
        switch (intOp) 
        {
            case 1:
                cadastraAluno(vetorAlunos, numDados, vetorCursos, numCursos, tipoOrd);
                menu = 1;
                break;
            case 2:
                imprimeALunosCadastrados(vetorAlunos, numDados);
                menu = 1;
                break;
            case 3:
                imprimePorBusca(vetorAlunos,numDados, vetorCursos,numCursos, tipoOrd);
                menu = 1;
                break;
            case 4:
                ordenaCadastro(vetorAlunos, numDados, tipoOrd);
                menu = 1;
                break;
            case 5:
                salvar(vetorAlunos, numDados, tipoOrd);
                menu = 1;
                break;
            case 6:
                menu = 0;
                printf("\nPrograma finalizado!\n\n");
                break;
        }
    }   
}

void inicializaDados(aluno vetorAlunos[], int numDados) 
{
    int i;
    aluno infoAluno;
    for (i = 0; i < numDados-1; i++) 
    {
        strcpy(infoAluno.nome, "");
        strcpy(infoAluno.sobrenome, "");
        infoAluno.nascimento.dia = 0;
        infoAluno.nascimento.mes = 0;
        infoAluno.nascimento.ano = 0;
        infoAluno.prontuario = 0;
        strcpy(infoAluno.curso, "");
        vetorAlunos[i] = infoAluno;
    }
}

int validaInteiro(char num[]) 
{ 
    int checagem = 1; //variável de checagem (1 = true, 0 = false)
    int i;
    //Como a inserção da string termina com a tecla "enter" a função "fgets" adiciona ao final da string
    //o caracter '\n', o que ocasiona mal funcionamento da função, o que pode ser evitado usando como final para
    //o laço "for" strlen(string) - 1. Isso evita o acesso ao último caracter da string, que no caso é '\n'. 
    for (i = 0; i < strlen(num) - 1; i++) 
    {
        if (num[i] < '0' || num[i] > '9') 
        {
            checagem = 0;
        }
    }
    if (checagem == 1) 
    {
        return atoi(num); //converte os caracteres de num[] para inteiro
    } else
    {
        return -1;
    }
}

int checaSeAnoBissexto(int ano) 
{
    if (ano % 4 == 0) 
    {
        if (ano % 100 == 0) 
        {
            if (ano % 400 == 0) 
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        } else 
        {
            return 1;
        }
    } else 
    {
        return 0;
    }
}

int validaData(int dia, int mes, int ano) 
{
    if (ano <= 0 || dia <= 0 || dia > 31 || mes <= 0 || mes > 12) 
    {
        return 0;
    } else  
    {
        if (mes == 2) 
        {
            if (checaSeAnoBissexto(ano) == 1) 
            {
                if (dia > 29) 
                {
                    return 0;
                } else 
                {
                    return 1;
                }
            } else 
            {
                if (dia > 28) 
                {
                    return 0;
                } else 
                {
                    return 1;
                }
            }
        } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) 
        {
            if (dia > 30) 
                {
                    return 0;
                } else 
                {
                    return 1;
                }  
        } else 
        {
           return 1; 
        }
    }   
}

int indexDados(aluno vetorAlunos[], int numDados)
{
    int index = 0;
    while(strlen(vetorAlunos[index].nome) != 0 && index <= numDados - 1) 
    {
        index++;
    }
    if (index == numDados) 
    {
        return -1;
    } else 
    {   
        return index;
    }
}

void cadastraAluno(aluno vetorAlunos[], int numDados, char vetorCursos[][TAMCURSO], int numCursos, int *tipoOrd)
{
    int index = indexDados(vetorAlunos, numDados);
    char prontuario[TAMPRONTUARIO];
    char curso[TAMCURSO];
    int j;
    int i; //contador de controle para os loops while
    int op; //opção de curso
    char strOp[100]; //string de opção para os cursos
    aluno infoAluno;
    if (index == -1) 
    {
        printf("\n Não há mais posições para salvar dados!");
    } else 
    {
        printf("\n--------------- Cadastrando aluno ---------------\n");
        printf("\nEntre com o nome do aluno: ");
        fgets(infoAluno.nome, TAMNOME, stdin);
        infoAluno.nome[strlen(infoAluno.nome)-1] = ' ';
        printf("\nEntre com o sobrenome do aluno: ");
        fgets(infoAluno.sobrenome, TAMSOBRENOME, stdin);
        infoAluno.sobrenome[strlen(infoAluno.sobrenome)-1] = ' '; 
        infoAluno.nascimento = cadastraDataNascimento();
        i = 0;
        infoAluno.prontuario = -1; //inicializa a váriavel com um valor inválido para o loop while
        while (infoAluno.prontuario == -1) 
        {
            if(i > 0) 
            {
                printf("\nValor inválido! \n");
            }
            printf("\nEntre com o prontuário do aluno: ");
            fgets(prontuario, TAMPRONTUARIO, stdin);
            infoAluno.prontuario = validaInteiro(prontuario);
            i++; //atualiza contador
        }
        i = 0; //reinicializa o contador para o próximo loop while
        op = 0; //inicializa a variável op com um valor inválido para o loop while
        while (op <= 0 || op >= numCursos) 
        {
            if(i > 0) 
            {
                printf("Opção inválida!\n");
            }
            printf("\nEscolha o curso do aluno: ");
            for (j = 0; j < numCursos-1; j++)  //aqui tem que ser numCursos-1, para descosiderar o último caracter do vetor que o de terminação
            {
                
                if (j == numCursos-2) //ultimo index válido do vetorCursos
                {
                    printf("[%d]%s \n", j+1, vetorCursos[j]);
                } else 
                {
                    printf("[%d]%s | ", j+1, vetorCursos[j]);
                }
            }
            printf("Opção: ");
            fgets(strOp, 100, stdin);
            op = validaInteiro(strOp);
            i++;//atualiza contador
        }
        //registrando a opção de curso
        strcpy(infoAluno.curso, vetorCursos[op-1]); 
        vetorAlunos[index] = infoAluno;
        printf("\nAluno cadastrado!!");
        *tipoOrd = 0;
    }
}

data cadastraDataNascimento()
{
    char dataDia[TAMDATA], dataMes[TAMDATA], dataAno[TAMDATA];
    int dia = 0, mes = 0, ano = 0; 
    int i = 0; //contador
    data nascimento;
    while (validaData(dia, mes, ano) == 0) 
        {
            if (i > 0) 
            {
                printf("\nData inválida! \n");
            }
            printf("\nEntre com o dia de nascimento do aluno: ");
            fgets(dataDia, TAMDATA, stdin);
            dia = validaInteiro(dataDia);
            while (dia == -1)
            {
                printf("\nValor inválido! \n");
                printf("\nEntre com o dia de nascimento do aluno: ");
                fgets(dataDia, TAMDATA, stdin);
                dia = validaInteiro(dataDia);
            }
            printf("\nEntre com o mês de nascimento do aluno: ");
            fgets(dataMes, TAMDATA, stdin);
            mes = validaInteiro(dataMes);
            while (mes == -1)
            {
                printf("\nValor inválido! \n");
                printf("\nEntre com o mês de nascimento do aluno: ");
                fgets(dataMes, TAMDATA, stdin);
                mes = validaInteiro(dataMes);
            }
            printf("\nEntre com o ano de nascimento do aluno: ");
            fgets(dataAno, TAMDATA, stdin);
            ano = validaInteiro(dataAno);
            while (ano == -1)
            {
                printf("\nValor inválido! \n");
                printf("\nEntre com o ano de nascimento do aluno: ");
                fgets(dataAno, TAMDATA, stdin);
                ano = validaInteiro(dataAno);
            }
            i++;//atualiza contador
        }
        nascimento.dia = dia;
        nascimento.mes = mes;
        nascimento.ano = ano;
        return nascimento;
}
void imprimeDadosAluno (aluno dadosAluno) {
    printf("Aluno: %s%s \n", dadosAluno.nome, dadosAluno.sobrenome);
    printf("Nascimento: %d/%d/%d \n", dadosAluno.nascimento.dia, dadosAluno.nascimento.mes, dadosAluno.nascimento.ano);
    printf("Prontuário: %d\n", dadosAluno.prontuario);
    printf("Curso: %s \n", dadosAluno.curso);
}
int checaSeCadastroVazio(aluno vetorAlunos[], int numDados) 
{
    int i, contador = 0;
    for(i = 0; i < numDados-1; i++)
    {
        if(strlen(vetorAlunos[i].nome) == 0) 
        {
            contador++;
        }
    }
    if (contador == numDados-1) 
    {
        return 1;
    } else {
        return 0;
    }
}
void imprimeALunosCadastrados(aluno vetorAlunos[], int numDados) 
{   
    int i;
    int cont = 0;
    printf("\n\n--------------- Alunos cadastrados --------------\n\n");
    if (checaSeCadastroVazio(vetorAlunos, numDados) == 0)
    {
        for (i = 0; i < numDados-1; i++)
        {
            if(strlen(vetorAlunos[i].nome) != 0) 
           {
                printf("%d\n", i);
                imprimeDadosAluno(vetorAlunos[i]);
                printf("\n-------------------------------------------------\n\n");
           }
        }    
    } 
    else 
    {
        printf("Não há alunos cadastrados!\n");
        printf("\n-------------------------------------------------\n\n");
    }
}
aluno zeraDado() 
{
    aluno infoAluno;
    strcpy(infoAluno.nome, "");
    strcpy(infoAluno.sobrenome, "");
    infoAluno.nascimento.dia = 0;
    infoAluno.nascimento.mes = 0;
    infoAluno.nascimento.ano = 0;
    infoAluno.prontuario = 0;
    strcpy(infoAluno.curso, "");
    return infoAluno;
}
void deletaDados(aluno vetorAlunos[], int numDados, int indices[], int numIndices)
{
    int i, j, indice;
    //aluno infoAluno;
    for (i = 0; i < numIndices; i++) 
    {
        indice = indices[i];
        vetorAlunos[indice] = zeraDado();
    }    
}
int comparaDatas(data data1, data data2) 
{
    int d1 = data1.ano*10000 + data1.mes*100 + data1.dia;
    int d2 = data2.ano*10000 + data2.mes*100 + data2.dia;
    return d1-d2;
}
int comparaInteiros(int n1, int n2) 
{
    return n1-n2;
}
int comparaAlunos(aluno aluno1, aluno aluno2, int op) {
    char s1[TAMSTR], s2[TAMSTR];
    switch (op)
    {
    case 1: //caso nome e sobrenome
        strcpy(s1, aluno1.nome);
        strcat(s1, aluno1.sobrenome);
        strcpy(s2, aluno2.nome);
        strcat(s2, aluno2.sobrenome);
        return strcmp(s1, s2);
        break;
    case 2: //caso sobrenome e nome
        strcpy(s1, aluno1.sobrenome);
        strcat(s1, aluno1.nome);
        strcpy(s2, aluno2.sobrenome);
        strcat(s2, aluno2.nome);
        return strcmp(s1, s2);
        break;
    case 3://curso
        return strcmp(aluno1.curso, aluno2.curso);
    case 4: //data
        return comparaDatas(aluno1.nascimento, aluno2.nascimento);
    case 5: //prontuário
        return comparaInteiros(aluno1.prontuario, aluno2.prontuario);
    }
}



void imprimeBuscandoNomeSobrenome(aluno vetorAlunos[], int numDados, int *tipoOrd)
{
    int indices[numDados];
    int i, j = 0;//contador
    int ini, meio, fim; //índices para busca binária
    char nome[TAMNOME], sobrenome[TAMSOBRENOME];
    char deletar[100];
    int intDeletar, tamIndices;
    printf("\n----- Buscando alunos por nome e sobrenome ------\n\n");
    printf("Entre com o nome do aluno: ");
    fgets(nome, TAMNOME, stdin);
    nome[strlen(nome)-1] = ' ';//retirando o enter da variável
    printf("Entre com o sobrenome do aluno: ");
    fgets(sobrenome, TAMSOBRENOME, stdin);
    sobrenome[strlen(sobrenome)-1] = ' ';//retirando o enter da variável
    printf("\n-------------------------------------------------\n\n");
    if (*tipoOrd == 1) //realiza busca binária 
    {
        ini = 0;
        fim = numDados-1;
        while (ini <= fim)
        {
            meio = (ini + fim) / 2;
            if (strcmp(vetorAlunos[meio].nome, nome) == 0 && strcmp(vetorAlunos[meio].sobrenome, sobrenome) == 0) 
            {
                imprimeDadosAluno(vetorAlunos[meio]);
                printf("\n-------------------------------------------------\n\n");
                indices[j] = meio;
                j++;
                ini = meio+1;

            } else if (strcmp(vetorAlunos[meio].nome, nome) > 0 && strcmp(vetorAlunos[meio].sobrenome, sobrenome) > 0) 
            {
                fim = meio-1;
            } else 
            {
                ini = meio+1;
            }
        }
    } else //realiza busca linear
    {
        for (i = 0; i < numDados-1; i++)
        {
            if(strcmp(vetorAlunos[i].nome, nome) == 0 && strcmp(vetorAlunos[i].sobrenome, sobrenome) == 0) 
            {
                imprimeDadosAluno(vetorAlunos[i]);
                printf("\n-------------------------------------------------\n\n");
                indices[j] = i;
                j++;
            }
        }
    }
    tamIndices = j;
    if (j == 0)
    {
        printf("\nNão há alunos com nome e sobrenome iguais aos digitados!\n");
    } else
    {
        j = 0; //zerando contador novamente
        intDeletar = -1; //inicializando variável com valor inválido para o loop while
        while(intDeletar == -1 || intDeletar < 1 || intDeletar > 2)
        {
            if (j > 0) 
            {
                printf("\nValor inválido!\n");
            }
            printf("\nQuer deletar os registros impresso? [1] - sim | [2] - não\n");
            fgets(deletar, 100, stdin);
            intDeletar = validaInteiro(deletar);
            j++;
        }
        if (intDeletar == 1)
        {
            deletaDados(vetorAlunos, numDados, indices, tamIndices);
            printf("Dados deletados!\n\n");
        }         
    }

}

void imprimeBuscandoNome(aluno vetorAlunos[], int numDados, int *tipoOrd)
{
    int indices[numDados];
    int i, j = 0; //contador
    int ini, meio, fim; //índices para busca binária
    char nome[TAMNOME];
    char deletar[100];
    int intDeletar, tamIndices;
    printf("\n----- Buscando alunos por nome ------\n\n");
    printf("Entre com o nome do aluno: ");
    fgets(nome, TAMNOME, stdin);
    nome[strlen(nome)-1] = ' ';//retirando o enter da variável
    printf("\n-------------------------------------------------\n\n");
    if (*tipoOrd == 1) //realiza busca binária 
    {
        ini = 0;
        fim = numDados-1;
        while (ini <= fim)
        {
            meio = (ini + fim) / 2;
            if (strcmp(vetorAlunos[meio].nome, nome) == 0) 
            {
                imprimeDadosAluno(vetorAlunos[meio]);
                printf("\n-------------------------------------------------\n\n");
                indices[j] = meio;
                j++;
                ini = meio+1;

            } else if (strcmp(vetorAlunos[meio].nome, nome) > 0) 
            {
                fim = meio-1;
            } else 
            {
                ini = meio+1;
            }
        }
    } else //realiza busca linear
    {
        for (i = 0; i < numDados-1; i++)
        {
            if(strcmp(vetorAlunos[i].nome, nome) == 0) 
            {
                imprimeDadosAluno(vetorAlunos[i]);
                printf("\n-------------------------------------------------\n\n");
                indices[j] = i;
                j++;
            }
        }
    }
    
    tamIndices = j;
    if (j == 0)
    {
        printf("\nNão há alunos com nome igual ao digitado!\n");
    } else
    {
        j = 0; //zerando contador novamente
        intDeletar = -1; //inicializando variável com valor inválido para o loop while
        while(intDeletar < 1 || intDeletar > 2)
        {
            if (j > 0) 
            {
                printf("\nValor inválido!\n");
            }
            printf("\nQuer deletar os registros impresso? [1] - sim | [2] - não\n");
            fgets(deletar, 100, stdin);
            intDeletar = validaInteiro(deletar);
            j++;
        }
        if (intDeletar == 1)
        {
            deletaDados(vetorAlunos, numDados, indices, tamIndices);
            printf("Dados deletados!");
        }         
    }
}

void imprimeBuscandoSobrenome(aluno vetorAlunos[], int numDados, int *tipoOrd)
{
    int indices[numDados];
    int i, j = 0;//contador
    int ini, meio, fim; //índices para busca binária
    char sobrenome[TAMSOBRENOME];
    char deletar[100];
    int intDeletar, tamIndices;
    printf("\n----- Buscando alunos por sobrenome ------\n\n");
    printf("Entre com o sobrenome do aluno: ");
    fgets(sobrenome, TAMSOBRENOME, stdin);
    sobrenome[strlen(sobrenome)-1] = ' ';//retirando o enter da variável
    printf("\n-------------------------------------------------\n\n");
    if (*tipoOrd == 2) //realiza busca binária 
    {
        ini = 0;
        fim = numDados-1;
        while (ini <= fim)
        {
            meio = (ini + fim) / 2;
            if (strcmp(vetorAlunos[meio].sobrenome, sobrenome) == 0) 
            {
                imprimeDadosAluno(vetorAlunos[meio]);
                printf("\n-------------------------------------------------\n\n");
                indices[j] = meio;
                j++;
                ini = meio+1;

            } else if (strcmp(vetorAlunos[meio].sobrenome, sobrenome) > 0) 
            {
                fim = meio-1;
            } else 
            {
                ini = meio+1;
            }
        }
    } else //realiza busca linear
    {
        for (i = 0; i < numDados-1; i++)
        {
            if(strcmp(vetorAlunos[i].sobrenome, sobrenome) == 0) 
            {
                imprimeDadosAluno(vetorAlunos[i]);
                printf("\n-------------------------------------------------\n\n");
                indices[j] = i;
                j++;
            }
        }
    }
    tamIndices = j;
    if (j == 0)
    {
        printf("\nNão há alunos com sobrenome igual ao digitado!\n");
    } else
    {
        j = 0; //zerando contador novamente
        intDeletar = -1; //inicializando variável com valor inválido para o loop while
        while(intDeletar == -1 || intDeletar < 1 || intDeletar > 2)
        {
            if (j > 0) 
            {
                printf("\nValor inválido!\n");
            }
            printf("\nQuer deletar os registros impresso? [1] - sim | [2] - não\n");
            fgets(deletar, 100, stdin);
            intDeletar = validaInteiro(deletar);
            j++;
        }
        if (intDeletar == 1)
        {
            deletaDados(vetorAlunos, numDados, indices, tamIndices);
            printf("Dados deletados!\n\n");
        }         
    }
}

void imprimeBuscandoProntuario(aluno vetorAlunos[], int numDados, int *tipoOrd) 
{   
    int indices[numDados];
    int i, j;//contador
    int ini, meio, fim; //índices para busca binária
    int prontuario; 
    char strProntuario[TAMPRONTUARIO]; //string de opção para os cursos
    char curso[TAMCURSO];
    char deletar[100];
    int intDeletar, tamIndices;
    printf("\n----- Buscando alunos por prontuário ------\n\n");
    prontuario = -1;
    i = 0;
    while (prontuario == -1) 
    {
        if(i > 0) 
        {
           printf("\nValor inválido! \n");
        }
        printf("\nEntre com o prontuário do aluno: ");
        fgets(strProntuario, TAMPRONTUARIO, stdin);
        prontuario = validaInteiro(strProntuario);
        i++; //atualiza contador
    }
    j = 0; //inicializa novamente o j
    printf("\n-------------------------------------------------\n\n");
    if (*tipoOrd == 5) //realiza busca binária 
    {
        ini = 0;
        fim = numDados-1;
        while (ini <= fim)
        {
            meio = (ini + fim) / 2;
            if (comparaInteiros(vetorAlunos[meio].prontuario, prontuario) == 0) 
            {
                imprimeDadosAluno(vetorAlunos[meio]);
                printf("\n-------------------------------------------------\n\n");
                indices[j] = meio;
                j++;
                ini = meio+1;

            } else if (comparaInteiros(vetorAlunos[meio].prontuario, prontuario) > 0) 
            {
                fim = meio-1;
            } else 
            {
                ini = meio+1;
            }
        }
    } else //realiza busca linear
    {
        for (i = 0; i < numDados-1; i++)
        {
            if(vetorAlunos[i].prontuario == prontuario) 
            {
                imprimeDadosAluno(vetorAlunos[i]);
                printf("\n-------------------------------------------------\n\n");
                indices[j] = i;
                j++;
            }
        }
    }
    tamIndices = j;
    if (j == 0)
    {
        printf("\nNão há aluno com o número de prontuário digitado");
    } else
    {
        j = 0; //zerando contador novamente
        intDeletar = -1; //inicializando variável com valor inválido para o loop while
        while(intDeletar == -1 || intDeletar < 1 || intDeletar > 2)
        {
            if (j > 0) 
            {
                printf("\nValor inválido!\n");
            }
            printf("\nQuer deletar os registros impresso? [1] - sim | [2] - não\n");
            fgets(deletar, 100, stdin);
            intDeletar = validaInteiro(deletar);
            j++;
        }
        if (intDeletar == 1)
        {
            deletaDados(vetorAlunos, numDados, indices, tamIndices);
            printf("Dados deletados!\n\n");
        }         
    }
}

void imprimeBuscandoDataNascimento(aluno vetorAlunos[], int numDados, int *tipoOrd) 
{   
    int indices[numDados];
    int i, j;//contador
    int ini, meio, fim; //índices para busca binária
    char deletar[100];
    int intDeletar, tamIndices;
    data nascimento;
    printf("\n--- Buscando alunos por data de nascimento ---\n\n");
    nascimento = cadastraDataNascimento();
    j = 0; //inicializa novamente o j
    printf("\n-------------------------------------------------\n\n");
    if (*tipoOrd == 4) //realiza busca binária 
    {
        ini = 0;
        fim = numDados-1;
        while (ini <= fim)
        {
            meio = (ini + fim) / 2;
            if (comparaDatas(vetorAlunos[meio].nascimento, nascimento) == 0) 
            {
                imprimeDadosAluno(vetorAlunos[meio]);
                printf("\n-------------------------------------------------\n\n");
                indices[j] = meio;
                j++;
                ini = meio+1;

            } else if (comparaDatas(vetorAlunos[meio].nascimento, nascimento) > 0) 
            {
                fim = meio-1;
            } else 
            {
                ini = meio+1;
            }
        }
    } else //realiza busca linear
    {
        for (i = 0; i < numDados-1; i++)
        {
            if(comparaDatas(vetorAlunos[i].nascimento, nascimento) == 0) 
            {
                imprimeDadosAluno(vetorAlunos[i]);
                printf("\n-------------------------------------------------\n\n");
                indices[j] = i;
                j++;
            }
        }
    }
    tamIndices = j;
    if (j == 0)
    {
        printf("\nNão há aluno com o número de prontuário digitado");
    } else
    {
        j = 0; //zerando contador novamente
        intDeletar = -1; //inicializando variável com valor inválido para o loop while
        while(intDeletar == -1 || intDeletar < 1 || intDeletar > 2)
        {
            if (j > 0) 
            {
                printf("\nValor inválido!\n");
            }
            printf("\nQuer deletar os registros impresso? [1] - sim | [2] - não\n");
            fgets(deletar, 100, stdin);
            intDeletar = validaInteiro(deletar);
            j++;
        }
        if (intDeletar == 1)
        {
            deletaDados(vetorAlunos, numDados, indices, tamIndices);
            printf("Dados deletados!\n\n");
        }         
    }
}

void imprimeBuscandoCurso(aluno vetorAlunos[], int numDados, char vetorCursos[][TAMCURSO], int numCursos, int *tipoOrd)
{
    int indices[numDados];
    int i, j;//contador
    int ini, meio, fim; //índices para busca binária
    int op; 
    char strOp[100]; //string de opção para os cursos
    char curso[TAMCURSO];
    char deletar[100];
    int intDeletar, tamIndices;
    printf("\n----- Buscando alunos por curso ------\n\n");
    i = 0; //reinicializa o contador para o próximo loop while
    op = 0; //inicializa a variável op com um valor inválido para o loop while
    while (op <= 0 || op >= numCursos) 
    {
        if(i > 0) 
        {
            printf("Opção inválida!\n");
        }
        printf("\nEscolha o curso do aluno: ");
        for (j = 0; j < numCursos-1; j++)  //aqui tem que ser numCursos-1, para descosiderar o último caracter do vetor que o de terminação
        {
            if (j == numCursos-2) //ultimo index válido do vetorCursos
            {
                printf("[%d]%s \n", j+1, vetorCursos[j]);
            } else 
            {
                printf("[%d]%s | ", j+1, vetorCursos[j]);
            }
        }
        printf("Opção: ");
        fgets(strOp, 100, stdin);
        op = validaInteiro(strOp);
        i++;//atualiza contador
    }
    j = 0; //inicializa novamente o j
    printf("\n-------------------------------------------------\n\n");
    if (*tipoOrd == 3) //realiza busca binária 
    {
        ini = 0;
        fim = numDados-1;
        while (ini <= fim)
        {
            meio = (ini + fim) / 2;
            if (strcmp(vetorAlunos[meio].curso, vetorCursos[op-1]) == 0) 
            {
                imprimeDadosAluno(vetorAlunos[meio]);
                printf("\n-------------------------------------------------\n\n");
                indices[j] = meio;
                j++;
                ini = meio+1;

            } else if (strcmp(vetorAlunos[meio].curso, vetorCursos[op-1]) > 0) 
            {
                fim = meio-1;
            } else 
            {
                ini = meio+1;
            }
        }
    } else //realiza busca linear
    {
        for (i = 0; i < numDados-1; i++)
        {
            if(strcmp(vetorAlunos[i].curso, vetorCursos[op-1]) == 0) 
            {
                imprimeDadosAluno(vetorAlunos[i]);
                printf("\n-------------------------------------------------\n\n");
                indices[j] = i;
                j++;
            }
        }
    }
    tamIndices = j;
    if (j == 0)
    {
        printf("\nNão há alunos de %s cadastrados!\n", vetorCursos[op-1]);
    } else
    {
        j = 0; //zerando contador novamente
        intDeletar = -1; //inicializando variável com valor inválido para o loop while
        while(intDeletar == -1 || intDeletar < 1 || intDeletar > 2)
        {
            if (j > 0) 
            {
                printf("\nValor inválido!\n");
            }
            printf("\nQuer deletar os registros impresso? [1] - sim | [2] - não\n");
            fgets(deletar, 100, stdin);
            intDeletar = validaInteiro(deletar);
            j++;
        }
        if (intDeletar == 1)
        {
            deletaDados(vetorAlunos, numDados, indices, tamIndices);
            printf("Dados deletados!\n\n");
        }         
    }
}

void imprimePorBusca(aluno vetorAlunos[], int numDados, char vetorCursos[][TAMCURSO], int numCursos, int *tipoOrd)
{
    char op[100];
    int intOp;
    int i;//contador
    int tamVetor = delimitaTamVetor(vetorAlunos, numDados);
    i = 0;//inicializa contador para controle do loop while
    intOp = 0; //inicializa a variável com um valor inválido para o loop while
    while (intOp < 1 || intOp > 7)
    {
        if (i > 0) 
        {
            printf("\nOpção inválida!\n");
        }
        printf("\n--------- Imprime alunos mediante busca ---------\n\n");
        printf("[1] - Imprime mediante busca por nome e sobrenome\n");
        printf("[2] - Imprime mediante busca por nome\n");
        printf("[3] - Imprime mediante busca por sobrenome\n");
        printf("[4] - Imprime mediante busca por prontuário\n");
        printf("[5] - Imprime mediante busca por data de nascimento\n");
        printf("[6] - Imprime mediante busca por curso\n");
        printf("[7] - voltar ao menu\n");
        printf("\n-------------------------------------------------\n");
        printf("Selecione uma opção: ");
        fgets(op, 100, stdin);
        intOp = validaInteiro(op);
        i++;//atualiza contador2
    }
    switch (intOp) 
    {
        case 1:
            imprimeBuscandoNomeSobrenome(vetorAlunos, tamVetor, tipoOrd);
            break;
        case 2:
            imprimeBuscandoNome(vetorAlunos, tamVetor, tipoOrd);
            break;
        case 3:
            imprimeBuscandoSobrenome(vetorAlunos, tamVetor, tipoOrd);
            break;
        case 4:
            imprimeBuscandoProntuario(vetorAlunos, tamVetor, tipoOrd);
            break;
        case 5:
            imprimeBuscandoDataNascimento(vetorAlunos, tamVetor, tipoOrd);
            break;
        case 6:
            imprimeBuscandoCurso(vetorAlunos, tamVetor, vetorCursos, numCursos, tipoOrd);
            break;
        case 7:
            //volta para o menu
            break;
    }
}
//ordenar por inserção
int posicaoElemento (aluno vetorAlunos[], int ultimaPosicao, aluno elemento, int op)
{   int i;
    for (i = 0; i <= ultimaPosicao && comparaAlunos(vetorAlunos[i], elemento, op) <= 0; i++); 
            return i;
}
void deslocarSubvetor(aluno vetorAlunos[], int primeiraPosicacao, int ultimaPosicao) 
{
    int i;
    for (i = ultimaPosicao; i >= primeiraPosicacao; i--) 
    {
        vetorAlunos[i+1] = vetorAlunos[i];
    }
} 
void ordenarInsercao(aluno vetorAlunos[], int tamVetor, int op) 
{
    int i, posicao;
    aluno elemento;
    //i começa em 1 pois considera-se que o primeiro elemento já está ordenado
    for (i = 1; i < tamVetor; i++) {
        elemento = vetorAlunos[i];
        posicao = posicaoElemento(vetorAlunos, i-1, elemento, op);
        deslocarSubvetor(vetorAlunos, posicao, i-1);
        vetorAlunos[posicao] = elemento;
    }
}
//ordenação por intercalação
void intercalar(aluno vetorAlunos[], int inicio, int meio, int fim, int op) 
{
    aluno auxiliar[QUANTDADOS]; // vetor auxiliar
    int i = inicio, j = meio + 1, k = 0; // índices dos vetores
    // intercala
    while(i <= meio && j <= fim) 
    {
        if (comparaAlunos (vetorAlunos[i], vetorAlunos[j], op) <= 0) 
        {
            auxiliar[k] = vetorAlunos[i];
            k++;
            i++;
        }
        else 
        {
            auxiliar[k] = vetorAlunos[j];
            k++;
            j++;
        }  
    }
    // copia resto de cada subvetor
    while (i <= meio) 
    {
        auxiliar[k] = vetorAlunos[i];
        k++;
        i++;
    }
    while (j <= fim) 
    {
        auxiliar[k] = vetorAlunos[j];
        k++;
        j++;
    }
    // copia de auxiliar para vetor
    for (i = inicio, k = 0; i <= fim; i++, k++) 
    {
        vetorAlunos[i] = auxiliar[k];
    }  
}
void ordenarIntercalacao(aluno vetorAlunos[], int inicio, int fim, int op) 
{
    int meio;
    if (inicio < fim) 
    {
        meio = (inicio + fim) / 2;
        ordenarIntercalacao(vetorAlunos, inicio, meio, op);
        ordenarIntercalacao(vetorAlunos, meio+1, fim, op);
        intercalar(vetorAlunos, inicio, meio, fim, op);
    }
}
//ordena particionamento
void trocaElementos(aluno *a, aluno *b) 
{
    aluno aux = *a;
    *a = *b;
    *b = aux;
}
int particionarVetor(aluno vetorAlunos[], int inicio, int fim, int op) 
{   
    aluno pivo = vetorAlunos[fim];
    while (inicio < fim) 
    {
        while (inicio < fim && comparaAlunos(vetorAlunos[inicio], pivo, op) <= 0) 
        {
            inicio++;
        }
        while (inicio < fim && comparaAlunos(vetorAlunos[fim], pivo, op) > 0)
        {
            fim--;
        }
        trocaElementos(&vetorAlunos[inicio], &vetorAlunos[fim]);
    }
    return inicio;
}
void ordenarParticionamento(aluno vetorAlunos[], int inicio, int fim, int op) 
{
    int pos;
    if (inicio < fim) 
    {
        pos = particionarVetor(vetorAlunos, inicio, fim, op);
        ordenarParticionamento(vetorAlunos, inicio, pos -1, op);
        ordenarParticionamento(vetorAlunos, pos, fim, op);
    }
}
//Ordena o vetor por inserção
int menorElemento(aluno vetorAlunos[], int tamVetor, int primeiraPosicao, int op) 
{
    int i, posicaoMenor = primeiraPosicao;
    for (i = primeiraPosicao + 1; i < tamVetor; i++) {
        if (comparaAlunos(vetorAlunos[i], vetorAlunos[posicaoMenor], op) < 0)
        posicaoMenor = i;
    }
    return posicaoMenor;
}
int ordenarSelecao(aluno vetorAlunos[], int tamVetor, int op) 
{
    int i, posicaoMenor;
    for (i = 0; i < tamVetor; i++) 
    {
    posicaoMenor = menorElemento(vetorAlunos, tamVetor, i, op);
    trocaElementos(&vetorAlunos[i], &vetorAlunos[posicaoMenor]);
    }
}

int delimitaTamVetor(aluno vetorAlunos[], int numDados) 
{
    int i;
    for (i = 0; i < numDados; i++) 
    {
        if(vetorAlunos[i].prontuario == 0) {
            return i;
        }
    }
}



int ordenaCadastro(aluno vetorAlunos[], int numDados, int *tipoOrd) 
{
    if (checaSeCadastroVazio(vetorAlunos,numDados) == 1) 
    {
        printf("\nImpossível ordenar cadastro, não há alunos cadastrados!\n");
        return -1;
    }  else 
    {
        char op[100];
        int intOrd; //armazena o valor do tipo de ordenação desejada
        int intOp; //armazena o valor do tipo de algorítimo será utilizado
        int i;//contador
        int tamVetor = delimitaTamVetor(vetorAlunos, numDados);
        i = 0;//inicializa contador para controle do loop while
        intOrd = 0; //inicializa a variável com um valor inválido para o loop while
        while (intOrd < 1 || intOrd > 7)
        {
            if (i > 0) 
            {
                printf("\nOpção inválida!\n");
            }
            //1 = nome e sobrenome, 2 = sobrenome e nome,  3 = curso, 4 = data nascimento e 5 = prontuário)
            printf("\n--------------- Ordena cadastro ----------------\n\n");
            printf("[1] - Ordena por nome e sobrenome\n");
            printf("[2] - Ordena por sobrenome e nome\n");
            printf("[3] - Ordena por curso\n");
            printf("[4] - Ordena por data de nascimento\n");
            printf("[5] - Ordena por prontuário\n");
            printf("[6] - voltar ao menu\n");
            printf("\n-------------------------------------------------\n");
            printf("Selecione uma opção: ");
            fgets(op, 100, stdin);
            intOrd = validaInteiro(op);
            i++;//atualiza contador
        }
        if (intOrd == 6)  //sai da função e volta para o menu
        { 
            return -1;
        } 
        i = 0;//reinicializa o contador para controle do loop while
        intOp = 0; //inicializa a variável com um valor inválido para o loop while
        //continua código se intOrd != 6
        while (intOp < 1 || intOp > 5)
        {
            if (i > 0) 
            {
                printf("\nOpção inválida!\n");
            }
            printf("\n-------- Selecionando tipo de ordenação --------\n\n");
            printf("[1] - Ordenação por particionamento (quick sort) \n");
            printf("[2] - Ordenação por intercalação (merge sort)\n");
            printf("[3] - Ordenação por inserção (insertion sort)\n");
            printf("[4] - Ordenação por seleção (selection sort)\n");
            printf("[5] - voltar ao menu\n");
            printf("\n-------------------------------------------------\n");
            printf("Selecione uma opção: ");
            fgets(op, 100, stdin);
            intOp = validaInteiro(op);
            i++;//atualiza contador
        }
        switch (intOp) 
        {
            case 1:
                ordenarParticionamento(vetorAlunos, 0, tamVetor-1, intOrd);
                break;
            case 2:
                ordenarIntercalacao(vetorAlunos, 0, tamVetor-1, intOrd);
                break;
            case 3:
                ordenarInsercao(vetorAlunos, tamVetor, intOrd);
                break;
            case 4:
                ordenarSelecao(vetorAlunos, tamVetor, intOrd);
                break;
            case 5:
                //retorna menu
                break;
        }
        *tipoOrd = intOrd; //altera a variável que indica o tipo de ordenação
        return -1;
    }   
}

void salvar(aluno vetorAlunos[], int numDados, int *tipoOrd) 
{
    FILE *arquivo;
    int i, salvar, estadoOrdVetor;
    //salvando os dados dos alunos
    arquivo = fopen("cadastro_alunos", "wb");
    if (arquivo == NULL)
    {
        printf("\nOs registro não podem ser salvos!\n");
    } else 
    {
        for (i = 0; i < numDados-1; i++)
        {
            if(strlen(vetorAlunos[i].nome) != 0)
            {
                salvar = fwrite(&vetorAlunos[i], sizeof(aluno), 1 , arquivo);
            }     
        }
        fclose(arquivo);  
        if(salvar == 0) 
        {
            printf("\nErro no salvamento dos registros!\n");
        }else 
        {
            printf("\nRegistros salvos!\n");
        }      

    }
    //salvando o estado de organização do vetor
    estadoOrdVetor = *tipoOrd;
    arquivo = fopen("estado_vetor", "wb");
    if (arquivo == NULL)
    {
        printf("\nOs estado de organização do vetor não pode ser salvo!\n");
    } else 
    {
        salvar = fwrite(&estadoOrdVetor, sizeof(int), 1 , arquivo);
        fclose(arquivo);  
        if(salvar == 0) 
        {
            printf("\nErro no salvamento dos registros!\n");
        }else 
        {
            printf("\nEstado de ordenação do vetor salvo!\n");
        }      
    }
}

void carregar(aluno vetorAlunos[], int numDados, int *tipoOrd) 
{
    
    FILE *arquivo;
    int i, carrega, finalArquivo, estadoOrdVetor;
    //carrega os dados dos alunos do arquivo
    arquivo = fopen("cadastro_alunos", "rb");
    if (arquivo == NULL)
    {
        printf("\nOs registro dos alunos não pode ser carregados!\n");
    } else 
    {
        i = 0;
        while (i < numDados-1 && feof(arquivo) == 0) 
        {
            carrega = fread(&vetorAlunos[i], sizeof(aluno), numDados , arquivo);
            i++;
        }
        finalArquivo = feof(arquivo);
        fclose(arquivo);  
        if(carrega > 0 && finalArquivo == 1) 
        {
            printf("\nRegistros carregados!\n");

        }else 
        {
            printf("\nErro no carregamento dos registros!\n");
            printf("%d - %d - %d",carrega, finalArquivo, estadoOrdVetor);
        }      
    }
    //carrega os estado de organização do vetor do arquivo 
    arquivo = fopen("estado_vetor", "rb");
    if (arquivo == NULL)
    {
        printf("\nO estado de ordenação de vetor não pode ser carregado!\n");
    } else 
    {
        carrega = fread(&estadoOrdVetor, sizeof(int), 1 , arquivo);
        finalArquivo = feof(arquivo);
        fclose(arquivo); 
        *tipoOrd = estadoOrdVetor;
        if(carrega > 0) 
        {
            printf("\nEstado de organização do vetor carregado com sucesso!\n");
        }else 
        {
            printf("\nErro no carregamento do estado de organização do vetor!\n");
        }      
    }
}