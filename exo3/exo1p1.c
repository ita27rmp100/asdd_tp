// implementation of queue using array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 100
typedef struct
{
    int arr[max];
    int front,rear;
}Queue;

void CreateQueue(Queue *Q){
    Q->front = -1;
    Q->rear = -1;
}
bool isFull(Queue *Q){
    return (Q->front)==((Q->rear % max)+1);
}
bool isEmpty(Queue *Q){
    return (Q->rear==-1) && (Q->front==-1);
}
void Enqueue(Queue *Q,int *val){
    if (isFull(Q))
    {
        printf("This Queue is full \n");
    }
    else{
        Q->arr[Q->rear] = *val;
        Q->rear = (Q->rear+1)%max;
        printf("VALUE ADDED \n");
    }
}
void Dequeue(Queue *Q,int *c){
    if(isEmpty(Q)){
        printf("Nothing to deuque it");
    }
    else{
        *c = Q->arr[Q->front];
        Q->front = Q->front + 1;
    }
}

int main(){
    int value;
    Queue q;
    CreateQueue(&q);
    for (int i = 0; i < 5; i++)
    {
        if (!isFull(&q))
        {
            printf("Enter a value : ");
            scanf("%i",&value);
            Enqueue(&q,&value);
        }
        else{
            printf("This queue is empty \n");
            break;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        Dequeue(&q,&value);
        printf("%i \n",value);        
    }
}