/**
 * Cursor based implementations, definitions and funtions here
 */

#ifndef Cursor_based_implementation
#define Cursor_based_implementation

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct{
    char elem;
    int next;
}Cell;

typedef struct {
    Cell Nodes[MAX];
    int avail;
}VirtualHeap;
typedef int List;
typedef enum{TRUE,FALSE}boolean;

//cursor based preparation functions
void initVH(VirtualHeap* VH){
    int i;
    for(i = 0; i<MAX; i++){
        VH->Nodes[i].next = i+1;
    }
    VH->Nodes[MAX-1].next = -1;
    VH->avail = 0;
}

int mallocSpace(VirtualHeap* VH){
    int index = VH->avail;
    if(index != -1){
        VH->avail = VH->Nodes[index].next;
    }
    return index;
}

void freeSpace(VirtualHeap* VH, int index){
    VH->Nodes[index].next = VH->avail;
    VH->avail = index;
}

//List operations
void initList(List* A){
    *A = -1;
}

void display(List A, VirtualHeap VH){
    printf("CB List: ");
    if(A != -1){
        int i;
        for(i = A; i!= -1; i = VH.Nodes[i].next){
            printf("%c ",VH.Nodes[i].elem);
        }
        printf("\n");
    }else{
        printf("Empty\n");
    }
}

void clean(List* A, VirtualHeap* VH){
    List temp;
    while(*A != -1){
        temp = *A;
        *A = VH->Nodes[temp].next;
        freeSpace(VH,temp);
    }
}

void insertFirst(List* A, VirtualHeap* VH, char elem){
    List temp = mallocSpace(VH);
    if(temp != -1){
        VH->Nodes[temp].elem = elem;
        VH->Nodes[temp].next = *A;
        *A = temp;
    }
}

void insertLast(List* A, VirtualHeap* VH, char elem){
    List temp = mallocSpace(VH), *trav;
    if(temp != -1){
        for(trav = A; *trav != -1; trav = &(VH->Nodes[*trav].next)){}
        if(*trav == -1){
            VH->Nodes[temp].elem = elem;
            VH->Nodes[temp].next = *trav;
            *trav = temp;
        }
    }
}

void insertSorted(List* A, VirtualHeap* VH, char elem){
    List temp = mallocSpace(VH),* trav;
    
    if(temp != -1){
        for(trav = A; *trav != -1 && VH->Nodes[*trav].elem < elem; trav = &(VH->Nodes[*trav].next)){}
            VH->Nodes[temp].elem = elem;
            VH->Nodes[temp].next = *trav;
            *trav = temp;
    }
}

void insertAtPost(List* A, VirtualHeap* VH, char elem, int pos){
    List temp = mallocSpace(VH) ,*trav;
    int i;
    if(temp != -1){
        for(trav = A,i=0; *trav != -1 && i!=pos; trav = &(VH->Nodes[*trav].next),i++){}
        if(i == pos){
            VH->Nodes[temp].elem = elem;
            VH->Nodes[temp].next = *trav;
            *trav = temp; 
        }
    }
}

boolean findElem(List A, VirtualHeap VH, char elem){
    List trav;
    for(trav = A; trav != -1 && VH.Nodes[trav].elem != elem; trav = VH.Nodes[trav].next){}
    return (trav != -1)? TRUE:FALSE;
}

void deleteElem(List* A, VirtualHeap* VH, char elem){
    List * trav, temp;
    for(trav = A; *trav != -1 && VH->Nodes[*trav].elem != elem; trav =  &(VH->Nodes[*trav].next)){}
    if(*trav != -1){
        temp = *trav;
        *trav = VH->Nodes[temp].next;
        freeSpace(VH,temp);
    }
}

void deleteAllOccur(List* A, VirtualHeap* VH, char elem){
    List temp, *trav;
    for(trav = A; *trav != -1;){
        if(VH->Nodes[*trav].elem == elem){
            temp = *trav;
            *trav = VH->Nodes[temp].next;
            freeSpace(VH, temp);
        }else{
            trav = &(VH->Nodes[*trav].next);
        }
    }
}

boolean isEqualList(List SET1, List SET2, VirtualHeap VH){
    int i,j;
    for(i = SET1,j=SET2; i!= -1 && j != -1 && VH.Nodes[i].elem == VH.Nodes[j].elem; i = VH.Nodes[i].next,j = VH.Nodes[j].next){}
    return (i == -1 && j == -1)? TRUE:FALSE;
}

void displayAvail(VirtualHeap VH){
    int i = VH.avail;
    while(i != -1){
        printf("%d ",VH.avail);
        VH.avail = VH.Nodes[i].next;
        i = VH.avail;
    }
    printf("\n");
}

#endif