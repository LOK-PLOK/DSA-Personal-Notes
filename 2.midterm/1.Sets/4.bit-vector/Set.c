#include <stdio.h>
#include <string.h>

typedef unsigned char SET;

SET initSet();
void displaySet(SET A);
void insert(SET* S, int elem);
int member(SET S, int elem);
void delete(SET* S, int elem);
SET UnionAB(SET A, SET B);
SET IntersectAB(SET A, SET B);
SET DifferenceAB(SET A, SET B);

int main(){
    SET A = 'A';
    SET B = initSet();

    printf("SetA: ");
    displaySet(A);
    printf("SetB: ");
    displaySet(B);

    insert(&A,1);
    insert(&A,2);
    insert(&A,3);
    insert(&A,4);
    insert(&A,5);
    insert(&A,7);

    printf("\ninsert(1,2,3,4,5,7): \n");
    printf("SetA: ");
    displaySet(A);
    printf("SetB: ");
    displaySet(B);

    

}

SET initSet(){
    return 0; // inializies all bits to 0  --> 0000 0000
}

void displaySet(SET A){
    int masked = 1 << (sizeof(A)*8 -1);

    while(masked != 0){
        printf("%d ",(A & masked)? 1:0);
        masked = masked >> 1;
    }
    printf("\n");
}

void insert(SET* S, int elem){
    *S |= (1<< elem); // *S = *S | (1<<elem)
}

int member(SET S, int elem){
    return(S & (1<<elem)); 
}

void delete(SET* S, int elem){
    *S &= ~(1<<elem); // *S = *S & ~(1<<elem)
}

SET UnionAB(SET A, SET B){
    return A | B;
}

SET IntersectAB(SET A, SET B){
    return A & B;
}

SET DifferenceAB(SET A, SET B){
    return A & ~B;
} 