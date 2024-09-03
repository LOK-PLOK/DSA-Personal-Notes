#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int data;
    int next;
}Cell;

typedef struct {
    Cell Nodes[MAX];
    int avail;
}VirtualHeap;

typedef int Stack;

//cursor-based preparations;
void initStack(Stack* S,VirtualHeap* vh);
int allocSpace(VirtualHeap* vh);
void deallocSpace(VirtualHeap* vh, int index);

//Stack operations
void push(Stack*S, VirtualHeap* vh, int elem);
int isEmpty(Stack S);
int top(Stack S, VirtualHeap vh);
void display(Stack S,VirtualHeap vh);
void pop(Stack* S,VirtualHeap* vh);

int main(){
    Stack S;
    VirtualHeap vh;
    
    system("cls");
    printf("init and display:");
    initStack(&S,&vh);
    display(S,vh);

    printf("\npush(1,2,3):");
    push(&S,&vh, 1);
    push(&S,&vh, 2);
    push(&S,&vh, 3);
    display(S,vh);

    printf("\ntop(): \n");
    int topElem = top(S,vh);
    printf("Top: %d\n",topElem);

    printf("\npop():");
    pop(&S,&vh);
    display(S,vh);
    
    return 0;
}

int isEmpty(Stack S){
    return (S != -1)? 0:1;
}

int top(Stack S, VirtualHeap vh){
    return (S != -1)? vh.Nodes[S].data:-1;
}

void push(Stack*S, VirtualHeap* vh, int elem){
    Stack temp = allocSpace(vh);
    if(temp != -1){
        vh->Nodes[temp].data = elem;
        vh->Nodes[temp].next = *S;
        *S = temp;
    }
}

void pop(Stack* S,VirtualHeap* vh){
    if(!isEmpty(*S)){
        Stack temp = *S;
        *S = vh->Nodes[temp].next;
        deallocSpace(vh,temp);
    }
}

void display(Stack S,VirtualHeap vh){
    printf("\nCB Stack: ");
    if(!isEmpty(S)){
        Stack i;
        for(i = S; i != -1; i= vh.Nodes[i].next){
            printf("%d ",vh.Nodes[i].data);
        }
        printf("\n");
    }else{
        printf("Empty\n");
    }
}

void initStack(Stack* S,VirtualHeap* vh){
    *S = -1;

    int i;
    for(i = MAX-1; i>=0; i--){
        vh->Nodes[i].next = i-1;
    }
    vh->avail = MAX-1;
}

int allocSpace(VirtualHeap* vh){
    int index = vh->avail;
    if(index != -1){
        vh->avail = vh->Nodes[index].next;
    }
    return index;
}

void deallocSpace(VirtualHeap* vh, int index){
    if(index >= 0 && index < MAX){
        vh->Nodes[index].next = vh->avail;
        vh->avail = index;
    }
}
