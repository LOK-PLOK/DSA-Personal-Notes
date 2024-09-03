#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int Elem[5];
    int top;
}Stack;


void intializeStack(Stack* A);
void push(Stack* A, int elem);
void pop(Stack* A);
int top(Stack A);
int isEmpty(Stack A);
int isFull(Stack A);
void display(Stack A);

int main(){
    Stack S;
    
    system("cls");
    
    intializeStack(&S);
    display(S);

    push(&S, 1);
    display(S);

    push(&S, 2);
    push(&S, 3);
    display(S);


    int topElem = top(S);
    printf("\nTop: %d\n", topElem);

    pop(&S);
    display(S);


    return 0;
}

void intializeStack(Stack* A){
    A->top = MAX;
}

void push(Stack* A, int elem){
    if(isFull(*A)){
        A->Elem[-- A->top] = elem;
    }else{
        printf("Stack is Full\n");
    }
}

void pop(Stack* A){
    if(isEmpty(*A)){
        A->top++;
    }else{
        printf("Stack is empty\n");
    }
}

int top(Stack A){
    return A.Elem[A.top];
}

int isEmpty(Stack A){
    return (A.top != MAX)? 1:0;
}

int isFull(Stack A){
    return (A.top != 0)? 1:0;
}

void display(Stack A){
    printf("\nStack: ");
    int i;
    if(!isEmpty(A)){
        printf("Empty\n");
    }
    for(i=A.top;i<MAX;i++){
        printf("%d ",A.Elem[i]);
    }
}
