
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}*Stack;

void init(Stack* A);
void push(Stack* A, int elem);
void pop(Stack* A);
int top(Stack A);
void display(Stack A);

int main(){
    Stack S;
    
    system("cls");
    
    init(&S);
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

