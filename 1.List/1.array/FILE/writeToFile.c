#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//Version 1 and FILE implementation

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


void saveToFile(List A, FILE** fptr);
void displayList(List A);

int main(){

    Elements examp6 = {{"Paul France",'M',"Detablan"},23100209,"BSCS",2};
    Elements examp3 = {{"Luis Andrei",'E',"Ouano"},23100371,"BSCS",2};
    Elements examp2 = {{"Carlos Miguel",'K',"Jakosalem"},23100571,"BSCS",2};
    Elements examp5 = {{"Kenji",'D',"Tundag"},23100244,"BSIT",2};
    Elements examp4 = {{"Paul Winston",'T',"Ancajas"},23102628,"BSIS",2};
    Elements examp1 = {{"Katsu",'A',"Ito"},20104115,"BSIS",2};
    List L = {{examp1,examp2,examp3,examp4,examp5,examp6},6};
    FILE* fptr = fopen("AdtList.dat","rb+");

    saveToFile(L,&fptr);
    displayList(L);

}

void saveToFile(List A, FILE** fptr){
    FILE* newFile = fopen("temp.dat","wb+");
    int i;
    for(i=0;i<A.count; i++){
        fwrite(&A.stud[i],sizeof(Elements),1,newFile);
    }

    fclose(newFile);
    fclose(*fptr);

    remove("AdtList.dat");
    rename("temp.dat","AdtList.dat");
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