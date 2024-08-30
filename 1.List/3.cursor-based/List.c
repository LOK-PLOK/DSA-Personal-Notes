#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int List;

typedef struct {
    int elem;
    int link;
}Cell;

typedef struct{
    Cell Nodes[MAX];
    int avail;
}VirtualHeap;

void insertFirst(List* L, VirtualHeap* VH, int elem);

//Cursor-based preparation functions: 
void initVirtualHeap(VirtualHeap* VH);
void initList(List* A);
int allocSpace(VirtualHeap* VH);
void freeSpace(VirtualHeap* VH, int index);
void display(List L,VirtualHeap VH);

//List functions:
void insertFirst(List* L, VirtualHeap* VH, int elem);
// void insertLast(List* L, VirtualHeap* VH, int elem);
// void delete(List* L, VirtualHeap* VH, int elem);
// int isInList(List L, VirtualHeap VH, int elem);
// int locate(List L, VirtualHeap VH, int elem);

/*
    Note to self:
    cursor-base has 2 variables, the heap and the pointer to the list, meaning 2 initialization
 */

int main(){
    List L;
    VirtualHeap VH;

    system("cls");
    initVirtualHeap(&VH);
    initList(&L);
    display(L,VH);

    insertFirst(&L,&VH,5);
    display(L,VH);
    
}

void initVirtualHeap(VirtualHeap* VH){   
    VH->avail = MAX  -1;                
    int i;                             
    for(i = MAX - 1; i>=0; i--){       
        VH->Nodes[i].link = i-1;        
    }                                   
}                                      
                                       
void initList(List* A){                
    *A = -1;                           
}                                       

int allocSpace(VirtualHeap* VH){
    int Index = VH->avail; // get the index of the first available cell
    if(Index != -1){
        VH->avail = VH->Nodes[Index].link; // changes avail to the index of the next available cell 
    }
    return Index;
}

void freeSpace(VirtualHeap* VH, int index){
    if(index >=0 && index < MAX){
        VH->Nodes[index].link = VH->avail; // assign the cell to the next available cell
        VH->avail = index;// assigns the current cell as the current available cell;
    }
}

void display(List L,VirtualHeap VH){
    printf("\nCursor-based List: ");
    if(L != -1){
        List i;
        for(i = L; i!=-1 ; i = VH.Nodes[i].link){
            printf("%d ",VH.Nodes[i].elem);
        }
    }else{
        printf("Empty\n");
    }
}

void insertFirst(List* L, VirtualHeap* VH, int elem){
    if(VH->avail != -1){
        int avail = allocSpace(VH);
        VH->Nodes[avail].elem = elem;
        VH->Nodes[avail].link = *L;
        *L = avail;
    }else{
        printf("No available space");
    }
}
