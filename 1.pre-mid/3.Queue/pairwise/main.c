#include "header/array.h"
// #include "header/linkedList.h"

int main(){
    Queue Q = initQueue();
    displayQueue(&Q);

    enqueue(&Q,'A');
    displayQueue(&Q);

    enqueue(&Q,'B');
    enqueue(&Q,'C');
    enqueue(&Q,'D');
    displayQueue(&Q);

    printf("Front: %c \n\n", front(Q));

    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    displayQueue(&Q);
    
    return 0;
}

