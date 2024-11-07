#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void heapifyAll(int data[],int size);
void heapifyMin(int data[],int lastIndx,int index); // index <- parent
void display(int data[],int size);
void heapsort(int data[],int size);

int main(){
    int data[] = {61,10,30,1,8,25,30,0,100,55};
    int size = sizeof(data)/sizeof(data[0]);
    display(data,size);
    heapifyAll(data,size);
    display(data,size);
    heapsort(data,size);
    display(data,size);

}

void heapifyAll(int data[],int size){
    int i;
    int lastIndx = size-1;
    for(i = (lastIndx-1)/2; i>=0; i--){
        heapifyMin(data,lastIndx,i);
    }
}

// Note: heapify needs the "array", the last "index" of the array, and the "right most subtree parent"
void heapifyMin(int data[],int lastIndx,int index){
    int small,LC,RC,flag=0;

    while(!flag){
        small = index;
        LC = index*2+1;
        RC = LC+1;

        if(LC<= lastIndx && data[LC] < data[small]){
            small = LC;
        }

        if(RC<= lastIndx && data[RC] < data[small]){
            small = RC;
        }

        if(small != index){
            int temp = data[small];
            data[small] = data[index];
            data[index] = temp;
            index = small; // always remember to change the parent to the least priority
        }else{
            flag = 1;
        }
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

void heapsort(int data[],int size){
    int i;
    int lastIndx = size-1;
    for(i=0; i<size;i++){
        int temp = data[0];
        data[0] = data[lastIndx];
        data[lastIndx--] = temp;

        heapifyMin(data,lastIndx,0);
    }
}
