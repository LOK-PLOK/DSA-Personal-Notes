#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int set[MAX];
    int size;
} Set;

Set initSet();
void insertSet(Set* A, int data[], int size);
void deleteFromSet(Set *S, int data);
void displaySet(Set S);
Set Union(Set A, Set B);
Set Intersection(Set A, Set B);
Set Difference(Set A, Set B);

int main() {
    system("cls");
    Set A = initSet();
    Set B = initSet();
    int data[] = {0,2,4,6,7,9};
    int data2[] = {0,3,4,7,8,9};

    printf("Set A: ");
    insertSet(&A,data, sizeof(data)/sizeof(data[0]));
    displaySet(A);

    printf("Set B: ");
    insertSet(&B,data2, sizeof(data2)/sizeof(data2[0]));
    displaySet(B);


    Set U = Union(A, B);
    printf("Union: ");
    displaySet(U);

    Set I = Intersection(A, B);
    printf("Intersection: ");
    displaySet(I);

    Set D = Difference(A, B);
    printf("(A - B): ");
    displaySet(D);

    D = Difference(B, A);
    printf("(B - A): ");
    displaySet(D);

    int temp;
    printf("\nRemove an element from set A: ");
    scanf(" %d", &temp);

    deleteFromSet(&A, temp);
    printf("A without '%d': ", temp);
    displaySet(A);

    return 0;
}

Set initSet(){
    Set temp;
    int i;
    for(i = 0; i<MAX; i++){
        temp.set[i] = 0;
    }
    temp.size = 0;
    return temp;
}

void insertSet(Set* A, int data[], int size){
    int i;
    for(i = 0; i< size; i++){
        A->set[data[i]] = 1;
    }
    A->size = size;
}

void deleteFromSet(Set *A, int data){
    A->set[data] = 0;
    A->size--;
}

void displaySet(Set S){
    int i;
    printf("{ ");
    for(i = 0; i<MAX; i++){
        if(S.set[i] == 1){
            printf("%d ", i);
        }
    }
    printf("}");
    printf("\n\n");
}

Set Union(Set A, Set B){
    int i;
    Set U = initSet();
    for(i = 0; i< MAX; i++){
        U.set[i] = A.set[i] | B.set[i];
        if(U.set[i] == 1){
            U.size++;
        }
    }
    return U;
}

Set Intersection(Set A, Set B){
    int i;
    Set I = initSet();
    for(i = 0; i<MAX; i++){
        I.set[i] = A.set[i] & B.set[i];
        if(I.set[i] == 1){
            I.size++;
        }
    }
    return I;
}

Set Difference(Set A, Set B){
    int i;
    Set D = initSet();
    for(i = 0; i< MAX; i++){
        D.set[i] = A.set[i] & ~B.set[i];
        if(D.set[i] == 1){
            D.size++;
        }
    }
    return D;
}