#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int Tree[MAX];

Tree* initTree();

void display(Tree T);
void displayParents(int node,Tree T);
void insert(int elem,int parent,Tree* T);

int main(){
    Tree* T = initTree();

    insert(3,-1,T);
    insert(5,3,T);
    insert(6,3,T);
    insert(4,6,T);

    display(*T);
    displayParents(4,*T);
    free(T);
}

Tree* initTree(){
    Tree* temp = (Tree*)malloc(sizeof(Tree));
    if(temp != NULL){
        int i;
        for(i = 0; i <MAX; i++){
            (*temp)[i] = -1;
        }
    }else{
        printf("Allocation Failed\n\n");
    }

    return temp;    
}

void insert(int elem,int parent,Tree* T){
    if(elem < MAX && elem >-1 && parent < MAX && parent > -1){
        (*T)[elem] = parent;
    }else{
        printf("INVALID\n\n");
    }
}

void display(Tree T){
    int i;
    printf("Tree:\n");
    for(i=0; i< MAX; i++){
        printf("%d: %d\n",i,T[i]);
    }
    printf("\n");
}

void displayParents(int node,Tree T){
    if(node < MAX && node >-1 && T[node] != -1){
        int i;
        for(i=node; T[i] != -1; i = T[i]){
            printf("%d ", i);
        }
        printf("%5d",i);
        printf("\n");
    }
}
