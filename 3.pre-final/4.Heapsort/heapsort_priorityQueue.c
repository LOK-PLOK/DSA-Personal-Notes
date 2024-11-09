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
void heapiftyAll(POT* heap);
void heapify(POT* heap, int parent);
void heapifyV2Min(POT* heap, int parent);
void heapifyV2Max(POT* heap, int parent);
int deleteMin(POT* heap);
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

void init(POT* heap) {
    heap->lastNdx = -1;
}

void display(POT heap) {
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

void insert(POT* heap, int elem) {
    if (heap->lastNdx < MAX - 1) {
        heap->tree[++heap->lastNdx] = elem;

        int idx;
        for (idx = heap->lastNdx; idx > 0 && heap->tree[idx] < heap->tree[(idx - 1) / 2]; idx = (idx - 1) / 2) {
            int temp = heap->tree[idx];
            heap->tree[idx] = heap->tree[(idx - 1) / 2];
            heap->tree[(idx - 1) / 2] = temp;
        }
    }
}

void populate(POT* heap, int data[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        insert(heap, data[i]);
    }
}

void heapiftyAll(POT* heap) {
    int lastNdx = heap->lastNdx;
    int i;
    for (i = (lastNdx - 1) / 2; i >= 0; i--) {
        heapify(heap, i);
    }
}

void heapify(POT* heap, int parent) {
    int small = parent;
    int LC = parent * 2 + 1;
    int RC = LC + 1;

    if (LC <= heap->lastNdx && heap->tree[LC] < heap->tree[small]) {
        small = LC;
    }

    if (RC <= heap->lastNdx && heap->tree[RC] < heap->tree[small]) {
        small = RC;
    }

    if (small != parent) {
        int temp = heap->tree[small];
        heap->tree[small] = heap->tree[parent];
        heap->tree[parent] = temp;
        heapify(heap, small);
    }
}

void heapifyV2Min(POT* heap, int parent) {
    int small, LC, RC, flag = 0;

    while (!flag) {
        small = parent;
        LC = parent * 2 + 1;
        RC = LC + 1;

        if (LC <= heap->lastNdx && heap->tree[LC] < heap->tree[small]) {
            small = LC;
        }

        if (RC <= heap->lastNdx && heap->tree[RC] < heap->tree[small]) {
            small = RC;
        }

        if (small != parent) {
            int temp = heap->tree[small];
            heap->tree[small] = heap->tree[parent];
            heap->tree[parent] = temp;
            parent = small;
        } else {
            flag = 1;
        }
    }
}
void heapifyV2Max(POT* heap, int parent) {
    int large, LC, RC, flag = 0;

    while (!flag) {
        large = parent;
        LC = parent * 2 + 1;
        RC = LC + 1;

        if (LC <= heap->lastNdx && heap->tree[LC] > heap->tree[large]) {
            large = LC;
        }

        if (RC <= heap->lastNdx && heap->tree[RC] > heap->tree[large]) {
            large = RC;
        }

        if (large != parent) {
            int temp = heap->tree[large];
            heap->tree[large] = heap->tree[parent];
            heap->tree[parent] = temp;
            parent = large;
        } else {
            flag = 1;
        }
    }
}

int deleteMin(POT* heap) {
    if (heap->lastNdx != -1) {
        int deleteElem = heap->tree[0];
        heap->tree[0] = heap->tree[heap->lastNdx];
        heap->tree[heap->lastNdx--] = deleteElem;

        heapify(heap, 0);
        return deleteElem;
    }
    return -1; // Return a value to indicate the heap was empty
}

void heapsortMin(POT* heap) {
    int originalLastNdx = heap->lastNdx;

    for (int i = heap->lastNdx; i > 0; i--) {
        int temp = heap->tree[0];
        heap->tree[0] = heap->tree[i];
        heap->tree[i] = temp;

        heap->lastNdx--;
        heapifyV2Min(heap, 0);
    }

    heap->lastNdx = originalLastNdx;
}

void heapsortMax(POT* heap) {
    int originalLastNdx = heap->lastNdx;

    for (int i = heap->lastNdx; i > 0; i--) {
        int temp = heap->tree[0];
        heap->tree[0] = heap->tree[i];
        heap->tree[i] = temp;

        heap->lastNdx--;
        heapifyV2Max(heap, 0);
    }

    heap->lastNdx = originalLastNdx;
}