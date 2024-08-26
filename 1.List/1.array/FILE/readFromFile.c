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

FILE* checkFile();
void saveToFile(List A, FILE** fptr);
void displayList(List A);

List getList(FILE* fptr);

int main(){
    FILE* fptr = checkFile();
    List L = getList(fptr);

    saveToFile(L,&fptr);
    displayList(L);

}

List getList(FILE* fptr){
    List A;
    A.count = 0;
    Elements temp;

    rewind(fptr);
    while(fread(&temp,sizeof(Elements),1,fptr) != 0){
        if(A.count < MAX){
            A.stud[A.count++] = temp;
        }else{
            printf("LIST IS FULL");
        }
    }

    return A;
}

FILE* checkFile(){
    FILE* fptr;

    if((fptr = fopen("AdtList.dat","rb+")) == NULL){
        fptr = fopen("AdtList.dat","wb+");
    }else{
        fclose(fptr);
        fptr = fopen("AdtList.dat","rb+");
    }

    return fptr;
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