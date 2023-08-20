#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int loadIntFromFile()
{
    FILE *file;
    
    file = fopen("musics.txt", "r");
    if(file == NULL) 
    {
        return 0;
    } else 
    {
        char str[1000];
        fgets(str, strlen(str), file);
        fclose(file);
        printf("%s", str);
        return 1;
    }
}
int main()
{   
    
    loadIntFromFile();
    
    return 0;
}