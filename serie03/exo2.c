// implementation of queue using array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// definition
#define max 100
typedef struct node{
        int data;
        struct node *next;
}node;
typedef struct
    {
        node *front , *rear;
    }Queue;
// implementation
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
// concerned function
    // counts
int lenQ(Queue Q){
    int l = 0;
    node* temp = Q.front;
    while (temp!=NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}
    // display
void dispQ(Queue Q){
    int i=1;
    node* temp = Q.front;
    printf("element N°i |data|prip|");
    while (temp!=NULL)
    {
        temp = temp->next;
        printf("element N°%i | %i | %i\n",temp->data,5);
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
    dispQ(q);
}