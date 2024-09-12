#include <stdio.h>
#include <stdlib.h>

typedef unsigned char SET;

SET initSet();
void displaySet(SET S);

int main(){
    system("cls");
    SET A = initSet();
    SET B = initSet();

    printf("Set A: ");
    displaySet(A);
    printf("Set B: ");
    displaySet(B);

    return 0;
}

SET initSet(){
    return 0;
}

void displaySet(SET S){
    int mask = 1 << (sizeof(S) * 8 -1);

    while(mask != 0){
        printf("%d ",(S & mask)? 1:0);
        mask = mask >> 1;
    }
    printf("\n");
}