#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15

typedef struct {
    int tree[MAX];
    int lastNdx;
}POT;

void initPOT(POT* pq);
void insert(POT* pq, int elem);
void deleteMin(POT* pq);
void populate(POT* pq,int data[],int size);
void heapify(POT* pq, int parent);
void display(POT pq);
void displayV2(POT pq);
void heapsort(POT* pq,int lastNdx);

int main(){
    POT pq;
    initPOT(&pq);

    int data[] = {6,10,30,1,8,55,30,15,100,25};
    populate(&pq,data,sizeof(data)/sizeof(data[0]));
    display(pq);


    //heapsort
    printf("HeapSort: ");
    heapsort(&pq,pq.lastNdx);
    displayV2(pq);

    //deleteMin
    printf("DeleteMin:\n");
    deleteMin(&pq);
    display(pq);

    
    return 0;
}

void initPOT(POT* pq){
    pq->lastNdx = -1;
}

void insert(POT* pq, int elem){
    if(pq->lastNdx != MAX){
        pq->tree[++pq->lastNdx]= elem;

        for(int idx = pq->lastNdx; idx>=0 && pq->tree[idx] < pq->tree[(idx-1)/2]; idx = (idx-1)/2){
            int temp = pq->tree[idx];
            pq->tree[idx] = pq->tree[(idx-1)/2];
            pq->tree[(idx-1)/2] = temp;

        }
    }
}

void deleteMin(POT* pq){
    if(pq->lastNdx != -1){
        int deleteElem = pq->tree[0];
        pq->tree[0] = pq->tree[pq->lastNdx--];
        heapify(pq,0);
    }
}

void populate(POT* pq,int data[],int size){
    for(int i = 0; i<size; i++){
        insert(pq,data[i]);
    }
}

void heapify(POT* pq, int parent){
    int small = parent;
    int LC = parent*2+1;
    int RC = parent*2+2;

    if(LC <= pq->lastNdx && pq->tree[LC] < pq->tree[small]){
        small = LC;
    }

    if(RC <= pq->lastNdx && pq->tree[RC] < pq->tree[small]){
        small = RC;
    }

    if(small != parent){
        int temp = pq->tree[small];
        pq->tree[small] = pq->tree[parent];
        pq->tree[parent] = temp;
        heapify(pq,small);
    }
}

void display(POT pq){
    if(pq.lastNdx == -1){
        printf("EMPTY");
    }else{
        int i;
        printf("%-20s%-20s\n","index","Priority");
        for(i=0;i<=pq.lastNdx;i++){
            printf("%-20d%-20d\n",i,pq.tree[i]);
        }
    }

    printf("\n\n");
}

void displayV2(POT pq){
    if(pq.lastNdx == -1){
        printf("EMPTY");
    }else{
        int i;
        for(i=0;i<=pq.lastNdx;i++){
            printf("%d ",pq.tree[i]);
        }
    }

    printf("\n\n");
}

void heapsort(POT* pq,int lastNdx){
    int lastIndex = lastNdx;

    for(int i = lastIndex; i>0; i--){
        int temp = pq->tree[0];
        pq->tree[0] = pq->tree[i];
        pq->tree[i] = temp;

        pq->lastNdx--;

        heapify(pq,0);
    }

    pq->lastNdx = lastIndex;
}
