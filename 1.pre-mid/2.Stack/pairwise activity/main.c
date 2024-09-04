// #include "./header/array.h"
#include "./header/LinkedList.h"
int main(){
    Stack S;
    
    system("cls");  //<-- Windows
    // system("clear");  //<-- Linux
    
    printf("\ninitStack(): \n");
    initStack(&S);
    display(S);

    printf("\npush(A): \n");
    push(&S, 'A');
    display(S);

    printf("\npush(B,C,D,E): \n");
    push(&S, 'B');
    push(&S, 'C');
    push(&S, 'D');
    push(&S, 'E');
    display(S);


    int topElem = top(S);
    printf("\nTop: %c\n", topElem);

    printf("\npop(): \n");
    pop(&S);
    display(S);

    printf("\ninsertBottom(Z): \n");
    insertBottom(&S,'Z');
    display(S);

    printf("\nclean(): \n");
    clean(&S);
    display(S);
    return 0;
}

