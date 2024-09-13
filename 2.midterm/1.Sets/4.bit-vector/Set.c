#include <stdio.h>
#include <stdlib.h>

typedef unsigned char SET;

SET initSet();
void display(SET S);
void insert(SET* S, int elem);
int isMember(SET S, int elem);
void delete(SET* S, int elem);
SET Union(SET A, SET B);
SET Intersect(SET A, SET B);
SET Difference(SET A, SET B);

int main(){
    system("cls");
    SET A = initSet();
    SET B = initSet();
    
    printf("Initial Set A: ");
    display(A);
    printf("Initial Set B: ");
    display(B);

    // Insert values in A: 0, 1, 3
    insert(&A, 0);
    insert(&A, 1);
    insert(&A, 3);

    // Insert values in B: 1, 2, 4
    insert(&B, 1);
    insert(&B, 2);
    insert(&B, 4);

    printf("\nAfter inserting 0,1,3 into A\n");
    printf("After inserting 1,2,4 into B\n");

    printf("Set A: ");
    display(A);
    printf("Set B: ");
    display(B);

    // Demonstrate isMember
    printf("isMember(A,1): %d\n", isMember(A, 1)? 1 : 0);
    printf("isMember(B,0): %d\n", isMember(B, 0)? 1 : 0);
    
    // Delete elements 1 and 3 from A
    delete(&A, 1);
    delete(&A, 3);
    printf("\nAfter deleting 1,3 from A\n");
    printf("Set A: ");
    display(A);

    // Set operations
    SET unionSet = Union(A,B);
    SET intersectSet = Intersect(A,B);
    SET differenceAB = Difference(A,B);
    SET differenceBA = Difference(B,A);

    printf("\nUnion A&B: ");
    display(unionSet);

    printf("Intersect A&B: ");
    display(intersectSet);

    printf("Difference A&B: ");
    display(differenceAB);

    printf("Difference B&A: ");
    display(differenceBA);

    return 0;
}

SET initSet(){
    return 0;  // Initializes all bits to 0
}

void display(SET S){
    int masked = 1 << (sizeof(S) * 8 - 1);  // Mask starts at the leftmost bit

    while (masked != 0){
        printf("%d ", (S & masked) ? 1 : 0);
        masked = masked >> 1;
    }
    printf("\n");
}

void insert(SET* S, int elem){
    *S |= (1 << elem);  // Set the bit at position `elem` to 1
}

int isMember(SET S, int elem){
    return (S & (1 << elem-1));  // Return non-zero if the bit is set
}

void delete(SET* S, int elem){
    *S &= ~(1 << elem-1);  // Clear the bit at position `elem`
}

SET Union(SET A, SET B){
    return (A | B);  // Bitwise OR of A and B 
}

SET Intersect(SET A, SET B){
    return (A & B);  // Bitwise AND of A and B
}

SET Difference(SET A, SET B){
    return (A & ~B);  // Elements in A but not in B
}
