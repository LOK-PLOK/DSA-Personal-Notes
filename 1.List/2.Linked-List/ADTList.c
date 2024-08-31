#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char fName[24];
    char MI;
    char lName[16];
    char fullName[40];
}Name;

typedef struct {
    Name name;
    int id;
    char course[8];
    int year;
}Elements;

typedef struct node{
    Elements stud;
    struct node* next;
}*List;

void initList(List* A);
void display(List A);
void insertEnd(List* A,Elements elem);
void insertFirst(List* A,Elements elem);
void clean(List* A);
void insertPos(List* A,Elements elem, int pos);
void deleteStud(List* A, int ID);
void deleteAtPos(List* A, int pos);
void deleteAllOccur(List* A,const char course[]);

int main(){
    List L;
    initList(&L);

    system("cls");
    Elements examp6 = {{"Paul France",'M',"Detablan"},23100209,"BSCS",2};
    Elements examp3 = {{"Luis Andrei",'E',"Ouano"},23100371,"BSCS",2};
    Elements examp2 = {{"Carlos Miguel",'K',"Jakosalem"},23100571,"BSCS",2};
    Elements examp5 = {{"Kenji",'D',"Tundag"},23100244,"BSIT",2};
    Elements examp4 = {{"Paul Winston",'T',"Ancajas"},23102628,"BSIS",2};
    Elements examp1 = {{"Katsu",'A',"Ito"},20104115,"BSIS",2};

    insertEnd(&L,examp1);
    insertEnd(&L,examp2);
    insertEnd(&L,examp3);
    insertEnd(&L,examp4);
    insertFirst(&L,examp5);
    insertPos(&L,examp6,2);
    display(L);

    printf("\n\n=====================================================\n\n");
    deleteStud(&L, 23100244);
    deleteAtPos(&L, 2);
    display(L);

    printf("\n\n=====================================================\n\n");
    deleteAllOccur(&L,"BSCS");
    display(L);

    clean(&L);
    return 0;
}

void initList(List* A){
    *A = NULL;
}

void insertEnd(List* A,Elements elem){
    List temp = (List)malloc(sizeof(struct node));
    if(temp != NULL){
        List* trav;
        for(trav = A; *trav != NULL; trav = &(*trav)->next){}
        if(*trav == NULL){
            temp->stud = elem;
            temp->next = *trav;
            *trav = temp;
        }
    }
}

void insertFirst(List* A,Elements elem){
    List temp = (List)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->stud = elem;
        temp->next = *A;
        *A = temp;
    }
}

void insertPos(List* A,Elements elem, int pos){
    List temp = (List)malloc(sizeof(struct node));
    List* trav;
    int i;
    if(temp != NULL){
        for(trav = A,i=0; *trav != NULL && i != pos; trav = &(*trav)->next, i++){}
        if(i==pos){
            temp->stud = elem;
            temp->next = *trav;
            *trav = temp;
        }
    }
}

void deleteStud(List* A, int ID){
    List * trav;
    List temp;
    for(trav = A; *trav != NULL && (*trav)->stud.id != ID; trav = &(*trav)->next){}
    if(*trav != NULL){
        temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

void deleteAtPos(List* A, int pos){
    List* trav;
    List temp;
    int i;
    for(trav = A,i=0; *trav != NULL && i!=pos; trav = &(*trav)->next, i++){}
    if(i==pos){
        temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

void deleteAllOccur(List* A,const char course[]){
    List* trav;
    List temp;
    for(trav = A; *trav != NULL;){
        if(strcmp((*trav)->stud.course,course) == 0){
            temp = *trav;
            *trav = temp->next;
            free(temp);
        }else{
            trav = &(*trav)->next;
        }
    }
}

void display(List A){
    List trav;
    int i = 0;
    if (A != NULL) {
        for (trav = A; trav != NULL; trav = trav->next) {
            // Construct the full name
            snprintf(trav->stud.name.fullName, sizeof(trav->stud.name.fullName), "%s %c. %s",
                    trav->stud.name.fName, trav->stud.name.MI, trav->stud.name.lName);

            // Display the student details
            printf("Student %d:\n", i + 1);
            printf("  Name   : %s\n", trav->stud.name.fullName);
            printf("  ID     : %d\n", trav->stud.id);
            printf("  Course : %s\n", trav->stud.course);
            printf("  Year   : %d\n", trav->stud.year);
            printf("\n");
            i++;
        }
    }else{
        printf("The list is empty.\n");
    }
}

void clean(List* A){
    List temp;
    while(*A != NULL){
        temp = *A;
        *A = temp->next;
        free(temp);
    }
}