#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define INPUT_LENGTH 200

int check_input(char input[], int numbers[]) 
{
    int i, j = 0, input_length = strlen(input), num_length = 0;
    char str_num[INPUT_LENGTH];

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

int main()
{
    int numbers[INPUT_LENGTH];
    int numbers_length, i;
    char input[INPUT_LENGTH];
    printf("Entre com valores inteiros separados por espaço\n");
    fgets(input, INPUT_LENGTH, stdin);
    numbers_length = check_input(input, numbers);
    printf("%d\n", numbers_length);
    if (numbers_length) {
        for (i = 0; i < numbers_length; i++) {
            printf("%d\n", numbers[i]);
        }
    }
    
    return 0;
}