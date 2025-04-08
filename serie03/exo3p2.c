// implementation of Stack using array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 100
typedef struct node
    {
        int data;
        struct node *next;
    }node;
typedef struct{
        node *top;
    }Stack;
    

void CreateStack(Stack *S){
    S->top = NULL;
}
bool isEmpty(Stack *S){
    return S->top==NULL;
}
void push(Stack *S,int *val){
    node *p = (node*)malloc(sizeof(node));
    p->next = S->top; 
    p->data = *val;
    S->top = p;
    printf("VALUE ADDED \n");
}
void pop(Stack *S,int *c){
    if(isEmpty(S)){
        printf("Nothing to pop it");
    }
    else{
        node *p = S->top;
        *c = S->top->data;
        S->top = S->top->next;
        free(p);
    }
}

int main(){
    int value;
    Stack S;
    CreateStack(&S);
    for (int i = 0; i < 5; i++)
    {
        printf("Enter a value : ");
        scanf("%i",&value);
        push(&S,&value);
    }
    for (int i = 0; i < 5; i++)
    {
        pop(&S,&value);
        printf("%i \n",value);        
    }
}