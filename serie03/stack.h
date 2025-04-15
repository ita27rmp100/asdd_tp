#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 100
typedef struct
{
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

#endif