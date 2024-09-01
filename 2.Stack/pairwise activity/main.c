// #include "./header/array.h"
#include "./header/LinkedList.h"
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

