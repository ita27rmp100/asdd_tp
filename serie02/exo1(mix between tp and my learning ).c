#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;   
}Node;
// create a node
Node* createnode(int value){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node==NULL){
        printf("Allocating failed");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node ;
}
// Insert at the beginnig / end
Node* insertbeg(Node *head,int value){
    Node *new_node = createnode(value);
    new_node->next = head;
    return new_node;
}
Node *insertend(Node *head,int value){
    Node *p = head;
    Node *new_node = createnode(value);
    if(head==NULL){
        return new_node;
    }
    while (p->next!=NULL)
    {
        p = p->next;
    }
    p->next = new_node;
    return new_node;
}
// Display
void display(Node *head){
    Node *p = head;
    while (p!=NULL)
    {
        printf("Data : %i | Address : %p\n",p->data,p->next);
        p = p->next;
    }
}
// free 
void freell(Node *head){
    Node *p = head;
    while (p!=NULL)
    {
        Node *temp = p;
        p = p->next;
        free(temp);
    }
    printf("Freeing done !");
}

int main(){
    Node *head = NULL;
    Node *first = NULL , *second = NULL ;

    head = insertbeg(head,10);
    first = insertend(head,30);
    second = insertend(head,50);

    display(head);

    freell(head);

    return 0;
}