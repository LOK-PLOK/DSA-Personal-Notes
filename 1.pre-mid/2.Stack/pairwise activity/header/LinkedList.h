#ifndef LINKEDLISTIMPLEMENT_H
#define LINKEDLISTIMPLEMENT_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct node{
    char elem;
    struct node* next;
}*Stack;

void initStack(Stack* A){
    (*A) = NULL;
}

int isEmpty(Stack A){
    return(A == NULL)? 1:0;
}


void push(Stack* A, char elem){
    Stack temp = (Stack)malloc(sizeof(struct node));
    if(temp != NULL){
       temp->elem = elem;
       temp->next = *A;
       *A = temp;
    }
}

void pop(Stack* A){
    if(!isEmpty(*A)){
        Stack temp = *A;
        *A = temp->next;
        free(temp);
    }else{
        printf("Stack is Empty\n");       
    }
}

int top(Stack A){
    return A->elem;
}

int isEmpty(Stack A){
    return(A == NULL)? 1:0;
}

void insertBottom(Stack* A, char elem) {
    Stack temp,trav;
    initStack(&temp);   

    char topElem;
    for(trav = *A; trav != NULL; trav = trav->next){
        topElem = top(trav);
        pop(A);
        push(&temp, topElem);
    }

    push(&temp,elem);

    for(trav = temp; trav != NULL; trav = trav->next){
        topElem = top(temp);
        pop(&temp);
        push(A, topElem);
    }
}

void display(Stack A){
    printf("\nStack: ");
    if(A != NULL){
        Stack trav;
        for(trav = A; trav != NULL; trav = trav->next){
            printf("%d ",trav->elem);
        }
    }else{
        printf("Empty\n");
    }
}
void clean(Stack* A){
    Stack temp;
    while(*A != NULL){
        temp = *A;
        *A = temp->next;
        free(temp);
    }
}


#endif