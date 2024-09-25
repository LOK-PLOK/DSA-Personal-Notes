#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 0XA

// return TRUE if ang Queue kay in asceding order based from ID
// isAscending(); functions accepts a list ang returns TRUE if ASCENDING and False if otherwise

typedef enum{TRUE, FALSE}Boolean;

typedef struct {
    char fName[24];
    char lName[16];
}Name;

typedef struct {
    unsigned int ID;
    Name name;
    // naapatoy uban pero ID importante
}Element;

typedef struct node{
    Element stud;
    struct node* link;
}*qptr;

typedef struct {
    qptr front;
    qptr rear;
    int count;
}Queue;

Boolean isAscending(Queue A){
    int i;
    qptr temp = A.front->link;
    for(i = 0; i<A.count && A.front != NULL && A.front->stud.ID < temp->stud.ID; i++, A.front = A.front->link, temp = temp->link){}

    return (A.front == A.rear)? TRUE:FALSE;
}

Boolean isAscendingV2(Queue A){
    unsigned int prevID = A.front->stud.ID;
    A.front = A.front->link;
    while(A.front != NULL){
        if(A.front->stud.ID < prevID){
            prevID = A.front->stud.ID;
            A.front = A.front->link;
        }
    }

    return (A.front == NULL)? TRUE: FALSE;
}

