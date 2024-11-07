#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 12

typedef struct {
    int tree[MAX];
    int lastNdx;
}POT;

void init(POT* heap);
void display(POT heap);
void insert(POT* heap, int elem);
void populate(POT* heap,int data[],int size);
void heapiftyAll(POT* heap);
void heapify(POT* heap,int parent);
void heapifyV2(POT* heap,int parent);
int deleteMin(POT *heap);

int main(){
    POT heap;
    init(&heap);
    display(heap);

    int data[] = {6,10,30,1,8,55,30,15,100,25};
    populate(&heap,data,sizeof(data)/sizeof(data[0]));
    display(heap);
 
    //deleteMin
    printf("DeleteMin:\n");
    deleteMin(&heap);
    display(heap);
    
    return 0;
}


void init(POT* heap){
    heap->lastNdx = -1;
}

//insert then heapify
void insert(POT* heap, int elem){
    if(heap->lastNdx <MAX-1){
        heap->tree[++heap->lastNdx] = elem;

        int idx;
        for(idx = heap->lastNdx; idx>=0&& heap->tree[idx] < heap->tree[(idx-1)/2];idx = (idx-1)/2){
            int temp = heap->tree[idx];
            heap->tree[idx] = heap->tree[(idx-1)/2];
            heap->tree[(idx-1)/2] = temp;
        }
    }
}

void populate(POT* heap,int data[],int size){
    int i;
    for(i=0;i<size;i++){
        insert(heap,data[i]);
    }
}

int deleteMin(POT *heap){
    if(heap->lastNdx != -1){
        int deletedElem = heap->tree[0];
        heap->tree[0] = heap->tree[heap->lastNdx];
        heap->lastNdx--;
        heapifyV2(heap,0);
        return deletedElem;
    }
}

void heapiftyAll(POT* heap){
    int i;
    for(i = (heap->lastNdx-1)/2;i>=0;i--){
        heapifyV2(heap,i);
    }
}

void heapify(POT* heap,int parent){
    int small = parent;
    int LChild = parent*2+1;
    int RChild = parent*2+2;

    if(LChild <= heap->lastNdx && heap->tree[LChild] < heap->tree[small]){
        small = LChild;
    }

    if(RChild <= heap->lastNdx && heap->tree[RChild] < heap->tree[small]){
        small = RChild;
    }

    if(small != parent){
        int temp = heap->tree[parent];
        heap->tree[parent] = heap->tree[small];
        heap->tree[small] = temp;
        heapify(heap,small);
    }
}

void heapifyV2(POT* heap,int parent){
    int small,LC,RC;
    int flag = 0;

    while(!flag){
        small = parent;
        LC = parent*2+1;
        RC = LC+1;
        if(LC <= heap->lastNdx && heap->tree[LC] < heap->tree[small]){
            small = LC;
        }

        if(RC <= heap->lastNdx && heap->tree[RC] < heap->tree[small]){
            small = RC;
        }

        if(small != parent){
            int temp = heap->tree[small];
            heap->tree[small] = heap->tree[parent];
            heap->tree[parent] = temp;
            parent = small;
        }else{
            flag = 1;
        }
    }
}

void display(POT heap){
    if(heap.lastNdx == -1){
        printf("EMPTY");
    }else{
        int i;
        printf("%-20s%-20s\n","index","Priority");
        for(i=0;i<=heap.lastNdx;i++){
            printf("%-20d%-20d\n",i,heap.tree[i]);
        }
    }

    printf("\n\n");
}
