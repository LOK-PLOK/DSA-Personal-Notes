#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    char fName[24];
    char MI;
    char lName[16];
    char fullName[40];
}Name;

typedef struct{
    Name name;
    int id;
    char course[8];
    int year;
}Elements;

typedef struct nodetype{
    Elements* stud;
    int count;
    int arrSize;
}List;

void initList(List* A);
void clean(List* A);
void insertEnd(List* A,Elements elem);
void insertFirst(List* A,Elements elem);
void displayList(List A);

int main(){
    List L;
    initList(&L);

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
    displayList(L);


    clean(&L);
    return 0;
}

void initList(List* A){
    A->arrSize = MAX;
    A->stud = (Elements*)malloc(sizeof(Elements)*A->arrSize);
    if(A->stud != NULL){
        A->count = 0;
    }else{
        printf("ERROR: Memory allocation failed");
        exit(1);
    }
}

void insertEnd(List* A,Elements elem){
    if(A->count < A->arrSize){
        A->stud[A->count++] = elem;
    }else{
        printf("Max capacity reached: %d/%d\n",A->count,A->arrSize);
    }
}
void insertFirst(List* A,Elements elem);

void displayList(List A){
    int i;
    if(A.count != 0){
        for(i = 0; i<A.count; i++){
            snprintf(A.stud[i].name.fullName,sizeof(A.stud[i].name.fullName),"%s %c. %s",
                    A.stud[i].name.fName,A.stud[i].name.MI,A.stud[i].name.lName);

            printf("Student %d:\n",i+1);
            printf("  Name   : %s\n",A.stud[i].name.fullName);
            printf("  ID     : %d\n",A.stud[i].id);
            printf("  Course : %s\n",A.stud[i].course);
            printf("  Year   : %d\n",A.stud[i].year);
            printf("\n");
        } 
    }else{
        printf("The List is empty.\n");
    }
}

void clean(List* A){
    free(A->stud);
    A->stud = NULL;
    A->count = 0;
    A->arrSize = 0;
}