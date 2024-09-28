#include <stdio.h>
#include <stdbool.h>
#define MAX 10


typedef struct{
    char data;
    int link;
}Cell;

typedef struct{
    Cell Node[MAX];
    int avail;
}heap;

typedef struct{
    int front;
    int rear;
}Queue;

void initVh(heap* VH);
int getMalloc(heap* VH);
void getFree(heap* VH, int index);

Queue initQueue();
bool isEmpty(Queue A);
char front(Queue A, heap VH);
void enqueue(Queue* A, heap* VH, char elem);
void dequeue(Queue* A, heap* VH);
void displayQueue(Queue* A, heap* VH);

int main(){
    heap vh;
    initVh(&vh);

    Queue Q = initQueue();
    displayQueue(&Q,&vh);

    enqueue(&Q,&vh,'A');
    displayQueue(&Q,&vh);

    enqueue(&Q,&vh,'B');
    enqueue(&Q,&vh,'C');
    enqueue(&Q,&vh,'D');
    displayQueue(&Q,&vh);

    printf("Front: %c \n\n", front(Q,vh));

    dequeue(&Q,&vh);
    dequeue(&Q,&vh);
    dequeue(&Q,&vh);
    displayQueue(&Q,&vh);

    return 0;
}

Queue initQueue(){
    Queue temp = {.front = -1, .rear = -1};
    return temp;
}

bool isEmpty(Queue A){
    return(A.front == -1)? 1:0;
}

char front(Queue A, heap VH){
    return(!isEmpty(A))? VH.Node[A.front].data:'#';
}

void enqueue(Queue* A, heap* VH, char elem){
    int temp = getMalloc(VH);
    if(temp != -1){
        VH->Node[temp].data = elem;
        VH->Node[temp].link = -1;
        if(isEmpty(*A)){
            A->front = temp;
        }else{
            VH->Node[A->rear].link = temp;
        }
        A->rear = temp;
    }
}

void dequeue(Queue* A, heap* VH){
    int temp = A->front;
    A->front = VH->Node[temp].link;
    if(A->front == -1){
        A->rear == -1;
    }
    getFree(VH, temp);
}

void displayQueue(Queue* A, heap* VH){
    printf("Queue Q: ");
    if(isEmpty(*A)){
        printf("Empty\n\n");
    }else{
        Queue temp = initQueue(); 
        while(!isEmpty(*A)){
            char data  = VH->Node[A->front].data;
            printf("%c ",data);
            enqueue(&temp, VH,data);
            dequeue(A, VH);
        }

        while(!isEmpty(temp)){
            char data  = VH->Node[temp.front].data;
            enqueue(A, VH, data);
            dequeue(&temp, VH);
        }
        printf("\n\n");
    }
}

void initVh(heap* VH){
    int i;
    for(i = MAX-1; i>=0; i--){
        VH->Node[i].link = i-1;
    }
    VH->avail = MAX-1;
}

int getMalloc(heap* VH){
    int index = VH->avail;
    if(index != -1){
        VH->avail = VH->Node[index].link;
    }
    return index;
}

void getFree(heap* VH, int index){
    if(index != -1){
        VH->Node[index].link = VH->avail;
        VH->avail = index;
    }
}