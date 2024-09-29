#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef enum{EMPTY = -1, DELETED = -2} State;
typedef enum{TRUE = 1, FALSE = 0} boolean;
typedef int Dictionary[SIZE];
typedef int Set[SIZE];

int hash(int elem);
void initDic(Dictionary D);
void displayDic(Dictionary D);
void insert(Dictionary D, int elem);
void populateDic(Dictionary D, Set A);
void delete(Dictionary D,int elem);
boolean isMember(Dictionary D, int elem);

int main(){
    system("cls");
    Dictionary D;
    initDic(D);
    displayDic(D);
    Set A = {0,13,20,28,30,33,45,48,108};
    
    populateDic(D,A);
    printf("\n\n");
    displayDic(D);

    delete(D,48);
    printf("\n\n");
    displayDic(D);

    int num = 48;
    // int num = 108;
    printf("The number %d is %s",num,(isMember(D,num))? "A member":"Not a member");

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
    int stopper = (start + SIZE -1) % SIZE; // gets the index of before the starting index like if start = 5, stopper = 4
    int spotAvail = -1;
    int i;
    for(i = start; i!= stopper && D[i] != elem && D[i] != EMPTY && D[i] != DELETED; i = (i+1)%SIZE){}

    if(D[i] != elem && (D[i] == EMPTY || D[i] == DELETED)){
        D[i] = elem;
    }
}

void populateDic(Dictionary D, Set A){
    int i;
    for(i = 0; i<SIZE; i++){
        insert(D,A[i]);
    }
}

void delete(Dictionary D,int elem){
    int start = hash(elem);
    int stopper = (start + SIZE -1) % SIZE;
    int spotAvail = -1;
    int i;
    for(i = start; i!= stopper && D[i] != elem && D[i] != EMPTY; i = (i+1)%SIZE){}

    if(D[i] == elem){
        D[i] = DELETED;
    }
}

boolean isMember(Dictionary D, int elem){
    int start = hash(elem);
    int stopper = (start + SIZE -1) % SIZE;
    int spotAvail = -1;
    int i;
    for(i = start; i!= stopper && D[i] != elem && D[i] != EMPTY; i = (i+1)%SIZE){}

    return (D[i] == elem)? TRUE: FALSE;
}

void displayDic(Dictionary D){
    int i;
    for(i = 0; i<SIZE; i++){
        printf("%d: ",i);
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
