#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5

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
void insertPos(List* A,Elements elem,int pos);
void deleteStud(List* A,int ID);
void deletePos(List* A,int pos);
void deleteAllOccur(List* A,const char course[]);
void displayList(List A);

// Other operations that Im to lazy to do yet
// InsertSorted()
// InsertUniqueElem()
// bubbleSort()
// selectionSort()
// insertionSort()

// NOTE: There are many redundancy in this code that can be simplified but im lazy haha

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

    printf("\n\n=====================================================\n\n");
    deleteStud(&L,23100244);
    deletePos(&L,2);
    displayList(L);

    printf("\n\n=====================================================\n\n");
    deleteAllOccur(&L,"BSCS");
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
    if(A->count >= A->arrSize){
        A->arrSize *= 2;
        A->stud = (Elements*)realloc(A->stud,sizeof(Elements)*A->arrSize);
        if(A->stud == NULL){
            printf("ERROR: Memory allocation failed\n");
            exit(1);
        }
    }

    A->stud[A->count++] = elem;
}
void insertFirst(List* A,Elements elem){
    if(A->count >= A->arrSize){
        A->arrSize *= 2;
        A->stud = (Elements*)realloc(A->stud,sizeof(Elements)*A->arrSize);
        if(A->stud == NULL){
            printf("ERROR: Memory allocation failed\n");
            exit(1);
        }
        
    }

    int i;
    for(i = A->count; i>0;i--){
        A->stud[i] = A->stud[i-1];
    }
    A->stud[0] = elem;
    A->count++;
}

void insertPos(List* A,Elements elem,int pos){
    if(pos <= A->count && pos >= 0){
        if(A->count >= A->arrSize){
            A->arrSize *= 2;
            A->stud =  (Elements*)realloc(A->stud,sizeof(Elements)*A->arrSize);
            if(A->stud == NULL){
                printf("ERROR: Memory allocation failed\n");
                exit(1);
            }
        }

        int i;
        for(i=A->count;i>pos;i--){
            A->stud[i] = A->stud[i-1]; 
        }
        A->stud[pos] = elem;
        A->count++;
    }else{
        printf("ERROR: Invalid position\n");
    }
}

void deleteStud(List* A,int ID){
    int i,j;
    for(i=0;i<A->count && A->stud[i].id != ID;i++){}
    if(i != A->count){
        for(j = i+1; j<A->count; j++){
            A->stud[j-1] = A->stud[j];
        }
        A->count--;
    }else{
        printf("\n\nStudent not in List\n\n");
    }
}

void deletePos(List* A,int pos){
    if(pos <= A->count && pos >= 0 && A->count != 0){
        int i;
        for(i=pos+1;i<A->count;i++){
            A->stud[i-1] = A->stud[i];
        }
        A->count--;
    }else{
        printf("\n\nStudent not in List\n\n");
    }
}

void deleteAllOccur(List* A,const char course[]){
    if(A->count != 0){
        int i,j;
        for(i=0; i<A->count;){
            if(strcmp(A->stud[i].course,course) == 0){
                for(j=i+1; j<A->count;j++){
                    A->stud[j-1] = A->stud[j];
                }
                A->count--;
            }else{
                i++;
            }
        }
    }else{
        printf("The List is empty.\n");
    }
}

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