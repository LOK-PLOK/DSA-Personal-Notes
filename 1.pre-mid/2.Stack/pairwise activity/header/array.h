#ifndef ARRAYIMPLEMENT_H
#define ARRAYIMPLEMENT_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    char elem[MAX];
    int top;
}Stack;

void initStack(Stack* A){
    A->top = MAX;
}

int isEmpty(Stack A){
    return(A.top == MAX)? 1:0;
}

int isFull(Stack A){
    return (A.top == 0)? 1:0;
}
void push(Stack* A, char elem){
    if(!isFull(*A)){
        A->elem[--A->top] = elem;
    }else{
        printf("Stack is Full\n");
    }
}

void pop(Stack* A){
    if(!isEmpty(*A)){
        A->top++;
    }else{
        printf("Stack is Empty\n");        
    }
}


int top(Stack A){
    return (A.top != MAX)? A.elem[A.top]:-1; 
}


void insertBottom(Stack* A, char elem) {
    Stack temp;
    initStack(&temp);  

    char topElem;
    while(A->top != MAX){
        topElem = top(*A);
        pop(A);
        push(&temp, topElem);
    }

    push(&temp, elem);

    while(temp.top != MAX){
        topElem = top(temp);
        pop(&temp);
        push(A, topElem);
    }
}

void display(Stack A){
    Stack temp;
    printf("Stack: ");
    if(A.top != MAX){
        for(temp = A; temp.top != MAX;){
            printf("%c ",temp.elem[temp.top]);
            pop(&temp); 
        }
        printf("\n");
    }else{
        printf("Empty\n");
    }
}

void clean(Stack* A){
    while(A->top != MAX){
        pop(A);
    }
}




#endif