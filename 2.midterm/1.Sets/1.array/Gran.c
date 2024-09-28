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
    system("cls");
    Set A = createSet(7);
    Set B = createSet(10);

    //Elements of A
    addElem(&A, 0);
    addElem(&A, 2);
    addElem(&A, 4);
    addElem(&A, 5);
    addElem(&A, 6);

    //Elements of B
    addElem(&B, 0);
    addElem(&B, 1);
    addElem(&B, 2);
    addElem(&B, 4);
    addElem(&B, 7);
    addElem(&B, 9);

    //Print both Sets
    printf("Set A: ");
    displaySet(A);
    printf("Set B: ");
    displaySet(B);

    //Check if A is a subset of B
    if(isSubset(A, B)){
        printf("\nA is a subset of B\n");
    }else{
        printf("\nA is not a subset of B\n");
    }

    //Check if B is a subset of A
    if(isSubset(B, A)){
        printf("B is a subset of A\n");
    }else{
        printf("B is not a subset of A\n");
    }

    //Union of A and B
    Set C = UnionSet(A,B);
    printf("\nUnion of A and B: ");
    displaySet(C);

    //Intersect of A and B
    Set D = Intersect(A,B);
    printf("Intersect of A and B: ");
    displaySet(D);

    //Difference of A and B
    Set E = DifferenceSet(A,B);
    printf("Difference of A and B: ");
    displaySet(E);

    //Symmetric Difference of A and B
    Set F = symmetricDifference(A,B);
    printf("Symmetric Difference of A and B: ");
    displaySet(F);

    //Adding 1 to Set A if it does not have 1
    addElem(&A, 1);  
    printf("\nAfter adding 1 to A: ");
    displaySet(A);
    
    //remove 1 to Set A if its 1
    removeElem(&A, 0); 
    printf("After removing 0 from A: ");
    displaySet(A);

    //Checking if 2 is an element of Set A
    if (isElem(A, 2)) {
        printf("\nElement 2 is in A\n");
    } else {
        printf("Element 2 is not in A\n");
    }

    //Cleaning of Dynamic Arrays
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
    temp.count = 0;
    temp.max = max;
    temp.elem = (int*)calloc(sizeof(int),temp.max);
    return temp;
}

bool addElem(Set* S, int index){
    if(S->elem[index] == 0){
        S->elem[index] = 1;
        S->count++;
        return 1;
    }
    return 0;
}

void displaySet(Set S){
    int i;
    for(i = 0; i<S.max; i++){
        printf("%d ",(S.elem[i] == 1)? 1:0);
    }
    printf("\n");
}

bool removeElem(Set* S, int index){
    if(S->elem[index] == 1){
        S->elem[index] = 0;
        S->count--;
        return 1;
    }
    return 0;
}

bool isElem(Set S, int index){
    if(S.elem[index] == 1){
        return 1;
    }
    return 0;
}

bool isSubset(Set A, Set B){
    int i;
    for(i=0; i<A.max; i++){
        if(A.elem[i] == 1 && B.elem[i] == 0){
            return 0;
        }
    }

    return 1;
}

Set UnionSet(Set A, Set B){
    Set big = (A.max > B.max)? A:B;
    Set small = (A.max > B.max)? B:A;
    Set temp = createSet(big.max);

    int i;
    for(i=0;i<small.max;i++){
        temp.elem[i] = big.elem[i] | small.elem[i];
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
    for(i=0;i<small.max;i++){
        temp.elem[i] = big.elem[i] & small.elem[i];
    }

    if(temp.max == big.max){
        while(i<big.max){
            temp.elem[i] = big.elem[i];
            i++;
        }
    }

    return temp;
}

Set DifferenceSet(Set A, Set B){
    Set big = (A.max > B.max)? A:B;
    Set small = (A.max > B.max)? B:A;
    Set temp = createSet(A.max);

    int i;
    for(i=0;i<small.max;i++){
        temp.elem[i] = small.elem[i] & ~big.elem[i];
    }

    if(temp.max == big.max){
        while(i<big.max){
            temp.elem[i] = big.elem[i];
            i++;
        }
    }

    return temp;
}


Set symmetricDifference(Set A, Set B) {
    int size = (A.max > B.max) ? A.max : B.max;
    Set temp = createSet(size);

    Set diffAB = DifferenceSet(A, B);
    Set diffBA = DifferenceSet(B, A);

    temp = UnionSet(diffAB, diffBA);

    free(diffAB.elem);
    free(diffBA.elem);

    return temp;
}
