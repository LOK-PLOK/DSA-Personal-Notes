#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int SET[MAX];

void displaySet(SET S);
SET* Union(SET A, SET B);
SET* Intersect(SET A, SET B);
SET* Difference(SET A, SET B);

int main(){
    system("cls");
    // system("clear");
    SET A = {1, 0, 1, 0, 1, 0, 1, 1, 0, 1};
    SET B = {1, 0, 0, 1, 1, 0, 0, 1, 1, 1};
    SET* C = Union(A,B);
    SET* D = Intersect(A,B);
    SET* E = Difference(A,B);
    SET* F = Difference(B,A);
    
    printf("Set A: ");
    displaySet(A);

    printf("Set B: ");
    displaySet(B);

    printf("Union A & B: ");
    displaySet(*C);

    printf("Intersect A & B: ");
    displaySet(*D);

    printf("Difference A - B: ");
    displaySet(*E);

    printf("Difference B - A: ");
    displaySet(*F);

    free(C);
    free(D);
    free(E);
    free(F);
    return 0;
}

void displaySet(SET S){
    printf("{");
    int i;
    for(i=0;i<MAX;i++){
        if(S[i] == 1){
            printf(" %d ",i);
        }
    }
    printf("}");
    printf("\n");
}

SET* Union(SET A, SET B){
    SET* S = (SET*)malloc(sizeof(SET));
    if(S != NULL){
        int i;
        for(i=0;i<MAX;i++){
            (*S)[i] = A[i] | B[i];
        }
    }
    return S;
}

SET* Intersect(SET A, SET B){
    SET* S = (SET*)malloc(sizeof(SET));
    if(S != NULL){
        int i;
        for(i=0;i<MAX;i++){
            (*S)[i] = A[i] & B[i];
        }
}
    return S;
}

SET* Difference(SET A, SET B){
    SET* S = (SET*)malloc(sizeof(SET)); 
    if(S != NULL){
        int i;
        for(i=0;i<MAX;i++){
            (*S)[i] = A[i] & ~B[i];
        }
    }
    return S;
}