#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
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

typedef struct{
    Elements stud[MAX];
    int count;
}List;

void initList(List* A);
void insertEnd(List* A, Elements elem);
void insertFirst(List* A, Elements elem);
void insertPos(List* A, Elements elem, int pos);
void deleteStud(List* A,int ID);
void deleteAtPos(List* A, int pos);
void displayList(List A);
void deleteAllOccur(List* A,const char course[]);

// Other operations that Im to lazy to do yet
// InsertSorted()
// InsertUniqueElem()
// bubbleSort()
// selectionSort()
// insertionSort()

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
    insertPos(&L,examp6,2);
    displayList(L);

    deleteStud(&L, 23100244);
    deleteAtPos(&L, 2);
    displayList(L);

    deleteAllOccur(&L,"BSCS");
    displayList(L);

    return 0;
}

void initList(List* A){
    A->count = 0;
}

void insertEnd(List* A,Elements elem){
    if(A->count < MAX){
        A->stud[A->count++] = elem;
    }else{
        printf("Max capacity reached: %d/%d\n",A->count,MAX);
    }
}

void insertFirst(List* A,Elements elem){
    if(A->count < MAX){
        int x;
        for(x = A->count; x>0; x--){
            A->stud[x] = A->stud[x-1];
        }
        A->stud[0] = elem;
        A->count++;
    }else{
        printf("Max capacity reached: %d/%d\n",A->count,MAX);
    }
}

void insertPos(List* A, Elements elem, int pos){
    if(A->count < MAX && pos <= A->count && pos >= 0){
        int x;
        for(x = A->count; x > pos; x--){
            A->stud[x] = A->stud[x - 1];
        }
        A->stud[pos] = elem;
        A->count++;
    }else{
        printf("\n\nERROR: Invalid position or list is full.\n\n");
    }
}

void deleteStud(List* A,int ID){
    int x,j;
    for(x = 0; x < A->count && A->stud[x].id != ID ; x++){}
    if(x != A->count){
        for(j = x+1; j<A->count;j++){
            A->stud[j -1] = A->stud[j];
        }
        A->count--;
    }else{
        printf("\n\nStudent not in List\n\n");
    }
}

void deleteAtPos(List* A, int pos){
    if(pos < A->count && pos >= 0){
        int x;
        for(x= pos+1;x<A->count;x++){
            A->stud[x-1] = A->stud[x];
        }
        A->count--;
    }else{
        printf("\n\nStudent not in List\n\n");
    }
}

void deleteAllOccur(List* A,const char course[]){
    int x,j;
    for(x = 0; x<A->count;){
        if(strcmp(A->stud[x].course,course) == 0){
            for(j=x+1; j<A->count;j++){
                A->stud[j-1] = A->stud[j];
            }
            A->count--;
        }else{
            x++;
        }
    }
}

void displayList(List A){
     int i;
    if (A.count != 0) {
        for (i = 0; i < A.count; i++) {
            // Construct the full name
            snprintf(A.stud[i].name.fullName, sizeof(A.stud[i].name.fullName), "%s %c. %s",
                    A.stud[i].name.fName, A.stud[i].name.MI, A.stud[i].name.lName);

            // Display the student details
            printf("Student %d:\n", i + 1);
            printf("  Name   : %s\n", A.stud[i].name.fullName);
            printf("  ID     : %d\n", A.stud[i].id);
            printf("  Course : %s\n", A.stud[i].course);
            printf("  Year   : %d\n", A.stud[i].year);
            printf("\n");
        }
    }else{
        printf("The list is empty.\n");
    }
}