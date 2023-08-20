#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int saveIntInAFile(int *p){
    FILE *file;
    int num = *p;
    file = fopen("test.txt", "w");
    if(file == NULL) 
    {
        return 0;
    } else 
    {
        fprintf(file, "%d", num);
        fclose(file);
        return 1;
    }
}


int loadIntFromFile(int *p)
{
    FILE *file;
    int num;
    file = fopen("test.txt", "r");
    if(file == NULL) 
    {
        return 0;
    } else 
    {
        fscanf(file, "%d", p);
        fclose(file);
        return 1;
    }
}
int main()
{   int *p1, *p2;
    int i = 55;
    int j = 0;
    int save, load;
    p1 = &i;
    save = saveIntInAFile(p1);
    if(save) 
        printf("Deu certo salvar \n");
    else
        printf("Deu merda em salvar! \n");
   
    load = loadIntFromFile(p2);
    
    if(load) 
        printf("Deu certo carregar \n");
    else
        printf("Deu merda em carregar! \n");
    printf("j = %d \n", j);
    j = *p2;
    printf("j = %d \n", j);
    return 0;
}