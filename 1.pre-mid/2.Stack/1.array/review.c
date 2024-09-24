/**
 * Stack operations
 * Push() insert an element at the top of the stack
 * Pop() delete an elemen at the top of the stack
 * Top() return the top element of the stack // different for ADT 
 * Size() return the size of the stack
 * isEmpty() returns 1 if true and 0 if not
 * isFull() returns 1 if true and 0 if not
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    char elem[MAX];
    int top;
}Stack;

Stack initStack();
void displayStack(Stack A);
void displayStackV2(Stack* A);
char topElem(Stack A);
bool isEmpty(Stack A);
bool isFull(Stack A);

void Push(Stack* A, char elem);
void Pop(Stack* A);

int main(){
    system("cls");
    Stack S = initStack();


    printf("\ninitStack()\n");
    printf("Stack S: ");
    displayStack(S);

    printf("\nPush(A,B,C,D,E)\n");
    printf("Stack S: ");
    Push(&S,'A');
    Push(&S,'B');
    Push(&S,'C');
    Push(&S,'D');
    Push(&S,'E');
    displayStack(S);

    printf("\nTop element: %c\n",topElem(S));

    printf("\nPop() 2 times\n");
    Pop(&S);
    Pop(&S);
    displayStackV2(&S);
}

Stack initStack(){
    Stack temp;
    temp.top = -1;
    return temp;
}

void Push(Stack* A, char elem){
    if(isFull(*A) != 1){
        A->elem[++A->top] = elem;
    } 
}

void Pop(Stack* A){
    if(isEmpty(*A) != 1){
        A->top--;
    }
}

char topElem(Stack A){
    return (A.top != -1)? A.elem[A.top]: '-';
}

bool isEmpty(Stack A){
    return (A.top == -1)? 1:0;
}
bool isFull(Stack A){
    return (A.top == MAX -1)? 1:0;
}

void displayStack(Stack A){
    if(!isEmpty(A)){
        Stack temp = initStack();

        while(A.top != -1){
            printf("%c ",A.elem[A.top]);
            Push(&temp, A.elem[A.top]);
            Pop(&A);
        }

        while(temp.top != -1){
            Push(&A, temp.elem[temp.top]);
            Pop(&temp);
        }

        printf("\n");
    }else{
        printf("Empty\n");
    }
    
}

void displayStackV2(Stack* A){
    int top = A->top;
    while(!isEmpty(*A)){
        printf("%c ",A->elem[A->top]);
        A->top -= 1;
    }
    A->top = top;
}

/**
 *IMPORTANT: This might be wrong but will be made into considerations 
 *
 * displayStackV2 might look like you are travering in a list but in all actuallity the word "traverse" is when 
 * you have a variable that is looping through a LIST
 * 
 * with following the STACK data structure we are actually traversing via the TOP pointer until LIST/STACK is empty, 
 * 
 * same as traversing but not using a variable to traverse
 * 
 * NOTE: must USE and ACCESS via the HEAD or TOP pointer
 */