#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char elem;
    struct node* link;
}*NodePtr, Node;

typedef struct {
    NodePtr front;
    NodePtr rear;
}Queue;


Queue initQueue();
bool isEmpty(Queue A);
char front(Queue A);  
void enqueue(Queue* A, char elem);
void dequeue(Queue* A);
void displayQueue(Queue A);
void makeNull(Queue* A);


int main(){
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
    temp.front = NULL;
    temp.rear = NULL;
    return temp;
}

bool isEmpty(Queue A){
    return(A.front == NULL)? 1:0;
}

char front(Queue A){
    return(!isEmpty(A))? A.front->elem:'-';
}

void enqueue(Queue* A, char elem){
    NodePtr temp = (NodePtr)malloc(sizeof(Node));
    if(temp != NULL){
        temp->elem = elem;
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
    NodePtr temp = A->front;
    A->front = temp->link;
    if(A->front == NULL){
        A->rear == NULL;
    }
    free(temp);

}
void displayQueue(Queue A){
    if(!isEmpty(A)){
        NodePtr temp = A.front;
        while(A.front != NULL){
            printf("%c ",A.front->elem);
            A.front = A.front->link;
        }
        A.front = temp;
        printf("\n");
    }else{
        printf("Empty\n");
    }
}
void makeNull(Queue* A){
    while(A->front != NULL){
        dequeue(A);
    }
}