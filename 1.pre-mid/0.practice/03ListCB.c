/**
 * List Cursor Based Implementation
 * 
 * initList()
 * isEmpty()
 * isFull()
 * displayList()
 * insertEnd()
 * insertFirst()
 * insertPos()
 * deleteElem()
 * deleteAtPos()
 * deleteAllOccur()
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef int List;

typedef struct{
    char elem;
    int link;
}Cell;

typedef struct {
    Cell Node[MAX];
    int avail;
}Heap;

void initHeap(Heap* VH);
int getSpace(Heap* VH);
void freeSpace(Heap* VH, int index);
void displayVH(Heap VH);
void clean(List* A,Heap* VH);

List initList();
void displayList(List A,Heap VH);
void insertFirst(Heap* VH,List* A, int elem);
void insertEnd(Heap* VH,List* A, int elem);
void insertPos(Heap* VH, List* A, int elem, int pos);
void deleteElem(Heap* VH,List* A, int elem);
void deletePos(Heap* VH,List* A, int pos);
void deleteAllOccur(Heap* VH,List* A, int elem);

int main(){
    system("cls");
    List L = initList();
    Heap VH;
    initHeap(&VH);
    // displayVH(VH);

    printf("List L: ");
    displayList(L, VH);

    insertFirst(&VH,&L, 1);
    insertFirst(&VH,&L, 2);
    insertFirst(&VH,&L, 3);
    insertFirst(&VH,&L, 4);

    printf("\ninsertFirst(1,2,3,4)\n");
    printf("List L: ");
    displayList(L, VH);

    insertEnd(&VH,&L, 5);
    insertEnd(&VH,&L, 6);
    printf("\ninsertEnd(5,6)\n");
    printf("List L: ");
    displayList(L,VH);

    insertPos(&VH,&L, 100, 3);
    printf("\ninsertPos(100,3)\n");
    printf("List L: ");
    displayList(L,VH);

    deleteElem(&VH,&L, 100);
    printf("\ndeleteElem(100)\n");
    printf("List L: ");
    displayList(L,VH);

    deletePos(&VH,&L, 3);
    printf("\ndeletePos(3)\n");
    printf("List L: ");
    displayList(L,VH);
    clean(&L,&VH);

    insertFirst(&VH, &L, 1);
    insertFirst(&VH, &L, 2);
    insertFirst(&VH, &L, 1);
    insertFirst(&VH, &L, 2);
    insertFirst(&VH, &L, 1);
    insertFirst(&VH, &L, 1);
    insertFirst(&VH, &L, 2);
    insertFirst(&VH, &L, 2);
    insertFirst(&VH, &L, 1);
    insertFirst(&VH, &L, 1);
    deleteAllOccur(&VH,&L, 1);
    printf("\ndeletePos(3)\n");
    printf("List L: ");
    displayList(L,VH);

    clean(&L,&VH);
    return 0;
}

List initList(){
    List temp = -1;
    return temp;
}
void displayList(List A,Heap VH){
    if(A != -1){
        List trav;
        for(trav = A; trav != -1; trav = VH.Node[trav].link){
            printf("%d ",VH.Node[trav].elem);
        }
        printf("\n");
    }else{
        printf("Empty\n");
    }
}

void insertFirst(Heap* VH,List* A, int elem){
    List temp = getSpace(VH);
    if(temp != -1){
        VH->Node[temp].elem = elem;
        VH->Node[temp].link = *A;
        *A = temp;
    }
}

void insertEnd(Heap* VH,List* A, int elem){
    List *trav,temp = getSpace(VH);
    if(temp != -1){
        for(trav = A; *trav != -1; trav = &VH->Node[*trav].link){}
        VH->Node[temp].elem = elem;
        VH->Node[temp].link = *trav;
        *trav = temp;
    }
}

void insertPos(Heap* VH, List* A, int elem, int pos){
    List *trav,temp = getSpace(VH);
    int i;
    if(temp != -1){
        for(trav = A,i=0; *trav != -1 && i != pos;trav = &VH->Node[*trav].link, i++){}
        if(i == pos){
            VH->Node[temp].elem = elem;
            VH->Node[temp].link = *trav;
            *trav = temp;
        }
    }
}

void deleteElem(Heap* VH,List* A, int elem){
    List* trav,temp;
    for(trav = A; *trav != -1 && VH->Node[*trav].elem != elem; trav = &VH->Node[*trav].link){}
    if(*trav != -1){
        temp = *trav;
        *trav = VH->Node[temp].link;
        freeSpace(VH,temp);
    }
}
void deletePos(Heap* VH,List* A, int pos){
    List* trav,temp;
    int i;
    for(trav = A,i=0; *trav != -1 && i != pos; trav = &VH->Node[*trav].link,i++){}
    if(i == pos){
        temp = *trav;
        *trav = VH->Node[temp].link;
        freeSpace(VH,temp);
    }
}

void deleteAllOccur(Heap* VH,List* A, int elem){
    List* trav,temp;
    for(trav = A; *trav != -1;){
        if(VH->Node[*trav].elem == elem){
            temp = *trav;
            *trav = VH->Node[temp].link;
            freeSpace(VH,temp);
        }else{
            trav = &VH->Node[*trav].link;
        }
    }
}

void initHeap(Heap* VH){
    int i;
    int last = MAX-1;
    for(i = 0; i<last; i++){
        VH->Node[i].link = i+1;
    }   
    VH->Node[last].link = -1;
    VH->avail = 0;
}
int getSpace(Heap* VH){
    int index = VH->avail;
    if(index != -1){
        VH->avail = VH->Node[index].link;
    }
    return index;
}
void freeSpace(Heap* VH, int index){
        VH->Node[index].link = VH->avail;
        VH->avail = index;
}
    

void displayVH(Heap VH){
    int i;
    for(i=0; i<MAX; i++){
        printf("%d ",i);
    }
    printf("\n");
    for(i=0; i<MAX; i++){
        printf("%d ",VH.Node[i].link);
    }
}
void clean(List* A,Heap* VH){
    List temp;
    while(*A != -1){
        temp = *A;
        *A = VH->Node[temp].link;
        freeSpace(VH,temp);
    }
}