#include <stdio.h>
#include <stdbool.h>
#define MAX 30

typedef int Stack;

typedef struct {
    char elem;
    int link;
}Cell;

typedef struct {
    Cell Node[MAX];
    int avail;
}Heap;

void initHeap(Heap* VH);
int getSpace(Heap* VH);
void freeSpace(Heap* VH, int index);
void displayStack(Heap* VH, Stack* A);

Stack initStack();
char topElem(Heap VH,Stack A);
bool isEmpty(Stack A);
void Push(Heap* VH, Stack* A, char elem);
void Pop(Heap* VH,Stack* A);

int main(){
    Stack S = initStack();
    Heap VH;

    initHeap(&VH);
    
    printf("\ninitStack()\n");
    printf("Stack S: ");
    displayStack(&VH,&S);

    printf("\nPush(A,B,C,D,E)\n");
    printf("Stack S: ");
    Push(&VH,&S,'A');
    Push(&VH,&S,'B');
    Push(&VH,&S,'C');
    Push(&VH,&S,'D');
    Push(&VH,&S,'E');
    displayStack(&VH,&S);

    printf("\nTop element: %c\n",topElem(VH,S));

    printf("\nPop() 2 times\n");
    Pop(&VH,&S);
    Pop(&VH,&S);
    displayStack(&VH,&S);
    
    return 0;

}

Stack initStack(){
    return -1;
}

char topElem(Heap VH,Stack A){
    return(A != -1)? VH.Node[A].elem:-1;
}

bool isEmpty(Stack A){
    return (A == -1)? 1:0; 
}

void Push(Heap* VH, Stack* A, char elem){
    Stack temp = getSpace(VH);
    if(temp != -1){
        VH->Node[temp].elem = elem;
        VH->Node[temp].link = *A;
        *A = temp;
    }
}

void Pop(Heap* VH, Stack* A){
    if(!isEmpty(*A)){
        Stack temp;
        temp = *A;
        *A = VH->Node[temp].link;
        freeSpace(VH,temp);
    }
}


void displayStack(Heap* VH, Stack* A){
    if(!isEmpty(*A)){
        Stack temp = initStack();
        while(*A != -1){
            printf("%c ",VH->Node[*A].elem);
            Push(VH,&temp, VH->Node[*A].elem);
            Pop(VH,A);
        }

        while(temp != -1){
            Push(VH,A, VH->Node[temp].elem);
            Pop(VH,&temp);
        }
    }else{
        printf("Empty\n");
    }

}

void initHeap(Heap* VH){
    int i;
    for(i=MAX-1; i>=0; i--){
        VH->Node[i].link = i-1;
    }
    VH->avail = MAX -1;
}

int getSpace(Heap* VH){
    int index = VH->avail;
    if(index != -1){
        VH->avail = VH->Node[index].link;
    }
    return index;
}

void freeSpace(Heap* VH, int index){
    if(index != -1){
        VH->Node[index].link = VH->avail;
        VH->avail = index;
    }
}
