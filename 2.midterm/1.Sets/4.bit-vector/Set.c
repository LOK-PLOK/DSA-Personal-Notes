#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef int Set[MAX];
void displaySet(Set S);
Set* Union(Set A, Set B);
Set* Intersect(Set A, Set B);
Set* Difference(Set A, Set B);

int main(){
    Set A  = {1,0,1,0,1,0,1,1,0,1};
    Set B = {1,0,0,1,1,0,0,1,1,1};

    printf("Set A: ");
    displaySet(A);

    printf("Set A: ");
    displaySet(B);

    printf("Set U: ");
    Set* U = Union(A,B);
    displaySet(*U);

    printf("Set I: ");
    Set* I = Intersect(A,B);
    displaySet(*I);

    printf("Set D: ");
    Set* D = Difference(A,B);
    displaySet(*D);

    printf("Set E: ");
    Set* E = Difference(B,A);
    displaySet(*E);


    free(U);
    free(I);
    free(D);
    free(E);
    return 0;
}

void displaySet(Set S){
    int i;
    for(i = 0; i < MAX; i++){
        printf("%d ",S[i]);
    }
    printf("\n\n");
}

Set* Union(Set A, Set B){
    Set* U = (Set*)malloc(sizeof(Set));

    if(U != NULL){
        int i;
        for(i = 0; i< MAX; i++){
            (*U)[i] = A[i] | B[i];
        }
    }
}

Set* Intersect(Set A, Set B){
    Set* I = (Set*)malloc(sizeof(Set));

    if(I != NULL){
        int i;
        for(i = 0; i< MAX; i++){
            (*I)[i] = A[i] & B[i];
        }
    }
}

Set* Difference(Set A, Set B){
    Set* D = (Set*)malloc(sizeof(Set));

    if(D != NULL){
        int i;
        for(i = 0; i< MAX; i++){
            (*D)[i] = A[i] & ~B[i];
        }
    }
}
