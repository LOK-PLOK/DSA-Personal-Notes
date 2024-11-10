#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 12

typedef struct {
    int tree[MAX];
    int lastNdx;
} POT;

void init(POT* heap);
void display(POT heap);
void displayV2(POT heap);
void insert(POT* heap, int elem);
void populate(POT* heap, int data[], int size);
void heapiftyAllMin(POT* heap);
void heapiftyAllMax(POT* heap);
void heapifMinRec(POT* heap, int parent);
void heapifMaxRec(POT* heap, int parent);
void heapifyMin(POT* heap, int parent);
void heapifyMax(POT* heap, int parent);
int deleteMin(POT* heap);
int deleteMax(POT* heap);
void heapsortMin(POT* heap);
void heapsortMax(POT* heap);

int main() {
    POT heap;
    init(&heap);
    display(heap);

    int data[] = {6, 10, 30, 1, 8, 55, 30, 15, 100, 25};
    populate(&heap, data, sizeof(data) / sizeof(data[0]));
    display(heap);

    // deleteMin
    printf("DeleteMin:\n");
    deleteMin(&heap);
    display(heap);

    // heapsort
    printf("HeapSortMin: ");
    heapsortMin(&heap);
    displayV2(heap);
    
    printf("HeapSortMax: ");
    heapsortMax(&heap);
    displayV2(heap);

    return 0;
}

void init(POT* heap){
    heap->lastNdx = -1;
}

void display(POT heap){
    if (heap.lastNdx == -1) {
        printf("EMPTY");
    } else {
        int i;
        printf("%-20s%-20s\n", "index", "Priority");
        for (i = 0; i <= heap.lastNdx; i++) {
            printf("%-20d%-20d\n", i, heap.tree[i]);
        }
    }

    printf("\n\n");
}

void displayV2(POT heap){
    if (heap.lastNdx == -1) {
        printf("EMPTY");
    } else {
        int i;
        for (i = 0; i <= heap.lastNdx; i++) {
            printf("%d ",heap.tree[i]);
        }
        printf("\n\n");
    }
}

void insert(POT* heap, int elem){
    if(heap->lastNdx != MAX-1){
        heap->tree[++heap->lastNdx] = elem;
    }else{
        printf("POT FULL\n\n");
    }
}

void populate(POT* heap, int data[], int size){
    int i;
    for(i=0;i<size;i++){
        insert(heap,data[i]);
    }
}

void heapiftyAllMin(POT* heap){
    int i;
    int lastNdx = heap->lastNdx;
    for(i = (lastNdx-1)/2;i>=0;i--){
        heapifyMin(heap,i);
    }
}

void heapiftyAllMax(POT* heap){
    int i;
    int lastNdx = heap->lastNdx;
    for(i = (lastNdx-1)/2;i>=0;i--){
        heapifyMax(heap,i);
    }
}

void heapifMinRec(POT* heap, int parent){
    int i;
    int small = parent;
    int LC = parent * 2 + 1;
    int RC = LC + 1;

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
        heapifMinRec(heap,small);
    }
}

void heapifMaxRec(POT* heap, int parent){
    int i;
    int large = parent;
    int LC = parent * 2 + 1;
    int RC = LC + 1;

    if(LC <= heap->lastNdx && heap->tree[LC] > heap->tree[large]){
        large = LC;
    }

    if(RC <= heap->lastNdx && heap->tree[RC] > heap->tree[large]){
        large = RC;
    }

    if(large != parent){
        int temp = heap->tree[large];
        heap->tree[large] = heap->tree[parent];
        heap->tree[parent] = temp;
        heapifMinRec(heap,large);
    }
}

void heapifyMin(POT* heap, int parent){
    int small,LC,RC,flag = 0;

    while(!flag){
        small = parent;
        LC = parent * 2 + 1;
        RC = LC + 1;

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

void heapifyMax(POT* heap, int parent){
    int large,LC,RC,flag = 0;

    while(!flag){
        large = parent;
        LC = parent * 2 + 1;
        RC = LC + 1;

        if(LC <= heap->lastNdx && heap->tree[LC] > heap->tree[large]){
        large = LC;
        }

        if(RC <= heap->lastNdx && heap->tree[RC] > heap->tree[large]){
            large = RC;
        }

        if(large != parent){
            int temp = heap->tree[large];
            heap->tree[large] = heap->tree[parent];
            heap->tree[parent] = temp;
            parent = large;
        }else{
            flag = 1;
        }
    }
}

int deleteMin(POT* heap){
    if(heap->lastNdx != -1){
        int deletedElem = heap->tree[0];
        heap->tree[0] = heap->tree[heap->lastNdx];
        heap->tree[heap->lastNdx --] = deletedElem;

        heapifyMin(heap,0);
        return deletedElem;
    }
}

int deleteMax(POT* heap){
    if(heap->lastNdx != -1){
        int deletedElem = heap->tree[0];
        heap->tree[0] = heap->tree[heap->lastNdx];
        heap->tree[heap->lastNdx --] = deletedElem;

        heapifyMax(heap,0);
        return deletedElem;
    }
}

void heapsortMin(POT* heap){
    int i;
    int lastNdx = heap->lastNdx;
    for(i = (lastNdx-1)/2;i>=0;i--){
        heapifyMin(heap,i);
    }
    for(i=heap->lastNdx; i>0;i--){
        int temp = heap->tree[0];
        heap->tree[0] = heap->tree[i];
        heap->tree[i] = temp;

        heap->lastNdx --;
        heapifyMin(heap,0);
    }

    heap->lastNdx = lastNdx;
}

void heapsortMax(POT* heap){
    int i;
    int lastNdx = heap->lastNdx;
    for(i = (lastNdx-1)/2;i>=0;i--){
        heapifyMax(heap,i);
    }
    for(i=heap->lastNdx; i>0;i--){
        int temp = heap->tree[0];
        heap->tree[0] = heap->tree[i];
        heap->tree[i] = temp;

        heap->lastNdx --;
        heapifyMax(heap,0);
    }

    heap->lastNdx = lastNdx;
}