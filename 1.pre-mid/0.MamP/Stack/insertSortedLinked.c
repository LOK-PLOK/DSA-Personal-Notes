#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char data;
    struct node* link;
}*Stack;

Stack initStack();
int isEmpty(Stack A);
void push(Stack* A, char elem);
void pop(Stack* A);
void pushWithoutMalloc(Stack* A, Stack B);
Stack popWithoutFree(Stack* A);
char top(Stack A);
int size(Stack* A);
void displayStack(Stack* A);
void insertSorted(Stack*A, char elem);



int main(){
    Stack S = initStack();
    displayStack(&S);

    printf("Checking push('A','B','C')\n");
    push(&S ,'A');
    push(&S ,'B');
    push(&S ,'C');
    displayStack(&S);

    printf("\nChecking isEmpty()\n");
    printf("isEmpty(): %d\n",isEmpty(S));

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
    
    return 0;
}

Stack initStack(){ 
    Stack temp;
    temp = NULL;
    return temp; 
}

int isEmpty(Stack A){
    return (A == NULL)? 1:0;
}

void push(Stack* A, char elem){
    Stack temp = (Stack)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = elem;
        temp->link = *A;
        *A = temp;
    }
}

void pop(Stack* A){
    Stack temp;
    if(!isEmpty(*A)){
        temp = *A;
        *A = temp->link;
        free(temp);
    }
}

// Need to do again because I did not fully understood it
void pushWithoutMalloc(Stack* A, Stack B){
    if(B != NULL){
        B->link = *A;
        *A = B;
    }
}
// Need to do again because I did not fully understood it
Stack popWithoutFree(Stack* A){
    Stack temp = *A;
    if(*A != NULL){
        *A = temp->link;
    }
    return temp;
}


char top(Stack A){
    return (A != NULL)? A->data:'#';
}


// Need to do again because I did not fully understood it
int size(Stack* A) {
    int size = 0;
    Stack temp = initStack();

    while (*A != NULL) {
        Stack B = popWithoutFree(A); 
        size++;
        pushWithoutMalloc(&temp, B); 
    }

    while (temp != NULL) {
        Stack B = popWithoutFree(&temp); 
        pushWithoutMalloc(A, B);         
    }

    return size;
}

// Need to do again because I did not fully understood it
void displayStack(Stack* A) {
    Stack temp = initStack();
    if (!isEmpty(*A)) {

        while (*A != NULL) {
            char data = top(*A);
            printf("%c ", data);
            Stack B = popWithoutFree(A); 
            pushWithoutMalloc(&temp, B); 
        }
        printf("\n");

        while (temp != NULL) {
            Stack B = popWithoutFree(&temp); 
            pushWithoutMalloc(A, B);        
        }
    } else {
        printf("Stack is empty.\n");
    }
}

void insertSorted(Stack*A, char elem);

