#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    char elem[MAX];
    int front;
    int rear;
} Queue;

Queue initQueue();
bool isEmpty(Queue A);
bool isFull(Queue A);
char front(Queue A);  
void enqueue(Queue* A, char elem);
void dequeue(Queue* A);
void displayQueue(Queue A);
void makeNull(Queue* A);

int main() {
    system("cls");
    Queue Q = initQueue();

    printf("\ninitQueue()\n");
    printf("Queue Q: ");
    displayQueue(Q);

    printf("\nenqueue(A, B, C, D)\n");
    printf("Queue Q: ");
    enqueue(&Q, 'A');
    enqueue(&Q, 'B');
    enqueue(&Q, 'C');
    enqueue(&Q, 'D');
    displayQueue(Q);

    printf("\nFront element: %c\n", front(Q)); 

    printf("\ndequeue()\n");
    printf("Queue Q: ");
    dequeue(&Q);
    displayQueue(Q);

    printf("\nmakeNull()\n");
    printf("Queue Q: ");
    makeNull(&Q);
    displayQueue(Q);
    
    return 0;
}

Queue initQueue(){
    Queue temp;
    temp.front = 0;
    temp.rear = MAX-1;
    return temp;
}

bool isEmpty(Queue A){
    return ((A.rear + 1)%MAX == A.front)? 1:0;
}

bool isFull(Queue A){
    return ((A.rear + 2)%MAX == A.front)? 1:0;
}

char front(Queue A){
    return(!isEmpty(A))? A.elem[A.front]:'-';
}

void enqueue(Queue* A, char elem){
    if(!isFull(*A)){
        A->rear = (A->rear+1)% MAX;
        A->elem[A->rear] = elem;
    }
}

void dequeue(Queue* A){
    if(!isEmpty(*A)){
        A->front = (A->front +1)% MAX;
    }
}

void displayQueue(Queue A){
    if(!isEmpty(A)){
        int temp = A.front;
        while(A.front != A.rear + 1){
            printf("%c ",A.elem[A.front]);
            A.front = (A.front+1)% MAX;
        }
        A.front = temp;
        printf("\n");
    }else{
        printf("Empty\n");
    }
}

void makeNull(Queue* A){
    A->front = 0;
    A->rear= MAX-1;
}
