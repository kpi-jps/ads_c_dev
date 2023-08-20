#include <stdlib.h>
#include <stdio.h>

 void printIntPointer(int *p) 
{   
    printf("Poiter value = %d \n", *p);
    printf("Poiter memory adress = %d\n", &p);
    printf("Variable pointed memory adress = %d\n", p);
        
}
int main() 
{   

    int *p1;
    int i = 10;
    char *p2; 
    char c = 'a';
    p1 = &i;
    p2 = &c;

    printf("*p1 = %i \n",*p1);
    printf("p1 = %i \n",p1);
    printf("&i = p1 = %i \n",&i);
    printf("\n");
    printIntPointer(p1);
    return 0;
   
}