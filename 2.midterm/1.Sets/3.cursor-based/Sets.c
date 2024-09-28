#include <stdio.h>
#include <stdbool.h>
#define MAX 50


typedef struct{
    int data;
    int next;
}Cell;

typedef struct{
    Cell Node[MAX];
    int avail;
}heap;

typedef int Set;

void initHeap(heap * VH);
int getMalloc(heap* VH);
void dealloc(heap* VH, int index);

Set initSet();
void insertSet(Set* A,heap* VH, int data[], int size);
void insertSetData(Set* A, heap* VH, int elem);
void deleteFromSet(Set*A, heap*VH, int elem);
void displaySet(Set A, heap VH);
Set Union(Set A, Set B, heap* VH);
void deleteFromSet(Set*A, heap*VH, int elem);
Set Intersection(Set A, Set B, heap* VH);
Set Difference(Set A, Set B, heap* VH);

int main(){
    heap vh;
    initHeap(&vh);

    Set A = initSet(); 
    Set B = initSet(); 
    int data[] = {0,2,4,6,7,9};
    int data2[] = {0,3,4,7,8,9};

    printf("Set A: ");
    insertSet(&A,&vh,data, sizeof(data)/sizeof(data[0]));
    displaySet(A, vh);

    printf("Set B: ");
    insertSet(&B,&vh,data2, sizeof(data2)/sizeof(data2[0]));
    displaySet(B,vh);

    Set U = Union(A, B, &vh);
    printf("Union: ");
    displaySet(U,vh);

    Set I = Intersection(A, B, &vh);
    printf("Intersection: ");
    displaySet(I,vh);

    Set D = Difference(A, B,& vh);
    printf("(A - B): ");
    displaySet(D,vh);

    D = Difference(B, A, &vh);
    printf("(B - A): ");
    displaySet(D,vh);

    int temp;
    printf("\nRemove an element from set A: ");
    scanf(" %d", &temp);

    deleteFromSet(&A,&vh, temp);
    printf("A without '%d': ", temp);
    displaySet(A,vh);

    return 0;
}

Set initSet(){
    Set temp = -1;
    return temp;
}

void insertSet(Set* A,heap* VH, int data[], int size){
    int i;
    for(i = 0; i< size; i++){
        Set temp = getMalloc(VH);
        if(temp!= -1){
            VH->Node[temp].data = data[i];
            VH->Node[temp].next = *A;
            *A = temp;
        }
    }
}

void insertSetData(Set* A, heap* VH, int elem){
    Set temp = getMalloc(VH);
    if(temp != -1){
        VH->Node[temp].data = elem;
        VH->Node[temp].next = *A;
        *A = temp;
    }
}

void deleteFromSet(Set*A, heap*VH, int elem){
    Set* trav;
    for(trav = A; *trav != -1 && VH->Node[*trav].data != elem; trav = &VH->Node[*trav].next){}
    if(*trav != -1){
        Set temp = *trav;
        *trav = VH->Node[temp].next;
        dealloc(VH,temp);
    }
}

void displaySet(Set A, heap VH){
    Set trav;
    for(trav = A; trav != -1; trav = VH.Node[trav].next){
        printf("%d ",VH.Node[trav].data);
    }
    printf("\n\n");
}

void initHeap(heap * VH){
    VH->avail = MAX-1;
    int i;
    for(i = MAX-1; i>=0; i--){
        VH->Node[i].next = i-1;
    }
}

int getMalloc(heap* VH){
    int index = VH->avail;
    if(index != -1){
        VH->avail = VH->Node[index].next;
    }
    return index;
}

void dealloc(heap* VH, int index){
    if(index != -1){
        VH->Node[index].next = VH->avail;
        VH->avail = index;
    }
}

Set Union(Set A, Set B, heap* VH){
    Set U = initSet();
    Set travA = A,travB = B;

    while(travA != -1 && travB != -1){
        if(VH->Node[travA].data == VH->Node[travB].data){
            insertSetData(&U,VH,VH->Node[travA].data);
            travA = VH->Node[travA].next;
            travB = VH->Node[travB].next;
        }else if(VH->Node[travA].data > VH->Node[travB].data){
            insertSetData(&U,VH,VH->Node[travA].data);
            travA = VH->Node[travA].next;
        }else{
            insertSetData(&U,VH,VH->Node[travB].data);
            travB = VH->Node[travB].next;
        }
    }

    Set remaining = (travA != -1)? travA:travB;
    while(remaining != -1){
        insertSetData(&U,VH,VH->Node[remaining].data);
        remaining = VH->Node[remaining].next;

    }
    return U;
}

Set Intersection(Set A, Set B, heap* VH){
    Set I = initSet();
    Set travA = A,travB = B;

    while(travA != -1 && travB != -1){
        if(VH->Node[travA].data == VH->Node[travB].data){
            insertSetData(&I,VH,VH->Node[travA].data);
            travA = VH->Node[travA].next;
            travB = VH->Node[travB].next;
        }else if(VH->Node[travA].data > VH->Node[travB].data){
            travA = VH->Node[travA].next;
        }else{
            travB = VH->Node[travB].next;
        }
    }

    Set remaining = (travA != -1)? travA:travB;
    while(remaining != -1){
        insertSetData(&I,VH,VH->Node[remaining].data);
        remaining = VH->Node[remaining].next;

    }
    return I;
}

Set Difference(Set A, Set B, heap* VH){
    Set D = initSet();
    Set travA = A,travB = B;

    while(travA != -1 && travB != -1){
        if(VH->Node[travA].data == VH->Node[travB].data){
            travA = VH->Node[travA].next;
            travB = VH->Node[travB].next;
        }else if(VH->Node[travA].data > VH->Node[travB].data){
            insertSetData(&D,VH,VH->Node[travA].data);
            travA = VH->Node[travA].next;
        }else{
            travB = VH->Node[travB].next;
        }
    }

    return D;
}