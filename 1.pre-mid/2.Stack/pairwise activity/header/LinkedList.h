#ifndef LINKEDLISTIMPLEMENT_H
#define LINKEDLISTIMPLEMENT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char elem;
    struct node* next;
}*Stack;


void initStack(Stack* A) {
    *A = NULL;
}


int isEmpty(Stack A) {
    return (A == NULL)? 1:0;
}


void push(Stack* A, char elem) {
    Stack temp = (Stack)malloc(sizeof(struct node));
    if (temp != NULL) {
        temp->elem = elem;
        temp->next = *A;
        *A = temp;
    }
}

void pop(Stack* A) {
    if (!isEmpty(*A)) {
        Stack temp = *A;
        *A = (*A)->next;
        free(temp);
    } else {
        printf("Stack is Empty\n");
    }
}


char top(Stack A) {
    return A->elem;
}

void insertBottom(Stack* A, char elem) {
    Stack temp = NULL;

    while (!isEmpty(*A)) {
        push(&temp, top(*A));
        pop(A);
    }
    push(A, elem);

    while (!isEmpty(temp)) {
        push(A, top(temp));
        pop(&temp);
    }
}

void display(Stack A) {
    Stack temp = NULL;
    printf("Stack: ");
    if (!isEmpty(A)) {
        while (!isEmpty(A)) {
            printf("%c ",top(A));
            push(&temp, top(A));
            pop(&A);
        }
        
        while (!isEmpty(temp)) {
            push(&A, top(temp));
            pop(&temp);
        }
        printf("\n");
    } else {
        printf("Empty\n");
    }
}

void clean(Stack* A) {
    Stack temp;
    while (*A != NULL) {
        temp = *A;
        *A = (*A)->next;
        free(temp);
    }
}

#endif
