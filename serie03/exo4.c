// implementation of Stack using array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
// concerned function
    // S1 into S2
void s1Tos2(Stack *S1,Stack *S2){
    Stack s3;
    int i;
    CreateStack(&s3);
    while (isEmpty(S1)==false){
        pop(S1,&i);
        if(i%2 == 0){
            push(S2,&i);
        }
        else{
            push(&s3,&i);
        }
    }
    while(isEmpty(&s3)==false){
        pop(&s3,&i);
        push(S2,&i);
    }
}
    // copy even from S1 to S2
void copy(Stack *S1,Stack *S2){
    Stack s3;
    int i;
    CreateStack(&s3);
    while (isEmpty(S1) == false){
        pop(S1,&i);
        push(&s3,&i);
    }
    while(isEmpty(&s3) == false){
        pop(&s3,&i);
        push(S1,&i);
        if(i%2 == 0){
            push(S2,&i);
        }
    }
}
int main(){
    int value;
    Stack S1,S2,S3;
    CreateStack(&S1);
    CreateStack(&S2);
    CreateStack(&S3);
    for (int i = 0; i < 5; i++)
    {
        printf("Enter a value : ");
        scanf("%i",&value);
        push(&S1,&value);
    }
    copy(&S1,&S2);
    for (int i = 0; i < 5; i++)
    {
        pop(&S2,&value);
        printf("%i \n",value);        
    }
}