#ifndef LINKEDLISTIMPLEMENT_H
#define LINKEDLISTIMPLEMENT_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct node{
    int data;
    struct node* next;
}*Stack;

void init(Stack* A){
    (*A) = NULL;
}

void push(Stack* A, int elem){
    Stack temp = (Stack)malloc(sizeof(struct node));
    if(temp != NULL){
       temp->data = elem;
       temp->next = *A;
       *A = temp;
    }
}

void pop(Stack* A){
    if(*A != NULL){
        Stack temp = *A;
        *A = temp->next;
        free(temp);
    }else{
        printf("Stack is Empty\n");       
    }
}

int top(Stack A){
    return A->data;
}

void display(Stack A){
    printf("\nStack: ");
    if(A != NULL){
        Stack trav;
        for(trav = A; trav != NULL; trav = trav->next){
            printf("%d ",trav->data);
        }
    }else{
        printf("Empty\n");
    }
}



#endif