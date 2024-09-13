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

int main() {
    Set A = createSet(6);
    Set B = createSet(10);
    
    // Adding elements to A
    addElem(&A, 0);
    addElem(&A, 2);
    addElem(&A, 4);
    addElem(&A, 5);
    
    // Adding elements to B
    addElem(&B, 0);
    addElem(&B, 1);
    addElem(&B, 2);
    addElem(&B, 3);
    addElem(&B, 4);
    addElem(&B, 7);
    addElem(&B, 9);
    
    // Display sets
    printf("Set A: ");
    displaySet(A);
    printf("Set B: ");
    displaySet(B);
    
    // Check if A is a subset of B
    if (isSubset(A, B)) {
        printf("\nA is a subset of B\n");
    } else {
        printf("\nA is not a subset of B\n");
    }
    
    // Check if B is a subset of A
    if (isSubset(B, A)) {
        printf("B is a subset of A\n");
    } else {
        printf("B is not a subset of A\n");
    }
    
    // Union of A and B
    Set C = UnionSet(A, B);
    printf("\nUnion of A and B: ");
    displaySet(C);

    // Intersect of A and B
    Set D = Intersect(A, B);
    printf("Intersect of A and B: ");
    displaySet(D);

    Set E = DifferenceSet(A, B);
    printf("Difference of A and B: ");
    displaySet(E);

    Set F = symmetricDifference(A, B);
    printf("symmetricDifference of A and B: ");
    displaySet(F);

    // Add and remove elements from set A
    addElem(&A, 1);  // Add element to A
    printf("\nAfter adding 1 to A: ");
    displaySet(A);
    
    removeElem(&A, 0);  // Remove element from A
    printf("After removing 0 from A: ");
    displaySet(A);

    // Check if an element is present in a set
    if (isElem(A, 2)) {
        printf("\nElement 2 is in A\n");
    } else {
        printf("Element 2 is not in A\n");
    }

    // Clean up dynamic memory
    free(A.elem);
    free(B.elem);
    free(C.elem);
    free(D.elem);
    free(E.elem);
    free(F.elem);
    
    return 0;
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

bool isElem(Set S, int elem){
    return (S.elem[elem] == 1)? 1:0;
}

bool isSubset(Set A, Set B) {
    int minMax = A.max;

    for (int i = 0; i < minMax; i++) {
        if (A.elem[i] == 1 && B.elem[i] == 0) {
            return false;
        }
    }
    return true;
}


Set UnionSet(Set A, Set B){
    Set big = (A.max > B.max)? A:B;
    Set small = (A.max > B.max)? B:A;
    Set temp = createSet(big.max);

    int i;
    for(i=0;i<small.max; i++){
        temp.elem[i] = small.elem[i] | big.elem[i];
    }

    while(i<big.max){
        temp.elem[i] = big.elem[i];
        i++;
    }

    return temp;

}

Set Intersect(Set A, Set B){
    Set big = (A.max > B.max)? A:B;
    Set small = (A.max > B.max)? B:A;
    Set temp = createSet(A.max);

    int i;
    for(i=0;i<small.max; i++){
        temp.elem[i] = small.elem[i] & big.elem[i];
    }

    
    return temp;
}

Set DifferenceSet(Set A, Set B){
    Set big = (A.max > B.max)? A:B;
    Set small = (A.max > B.max)? B:A;
    Set temp = createSet(A.max);

    int i;
    for(i=0;i<small.max; i++){
        temp.elem[i] = small.elem[i] & ~ big.elem[i];
    }

    if(temp.max == big.max){
        while(i<big.max){
            temp.elem[i] = big.elem[i];
            i++;
        }
    }

    return temp;
}

Set symmetricDifference(Set A, Set B){
    int big  = (A.max > B.max)? A.max:B.max;
    Set temp = createSet(big);
    Set first = (A,B);
    Set second = (B,A);
    temp = UnionSet(first,second);

    return temp;
}
