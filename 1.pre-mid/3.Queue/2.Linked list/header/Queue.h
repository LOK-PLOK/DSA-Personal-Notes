#ifndef QueueType_H
#define QueueType_H

#include "./Mydata.h"

typedef Student Data;
typedef struct node{
    Data elem;
    struct node* link;
}Nodetype,*NodePtr;

typedef struct{
    NodePtr head;
    NodePtr tail;
}Queue;


void initQueue(Queue* A){
    A->head = NULL;
    A->tail = NULL;
}

bool isEmpty(Queue A){
    return(A.head == NULL)? 1:0;
}

void displayData(Data elem){
    printf("  Name   : %s, %s\n", elem.studName.lname,elem.studName.fname);
    printf("  ID     : %d\n", elem.studID);
    printf("  Course : %s\n", elem.program);
    printf("  Sex    : %c\n", elem.sex);
}

void display(Queue A){
    printf("Queue: ");
    if (!isEmpty(A)){
        int i = 0;
        NodePtr trav;
        for(trav = A.head; trav != NULL; trav = trav->link, i++){
            printf("\n");
            printf("Student %d:\n", i + 1);
            displayData(trav->elem);
            printf("\n");
        }
    }else{
        printf("Empty\n");
    }
}

bool enqueue(Queue* A, Data elem){
    bool status  = 0;
    NodePtr temp = (NodePtr)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->elem = elem;
        temp->link = NULL;
        if(isEmpty(*A)){
            A->head = temp;
        }else{
            A->tail->link = temp;
        }
        A->tail = temp;
        status = 1;
    }
    return status;
}

bool dequeue(Queue* A){
    bool status = 0;
    NodePtr temp;
    if(!isEmpty(*A)){
        temp = A->head;
        A->head = temp->link;
        if(A->head == NULL){
            A->tail = NULL;
        }
        free(temp);
    }
}

Data front(Queue A){
    Data dummy = {00000000,{"XXXX","XXXX"},'X',"XXXX"};
    return(!isEmpty(A))? A.head->elem: dummy;
}

void makeNull(Queue* A){
    NodePtr temp;
    while(A->head != NULL){
        temp = A->head;
        A->head = temp->link;
        free(temp);
    }
}
#endif