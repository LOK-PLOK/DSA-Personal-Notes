/**
 * Linked List implementations, definitions and funtions here
 */

#ifndef Linked_List_implementation_H
#define Linked_List_implementation_HH

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char elem;
    struct node* next;
}*List;
typedef enum{TRUE,FALSE}boolean;

void initList(List* A){
    *A = NULL;
}

void display(List A){
    printf("Linked List, List: ");
    if(A != NULL){
        List trav;
        for(trav=A; trav != NULL ; trav = trav->next){
            printf("%c ",trav->elem);
        }
        printf("\n");
    }else{
        printf("Empty \n");
    }
}

void clean(List *A){
    List temp;
    while(*A != NULL){
        temp = *A;
        *A = temp->next;
        free(temp);
    }
}

void insertFirst(List* A, char elem){
    List temp = (List)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->elem = elem;
        temp->next = *A;
        *A = temp;
    }
}

void insertLast(List* A, char elem){
    List temp = (List)malloc(sizeof(struct node));
    List * trav;
    if(temp != NULL){
        for(trav = A; *trav != NULL; trav = &(*trav)->next){}
        if(*trav == NULL){
            temp->elem = elem;
            temp->next = *trav;
            *trav = temp;
        }
    }
}

void insertSorted(List* A, char elem){
    List temp = (List)malloc(sizeof(struct node));
    List* trav;
    if(temp != NULL){
        for(trav = A; *trav != NULL && (*trav)->elem < elem; trav = &(*trav)->next){}
        temp->elem = elem;
        temp->next = *trav;
        *trav = temp;
    }
}

void insertAtPos(List* A, char elem, int pos){
    int i;
    List* trav;
    List temp;
    for(i=0, trav = A; *trav != NULL && i != pos; trav = &(*trav)->next,i++){}
    if(i== pos){
        temp = (List)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->elem = elem;
            temp->next = *trav;
            *trav = temp;
        }
    }
}

boolean findElem(List A, char elem){
    List trav;
    for(trav = A; trav != NULL && trav->elem != elem; trav = trav->next){}
    return (trav != NULL)? TRUE:FALSE;
}

void deleteElem(List* A,char elem){
    List * trav;
    List temp;
    for(trav = A; *trav != NULL && (*trav)->elem != elem; trav = &(*trav)->next){}
    if(*trav != NULL){
        temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

void deleteAllOccur(List* A, char elem){
    List* trav;
    List temp;
    for(trav = A; *trav != NULL;){
        if((*trav)->elem == elem){
            temp = *trav;
            *trav = temp->next;
            free(temp);
        }else{
            trav = &(*trav)->next;
        }
    }
}

#endif