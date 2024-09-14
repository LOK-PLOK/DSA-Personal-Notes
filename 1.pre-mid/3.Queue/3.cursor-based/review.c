#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 15

typedef struct {
    int front;
    int rear;
}Queue;

typedef struct{
    char elem;
    int link;
}Cell;

typedef struct {
    Cell Node[MAX];
    int avail;
}Heap;

void initHeap(Heap* VH);
int getSpace(Heap* VH);
void freeSpace(Heap* VH, int index);

Queue initQueue();
bool isEmpty(Queue A);
char front(Heap VH, Queue A);
void enqueue(Heap* VH, Queue* A, char elem);
void dequeue(Heap* VH, Queue* A);
void displayQueue(Heap VH,Queue A);
void makeNull(Heap* VH, Queue* A);


int main(){
    Queue Q = initQueue();
    Heap VH;
    initHeap(&VH);

    printf("\ninitQueue()\n");
    printf("Queue Q: ");
    displayQueue(VH,Q);

    printf("\nenqueue(A,B,C,D)\n");
    printf("Queue Q: ");
    enqueue(&VH,&Q,'A');
    enqueue(&VH,&Q,'B');
    enqueue(&VH,&Q,'C');
    enqueue(&VH,&Q,'D');
    displayQueue(VH,Q);

    printf("\nFront element: %c\n", front(VH,Q)); 

    printf("\ndequeue()\n");
    printf("Queue Q: ");
    dequeue(&VH,&Q);
    displayQueue(VH,Q);

    printf("\nmakeNull()\n");
    printf("Queue Q: ");
    makeNull(&VH,&Q);
    displayQueue(VH,Q);
    
    return 0;
}

Queue initQueue(){
    Queue temp;
    temp.front = -1;
    temp.rear = -1;
    return temp;
}

bool isEmpty(Queue A){
    return(A.front == -1)? 1:0;
}

char front(Heap VH, Queue A){
    return(!isEmpty(A))? VH.Node[A.front].elem:'-';
}

void enqueue(Heap* VH, Queue* A, char elem){
    int temp = getSpace(VH);
    if(temp != -1){
        VH->Node[temp].elem = elem;
        VH->Node[temp].link = -1;
        if(A->front == -1){
            A->front = temp;
        }else{
            VH->Node[A->rear].link = temp;
        }
        A->rear = temp;
    }
}

void dequeue(Heap* VH, Queue* A){
    if(!isEmpty(*A)){
        int temp = A->front;
        A->front = VH->Node[temp].link;
        if(A->front == -1){
            A->rear = -1;
        }
        freeSpace(VH,temp);
    }
}

void displayQueue(Heap VH,Queue A){
    if(!isEmpty(A)){
        int temp = A.front;
        while(A.front != -1){
            printf("%c ",VH.Node[A.front].elem);
            A.front = VH.Node[A.front].link;
        }
        A.front = temp;
        printf("\n");
    }else{
        printf("Empty\n");
    }
}
void makeNull(Heap* VH, Queue* A){
    while(A->front != -1){
        dequeue(VH,A);
    }
}

void initHeap(Heap* VH){
    int i;
    for(i = MAX -1; i>=0; i--){
        VH->Node[i].link = i-1;
    }
    VH->avail = MAX-1;
}

int getSpace(Heap* VH){
    int index = VH->avail;
    if(index != -1){
        VH->avail = VH->Node[index].link;
    }
    return index;
}

void freeSpace(Heap* VH, int index){
    if(index != -1){
        VH->Node[index].link = VH->avail;
        VH->avail = index;
    }
}

