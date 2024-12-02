#include <stdio.h>
#define MAX 0XD

typedef int maxHeap[MAX];

/**
 * A vartiation of the max heap stores the number of elements in the max heap
 * at the first position in the array. In effect the first element of the heap is stored
 * at the second position of the array. Write the code of function insertHeap(). The function
 * will insert a given element in the given max heap by shifting elements instead of swapping
 * elements in finding the appropriate position of the new element in the heap.
 * Constraints: 1 return statement only, no break/exit statement
 */


void display(maxHeap heap);
void insertHeap(maxHeap heap, int elem);

int main(){
    int data[] = {6,10,30,1,8,55,30,15,100,25};
    maxHeap heap = {0};

    for(int i = 0; i < sizeof(data)/sizeof(data[0]); i++) {
        insertHeap(heap, data[i]);
    }

    display(heap);

    return 0;
}

void display(maxHeap heap){
    if(heap[0] == 0){
        printf("EMPTY\n");
    }else{
        printf("%-20s%-20s\n","index","Priority");
        for(int i = 1; i <= heap[0]; i++){
            printf("%-20d%-20d\n",i,heap[i]);
        }
    }
    printf("\n\n");
}

void insertHeap(maxHeap heap, int elem){
    if(heap[0] < MAX){
        heap[0]++;
        int i;
        for(i=heap[0];i>1 && heap[i/2]<=elem;i=i/2){
            heap[i] = heap[i/2];
        }
        heap[i] = elem;
    }
}