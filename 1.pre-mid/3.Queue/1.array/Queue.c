#include <stdio.h>
#define MAX 7

typedef struct {
    int data[MAX];
    int front;
    int rear;
}Queue;

/*Function specifications:
    initQueue(): initializes the queue to be empty
    enqueue(): given the queue, and an element, it will insert thhe element at the rear of the queue.
    dequeue(): given the queue, the function will delete the front element.
    front(): given the queue, the function will return the front element.

    CONSIDERATIONS:
    enqueue(): what if the first inserted, the queue is empty
    dequeue(): what if the queue has 1 element and deleting it will make the queue empty.
    front(): returns a dummy value if the queue is empty.
 */

void initQueue(Queue* A);
void read(Queue A);
void enqueue(Queue* A, int elem);
void dequeue(Queue* A);
int front(Queue A);

int main(){
    Queue Q;
    initQueue(&Q);

    enqueue(&Q,5);
    enqueue(&Q,3);
    enqueue(&Q,7);
    enqueue(&Q,6);
    enqueue(&Q,1);
    read(Q);

    dequeue(&Q);
    read(Q);
    

    int first = front(Q);
    printf("\nfront element: %d ",first);

    return 0;
}

void initQueue(Queue* A){
    A->front = 0;
    A->rear = MAX-1;
}

//if empty = (rear + 1) % (size of array) != front check if front is ahead by 1 meaing it is empty
//if full = (rear + 2) % (size of array) != front  check if front is ahead by 2 meaing Queue is full

void enqueue(Queue* A, int elem){
    if((A->front + 2)%MAX != A->front){
        A->rear = (A->rear+1) % MAX;
        A->data[A->rear] = elem;
    }else{
        printf("Queue is full\n");
    }
}

void dequeue(Queue* A){
    if((A->rear +1) % MAX != A->front){
        A->front = (A->front +1) % MAX;
    }else{
        printf("Empty\n");
    }
}

int front(Queue A){
    return ((A.rear + 1) % MAX != A.front)? A.data[A.front]:-1;
}

void read(Queue A){
    printf("\nQueue: ");
    if((A.rear +1)% MAX != A.front){
        int i;
        for(i= A.front; i<=A.rear; i++){
            printf("%d ",A.data[i]);
        }
    }else{
        printf("Empty\n");
    }
}
