#ifndef Student_definition_H
#define Student_definition_H


typedef struct{
    char fname[20];
    char lname[20];
}Name;

typedef struct{
    int studID;
    Name studName;
    char sex; // F - emale  && M - ale
    char program[6];
}Student;


#endif