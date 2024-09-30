#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define MAX 30

typedef struct{
    int data;
    int next;
}Cell;

typedef struct{
    Cell Node[MAX];
    int avail;
}Vheap;

typedef enum{TRUE = 1, FALSE = 0}boolean;
typedef int Dictionary[SIZE];
typedef int Set[SIZE];

void initHeap(Vheap* VH);
int getMalloc(Vheap* VH);
void getFree(Vheap* VH, int index);

void initDic(Dictionary D);
int hash(int elem);
void displayDic(Dictionary D,Vheap VH);
void insert(Dictionary D, Vheap* VH, int elem);
void populate(Dictionary D, Vheap* VH, Set A);
void delete(Dictionary D,Vheap* VH,int elem);
boolean isMember(Dictionary D, Vheap VH, int elem);

int main(){
    Vheap vh;
    initHeap(&vh);

    Dictionary D;
    initDic(D);
    printf("\n\n");
    displayDic(D,vh);

    Set A = {0,13,20,28,30,33,45,48,108};
    populate(D,&vh,A);
    printf("\n\n");
    displayDic(D,vh);

    delete(D,&vh,48);
    printf("\n\n");
    displayDic(D,vh);

    // int num = 48;
    int num = 108;
    printf("\nThe number %d is %s",num,(isMember(D,vh,num))? "A member":"Not a member");

    return 0;

}

void initDic(Dictionary D){
    int i;
    for(i=0; i<SIZE; i++){
        D[i] = -1;
    }
}

int hash(int elem){
    return elem % 10;
}

void insert(Dictionary D, Vheap* VH, int elem){
    int* trav,temp;
    for(trav = &D[hash(elem)];*trav != -1 && VH->Node[*trav].data != elem; trav = &VH->Node[*trav].next){}
    if(*trav == -1){
        temp = getMalloc(VH);
        if(temp != -1){
            VH->Node[temp].data = elem;
            VH->Node[temp].next = *trav;
            *trav = temp;
        }
    }
}

void populate(Dictionary D, Vheap* VH, Set A){
    int i;
    for(i=0; i<SIZE;i++){
        insert(D,VH,A[i]);
    } 
}

void delete(Dictionary D,Vheap* VH,int elem){
    int* trav,temp;
    for(trav = &D[hash(elem)]; *trav != -1 && VH->Node[*trav].data != elem; trav = &VH->Node[*trav].next){}
    if(*trav != -1){
        temp = *trav;
        *trav = VH->Node[temp].next;
        getFree(VH,temp);
    }
}

boolean isMember(Dictionary D, Vheap VH, int elem){
    int trav;
    for(trav = D[hash(elem)]; trav != -1 && VH.Node[trav].data != elem; trav = VH.Node[trav].next){}
    return (trav != -1)? TRUE:FALSE;
}

void displayDic(Dictionary D,Vheap VH){
    int trav,i;
    for(i = 0; i<SIZE; i++){
        printf("%d: ",i);
        for(trav = D[i]; trav != -1; trav = VH.Node[trav].next){
            printf("%d --> ",VH.Node[trav].data);
        }
        printf("NULL\n");
    }

}


void initHeap(Vheap* VH){
    int i;
    for(i = MAX-1; i>=0; i--){
        VH->Node[i].next = i-1;
    }
    VH->avail = MAX-1;
}

int getMalloc(Vheap* VH){
    int index = VH->avail;
    if(index != -1){
        VH->avail = VH->Node[index].next;
    }
    return index;
}

void getFree(Vheap* VH, int index){
    if(index != -1){
        VH->Node[index].next = VH->avail;
        VH->avail = index;
    }
}
