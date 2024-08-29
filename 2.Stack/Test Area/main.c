
/*
    Learnings:
    header file: array.h
    ---> has different variable declaration basing from what version
    example:
    version 1: Stack S;
    version 2: Stack* S;  you have to malloc stack
    version 3: Stack S;
    version 4: Stack* S; you have to malloc stack and dynamic array

    header file: LinkedList.h
    ---> following the rules of how a linked list works, the declaration should be a pointer variable
    example: Stack* S

 */


// #include "./header/arrayV1.h"
// #include "./header/arrayV2.h"
#include "./header/LinkedList.h"
int main(){
    Stack* S;
    
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

