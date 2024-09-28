#ifndef array_h
#define array_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    char data[MAX];
    int front;
    int rear;
}Queue;

Queue initQueue(){
    Queue temp = {.front = 0, .rear = MAX-1};
    return temp;
}

bool isEmpty(Queue A){
    return((A.rear+1) % MAX == A.front)? 1:0;
}

bool isFull(Queue A){
    return((A.rear+2) % MAX == A.front)? 1:0;
}

char front(Queue A){
    return(!isEmpty(A))? A.data[A.front]:'#';
}

void enqueue(Queue* A, char elem){
    if(!isFull(*A)){
        A->rear = (A->rear+1) % MAX;
        A->data[A->rear] = elem;
    }
}

void dequeue(Queue* A){
    if(!isEmpty(*A)){
        A->front = (A->front+1) % MAX;
    }
}

void displayQueue(Queue* A) {
    Queue temp = initQueue();

    printf("Queue Q: ");
    if (isEmpty(*A)) {
        printf("Empty\n\n");
    } else {
        while (!isEmpty(*A)) {
            char data = A->data[A->front];
            printf("%c ", data);
            enqueue(&temp, data); 
            dequeue(A);           
        }

        while (!isEmpty(temp)) {
            char data = front(temp);  
            enqueue(A, data);         
            dequeue(&temp);           
        }
        printf("\n\n");
    }
}

#endif