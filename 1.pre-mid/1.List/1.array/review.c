#include <stdio.h>
#define MAX 10
/**
 * List Array implementaiton review
 * 
 * functions:
 * initList(),
 * insertLast(),
 * insertFirst()
 * insertPos()
 * deleteElem(),
 * deletePos(),
 * deleteAllOccur()
 * displayList()
 */

typedef struct {
    char elem[MAX];
    int count;
}List;

void initList(List* A);
void displayList(List A);
void insertEnd(List* A, int elem);
void insertFirst(List* A, int elem);
void insertPos(List* A, int elem, int pos);
void deleteElem(List* A, int elem);
void deletePos(List* A, int pos);
void deleteAll(List * A);
void deleteAllOccur(List * A, int elem);

int main(){
    List L;
    initList(&L);

    printf("List L: ");
    displayList(L);
    insertEnd(&L, 1);
    insertEnd(&L, 2);
    insertEnd(&L, 3);
    insertEnd(&L, 4);
    
    printf("\nInsertEnd(1,2,3,4)\n");
    printf("List L: ");
    displayList(L);

    insertFirst(&L,5);
    insertFirst(&L,6);
    printf("\nInsertFirst(5,6)\n");
    printf("List L: ");
    displayList(L);

    insertPos(&L, 100, 3);
    printf("\nInsertPos(100,3)\n");
    printf("List L: ");
    displayList(L);
    
    deleteElem(&L, 100);
    printf("\ndeleteElem(100)\n");
    printf("List L: ");
    displayList(L);
    
    deletePos(&L, 3);
    printf("\ndeletePos(3)\n");
    printf("List L: ");
    displayList(L);
    
    deleteAll(&L);
    printf("\ndeleteAll()\n");
    printf("List L: ");
    displayList(L);

    insertEnd(&L,1);
    insertEnd(&L,2);
    insertEnd(&L,1);
    insertEnd(&L,2);
    insertEnd(&L,1);
    insertEnd(&L,2);
    insertEnd(&L,1);
    insertEnd(&L,2);
    insertEnd(&L,1);
    insertEnd(&L,1);
    insertEnd(&L,1);

    deleteAllOccur(&L,1);
    printf("\ndeleteAllOccur(1)\n");
    printf("List L: ");
    displayList(L);

    return 0;
}

void initList(List* A){
    A->count = 0;
}

void displayList(List A){
    if(A.count !=0){
        int i;
        for(i=0;i<A.count;i++){
            printf("%d ",A.elem[i]);
        }
        printf("\n");
    }else{
        printf("Empty\n");
    }
}

void insertEnd(List* A, int elem){
    if(A->count != MAX){
        A->elem[A->count++] = elem;
    }
}

void insertFirst(List* A, int elem){
    if(A->count != MAX){
        int i;
        for(i=A->count; i>0; i--){
            A->elem[i] = A->elem[i-1];
        }
        A->elem[0] = elem;
        A->count++;
    }
}

void insertPos(List* A, int elem, int pos){
    if(A->count != MAX && pos <= A->count && pos >= 0){
        int i;
        for(i = A->count; i>pos; i--){
            A->elem[i] = A->elem[i-1];
        }
        A->elem[pos] = elem;
        A->count++;
    }
}

void deleteElem(List* A, int elem){
    int i,j;
    for(i=0; i<A->count && A->elem[i] != elem; i++){}

    if(i != A->count){
        for(j = i+1; j<A->count; j++){
            A->elem[j-1] = A->elem[j];
        }
        A->count--;
    }
}

void deletePos(List* A, int pos){
    if(pos < A->count && pos>= 0){
        int i;
        for(i=pos+1; i<A->count; i++){
            A->elem[i-1] = A->elem[i];
        }
        A->count--;
    }
}

void deleteAll(List * A){
    A->count = 0;
}

void deleteAllOccur(List * A, int elem){
    int i,j;
    for(i=0; i<A->count;){
        if(A->elem[i] == elem){
            for(j=i+1; j<A->count; j++){
                A->elem[j-1] = A->elem[j];
            }
            A->count--;
        }else{
            i++;
        }
    }
}