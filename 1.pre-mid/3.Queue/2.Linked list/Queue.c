#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}*Node;

typedef struct{
    Node front;
    Node rear;
}Queue;

void initQueue(Queue* A);
void read(Queue A);
void enqueue(Queue* A,int elem);
void dequeue(Queue* A);
void makeEmpty(Queue* A);
void insertSorted(Queue* Q,int elem);

int main(){
    Queue Q;
    initQueue(&Q);

    printf("Enqueing (1,2,3,4,5): ");
    enqueue(&Q,1);
    enqueue(&Q,2);
    enqueue(&Q,3);
    enqueue(&Q,4);
    enqueue(&Q,5);
    read(Q);

    printf("\nDequeue(): \n");
    dequeue(&Q);
    read(Q);

    printf("\n\nEmpty():");
    makeEmpty(&Q);
    read(Q);

    printf("\n\nEnqueing (5,6,8,9,10): ");
    enqueue(&Q,5);
    enqueue(&Q,6);
    enqueue(&Q,8);
    enqueue(&Q,9);
    enqueue(&Q,10);
    read(Q);

    printf("\n\ninsertSorted(7): ");
    insertSorted(&Q,7);
    read(Q);

    return 0;
}

void initQueue(Queue* A){
    A->front = NULL;
    A->rear = NULL;
}

void enqueue(Queue* A,int elem){
    Node temp = (Node)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = elem;
        temp->next = NULL;
        if(A->front == NULL){
            A->front = temp;
        }else{
            A->rear->next = temp;
        }
        A->rear = temp;
    }
}

void dequeue(Queue* A){
    Node temp = A->front;
    A->front = temp->next;
    if(A->front == NULL){
        A->rear = NULL;
    }
    free(temp);
}

void read(Queue A){
    printf("\nQueue: ");
    if(A.front != NULL){
        Node i;
        for(i = A.front; i!= NULL; i=i->next){
            printf("%d ",i->data);
        }
    }else{
        printf("Empty\n");
    }
}

void makeEmpty(Queue* A){
    while(A->front != NULL){
        dequeue(A);
    }
}

void insertSorted(Queue* Q,int elem){
    Queue temp;
    initQueue(&temp);

    
    while(Q->front != NULL && Q->front->data < elem){
        enqueue(&temp,Q->front->data);
        dequeue(Q);
    }

    enqueue(&temp,elem);

    while(Q->front != NULL){
        enqueue(&temp,Q->front->data);
        dequeue(Q);
    }

    while(temp.front != NULL){
        enqueue(Q,temp.front->data);
        dequeue(&temp);
    }
}