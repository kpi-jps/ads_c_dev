/*
Especificações do trabalho
1. O programa deve manter um cadastro de uma coleção de músicas em uma lista duplamente
encadeada.
A Estrutura que armazena os dados das músicas é dada por:
    typedef struct musica {
        int id;
        char titulo[200];
        char artista[200];
        char album[200];
        int duracao; //segundos
    } musica;
A estrutura da lista duplamente encadeada de músicas é dada por:
    typedef struct musica_no {
        musica *musica;
        struct musica_no *ant;
        struct musica_no *prox;
    } musica_no;
2. Deve haver uma função que cadastra novas músicas e as insere na lista duplamente encadeada.
3. Deve haver uma função que imprime todas as músicas da lista. O formato para a impressão da
duração deve converter segundos para o formato horas, minutos e segundos: HH:MM:SS.
4. Deve haver uma função para a criação de playlists em que o usuário indica pelo teclado de uma
string contendo os ids das músicas ex: “1 5 10 13 8 9 15”, na forma de listas circulares de músicas.
A estrutura da lista circular de músicas de uma playlist é dada por:
typedef struct playlist_no {
musica *musica;
struct playlist_no *prox;
} playlist_no;
Não devem ser criadas na memória cópias das músicas para sua inserção em playlists, elas devem
compartilhar as estruturas do tipo música já existentes na lista duplamente encadeada,
armazenando seus endereços.
5. As playlists são cadastradas em uma lista simplesmente encadeada.
A estrutura da lista simplesmente encadeada de playlists é dada por:
typedef struct lplaylists_no {
int id;
char nome[200];
playlist_no *musicas;
struct lplaylists_no *prox;
} lplaylists_no;
6. Deve haver uma função shuffle que altera aleatoriamente a ordem das músicas dentro de uma
playlist.
7. Deve haver uma função que imprime uma playlist.
8. Deve haver uma função que remove as músicas da lista duplamente encadeada e de todas as
playlists em que participa.
*/

//-----------------------------------
//libraries
//-----------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>
//-----------------------------------
//defining constants
//-----------------------------------
#define CHAR_INPUT 200
#define FILE_NAME_LENGTH 200
#define MUSIC_FILE "musics.txt"
#define PLAYLISTS_FILE "playlists.txt"
#define BLANCK '|'
//-----------------------------------
//defining data type
//-----------------------------------
//music
typedef struct music {
    int id;
    char title[CHAR_INPUT];        
    char artist[CHAR_INPUT];
    char album[CHAR_INPUT];
    int duration; //seconds
} music_slot;
//music list 
typedef struct music_node {
    music_slot *music;
    struct music_node *previous;
    struct music_node *next;
} music_node;
//playlist
typedef struct playlist_node {
    music_slot *music;
    struct playlist_node *next;
} playlist_node;
//playlists
typedef struct playlists_node {
    int id;
    char name[CHAR_INPUT];
    playlist_node *musics; //put here the head node next
    struct playlists_node *next;
} playlists_node;

//-----------------------------------
//defining functions
//-----------------------------------

//starts the random number generator, allowing that function randon_int
//returns unpredictable numbers (ref: https://www.ime.usp.br/~pf/algoritmos/aulas/random.html)
void randomize (void);

//returns a random number in the close interval [low...high]
//(code copied from Eric Roberts randon library)
//(ref: https://www.ime.usp.br/~pf/algoritmos/aulas/random.html)
int random_int (int low, int high);

