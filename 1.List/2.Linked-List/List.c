#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}*List;

void initList(List* A);
void display(List A);
void clean(List* A);

//List Operations
void insertFirst(List* A, int elem);
void insertEnd(List* A, int elem);
void insertPos(List* A,int pos, int elem);
void deleteElem(List* A, int elem);
void deleteAtPos(List* A, int pos);
void deleteAllOccur(List* A, int elem);

int main(){
    List  L;
    initList(&L);

    system("cls");
    printf("insertFirst(1,2,3,4):\n");
    insertFirst(&L, 1);
    insertFirst(&L, 2);
    insertFirst(&L, 3);
    insertFirst(&L, 4);
    display(L);

    printf("\ninsertEnd(5):\n");
    insertEnd(&L,5);
    display(L);

    printf("\ninsertPos(pos:3, elem: 9):\n");
    insertPos(&L,3,9);
    display(L);

    printf("\ndeleteElem(9):\n");
    deleteElem(&L,9);
    display(L);

    printf("\ndeleteAtPos(0):\n");
    deleteAtPos(&L,0);
    display(L);

    clean(&L);

    printf("\nclean()\n");
    printf("\ninsertEnd(1,2,2,1,1,1,2,1,1,1):\n");
    insertEnd(&L,1);
    insertEnd(&L,2);
    insertEnd(&L,2);
    insertEnd(&L,1);
    insertEnd(&L,1);
    insertEnd(&L,1);
    insertEnd(&L,2);
    insertEnd(&L,1);
    insertEnd(&L,1);
    insertEnd(&L,1);
    display(L);

    printf("\ndeleteAllOccur(1):\n");
    deleteAllOccur(&L,1);
    display(L);

    clean(&L);
    return 0;
}

void initList(List* A){
    *A = NULL;
}

void insertFirst(List* A, int elem){
    List temp = (List)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = elem;
        temp->next = *A;
        *A = temp;
    }
}

void insertEnd(List* A, int elem){
    List* trav;
    for(trav = A; *trav != NULL; trav = &(*trav)->next){}
    if(*trav == NULL){
        List temp = (List)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->data = elem;
            temp->next = *trav;
            *trav = temp;
        }
    }
}

void insertPos(List* A,int pos, int elem){
    List temp = (List)malloc(sizeof(struct node));
    if(temp != NULL){
        List* trav;
        int i;
        for(trav = A, i=0; *trav != NULL && i != pos; trav = &(*trav)->next,i++){}
        if(i == pos){
            temp->data = elem;
            temp->next = *trav;
            *trav = temp;
        }
    }
}

void deleteElem(List* A, int elem){
    List* trav;
    for(trav = A; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->next){}
    if(*trav != NULL){
        List temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

void deleteAtPos(List* A, int pos){
    List* trav;
    int i;
    for(trav = A,i=0; *trav != NULL && i != pos; trav = &(*trav)->next, i++){}
    if(i == pos){
        List temp = *trav;
        *trav =temp->next;
        free(temp);
    }
}

void deleteAllOccur(List* A, int elem){
    List* trav;
    List temp;
    for(trav = A; *trav != NULL;){
        if((*trav)->data == elem){
            temp = *trav;
            *trav = temp->next;
            free(temp);
        }else{
            trav = &(*trav)->next;
        }
    }
}

void display(List A){
    printf("Linked List: ");
    if(A != NULL){
        List trav;
        for(trav = A; trav != NULL; trav = trav->next){
            printf("%d ",trav->data);
        }
        printf("\n");
    }else{
        printf("Empty\n");
    }

}

void clean(List* A){
    while(*A != NULL){
        List temp = *A;
        *A = temp->next;
        free(temp);
    }
}
