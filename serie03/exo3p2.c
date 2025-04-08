// implementation of Stack using array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 100
typedef struct node
    {
        int data;
        struct node *next
    }node;
typedef struct{
        int arr[max];
        int top;
    }Stack;
    

void CreateStack(Stack *S){
    S->top = -1;
}
bool isFull(Stack *S){
    return S->top ==max;
}
bool isEmpty(Stack *S){
    return S->top==-1;
}
void push(Stack *S,int *val){
    if (isFull(S))
    {
        printf("This Stack is full \n");
    }
    else{
        S->arr[S->top] = *val;
        S->top = S->top +1;
        printf("VALUE ADDED \n");
    }
}
void pop(Stack *S,int *c){
    if(isEmpty(S)){
        printf("Nothing to pop it");
    }
    else{
        *c = S->arr[S->top];
        S->top = S->top - 1;
    }
}

int main(){
    int value;
    Stack S;
    CreateStack(&S);
    for (int i = 0; i < 5; i++)
    {
        if (!isFull(&S))
        {
            printf("Enter a value : ");
            scanf("%i",&value);
            push(&S,&value);
        }
        else{
            printf("This Stack is empty \n");
            break;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        pop(&S,&value);
        printf("%i \n",value);        
    }
}