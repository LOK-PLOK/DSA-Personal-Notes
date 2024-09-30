#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef enum{EMPTY = -1, DELETED = -2} State;
typedef enum{TRUE = 1, FALSE = 0}boolean;
typedef int Dictionary[SIZE];
typedef int Set[SIZE];

void initDic(Dictionary D);
void displayDic(Dictionary D);
int hash(int elem);
void insert(Dictionary D, int elem);
void populate(Dictionary D, Set A);
void delete(Dictionary D, int elem);
boolean isMember(Dictionary D, int elem);

int main(){
    Dictionary D;
    initDic(D);

    printf("\n\n");
    displayDic(D);

    Set A = {0,13,20,28,30,33,45,48,108};
    populate(D,A);
    printf("\n\n");
    displayDic(D);

    delete(D,48);
    printf("\n\n");
    displayDic(D);

    // int num = 48;
    int num = 108;
    printf("\nThe number %d is %s",num,(isMember(D,num))? "a member":"not a member");

    return 0;
}

void initDic(Dictionary D){
    int i;
    for(i = 0; i<SIZE; i++){
        D[i] = EMPTY;
    }
}

int hash(int elem){
    return elem % SIZE;
}

void insert(Dictionary D, int elem){
    int start = hash(elem);
    int stopper = (start + SIZE -1) % SIZE;

    int i;
    for(i = start; i != stopper && D[i]!= EMPTY && D[i] != DELETED; i = (i+1)% SIZE){}

    if(D[i] != elem && (D[i] == EMPTY || D[i] == DELETED)){
        D[i] = elem;
    }
}

void populate(Dictionary D, Set A){
    int i;
    for(i = 0; i<9; i++){
        insert(D,A[i]);
    }
}

void delete(Dictionary D, int elem){
    int start = hash(elem);
    int stopper = (start + SIZE -1) % SIZE;
    int i;
    for(i = start; i != stopper &&D[i] != elem && D[i] != EMPTY; i= (i+1) % SIZE){}

    if(D[i] == elem){
        D[i] = DELETED;
    }
}

boolean isMember(Dictionary D, int elem){
    int start = hash(elem);
    int stopper = (start + SIZE -1) % SIZE;
    int i;
    for(i = start; i != stopper && D[i] != elem &&D[i] != EMPTY; i= (i+1) % SIZE){}

    return (D[i] == elem)? TRUE:FALSE;
}

void displayDic(Dictionary D){
    int i;
    for(i = 0; i<SIZE; i ++){
        printf ("%d: ",i);
        if(D[i] == EMPTY){
            printf("EMPTY");
        }else if(D[i] == DELETED){
            printf("DELETED");
        }else{
            printf("%d ",D[i]);
        }
        printf("\n");
    }
}
