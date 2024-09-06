#ifndef Student_definition_H
#define Student_definition_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// typedef Student Data;
// typedef struct node{
//     Data elem;
//     struct node* link;
// }Nodetype,*NodePtr;

// typedef struct{
//     NodePtr head;
//     NodePtr tail;
// }Queue;
