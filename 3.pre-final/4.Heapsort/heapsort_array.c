#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void display(int data[],int size);
void heapifyAll(int data[],int size);
void heapifySubtreeMin(int data[],int lastNdx,int parent);
void heapifySubtreeMax(int data[],int lastNdx,int parent);
void heapsortMin(int data[],int size);
void heapsortMax(int data[],int size);

int main(){
    int data[] = {61,10,30,1,8,25,30,0,100,55};
    int size = sizeof(data)/sizeof(data[0]);
    display(data,size);
    heapifyAll(data,size);
    display(data,size);
    heapsortMax(data,size);
    display(data,size);
}

void heapifyAll(int data[],int size){
    int i;
    int lastNdx = size-1;
    for(i=(lastNdx-1)/2; i>=0; i--){
        heapifySubtreeMax(data,lastNdx,i);
    }
}

void heapifySubtreeMin(int data[],int lastNdx,int parent){
    int small,LC,RC,flag=0;
    while(!flag){
        small = parent;
        LC = parent*2+1;
        RC = LC + 1;

        if(LC <= lastNdx && data[LC] < data[small]){
            small = LC;
        }

        if(RC <= lastNdx && data[RC] < data[small]){
            small = RC;
        }

        if(small != parent){
            int temp = data[small];
            data[small] = data[parent];
            data[parent] = temp;
            parent = small;
        }else{
            flag = 1;
        }
    }
}

void heapifySubtreeMax(int data[],int lastNdx,int parent){
    int large,LC,RC,flag=0;
    while(!flag){
        large = parent;
        LC = parent*2+1;
        RC = LC + 1;

        if(LC <= lastNdx && data[LC] > data[large]){
            large = LC;
        }

        if(RC <= lastNdx && data[RC] > data[large]){
            large = RC;
        }

        if(large != parent){
            int temp = data[large];
            data[large] = data[parent];
            data[parent] = temp;
            parent = large;
        }else{
            flag = 1;
        }
    }
}

void heapsortMin(int data[],int size){
    int i;
    int lastNdx = size-1;
    for(i=0;i<size;i++){
        int temp = data[0];
        data[0] = data[lastNdx];
        data[lastNdx--] = temp;

        heapifySubtreeMin(data,lastNdx,0);
    }
}

void heapsortMax(int data[],int size){
    int i;
    int lastNdx = size-1;
    for(i=0;i<size;i++){
        int temp = data[0];
        data[0] = data[lastNdx];
        data[lastNdx--] = temp;

        heapifySubtreeMax(data,lastNdx,0);
    }
}

void display(int data[],int size){
    if(size != 0){
        int i;
        for(i=0; i< size; i++){
            printf("%d ",data[i]);
        }
    }else{
        printf("EMPTY");
    }
        printf("\n\n");
}
