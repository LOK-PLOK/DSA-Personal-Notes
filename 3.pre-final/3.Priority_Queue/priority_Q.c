#include <stdio.h>
#include <stdlib.h>
#define MAX 12

typedef struct {
    int tree[MAX];
    int lastNdx;    
}POT;

// helper or important functions
int parentIdx(int child){
    return (child - 1)/2;
}

int leftChildIdx(int parent){
    return (parent * 2 +1);
}

int rightChildIdx(int parent){
    return (parent * 2 +2);
}

void initPOT(POT* pq){
    pq->lastNdx = -1;
}

// it is not recommended to be calling a separate function to for calculating indices as it creates an execution record per call,
// therefore this function(populate, heapify) are space inefficient

void populate(POT* pq, int data){   
    //first insert element
    pq->tree[++pq->lastNdx] = data;
    int idx;
    // then compare the element with its parent and swap if the element is greater than its parent
    //this is the heapify up
    for(idx = pq->lastNdx; parentIdx(idx) >=0 && pq->tree[idx] > pq->tree[parentIdx(idx)]; idx = parentIdx(idx)){
        //swap
        int temp = pq->tree[idx];
        pq->tree[idx] = pq->tree[parentIdx(idx)];
        pq->tree[parentIdx(idx)] = temp;
    }
}

void heapify(POT* pq, int subRoot){
    int trav, idx;
    for(trav = subRoot; leftChildIdx(trav) <= pq->lastNdx; trav = idx){
        idx = leftChildIdx(trav);
        if(rightChildIdx(trav) <= pq->lastNdx && pq->tree[rightChildIdx(trav)] > pq->tree[idx]){
            idx = rightChildIdx(trav);
        }
        if(pq->tree[trav] < pq->tree[idx]){
            int temp = pq->tree[trav];
            pq->tree[trav] = pq->tree[idx];
            pq->tree[idx] = temp;
        } else {
            break;
        }
    }
}

int deleteMax(POT* pq){
    int max = pq->tree[0];
    pq->tree[0] = pq->tree[pq->lastNdx--];
    if(pq->lastNdx > 0){
        heapify(pq, 0);
    }
    return max;
}

void heapSort(POT* pq){
    int origLastNdx = pq->lastNdx;
    while(pq->lastNdx > 0){
        pq->tree[pq->lastNdx] = deleteMax(pq);
    }
    pq->lastNdx = origLastNdx;
}

int main(){
    POT pq;
    initPOT(&pq);

    int data[] = {30,40,0,10,50,25,60,45,15,35};
    for(int i=0;i<10;i++){
        populate(&pq, data[i]);
    }

    printf("Heap before sorting: \n");
    for(int i = 0; i <= pq.lastNdx; i++){
        printf("%d ", pq.tree[i]);
    }
    printf("\n");

    heapSort(&pq);

    printf("Heap after sorting: \n");
    for(int i = 0; i <= pq.lastNdx; i++){
        printf("%d ", pq.tree[i]);
    }
    printf("\n");

    return 0;
}