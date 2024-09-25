#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

//Implementing insertSorted with Stack Data structure

typedef struct {
    char data[MAX];
    int top;
}Stack;

Stack initStack();
int isEmpty(Stack A);
int isFull(Stack A);
void push(Stack* A, char elem); 
void pop(Stack* A);
char top(Stack A); // peek
int size(Stack* A);
void displayStack(Stack* A);
void insertSorted(Stack*A, char elem);


int main(){
    system("cls");
    Stack S = initStack();
    displayStack(&S);

    printf("Checking push('A','B','C')\n");
    push(&S ,'A');
    push(&S ,'B');
    push(&S ,'C');
    displayStack(&S);

    printf("\nChecking isEmpty()\n");
    printf("isEmpty(): %d\n",isEmpty(S));

    printf("\nChecking isFull()\n");
    printf("isFull(): %d\n",isFull(S));

    printf("\nChecking top()\n");
    printf("top(): %c\n",top(S));

    printf("\nChecking size()\n");
    printf("size(): %d\n",size(&S));

    printf("\nChecking pop() * 3\n");
    pop(&S);
    pop(&S);
    pop(&S);
    displayStack(&S);

    printf("\npushing('A','C','D')\n");
    push(&S ,'A');
    push(&S ,'C');
    push(&S ,'D');
    displayStack(&S);

    printf("\ncalling insertSorted('B')\n");
    insertSorted(&S, 'B');
    displayStack(&S);

    return 0;
}

Stack initStack(){
    Stack temp;
    temp.top = -1;
    return temp;
}

int isEmpty(Stack A){
    return(A.top == -1)? 1:0;
}

int isFull(Stack A){
    return(A.top == MAX-1)? 1:0;
}

void push(Stack* A, char elem){
    if(!isFull(*A)){
        A->data[++A->top] = elem;
    }
}

void pop(Stack* A){
    if(!isEmpty(*A)){
        A->top--;
    }
}

char top(Stack A) {
    return (A.top != -1) ? A.data[A.top] : '#'; 
}

/**
 * NOTE: Always remember to label your loops and what it does.
 */

int size(Stack* A){

    int size = 0;   
    Stack temp = initStack();

    while(A->top != -1){
        push(&temp, top(*A));
        pop(A);
        size += 1;
    }
    
    while(temp.top != -1){
        push(A, top(temp));
        pop(&temp);
    }

    return size;
}

/**
 * 
 * FUNCTION: displayStack()
 * 
 * DISCRIPTION: following the rules of STACK data structure, in displaying the given stack
 * one must create a temporary STACK variable
 * 
 * Pseudocode: 
 * Stack temp = initizalize stack function()
 *  firstLoop
 *  while STACK A top is not = empty
 *  data = STACK A top element
 *  print data
 *  push data to STACK temp
 *  pop STACK A
 * 
 *  
 *  SecondLoop
 *  while STACK temp is not = empty
 *  push data to STACK A
 *  pop STACK temp 
 */
void displayStack(Stack* A){
    printf("Stack S: ");
    if(isEmpty(*A)){
        printf("Empty\n");
    }

    Stack temp = initStack();

    while(A->top != -1){    
        char data = top(*A);
        printf("%c ",data);
        push(&temp, data);
        pop(A);
    }

    while(temp.top != -1){
        push(A,top(temp));
        pop(&temp);
    }

    printf("\n");
    
}

/**
 * 
 * FUNCTION: displayStack()
 * 
 * DISCRIPTION: following the rules of STACK data structure, in assumption that the stack is already sorted
 * the function must move the elements to the temporary stack and stop the moving when the given element is not less than the next element
 * then the temporary stack mush push to the original stack and pop the temp until empty
 * 
 */
void insertSorted(Stack*A, char elem){
    if(!isEmpty(*A)){
        Stack temp = initStack();

        // will pop STACK A until correct position
        while(A->top != -1 && A->data[A->top] > elem){
            push(&temp, top(*A));
            pop(A);
        }

        push(A, elem);

        // will pop temp until empty
        while(temp.top != -1){
            push(A, top(temp));
            pop(&temp);
        }
    }
}