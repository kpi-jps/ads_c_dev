/******************************************************************************
Ex.4 - Aprimore o programa 3, para que ele imprima os 20 primeiros
números primos.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int num = 2, i = 0, j;
    printf("Os 20 primeiros números primos são: \n ");
        
        while (i < 20) 
        {
            j = 2;
            while (num % j != 0) 
            {
                j++;
            }
            if (num == j) 
            {
               if(i == 19) 
               {
                   printf("%i", num);
               }
               else 
               {
                   printf("%i,", num);
               }
                
               i++;
            }
            num++;
        }
    return 0;
}