//receives a char vector and checks if the content correponding to a positive int,
//returning the char vector as an "int" if yes or -1 if not
int val_pos_int(char input[]);
//creates the app menu
void menu();
//saves a music in a file receiving asparameter a poiter to a music struct and returning 1 if 
//the save process occours or 0 if some error occours
int save_music(music_slot *music);
//inserts a music in the music list
void insert_music(music_node *headNode, music_slot *newMusic);
//searches an specific music using its id and returns its node on the linked list
music_node *search_for_a_music(music_node *headNode, int id);
//adds a music adding it on linked list
void add_music(music_node *headNode);
//loads the musics from .txt file
int load_musics(music_node *headNode);
//lists and prints all musics added
void print_all_music(music_node *headNode);
//replace separators in txt files according to the mode used:
//mode = 1 - replace blanckspace(' ') by symbol defined by constant 'BLANCK'
//mode = 2 - replace symbol defined by constant 'BLANCK' by blanckspace(' ')
void replace_blancks(char str[], int mode);
//checks if the typed id's as input is valid values (only numbers are allowed), if yes
//returns an integer > 0 (that is the number of typed music id's), if not returns -1;
int check_input_ids(char input[], int numbers[]);
//checks if valid id's are presentes in music list, if yes returns an integer > 0
//(that is the number of typed music id's) , if not returns -1;
int check_search_ids(int numbers[], int num_length, music_node *music_head_node);
//searches an specific music playlist using its id and returns its node on the linked list
playlists_node *search_for_a_playlist(playlists_node *head_node, int id);
//add musics to a playlist
void add_musics_to_playlist(playlists_node *playlists_node, music_node *music_list_head, int ids[], int ids_length);
//adds a playlist to a list of playlists
void add_playlist(playlists_node *playlists_head, playlists_node *playlists_slot);
//creates a playlist
void creates_playlist(playlists_node *playlists_head, music_node *music_list_head);
//print playlists
void print_playlists(playlists_node *playlists_head);
//print all musics in playlist
void print_playlist_musics(playlists_node *playlists_head, music_node *music_list_head);
//returns the length of a playlist
int playlist_length(playlist_node *playlist_head);
//returns the music list length
int music_list_length(music_node *music_list_head);
//searches for a music in a playlist using its id, returning a pointer to it if
//music was found or NULL if not.
playlist_node *search_in_playlist(playlist_node *playlist_head, int music_id);
//shuffles a playlist
void shuffle_playlist(playlists_node *playlists_head, music_node *music_list_head);
//removes a music from playlists that have it
int remove_music_from_playlits(playlists_node *playlists_head, music_node *music_list_head, int music_id);
//remove a music from music lista
void remove_music(music_node *music_list_head, int music_id);
//starts the music delete process 
void delete_music(playlists_node *playlists_head, music_node *music_list_head);

int main()
{   
    //crating a music slot to be used by playlist_head and music_list_head
    music_slot *music;
    music =  malloc(sizeof(music_slot));

    //creating a playlist slot to be used by playlists_node
    playlist_node *playlist_head;
    playlist_head = malloc(sizeof(playlist_node));
    playlist_head->music = music;
    playlist_head->next = NULL;
    
    //creating the head node for music list (dolbly linked-list)
    music_node *music_list_head;
    music_list_head = malloc(sizeof(music_node));
    music_list_head->next = NULL;
    music_list_head->music = music;
    
    //creating the head node for playlists list (linked-list)
    playlists_node *playlists_head;
    playlists_head = malloc(sizeof(playlists_node));
    playlists_head->musics = playlist_head;
    playlists_head->next = NULL;
    
    load_musics(music_list_head);

    menu(playlists_head, music_list_head);

    return 0;
}

void randomize (void)
{
    srand (time (NULL));
}

