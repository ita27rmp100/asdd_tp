// implementation of queue using array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 100
typedef struct node{
        int data;
        struct node *next;
}node;
typedef struct
    {
        node *front , *rear;
    }Queue;

void CreateQueue(Queue *Q){
    Q->front = NULL;
    Q->rear = NULL;
}
bool isEmpty(Queue *Q){
    return (Q->rear==NULL) && (Q->front==NULL);
}
void Enqueue(Queue *Q,int *val){
    node *p = (node*)malloc(sizeof(node));
    p->data = *val;
    p->next = NULL;
    if (isEmpty(Q)){
        Q->front = p;
    }
    else{
        Q->rear->next = p;
    }
    Q->rear = p ;
    printf("VALUE ADDED \n");
}
void Dequeue(Queue *Q,int *c){
    if(isEmpty(Q)){
        printf("Nothing to deuque it");
    }
    else{
        node *p = Q->front;
        *c = Q->front->data;
        Q->front = Q->front->next;
        free(p);
    }
}

int main(){
    int value;
    Queue q;
    CreateQueue(&q);
    for (int i = 0; i < 5; i++)
    {
        printf("Enter a value : ");
        scanf("%i",&value);
        Enqueue(&q,&value);
    }
    for (int i = 0; i < 5; i++)
    {
        Dequeue(&q,&value);
        printf("%i \n",value);        
    }
}