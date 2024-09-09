#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int elem;
    struct node* link;
}*SET;

void displaySet(SET S);
void clean(SET* S);
void insertSet(SET*S, int elem);

SET Union(SET A, SET B);
SET Intersect(SET A, SET B);
SET Difference(SET A, SET B);

int main(){
    SET A = NULL;
    insertSet(&A,0);
    insertSet(&A,2);
    insertSet(&A,4);
    insertSet(&A,6);
    insertSet(&A,7);
    insertSet(&A,9);

    SET B = NULL;
    insertSet(&B,0);
    insertSet(&B,3);
    insertSet(&B,4);
    insertSet(&B,7);
    insertSet(&B,8);
    insertSet(&B,9);

    SET C = Union(A,B);
    SET D = Intersect(A,B);
    SET E = Difference(A,B);
    SET F = Difference(B,A);

    printf("Set A: ");
    displaySet(A);

    printf("Set B: ");
    displaySet(B);

    printf("Union A & B: ");
    displaySet(C);

    printf("Intersect A & B: ");
    displaySet(D);

    printf("Difference A - B: ");
    displaySet(E);

    printf("Difference B - A: ");
    displaySet(F);

    clean(&A);
    clean(&B);
    clean(&C);
    clean(&D);
    clean(&E);
    clean(&F);
}

SET Union(SET A, SET B){
    SET travA = A, travB = B;
    SET S = NULL;

    while(travA != NULL && travB != NULL){
        if(travA->elem == travB->elem){
            insertSet(&S,travA->elem);
            travA = travA->link;
            travB = travB->link;
        }else if(travA->elem < travB->elem){
            insertSet(&S,travA->elem);
            travA = travA->link;
        }else{
            insertSet(&S,travB->elem);
            travB = travB->link;
        }
    }

    SET remaining = (travA != NULL)? travA:travB;
    while(remaining != NULL){
        insertSet(&S,remaining->elem);
        remaining = remaining->link;
    }

    return S;
}

SET Intersect(SET A, SET B){
    SET travA = A, travB = B;
    SET S = NULL;

    while(travA != NULL && travB != NULL){
        if(travA->elem == travB->elem){
            insertSet(&S,travA->elem);
            travA = travA->link;
            travB = travB->link;
        }else if(travA->elem < travB->elem){
            travA = travA->link;
        }else{
            travB = travB->link;
        }
    }
    return S;
}

SET Difference(SET A, SET B){
    SET travA = A, travB = B;
    SET S = NULL;

    while(travA != NULL && travB != NULL){
        if(travA->elem == travB->elem){
            travA = travA->link;
            travB = travB->link;
        }else if(travA->elem < travB->elem){
            insertSet(&S,travA->elem);
            travA = travA->link;
        }else{
            travB = travB->link;
        }
    }

    while (travA != NULL) {
        insertSet(&S, travA->elem);
        travA = travA->link;
    }

    return S;
}

void insertSet(SET*S, int elem){
    SET * trav,temp;
    for(trav = S; *trav != NULL; trav = &(*trav)->link){}
    if(*trav == NULL){
        temp = (SET)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->elem = elem;
            temp->link = *trav;
            *trav = temp;
        }
    }
}

void displaySet(SET S){
    SET trav;
    printf("{");
    for(trav = S; trav!=NULL; trav = trav->link){
        printf(" %d ",trav->elem);
    }
    printf("}");
    printf("\n");
}

void clean(SET* S){
    SET temp;
    while(*S != NULL){
        temp = *S;
        *S = temp->link;
        free(temp);
    }
}
