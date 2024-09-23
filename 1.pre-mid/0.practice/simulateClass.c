#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define flush fflush(stdin) 
#define SIZE 10

/**
 * Todo: Create a C program that simulates what happens in a Classroom
 * 
 * functions:
 * 
 * initClassRoom();
 * addTeacer();
 * addStudents();
 * 
 * 
 * 
 */

typedef enum{Male,Female} Gender;
typedef enum{Absent, Late, Present, Pending} Status;
typedef enum{TEACHER,STUDENT,EXIT} Option;
typedef enum{CREATE,READ,UPDATE,DELETE,EXIT}CRUD;

typedef struct{
    char fName[24];
    char lName[16];
}Name;

typedef struct {
    Name name;
    int age;
    float hight;
    float weight;
    char address[30];
    Gender gender;
    char phoneNumber[15];
}Person;

typedef struct{
    Person stud;
    int id;
    char gmail[30];
    char school[25];
}Data;

typedef struct {
    Data stud;
    Status status;
}Student;

typedef struct{
    Data teach;
    char course[20];
}Teacher;

typedef struct{
    Teacher teach;
    Student students[20];
    int seat[SIZE];
    int teachSeat;
    int count;
}Classroom;

Classroom initClassroom(){
    Classroom temp;
    temp.count = 0;
    temp.teachSeat = 0;
    return temp;
}

Option landingScreen(){
    char type;
    Option option;
    printf("Welcome to room 486, are you a: \n");
    printf("Teacher or Student \n");
    printf("Enter(T or S): ");
    scanf(" %c",&type);
    flush;

    type = tolower(type);
    switch(type){
        case 't': option = TEACHER; break;
        case 's': option = STUDENT; break;
        default: option = EXIT; break;
    }

    return option;
}

int main(){
    Classroom room486 = initClassroom();
    Option option = landingScreen();

    while(option != EXIT){
        
    }
    
}

