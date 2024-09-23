/**
 * List Array Implementation
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
#define MAX 10

typedef struct {
    int elem[MAX];
    int lastNdx;  // last index version
}*List,list; //version 2

void initList(List* A);
void insertEnd(List A, int elem);
void insertFirst(List A, int elem);
void insertPos(List A, int elem, int pos);
void deleteElem(List A, int elem);
void deleteAtPos(List A, int pos);
void deleteAllOccur(List  A, int elem);
void displayList(list A);

int main() {
    List A;
    initList(&A);

    // Example usage of the functions
    insertEnd(A, 5);
    insertEnd(A, 10);
    insertFirst(A, 1);
    insertPos(A, 7, 2);
    displayList(*A);

    deleteElem(A, 7);
    deleteAtPos(A, 1);
    displayList(*A);

    insertEnd(A, 5);
    deleteAllOccur(A, 5);
    displayList(*A);

    free(A);
    return 0;
}

void initList(List* A){
    (*A) = (List)malloc(sizeof(list));
    if((*A)!= NULL){
        (*A)->lastNdx = -1;
    }
}

void insertEnd(List A, int elem){
    if(A->lastNdx != MAX-1){
        A->elem[++A->lastNdx] = elem;
    }
}

void insertFirst(List A, int elem){
    if(A->lastNdx != MAX-1){
        int i;
        A->lastNdx++;
        for(i=A->lastNdx;i>0;i--){
            A->elem[i] = A->elem[i-1];
        }
        A->elem[0] = elem;
    }
}

void insertPos(List A, int elem, int pos){
    if(A->lastNdx+1 != MAX && pos <= A->lastNdx && pos >=0){
        int i;
        A->lastNdx++;
        for(i=A->lastNdx;i>pos;i--){
            A->elem[i] = A->elem[i-1];
        }
        A->elem[pos] = elem;
    }
}

void deleteElem(List A, int elem){
    if(A->lastNdx != -1){
        int i, j;
        for(i = 0; i<= A->lastNdx && A->elem[i] != elem; i++){}
        if(i <= A->lastNdx){
            for(j = i + 1; j <= A->lastNdx; j++){
                A->elem[j-1] = A->elem[j];
            }
            A->lastNdx--;
        }
    }
}

void deleteAtPos(List A, int pos){
    if(A->lastNdx != -1 && pos>=0 && pos <= A->lastNdx){
        int i;
        A->lastNdx--;
        for(i=pos+1; i<= A->lastNdx; i++){
            A->elem[i-1] = A->elem[i];
        }
    }
}

void deleteAllOccur(List A, int elem){
    if(A->lastNdx != -1){
        int i, j;
        for(i = 0; i <= A->lastNdx;){
            if(A->elem[i] == elem){
                A->lastNdx--;
                for(j = i + 1; j <= A->lastNdx; j++){
                    A->elem[j-1] = A->elem[j];
                }
            } else {
                i++;
            }
        }
    }
}

void displayList(list A){
    if(A.lastNdx != -1){
        printf("List: ");
        for (int i = 0; i <= A.lastNdx; i++) {
            printf("%d ", A.elem[i]);
        }
        printf("\n");
    } else {
        printf("Empty\n");
    }
}
