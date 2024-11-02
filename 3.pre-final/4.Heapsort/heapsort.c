#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20 

typedef struct {
    int tree[MAX];
    int lastNdx;
}POT;

void initPot(POT* pq);
void display(POT pq);
void displayV2(POT pq);
void insert(POT* pq,int elem);
void populate(POT* pq,int data[],int size);
void heapify(POT* pq, int index);
int deleteMin(POT* pq);

void heapsort(POT* pq,int size);

int main(){
    POT pq;
    initPot(&pq);
    display(pq);

    int data[] = {6,10,30,1,8,55,30,15,100,25};
    populate(&pq,data,sizeof(data)/sizeof(data[0]));
    display(pq);
    displayV2(pq);

    heapsort(&pq,pq.lastNdx);
    displayV2(pq);

}


void initPot(POT* pq){
    pq->lastNdx = -1;
}

void insert(POT* pq,int elem){
    if(pq->lastNdx != MAX){
        pq->tree[++pq->lastNdx] = elem;

        for(int idx = pq->lastNdx; idx>=0 && pq->tree[idx] < pq->tree[(idx-1)/2]; idx =(idx-1)/2 ){
            int temp = pq->tree[idx];
            pq->tree[idx] = pq->tree[(idx-1)/2];
            pq->tree[(idx-1)/2] = temp;
        }
    }
}

void populate(POT* pq,int data[],int size){
    for(int i = 0; i < size; i++){
        insert(pq,data[i]);
    }
}

void heapify(POT* pq, int index){
    int small = index;
    int LC = index*2+1;
    int RC = index*2+2;

    if(LC <= pq->lastNdx && pq->tree[LC] < pq->tree[small]){
        small = LC;
    }

    if(RC <= pq->lastNdx && pq->tree[RC] < pq->tree[small]){
        small = RC;
    }

    if(small != index){
        int temp = pq->tree[small];
        pq->tree[small] = pq->tree[index];
        pq->tree[index] = temp;
        heapify(pq,small);
    }
}

int deleteMin(POT* pq){
    if(pq->lastNdx != -1){
        int temp = pq->tree[pq->lastNdx];
        pq->tree[0] = pq->tree[pq->lastNdx];
        pq->lastNdx--;
        heapify(pq,0);
        return temp;
    }
}

void heapsort(POT* pq, int size) {
    int lastIndex = pq->lastNdx; // remembers the last index

    // Extract elements from the heap one by one
    for (int i = lastIndex; i > 0; i--) {
        // Move current root to end
        int temp = pq->tree[0];
        pq->tree[0] = pq->tree[i];
        pq->tree[i] = temp;

        // Reduce the heap size
        pq->lastNdx--;

        // Heapify the root element to maintain the max-heap property
        heapify(pq, 0);
    }

    // Restore the original lastNdx value
    pq->lastNdx = size - 1;
}

void display(POT pq){
    if(pq.lastNdx == -1){
        printf("EMPTY");
    }else{
        printf("%-20s%-20s\n","Priority","Index");
        for(int i=0; i <= pq.lastNdx; i++){
            printf("%-20d%-20d\n",i,pq.tree[i]);
        }
    }

    printf("\n\n");
}

void displayV2(POT pq){
    if(pq.lastNdx == -1){
        printf("EMPTY");
    }else{
        for(int i =0; i<=pq.lastNdx; i++){
            printf("%d ",pq.tree[i]);
        }
    }

    printf("\n\n");
}