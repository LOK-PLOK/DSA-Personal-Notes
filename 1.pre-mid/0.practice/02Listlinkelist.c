/**
 * List Linked List Implementation
 * 
 * initList()
 * isEmpty()
 * isFull()
 * displayList()
 * insertEnd()
 * insertFirst()
 * insertPos()
 * deleteElem()
 * deleteAtPos()
 * deleteAllOccur()
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct nodetype{
    int elem;
    struct nodetype* link;
}*List,Node;

List initList();
void displayList(List A);
void insertFirst(List* A, int elem);
void clean(List* A);
void insertEnd(List* A, int elem);
void insertPos(List* A, int elem, int pos);
void deleteElem(List* A, int elem);
void deletePos(List*A, int pos);
void deleteAllOccur(List* A, int elem);

int  main(){
    system("cls");
    List L = initList();

    printf("List L: ");
    displayList(L);

    insertFirst(&L, 1);
    insertFirst(&L, 2);
    insertFirst(&L, 3);
    insertFirst(&L, 4);

    printf("\ninsertFirst(1,2,3,4)\n");
    printf("List L: ");
    displayList(L);

    insertEnd(&L, 5);
    insertEnd(&L, 6);
    printf("\ninsertEnd(5,6)\n");
    printf("List L: ");
    displayList(L);
    
    insertPos(&L, 100, 3);
    printf("\ninsertPos(100,3)\n");
    printf("List L: ");
    displayList(L);

    deleteElem(&L, 100);
    printf("\ndeleteElem(100)\n");
    printf("List L: ");
    displayList(L);
    
    deletePos(&L, 3);
    printf("\ndeletePos(3)\n");
    printf("List L: ");
    displayList(L);
    clean(&L);
    
    insertFirst(&L, 1);
    insertFirst(&L, 2);
    insertFirst(&L, 1);
    insertFirst(&L, 2);
    insertFirst(&L, 1);
    insertFirst(&L, 1);
    insertFirst(&L, 2);
    insertFirst(&L, 2);
    insertFirst(&L, 1);
    insertFirst(&L, 1);
    deleteAllOccur(&L, 1);
    printf("\ndeletePos(3)\n");
    printf("List L: ");
    displayList(L);

    clean(&L);
}

List initList(){
    return NULL;
}


void displayList(List A){
    if(A != NULL){
        List trav;
        for(trav = A; trav != NULL; trav = trav->link){
            printf("%d ",trav->elem);
        }
        printf("\n");
    }else{
        printf("Empty\n");
    }    
}

void insertFirst(List* A, int elem){
    List temp = (List)malloc(sizeof(Node));
    if(temp != NULL){
        temp->elem = elem;
        temp->link = *A;
        *A = temp;
    }
}

void clean(List* A){
    List temp;
    while(*A != NULL){
        temp = *A;
        *A = temp->link;
        free(temp);
    }
}

void insertEnd(List* A, int elem){
    List* trav, temp;
    temp = (List)malloc(sizeof(Node));
    for(trav = A; *trav != NULL; trav = &(*trav)->link){}
    temp->elem = elem;
    temp->link = *trav;
    *trav = temp;
}

void insertPos(List* A, int elem, int pos){
    List* trav, temp;
    temp = (List)malloc(sizeof(Node));
    int i;
    for(trav = A, i = 0; *trav != NULL && i != pos; trav = &(*trav)->link, i++){}
    if(i == pos){
        temp->elem = elem;
        temp->link = *trav;
        *trav = temp;
    }
}

void deleteElem(List* A, int elem){
    List* trav,temp;
    for(trav = A; *trav != NULL && (*trav)->elem != elem; trav = &(*trav)->link){}
    if(*trav != NULL){
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

void deletePos(List*A, int pos){
    List* trav,temp;
    int i;
    for(trav = A, i = 0; *trav != NULL && i != pos; trav = &(*trav)->link, i++){}
    if(i == pos){
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

void deleteAllOccur(List* A, int elem){
    List* trav,temp;
    for(trav = A; *trav != NULL;){
        if((*trav)->elem == elem){
            temp = *trav;
            *trav = temp->link;
            free(temp);
        }else{
            trav = &(*trav)->link;
        }
    }
}