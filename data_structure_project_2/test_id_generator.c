#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int createsId() 
{
    int id, result;
    FILE *file;
    //just creating the file if it doesn't exist
    //to do this is necessary creates the file to append content ("ab")
    file = fopen("id's", "ab");
    if (file == NULL) 
    {
        fclose(file);
        return -1;
    }
    fclose(file);
    file = fopen("id's", "rb");
    if (file == NULL) 
    {
        fclose(file);
        return -1;
    }
    result = fread(&id, sizeof(id), 1, file);
    if(result == 0) {
        id = 1;
    }
    fclose(file);
    id++;
    file = fopen("id's", "wb");
    result = fwrite(&id, sizeof(id), 1, file);
    fclose(file);
    return --id;  
}


int main()

{   
   
    printf("id = %d \n", createsId());
        
    return 0;
}