#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *elem;
    int count;
    int max;
}Set;

// typedef char Set;

Set createSet(int max);
void initSet(Set* S, int max);

bool addElem(Set* S, int elem);
bool removeElem(Set* S, int elem);
void displaySet(Set S);
bool isElem(Set S, int elem);
bool isSubset(Set A, Set B);

Set UnionSet(Set A, Set B);
Set Intersect(Set A, Set B);
Set DifferenceSet(Set A, Set B);
Set symmetricDifference(Set A, Set B);

int main(){
    Set A = createSet(5);
    Set B = createSet(10);
    
    printf("Set A: ");
    displaySet(A);
    printf("Set B: ");
    displaySet(B);

    addElem(&A, 0);
    addElem(&A, 2);
    addElem(&A, 4);
    addElem(&B, 0);
    addElem(&B, 2);
    addElem(&B, 4);
    addElem(&B, 3);
    addElem(&B, 1);

    printf("\nSet A: ");
    displaySet(A);
    printf("Set B: ");
    displaySet(B);

}

Set createSet(int max){
    Set temp;
    temp.max = max;
    temp.count = 0;
    temp.elem = (int*)calloc(sizeof(int),temp.max);
    return temp;
}

void initSet(Set* S, int max){
    S->max = max;
    S->count = 0;
    S->elem = (int*)calloc(sizeof(int),S->max);
}

void displaySet(Set S){
    int i;
    for(i = 0; i<S.max;i++){
        printf("%d ",S.elem[i]);
    }
    printf("\n");
}

bool addElem(Set* S, int elem){
    if(S->elem[elem] == 0){
        S->elem[elem] =1;
        S->count++;
        return true;
    }

    return false;
}

bool removeElem(Set* S, int elem){
    if(S->elem[elem] == 1){
        S->elem[elem] = 0;
        S->count--;
        return true;
    }
    return false;
}

bool

/**
 * 
 * take into account into different maxes
 */

