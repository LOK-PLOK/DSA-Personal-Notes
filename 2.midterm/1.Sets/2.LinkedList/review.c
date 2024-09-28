#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}*Set;

Set initSet();
void insertSet(Set* A, int data[], int size);
void insertSetData(Set* A, int elem);
void deleteFromSet(Set *S, int data);
void displaySet(Set S);
Set Union(Set A, Set B);
Set Intersection(Set A, Set B);
Set Difference(Set A, Set B);

void clean(Set* A);

int main(){
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

    clean(&A);
    clean(&B);
    clean(&U);
    clean(&I);
    clean(&D);

    return 0;
}

Set initSet(){
    Set temp = NULL;
    return temp;
}

void insertSet(Set* A, int data[], int size){
    int i;
    for(i = 0; i< size; i++){
        Set temp = (Set)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->data = data[i];
            temp->next = *A;
            *A = temp;
        }
    }
}

void deleteFromSet(Set *S, int data){
    Set* trav;
    for(trav = S; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next){}
    if(*trav != NULL){
        Set temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

void displaySet(Set S){
    Set trav;
    for(trav = S; trav != NULL; trav = trav->next){
        printf("%d ",trav->data);
    }
    printf ("\n\n");
}

void clean(Set* A){
    Set temp;
    while(*A != NULL){
        temp = *A;
        *A = temp->next;
        free(temp);
    }
}

void insertSetData(Set* A, int elem){
    Set temp = (Set)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = elem;
        temp->next = *A;
        *A = temp;
    }
}

Set Union(Set A, Set B){
    Set U = initSet();
    Set travA = A, travB  = B;

    while(travA && travB != NULL){
        if(travA->data == travB->data){
            insertSetData(&U, travA->data);
            travA = travA->next;
            travB = travB->next;
        }else if(travA->data > travB->data){
            insertSetData(&U,travA->data);
            travA = travA->next;
        }else{
            insertSetData(&U,travB->data);
            travB = travB->next;
        }
    }

    Set remaining = (travA != NULL)? travA:travB;
    while(remaining != NULL){
        insertSetData(&U,remaining->data);
        remaining = remaining->next;
    }
    return U;
}

Set Intersection(Set A, Set B){
    Set I = initSet();
    Set travA = A, travB  = B;

    while(travA && travB != NULL){
        if(travA->data == travB->data){
            insertSetData(&I, travA->data);
            travA = travA->next;
            travB = travB->next;
        }else if(travA->data > travB->data){
            travA = travA->next;
        }else{
            travB = travB->next;
        }
    }

    Set remaining = (travA != NULL)? travA:travB;
    while(remaining != NULL){
        insertSetData(&I,remaining->data);
        remaining = remaining->next;
    }
    return I;

}

Set Difference(Set A, Set B){
    Set D = initSet();
    Set travA = A, travB  = B;

    while(travA && travB != NULL){
        if(travA->data == travB->data){
            travA = travA->next;
            travB = travB->next;
        }else if(travA->data > travB->data){
            insertSetData(&D, travA->data);
            travA = travA->next;
        }else{
            travB = travB->next;
        }
    }
    return D;
}
