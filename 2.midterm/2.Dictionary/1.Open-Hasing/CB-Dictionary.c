#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#define SIZE 10

typedef struct{
    int elem;
    int next;
}Cell;

typedef struct{
    Cell Node[MAX];
    int avail;
}heap;

typedef int Dictionary[SIZE];
typedef int Set[SIZE];
typedef enum{TRUE = 1, FALSE = 0}boolean;


void initHeap(heap* VH);
int getMalloc(heap* VH);
void getFree(heap* VH, int index);

int hash(int elem);
void initDic(Dictionary D);
void displayDic(Dictionary D, heap VH);
void insert(Dictionary D, heap* VH, int elem);
void populateDic(Dictionary D, heap* VH, Set A);
void delete(Dictionary D,heap* VH ,int elem);
boolean isMember(Dictionary D, heap VH, int elem);

int main(){
    heap vh;
    initHeap(&vh);

    Dictionary D;
    initDic(D);

    Set A = {0,13,20,28,30,33,45,48,108};
    populateDic(D,&vh,A);
    printf("\n\n");
    displayDic(D,vh);

    delete(D,&vh,48);
    printf("\n\n");
    displayDic(D,vh);

    int num = 108;
    printf("The number %d is %s",num,(isMember(D,vh,num))? "A member":"Not a member");

    return 0;
}

int hash(int elem){
    return elem % 10;
}

void initDic(Dictionary D){
    int i;
    for(i = 0; i< SIZE; i++){
        D[i] = -1;
    }
}

void populateDic(Dictionary D, heap* VH, Set A){
    int i;
    for(i = 0; i< SIZE; i++){   
        insert(D,VH, A[i]);
    }
}


void insert(Dictionary D, heap* VH, int elem){
    int* trav, temp;
    for(trav = &D[hash(elem)]; *trav != -1 && VH->Node[*trav].elem != elem; trav = &VH->Node[*trav].next){}
    if(*trav == -1){
        temp = getMalloc(VH);
        if(temp != -1){
            VH->Node[temp].elem = elem;
            VH->Node[temp].next = *trav;
            *trav = temp;
        }
    }
}

void delete(Dictionary D,heap* VH ,int elem){
    int *trav,temp;
    for(trav = &D[hash(elem)]; *trav != -1 && VH->Node[*trav].elem != elem; trav = &VH->Node[*trav].next){}
    if(*trav != -1){
        temp = *trav;
        *trav = VH->Node[temp].next;
        getFree(VH,temp);
    }
}

boolean isMember(Dictionary D, heap VH, int elem){
    int trav;
    for(trav = D[hash(elem)]; trav != -1 && VH.Node[trav].elem != elem; trav = VH.Node[trav].next){}
    
    return (trav != -1)? TRUE:FALSE;
}

void displayDic(Dictionary D, heap VH){
    int i,trav;
    for(i = 0; i< SIZE; i ++){
        printf("%d: ",i);
        for(trav = D[i]; trav!= -1; trav = VH.Node[trav].next){
            printf("%d --> ",VH.Node[trav].elem);
        }
        printf("NULL");
        printf("\n");
    }
}

void initHeap(heap* VH){
    int i;
    for(i = MAX -1; i>=0; i--){
        VH->Node[i].next = i-1;
    }
    VH->avail = MAX-1;
}

int getMalloc(heap* VH){
    int index = VH->avail;
    if(index != -1){
        VH->avail = VH->Node[index].next;
    }
    return index;
}


void getFree(heap* VH, int index){
    if(index != -1){
        VH->Node[index].next = VH->avail;
        VH->avail = index;
    }
}