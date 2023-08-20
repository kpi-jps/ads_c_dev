#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define INPUT_LENGTH 200

int check_input(char input[]) {
    int i, input_length = strlen(input);
    for (i = 0; i < input_length; i++){
        if(input[i] != ' ' && input[i] != '\n')
        {
            if(input[i] < '0' || input[i] > '9') {
                return 0;//false
            }  
        }
    }
    return 1;
};

int main()
{
    char input[INPUT_LENGTH];
    printf("Entre com valores inteiros separados por espaço\n");
    fgets(input, INPUT_LENGTH, stdin);
    printf("%d\n", check_input(input));
    return 0;
}