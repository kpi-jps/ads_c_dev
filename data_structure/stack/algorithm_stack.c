#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 100 

//defining the data type
typedef struct stack 
{
    int top;
    int items[STACKSIZE];
} stack;

//interface functions for stack data type

//checks if the stack is empty returning 1 (true) if yes and 0 (false) if not
int empty(stack *s) 
{
    if(s -> top == -1) 
    {
        return 1; //true
    } else 
    {
        return 0; //false
    }
}

//inserts an item on stack top, if the stack aren't full
void push(stack *s, int i) 
{
    if (s -> top == STACKSIZE-1) 
    {
        printf("Stack overflow!");
        exit(1); //finish the programm
    } else 
    {
        s -> top++;
        s -> items[s -> top] = i;
    }
}
//obs: the arrow operator (->) is used to access struct items when the struct is accessed as a pointer

//removes the item on stack top, if the stack aren't empty
int pop(stack *s)
{
    if(empty(s)) 
    {
        printf("Stack is underflow!");
        exit(1); //finish the programm
    } else 
    {
        int output = s->items[s->top];
        s -> top--;
        return output;
    }
}

int main() {
    stack s;
    s.top = -1; //initializing the top variable iquals to -1
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    printf("%d ", pop(&s));
    printf("%d ", pop(&s));
    printf("%d ", pop(&s));
    printf("%d ", pop(&s));
    printf("%d ", pop(&s));
    return 0;
}