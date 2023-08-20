#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int saveIntInAFile(int *p){
    FILE *file;
    int result;
    file = fopen("test", "wb");
    if(file == NULL) 
    {
        return 0;
    } else 
    {
        result = fwrite(p, sizeof(p), 1, file);
        if(result == 0) {
            fclose(file);
            return 0;
        }
        fclose(file);
        return 1;
    }
}
int loadIntFromFile(int *p)
{
    FILE *file;
    int result;
    file = fopen("test", "rb");
    if(file == NULL) 
    {
        return 0;
    } else 
    {
        while(!feof(file)) {
            result = fread(p, sizeof(p), 1, file);
        }
        if(result != 1 && !feof(file)) {
                fclose(file);
                return 0;
        }
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