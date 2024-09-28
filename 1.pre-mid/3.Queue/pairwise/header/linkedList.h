#ifndef linkedList_h
#define linkedList_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    char data;
    struct node* link;
}*ptr;

typedef struct {
    ptr front;
    ptr rear;
}Queue;

Queue initQueue(){
    Queue temp;
    temp.front = NULL;
    temp.rear = NULL;
    return temp;
}

bool isEmpty(Queue A){
    return(A.front == NULL)? 1:0;
}

char front(Queue A){
    return(!isEmpty(A))? A.front->data:'#';
}

void enqueue(Queue* A, char elem){
    ptr temp = (ptr)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = elem;
        temp->link = NULL;
        if(isEmpty(*A)){
            A->front = temp;
        }else{
            A->rear->link = temp;
        }
        A->rear = temp;
    }
}

void dequeue(Queue* A){
    ptr temp;
    temp = A->front;
    A->front = temp->link;
    if(A->front == NULL){
        A->rear = NULL;
    }
    free(temp);
}

void displayQueue(Queue* A){
    printf("Queue Q: ");
    if(isEmpty(*A)){
        printf("Empty\n\n");
    }else{
        Queue temp = initQueue();
        while(!isEmpty(*A)){
            char data = front(*A);
            printf("%c ",data);
            enqueue(&temp, data);
            dequeue(A);
        }

        while(!isEmpty(temp)){
            char data = temp.front->data;
            enqueue(A, data);
            dequeue(&temp);
        }
        printf("\n\n");
    }

}
#endif