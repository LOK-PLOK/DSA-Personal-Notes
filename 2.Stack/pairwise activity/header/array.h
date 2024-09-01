#ifndef ARRAYIMPLEMENT_H
#define ARRAYIMPLEMENT_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int data[MAX];
    int top;
}Stack;

void init(Stack* A){
    A->top = MAX;
}

void push(Stack* A, int elem){
    if(A->top != 0){
        A->data[--A->top] = elem;
    }else{
        printf("Stack is Full\n");
    }
}

void pop(Stack* A){
    if(A->top != MAX){
        A->top++;
    }else{
        printf("Stack is Empty\n");        
    }
}


int top(Stack A){
    return (A.top != MAX)? A.data[A.top]:-1; 
}

void display(Stack A){
    printf("\nStack: ");
    if(A.top != MAX){
        int i;
        for(i=A.top; i<MAX; i++){
            printf("%d ",A.data[i]);
        }
    }else{
        printf("Empty\n");
    }
}




#endif