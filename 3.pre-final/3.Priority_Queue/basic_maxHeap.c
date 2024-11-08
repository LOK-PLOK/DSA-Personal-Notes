#include <stdio.h>
#include <stdlib.h>
#define MAX 12

typedef struct {
    int List[MAX];
    int lastNdx;
}POT;


void INITIALIZE(POT* heap);
void DISPLAY(POT heap);
void INSERT(POT* heap, int elem);
void POPULATE(POT* heap,int data[],int size);
void HEAPIFYALL(POT* heap);
void HEAPIFYSUBTREE(POT* heap, int index);

int main(){
    POT heap;
    INITIALIZE(&heap);
    DISPLAY(heap);

    int data[] = {6,10,30,1,8,55,30,15,100,25};
    POPULATE(&heap,data,sizeof(data)/sizeof(data[0]));
    HEAPIFYALL(&heap);
    DISPLAY(heap);
    
    // //deleteMin
    // printf("DeleteMin:\n");
    // DELETEMAX(&heap);
    // DISPLAY(heap);

    return 0;
}

void INITIALIZE(POT* heap){
    heap->lastNdx = -1;
}

void INSERT(POT* heap, int elem){
    if(heap->lastNdx != MAX){
        heap->List[++heap->lastNdx] = elem;
    }
}

void POPULATE(POT* heap,int data[],int size){
    int i;
    for(i = 0; i<size;i++){
        INSERT(heap,data[i]);
    }
}

void HEAPIFYALL(POT* heap){
    int i;
    for(i = (heap->lastNdx-1)/2; i>=0; i--){
        HEAPIFYSUBTREE(heap,i);
    }
}

void HEAPIFYSUBTREE(POT* heap, int index){
    int large,LC,RC,flag = 0;

    while(!flag){
        large = index;
        LC = index* 2 +1;
        RC = LC+1;

        if(LC <= heap->lastNdx && heap->List[LC] > heap->List[large]){
            large = LC;
        }

        if(RC <= heap->lastNdx && heap->List[RC] > heap->List[large]){
            large = RC;
        }

        if(large != index){
            int temp = heap->List[large];
            heap->List[large] = heap->List[index];
            heap->List[index] = temp;
            index = large; // always remember to update the current index 
        }else{
            flag = 1;
        }
    }
}

void DISPLAY(POT heap){
    if (heap.lastNdx != -1){
        int i;
        printf("%-20s%-20s\n","index","priority");
        for(i=0;i<=heap.lastNdx;i++){
            printf("%-20d%-20d\n",i,heap.List[i]);
        }
    }else{
        printf("EMPTY");
    }
    printf("\n\n");
}