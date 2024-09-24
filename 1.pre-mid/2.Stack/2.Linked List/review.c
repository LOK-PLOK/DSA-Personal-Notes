#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    char elem;
    struct node* link;
}*Stack, StackNode;

Stack initStack();
char topElem(Stack A);
bool isEmpty(Stack A);
void displayStack(Stack* A);
void displayStackV2(Stack* A);

void Push(Stack* A,int elem);
void Pop(Stack* A);

int main(){
    system("cls");
    Stack S = initStack();


    printf("\ninitStack()\n");
    printf("Stack S: ");
    displayStack(&S);

    printf("\nPush(A,B,C,D,E)\n");
    printf("Stack S: ");
    Push(&S,'A');
    Push(&S,'B');
    Push(&S,'C');
    Push(&S,'D');
    Push(&S,'E');
    displayStack(&S);

    printf("\nTop element: %c\n",topElem(S));

    printf("\nPop() 2 times\n");
    Pop(&S);
    Pop(&S);
    displayStackV2(&S);
    
    return 0;
}

Stack initStack(){
    return NULL;
}

char topElem(Stack A){
    return(!isEmpty(A))? A->elem:'-';
}

bool isEmpty(Stack A){
    return (A == NULL)? 1:0;
}

void Push(Stack* A, int elem){
    Stack temp = (Stack)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->elem = elem ;
        temp->link = *A;
        *A = temp;
    }
}
void Pop(Stack* A){
    if(!isEmpty(*A)){
        Stack temp = *A;
        *A = temp->link;
        free(temp);
    }
}

void displayStack(Stack* A){
    if(!isEmpty(*A)){
          Stack temp = initStack();
        while(*A != NULL){
            printf("%c ",(*A)->elem);
            Push(&temp,(*A)->elem);
            Pop(A);
        }
        
        while(temp != NULL){
            Push(A,temp->elem);
            Pop(&temp);
        } 
        printf("\n");
    }else{
        printf("Empty\n");
    }
    
}

void displayStackV2(Stack* A){
    Stack top = *A;
    while(!isEmpty(*A)){
        printf("%c ", (*A)->elem);
        *A = (*A)->link;
    }
    *A = top;
}

/**
 * IMPORTANT: This might be wrong but will be made into considerations 
 * 
 * displayStackV2 might look like you are travering in a list but in all actuallity the word "traverse" is when 
 * you have a variable that is looping through a LIST
 * 
 * with following the STACK data structure we are actually traversing via the TOP pointer until LIST/STACK is empty, 
 * 
 * same as traversing but not using a variable to traverse
 * 
 * NOTE: must USE and ACCESS via the HEAD or TOP pointer
 * 
 * you can do insertSorted, insertAtPos, deleteElem, but it must be only using the TOP/HEAD pointer
 * you must also have a pointer to the top of the stack
 * Linked List implementation should be something like (Stack top = *A;) we are saving the address or the location of the top node
 * 
 * after execution of display or insertSorted,
 * *A must be re assigned to top element, which is *A = top;
 */