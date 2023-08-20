typedef struct data 
{
    int dia;
    int mes;
    int ano;
} data;

int comparaDatas(data data1, data data2) 
{
   if (data1.ano == data2.ano && data1.mes == data2.mes && data1.dia == data2.dia)
   {
       return 0;
   } else if(data1.ano > data2.ano) {
       return 1;
   } else
   {
       if (data1.mes > data2.mes) 
       {
           return 1;
       } else 
       {
           if(data1.dia > data2.dia)
           {
               return 1;
           } else 
           {
               return -1;
           }
       }
   }
}
int main()

{
    data data1;
    data data2;
    data1.ano = 1991;
    data1.mes = 12;
    data1.dia = 10;
    data2.ano = 1990;
    data2.mes = 12;
    data2.dia = 11;
    printf("\n%d\n", comparaDatas(data1, data2));
    return 0;
}