#ifndef CBFUNC_H
#define CBFUNC_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef int List;

typedef struct{
    int elem;
    int next;
}Cell;

typedef struct{
    Cell Nodes[MAX];
    int avail;
}virtualHeap;

/* <-------------------Function prototype-------------------> */

// List operations:
void display(List A,virtualHeap VH);
void insertFirst(List* A,virtualHeap* VH, int elem);
void insertLast(List* A,virtualHeap* VH, int elem);
void delete(List* A,virtualHeap* VH, int elem);
void deleteAllOccur(List* A,virtualHeap* VH, int elem);
void clean(List* A,virtualHeap* VH);
//void isMember()
//void locate()

// Cursor-based functions:
void initialize(List* A,virtualHeap* VH);
int allocSpace(virtualHeap * VH);
void deallocSpace(virtualHeap* VH, int index);


/* <-------------------Function definitions-------------------> */

void insertFirst(List* A,virtualHeap* VH, int elem){
    List temp = allocSpace(VH);
    if(temp != -1){
        VH->Nodes[temp].elem = elem;
        VH->Nodes[temp].next = *A;
        *A = temp;
    }else{
        printf("List is full");
    }
}

void insertLast(List* A,virtualHeap* VH, int elem){
    List temp = allocSpace(VH);
    if(temp != -1){
        List* trav;
        for(trav = A; *trav != -1; trav = &(VH->Nodes[*trav].next)){}
        if(*trav == -1){
            VH->Nodes[temp].elem = elem;
            VH->Nodes[temp].next = -1;
            *trav = temp;
        }
    }else{
        printf("List is full\n");
    }
}

void delete(List* A,virtualHeap* VH, int elem){
    List* trav;
    for(trav = A; *trav != -1 && VH->Nodes[*trav].elem != elem; trav = &(VH->Nodes[*trav].next)){}
    if(*trav != -1){
        int temp = * trav;
        *trav = VH->Nodes[temp].next;
        deallocSpace(VH,temp);
    }else{
        printf("Not in list\n");
    }
}
void deleteAllOccur(List* A,virtualHeap* VH, int elem){
    List* trav;
    for(trav = A; *trav != -1;){
        if(VH->Nodes[*trav].elem == elem){
            int temp = *trav;
            *trav = VH->Nodes[*trav].next;
            deallocSpace(VH,temp);
        }else{
            trav = &(VH->Nodes[*trav].next);
        }
    }
}

void display(List A,virtualHeap VH){
    printf("CB List: ");
    if(A != -1){
        int i;
        for(i = A; i != -1; i = VH.Nodes[i].next){
            printf("%d ",VH.Nodes[i].elem);
        }
        printf("\n");
    }else{
        printf("Empty \n");
    }
}

void clean(List* A,virtualHeap* VH){
    while(*A != -1){
        int temp = *A;
        *A = VH->Nodes[temp].next;
        deallocSpace(VH,temp);
    }
}

void initialize(List* A,virtualHeap* VH){
    *A = -1;

    int i;
    for(i=MAX-1; i>=0; i--){
        VH->Nodes[i].next = i-1;
    }
    VH->avail = MAX-1;
}

int allocSpace(virtualHeap * VH){
    int alloc = VH->avail; // gets the available index
    if(alloc != -1){ // -1 means there is no available space
        VH->avail = VH->Nodes[alloc].next;
    }

    return alloc;
}

void deallocSpace(virtualHeap* VH, int index){
    if(index >= 0 && index < MAX){
        VH->Nodes[index].next = VH->avail; // assigns the cell to the next available cell
        VH->avail = index; // available is holding the index of the cell that is being freed
    }
}


#endif