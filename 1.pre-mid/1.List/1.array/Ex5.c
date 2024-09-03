#include <stdio.h>
#include <stdlib.h>
#define MAX 5

//Version 3 implementation
typedef struct{
    int* arr;
    int count;
    int arrSize;
}List;

void initialize(List* A);
void insertPos(int elem,int pos,List* A);
void displayList(List A);
void deletePos(int pos,List* A);
int locate(int elem,List A);
int retrieve(int pos,List A);
void makeNull(List* A);
void clean(List* A);

int main(){
    List L;
    initialize(&L);

    printf("\n\n==============================\n");\
    printf("Function: insertPos()\n");
    insertPos(1,0,&L);
    insertPos(2,1,&L);
    insertPos(3,2,&L);
    insertPos(4,3,&L);
    insertPos(5,4,&L);
    displayList(L);

    printf("\n\n==============================\n");
    printf("Function: delete(4,&L)\n");
    deletePos(4,&L);
    displayList(L);

    printf("\n\n==============================\n");
    printf("Function: locate(5,L)\n");
    int elem = 5;
    int p = locate(elem,L);
    printf("index of %d: %d\n",elem,p);
    displayList(L);

    printf("\n\n==============================\n");
    printf("Function: retrieve(5,L)\n");
    int pos = 5;
    int x = retrieve(pos,L);
    printf("Elem of index %d: %d\n",pos,x);
    displayList(L);

    printf("\n\n==============================\n");
    printf("Function: makeNull(&L)\n");
    makeNull(&L);
    displayList(L);

    clean(&L);
    return 0;
}

void initialize(List* A){
    A->arr = (int*)malloc(sizeof(int)*MAX);
    if(A->arr != NULL){
        A->count = 0;
        A->arrSize = MAX;
    }
}

void insertPos(int elem,int pos,List* A){
    if(A->count < A->arrSize && pos <= A->count && pos >=0){
        int i;
        for(i=A->count;i>pos;i--){
            A->arr[i] = A->arr[i-1];
        }
        A->arr[pos] = elem;
        A->count++;
    }else{
        printf("\nCapacity: %d/%d",A->count,A->arrSize);
        printf("\nList is full or INVALID position to insert");
    }
}

void deletePos(int pos,List* A){
    if(pos >= 0 && pos <A->count){
        int i;
        for(i=pos+1; i<A->count;i++){
            A->arr[i-1] = A->arr[i];
        }
        A->count--;
    }else{
        printf("\nINVALID Postition");
    }
}

int locate(int elem,List A){
    int i;
    for(i = 0; i< A.count && A.arr[i] != elem; i++){}

    return (i != A.count)? i:-1;
}

int retrieve(int pos,List A){
    return (pos >=0 && pos<A.count)? A.arr[pos]:-1;
}

void makeNull(List* A){
    A->count = 0;
}

void displayList(List A){
    int i;
    printf("\nList: ");
    for(i=0;i<A.count;i++){
        printf("%d ",A.arr[i]);
    }
}

void clean(List* A){
    free(A->arr);
}