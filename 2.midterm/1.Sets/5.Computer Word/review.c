#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned char Set;

void display(Set S);
bool insertSet(Set* S, int elem);
bool isMember(Set S, int elem);
bool deleteSet(Set* S, int elem);
Set Union(Set A, Set B);
Set Intersect(Set A, Set B);
Set Difference(Set A, Set B);

int main(){
    Set A = 0;
    Set B = 0;

    printf("Set A: ");
    display(A);
    
    printf("Set B: ");
    display(B);

    insertSet(&A,2);
    insertSet(&A,3);
    insertSet(&A,4);
    insertSet(&A,5);
    insertSet(&B,4);
    insertSet(&B,5);
    insertSet(&B,6);
    insertSet(&B,7);

    // after insertion
    printf("Set A: ");
    display(A);
    
    printf("Set B: ");
    display(B);

    deleteSet(&B, 7);
    
    printf("\nSet B: ");
    display(B);

    // Set operations
    Set unionSet = Union(A,B);
    Set intersectSet = Intersect(A,B);
    Set differenceAB = Difference(A,B);
    Set differenceBA = Difference(B,A);

    printf("\nUnion A&B: ");
    display(unionSet);

    printf("Intersect A&B: ");
    display(intersectSet);

    printf("Difference A&B: ");
    display(differenceAB);

    printf("Difference B&A: ");
    display(differenceBA);

}

void display(Set S){
    int mask = 1 << (sizeof(S)* 8 - 1);

    while(mask != 0){
        printf("%d ",(S & mask)? 1:0);
        mask >>= 1;
    }
    printf("\n");
}

bool insertSet(Set* S, int elem){
    bool check = false;
    int mask = 1 << elem;
    if((*S & mask) != 1){
        *S = *S | mask;   
        check = true;
    }
    return check;
}

bool isMember(Set S, int elem){
    int mask = 1 << elem;
    return (S & mask)? true:false;
}

bool deleteSet(Set* S, int elem){
    bool check = false;
    int mask = 1 << elem;
    if((*S & mask) != 0){
        *S = *S & ~mask;
        check = true;
    }

    return check;
}

Set Union(Set A, Set B){
    return (A | B);
}

Set Intersect(Set A, Set B){
    return (A & B);
}

Set Difference(Set A, Set B){
    return (A & ~ B);
}