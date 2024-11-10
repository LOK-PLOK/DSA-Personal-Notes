#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void display(int data[],int size);
void heapifyAllMin(int data[],int size);
void heapifyAllMax(int data[],int size);
void heapifySubTreeMin(int data[],int lastNdx,int parent);
void heapifySubTreeMax(int data[],int lastNdx,int parent);
void heapsortMin(int data[],int size);
void heapsortMax(int data[],int size);

int main(){
    system("clear");
    int data1[] = {61,10,30,1,8,25,30,0,100,55};
    int data2[] = {61,10,30,1,8,25,30,0,100,55};
    int size1 = sizeof(data1)/sizeof(data1[0]);
    int size2 = sizeof(data1)/sizeof(data1[0]);
    printf("Data1: ");
    display(data1,size1);

    printf("Data2: ");
    display(data2,size2);


    printf("Heapsort Data1 (Min): ");
    heapsortMin(data1,size1);
    display(data1,size1);

    printf("Heapsort Data2 (Max): ");
    heapsortMax(data2,size2);
    display(data2,size2);
    return 0;
}

void display(int data[],int size){
    if(size != 0){
        int i;
        for(i=0;i<size;i++){
            printf("%d ",data[i]);
        }
    }else{
        printf("EMPTY");
    }

    printf("\n\n");
}

void heapifyAllMin(int data[],int size){
    int i;
    int lastNdx = size-1;
    for(i=(lastNdx-1)/2;i>=0;i--){
        heapifySubTreeMin(data,lastNdx,i);
    }
}

void heapifyAllMax(int data[],int size){
    int i;
    int lastNdx = size-1;
    for(i=(lastNdx-1)/2;i>=0;i--){
        heapifySubTreeMax(data,lastNdx,i);
    }
}

void heapifySubTreeMin(int data[],int lastNdx,int parent){
    int small,LC,RC,flag = 0;

    while(!flag){
        small = parent;
        LC = parent * 2 + 1;
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

void heapifySubTreeMax(int data[],int lastNdx,int parent){
    int large,LC,RC,flag = 0;

    while(!flag){
        large = parent;
        LC = parent * 2 + 1;
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
    for(i=(lastNdx-1)/2;i>=0;i--){
        heapifySubTreeMin(data,lastNdx,i);
    }
    for(i = lastNdx;i>0;i--){
        int temp = data[0];
        data[0] = data[i];
        data[i] = temp;
        lastNdx--;
        heapifySubTreeMin(data,lastNdx,0);
    }
}

void heapsortMax(int data[],int size){
    int i;
    int lastNdx = size-1;
    for(i=(lastNdx-1)/2;i>=0;i--){
        heapifySubTreeMax(data,lastNdx,i);
    }
    for(i = lastNdx;i>0;i--){
        int temp = data[0];
        data[0] = data[i];
        data[i] = temp;
        lastNdx--;
        heapifySubTreeMax(data,lastNdx,0);
    }
}