int random_int (int low, int high)
{
    randomize();
    double d;
    d = (double) rand () / ((double) RAND_MAX + 1);
    int k = d * (high - low + 1);
    return low + k;
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

void menu(playlists_node *playlists_head_node, music_node *music_head_node)
{
    int menu = 1; //true
    char option[CHAR_INPUT];
    int intOption;
    while(menu) {
        printf("\n#Menu:\n");
        printf("[1] Adicionar música\n");
        printf("[2] Listar músicas\n");
        printf("[3] Criar playlist\n");
        printf("[4] Listar playlists\n");
        printf("[5] Listar músicas de uma playlists\n");
        printf("[6] Reordenar playlist\n");
        printf("[7] Deletar musica\n");
        printf("[8] Finalizar programa\n");
        printf("Escolha uma opção:\n");
        fgets(option, CHAR_INPUT, stdin);
        intOption = val_pos_int(option);
        switch (intOption)
        {
        case 1:
            printf("\n\n");
            add_music(music_head_node);
            break;
        case 2:
            printf("\n\n");
            print_all_music(music_head_node);
            break;
        case 3:
            printf("\n\n");
            creates_playlist(playlists_head_node ,music_head_node);
            break;
        case 4:
            printf("\n\n");
            print_playlists(playlists_head_node);
            break;
        case 5:
            printf("\n\n");
            print_playlist_musics(playlists_head_node ,music_head_node);
            break;
        case 6:
            printf("\n\n");
            shuffle_playlist(playlists_head_node ,music_head_node);
            //printf("Tamanho lista de músicas %d\n",  music_list_length(music_head_node));
            //printf("O maior id é %d\n",  max_music_id(music_head_node));
            //menu = 0;//false
            break;
        case 7:
            printf("\n\n");
            delete_music(playlists_head_node, music_head_node);
            
            break;
        case 8:
            printf("Programa finalizado!\n");
            menu = 0;//false
            break;
        default:
            printf("Opção inválida\n");
            break;
        }

    }
}

int save_music(music_slot *music) {
    FILE *file;
    int result;
    music_slot music_aux;
    music_aux.id = music->id;
    music_aux.duration = music->duration;
    strcpy(music_aux.title, music->title);
    replace_blancks(music_aux.title,1);
    strcpy(music_aux.artist, music->artist);
    replace_blancks(music_aux.artist,1);
    strcpy(music_aux.album, music->album);
    replace_blancks(music_aux.album,1);
    file = fopen(MUSIC_FILE, "a");
    if(file == NULL) 
    {
        return 0;
    } else 
    {
        fprintf(file, "%d %s %d %s %s\n", music_aux.id, music_aux.title, music_aux.duration, music_aux.artist, music_aux.album);
        fclose(file);
        return 1;
    }
}

void insert_music(music_node *head_node, music_slot *new_music) 
{
    music_node *music;
    music = malloc(sizeof(music_node));
    music->music = new_music; 
    music->next = head_node->next;
    music->previous = head_node;
    if(head_node->next) head_node->next->previous = music;
    head_node->next = music;
}

music_node *search_for_a_music(music_node *head_node, int id) 
{
    music_node *pointer = head_node;
    while (pointer && pointer->music->id != id) 
        pointer = pointer->next;
    return pointer;  
}

void add_music(music_node *head_node) 
{   
    printf("\"Adicionar música\"\n");
    printf("Obs: Para cancelar a operação deixe qualquer um dos campos em branco e pressione \"ENTER\"!\n");
    music_slot *music;
    music = malloc(sizeof(music));
    char duration[CHAR_INPUT]; 
    int checkFile;
    char id[CHAR_INPUT];
    printf("Entre com o um valor inteiro para \"id\" da música:\n");
    fgets(id, CHAR_INPUT, stdin);
    while (val_pos_int(id) == -1 || search_for_a_music(head_node, val_pos_int(id)) != NULL)
    {
        if(strcmp(id, "\n") == 0) {
            printf("Operação cancelada!\n");
            free(music);
            return;
        }
        printf("Valor inválido ou já utilizado por outra música!\n");
        printf("Entre com o um valor inteiro para \"id\" da música:\n");
        fgets(id, CHAR_INPUT, stdin);
    }
    music->id = val_pos_int(id);
    printf("Entre com o título da música:\n");
    fgets(music->title, CHAR_INPUT, stdin);
    if(strcmp(music->title, "\n") == 0) {
        printf("Operação cancelada!\n");
        free(music);
        return;
    }
    music->title[strlen(music->title)-1] = ' ';
    printf("Entre com a duração da música em segundos (apenas números):\n");
    fgets(duration, CHAR_INPUT, stdin);
    while (val_pos_int(duration) == -1 || val_pos_int(duration) == 0) 
    {
        if(strcmp(duration, "\n") == 0) {
            printf("Operação cancelada!\n");
            free(music);
            return;
        }
        printf("O valor inválido!\n"); 
        printf("Entre com a duração da música em segundos (apenas números):\n");
        fgets(duration, CHAR_INPUT, stdin);
    }
    music->duration = val_pos_int(duration);
    printf("Entre com o nome do artista:\n");
    fgets(music->artist, CHAR_INPUT, stdin);
    if(strcmp(music->artist, "\n") == 0) {
        printf("Operação cancelada!\n");
        free(music);
        return;
    }
    music->artist[strlen(music->artist)-1] = ' ';
    printf("Entre com o nome do álbum:\n");
    fgets(music->album, CHAR_INPUT, stdin);
    if(strcmp(music->album, "\n") == 0) {
        printf("Operação cancelada!\n");
        free(music);
        return;
    }
    music->album[strlen(music->album)-1] = ' ';
    checkFile = save_music(music);
    if(checkFile) {
        insert_music(head_node, music);
        printf("Música adicionada!\n\n");
    } else {
        printf("Erro ao adicionar música!\n\n");
    } 
}

int load_musics(music_node *head_node) {
    FILE *file;
    file = fopen(MUSIC_FILE, "r");
    
    if(file == NULL) 
    {
        return 0;
    } else 
    {   
        int check_file = 1;
        music_slot music_aux;
        while(check_file != EOF) {
            music_slot *music;
            music = malloc(sizeof(music_slot));
            check_file = fscanf(file, "%d %s %d %s %s", &music_aux.id, music_aux.title, &music_aux.duration, music_aux.artist, music_aux.album);
            replace_blancks(music_aux.title,2);
            music->id = music_aux.id;
            music->duration = music_aux.duration;
            replace_blancks(music_aux.title,2);
            strcpy(music->title, music_aux.title);
            replace_blancks(music_aux.artist,2);
            strcpy(music->artist, music_aux.artist);
            replace_blancks(music_aux.album,2);
            strcpy(music->album, music_aux.album);
            if(check_file != EOF) 
            {
                insert_music(head_node, music);
            } else 
            {
                free(music);
            }
        }
        fclose(file);
        return 1;
    }
}

void print_all_music(music_node *head_node) {
    printf("\"Listando músicas\"\n");
    music_node *pointer = head_node->next;
    if(!pointer) {
        printf("Não há musicas cadastradas!\n");
        return;
    }
    printf("-----\n");
    while (pointer) {
        //music = pointer->music;
        int hours = (int)pointer->music->duration/3600;
        int minutes = (int)((pointer->music->duration%3600)/60);
        int seconds = (int)((pointer->music->duration%3600)%60);
        printf("#id: %d\n", pointer->music->id);
        printf("#título: %s\n", pointer->music->title);
        printf("#duração: ");
        if(hours < 10)
            printf("0");
        printf("%d:", hours);
        if(minutes < 10)
            printf("0");
        printf("%d:", minutes);
        if(seconds < 10)
            printf("0");
        printf("%d\n", seconds);
        printf("#artista: %s\n", pointer->music->artist);
        printf("#álbum: %s\n", pointer->music->album);
        printf("-----\n");
        pointer = pointer->next;
    }
}

void replace_blancks(char str[], int mode)
{
    int i;
    switch (mode)
    {
    case 1:
        for (i = 0; i < strlen(str); i++) {
            if(str[i] == ' ') {
                str[i] = BLANCK; 
            }
        }
        break;
    
    case 2:
        for (i = 0; i < strlen(str); i++) {
            if(str[i] == BLANCK) {
                str[i] = ' '; 
            }
        }
        break;
    } 
} 

int check_input_ids(char input[], int numbers[]) {
    int i, j = 0, input_length = strlen(input), num_length = 0;
    char str_num[CHAR_INPUT];

    for (i = 0; i < input_length; i++){
        if(input[i] != ' ' && input[i] != '\n')
        {
            if(input[i] < '0' || input[i] > '9') {
                return -1;
            }  
        }
        if(input[i] == ' ') 
        {
            j = 0;
        }  
        if (input[i] > '0' && input[i] < '9') 
        {
            str_num[j++] = input[i];
            numbers[num_length++] = atoi(str_num);
        }     
    }
    return num_length;
};

int check_search_ids(int numbers[], int num_length, music_node *music_head_node) 
{
    int i;
    for (i = 0; i < num_length; i++) 
    {
        if(search_for_a_music(music_head_node, numbers[i]) == NULL)
            return -1;
    }
    return num_length;
} 

playlists_node *search_for_a_playlist(playlists_node *head_node, int id) 
{
    playlists_node *pointer = head_node;
    while (pointer && pointer->id != id) 
        pointer = pointer->next;
    return pointer;  
}

void add_musics_to_playlist(playlists_node *playlists_node, music_node *music_list_head, int ids[], int ids_length)
{
    int i;
    playlist_node *playlist_head;
    playlist_head = malloc(sizeof(playlist_node));
    playlist_node *playlist_slot;
    music_node *music_node;
    for (i = 0; i < ids_length; i++)
    {
        playlist_slot = malloc(sizeof(playlist_node));
        music_node = search_for_a_music(music_list_head, ids[i]);
        playlist_slot->music = music_node->music;
        if(i == 0) 
        {
            playlist_slot->next = playlist_head;
            playlist_head->next = playlist_slot;
        } else 
        {
            playlist_node *aux_pointer;
            aux_pointer = playlist_head->next;
            playlist_head->next = playlist_slot;
            playlist_slot->next = aux_pointer;

        }  
    }
    playlists_node->musics = playlist_head;
};

void add_playlist(playlists_node *playlists_head, playlists_node *playlists_slot) 
{
    if(!playlists_head->next) 
    {
        playlists_head->next = playlists_slot; 
        playlists_slot->next = NULL;
    } else 
    {
        playlists_node *aux_pointer;
        aux_pointer = playlists_head->next;
        playlists_head->next = playlists_slot;
        playlists_slot->next = aux_pointer;

    }
}

void creates_playlist(playlists_node *playlists_head, music_node *music_list_head) 
{
    playlists_node *new_playlist_slot;
    new_playlist_slot = malloc(sizeof(playlists_node));
    int numbers[CHAR_INPUT];//stores id's as numbers
    int check_input; //stores the check up for valid id's used as input (only number is allowed)
    int check_musics ; //stores the check up for the search of id's on music list
    char id[CHAR_INPUT];
    char musics_ids[CHAR_INPUT];
    printf("\"Criar playlist\"\n");
    printf("Obs: Para cancelar a operação deixe qualquer um dos campos em branco e pressione \"ENTER\"!\n");
    printf("Entre com o um valor inteiro para \"id\" da playlist:\n");
    fgets(id, CHAR_INPUT, stdin);
    while (val_pos_int(id) == -1 || search_for_a_playlist(playlists_head, val_pos_int(id)) != NULL)
    {
        if(strcmp(id, "\n") == 0) {
            printf("Operação cancelada!\n");
            free(new_playlist_slot);
            return;
        }
        printf("Valor inválido ou já utilizado por outra playlist!\n");
        printf("Entre com o um valor inteiro para \"id\" da playlist:\n");
        fgets(id, CHAR_INPUT, stdin);
    }
    new_playlist_slot->id = val_pos_int(id);
    printf("Entre com o nome da playlist:\n");
    fgets(new_playlist_slot->name, CHAR_INPUT, stdin);
    if(strcmp(new_playlist_slot->name, "\n") == 0) {
        printf("Operação cancelada!\n");
        free(new_playlist_slot);
        return;
    }
    new_playlist_slot->name[strlen(new_playlist_slot->name)-1] = ' ';
    check_input = -1;
    check_musics = -1;
    while (check_input == -1 || check_musics == -1)
    {
        printf("Entre com o id's das músicas separados por espaço:\n");
        fgets(musics_ids, CHAR_INPUT, stdin);
        if(strcmp(musics_ids, "\n") == 0) {
            printf("Operação cancelada!\n");
            free(new_playlist_slot);
            return;
        }
        check_input = check_input_ids(musics_ids, numbers);
        if(check_input != -1) 
            check_musics = check_search_ids (numbers, check_input, music_list_head);

        if (check_input == -1 || check_musics == -1)
            printf("Id's invalidos ou não presentes na lista de músicas:\n"); 
    } 
   
    add_musics_to_playlist(new_playlist_slot, music_list_head, numbers, check_input); 
    add_playlist(playlists_head, new_playlist_slot);
  
    
}

void print_playlists(playlists_node *playlists_head)
{
    printf("\"Listando playlists\"\n");
    playlists_node *pointer = playlists_head->next;
    if(!pointer) {
        printf("Não há playlists cadastradas!\n");
        return;
    }
    printf("-----\n");
    printf("#id - nome\n");
    printf("-----\n");
    while (pointer) {
        printf("%d - %s\n", pointer->id, pointer->name);
        pointer = pointer->next;
        printf("-----\n");
    }
}


void print_playlist_musics(playlists_node *playlists_head, music_node *music_list_head) 
{   
    
    char str_id[CHAR_INPUT];
    playlists_node *playlist_slot;
    playlist_slot = NULL;
    int id = -1;
    printf("\"Listando música de uma playlist\"\n");
    printf("Obs: Para cancelar a operação deixe qualquer um dos campos em branco e pressione \"ENTER\"!\n");
    while (id == -1 ||  playlist_slot == NULL)
    {
        printf("Entre com o um valor inteiro para \"id\" da playlist:\n");
        fgets(str_id, CHAR_INPUT, stdin);
        if(strcmp(str_id, "\n") == 0) {
            printf("Operação cancelada!\n");
            return;
        }
        id = val_pos_int(str_id);
        playlist_slot = search_for_a_playlist(playlists_head, val_pos_int(str_id));
        if (id == -1 ||  playlist_slot == NULL)
            printf("Valor inválido ou não existe playlist com este id!\n");   
    }
    playlist_node *aux_pointer = playlist_slot->musics;
    playlist_node *pointer = playlist_slot->musics->next;
    printf("-----\n");
    while (pointer != aux_pointer) {
        //music = pointer->music;
        int hours = (int)pointer->music->duration/3600;
        int minutes = (int)((pointer->music->duration%3600)/60);
        int seconds = (int)((pointer->music->duration%3600)%60);
        printf("#id: %d\n", pointer->music->id);
        printf("#título: %s\n", pointer->music->title);
        printf("#duração: ");
        if(hours < 10)
            printf("0");
        printf("%d:", hours);
        if(minutes < 10)
            printf("0");
        printf("%d:", minutes);
        if(seconds < 10)
            printf("0");
        printf("%d\n", seconds);
        printf("#artista: %s\n", pointer->music->artist);
        printf("#álbum: %s\n", pointer->music->album);
        printf("-----\n");
        pointer = pointer->next;
    }
}

int playlist_length(playlist_node *playlist_head)
{
    
    playlist_node *playlist;
    playlist = playlist_head->next;
    int count = 0;
    while(playlist != playlist_head)
    {
        playlist = playlist->next;
        count++;
    }
    return count;
}

playlist_node *search_in_playlist(playlist_node *playlist_head, int music_id)
{
    playlist_node *playlist;
    playlist = playlist_head->next;
    while(playlist != playlist_head)
    {
        if(playlist->music->id == music_id)
            return playlist;
        playlist = playlist->next;
    }
    return NULL;
}

void shuffle_playlist(playlists_node *playlists_head, music_node *music_list_head) 
{
    char str_id[CHAR_INPUT];
    playlists_node *playlist_slot;
    playlist_node *playlist;
    playlist_node *playlist_head;
    playlist_node *playlist_aux;
    music_slot *music_aux;
    playlist_slot = NULL;
    int length_playlist;
    int id = -1;
    int i, int_random;
    
    printf("\"Reordenando playlist\"\n");
    printf("Obs: Para cancelar a operação deixe qualquer um dos campos em branco e pressione \"ENTER\"!\n");
    while (id == -1 ||  playlist_slot == NULL)
    {
        printf("Entre com o um valor inteiro para \"id\" da playlist:\n");
        fgets(str_id, CHAR_INPUT, stdin);
        if(strcmp(str_id, "\n") == 0) {
            printf("Operação cancelada!\n");
            return;
        }
        id = val_pos_int(str_id);
        playlist_slot = search_for_a_playlist(playlists_head, val_pos_int(str_id));
        if (id == -1 ||  playlist_slot == NULL)
            printf("Valor inválido ou não existe playlist com este id!\n");   
    }
    playlist_head = playlist_slot->musics;
    playlist = playlist_head->next;
    length_playlist = playlist_length(playlist_head);
    
    while(playlist != playlist_head) 
    {
        playlist_aux = playlist_head->next;
        int_random = random_int(0, length_playlist-1);
        for (i = 0; i < int_random; i++) {
            playlist_aux = playlist_aux->next;
        }
            
        music_aux = playlist->music;
        playlist->music = playlist_aux->music;
        playlist_aux->music = music_aux;
        playlist = playlist->next;
    }
}

int music_list_length(music_node *music_list_head)
{
    music_node *pointer = music_list_head->next;
    int count = 0;
    while(pointer)
    {
        pointer = pointer->next;
        count++;
    }
        
    return count;
}

int remove_music_from_playlits(playlists_node *playlists_head, music_node *music_list_head, int music_id) 
{   
    playlists_node *playlist_slot;
    playlists_node *playlist_slot_next;
    playlists_node *playlist_slot_previous;
    playlist_slot_previous = playlists_head;
    playlist_slot = playlists_head->next;
    playlist_node *playlist;
    playlist_node *playlist_head;
    playlist_node *next_playlist;
    playlist_node *previous_playlist;
    int check = 0;
    int playlist_music_id;
    int length_playlist;
    while(playlist_slot) 
    {
        playlist_head = playlist_slot->musics;
        playlist = playlist_head->next;
        previous_playlist = playlist_head;
        next_playlist = playlist->next;
        
        while(playlist != playlist_head)
        {
            length_playlist = playlist_length(playlist_head);
            playlist_music_id = playlist->music->id;
            if(length_playlist == 1 && playlist_music_id == music_id)
            {
                playlist = playlist_head; //getting out of while loop
            }
            else if(playlist->music->id == music_id) 
            {
                previous_playlist->next = playlist->next;
                free(playlist);
                playlist = playlist_head; //getting out of while loop
                check = 1;
            } else {
                previous_playlist = playlist;
                playlist = playlist->next;
                next_playlist = playlist->next;
            }
            
        }
        if(length_playlist == 1 && playlist_music_id == music_id)
        {
            playlist_slot_previous->next = playlist_slot->next;
            free(playlist_slot);
            playlist_slot = playlist_slot_previous->next;
        } else 
        {
            playlist_slot = playlist_slot->next;
        }   
    }
    return check;
}

void remove_music(music_node *music_list_head, int music_id)
{
    music_node *music = search_for_a_music(music_list_head, music_id);
    music_node *music_aux;
    music_aux = music->previous;
    music_aux->next = music->next;
    if(music->next) 
        music->next->previous = music_aux;
    free(music->music);
    free(music);
}

void delete_music(playlists_node *playlists_head, music_node *music_list_head)
{
    char str_id[CHAR_INPUT];
    music_node *music;
    music = NULL;
    int id = -1;
    int check;
    printf("\"Deletando música\"\n");
    printf("Obs: Para cancelar a operação deixe qualquer um dos campos em branco e pressione \"ENTER\"!\n");
    while (id == -1 ||  music == NULL)
    {
        printf("Entre com o um valor inteiro para \"id\" da musica\n");
        fgets(str_id, CHAR_INPUT, stdin);
        if(strcmp(str_id, "\n") == 0) {
            printf("Operação cancelada!\n");
            return;
        }
        id = val_pos_int(str_id);
        music = search_for_a_music(music_list_head, val_pos_int(str_id));
        if (id == -1 ||  music == NULL)
            printf("Valor inválido ou não existe música com este id!\n");   
    }
    check = remove_music_from_playlits(playlists_head, music_list_head, id);
    remove_music(music_list_head,id);
    if (check) 
    {
        printf("Música removida das playlists e da lista de músicas!\n");
        printf("A(s) playlist(s) que continha(m) apenas a música foi(foram) removida(s) por completo!\n");
    }
    else {
        printf("Música não encontrada na(s) playlist(s)!\n");
        printf("Música removida da lista de músicas!\n");
    }      
}