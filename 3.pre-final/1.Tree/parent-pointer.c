#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define ROOT  -1
#define NO_CHILD  -2

typedef int tree[MAX];

tree* initTree();
void insert(int elem,int parent,tree* T); // elemenent to insert, the parent, reference to the tree
void display(tree T);
int PARENT(int n, tree T);
int LEFTMOST_CHILD(int n, tree T);
int RIGHT_SIBLING(int n, tree T);
int Root(tree T);
void MAKENULL(tree* T);

int main(){
    // system("cls");
    system("clear");
    tree* T = initTree();
    insert(5,ROOT,T);
    insert(2,5,T);
    insert(4,5,T);
    insert(0,5,T);
    insert(7,2,T);
    insert(1,2,T);
    insert(8,0,T);
    insert(6,1,T);
    
    printf("Initial tree:\n");
    display(*T);

    printf("\nTesting PARENT function:\n");
    for (int i = 0; i < MAX; i++) {
        printf("PARENT(%d) = %d\n", i, PARENT(i, *T));
    }

    printf("\nTesting LEFTMOST_CHILD function:\n");
    for (int i = 0; i < MAX; i++) {
        printf("LEFTMOST_CHILD(%d) = %d\n", i, LEFTMOST_CHILD(i, *T));
    }

    printf("\nTesting RIGHT_SIBLING function:\n");
    for (int i = 0; i < MAX; i++) {
        printf("RIGHT_SIBLING(%d) = %d\n", i, RIGHT_SIBLING(i, *T));
    }

    printf("\nTesting Root function:\n");
    printf("Root = %d\n", Root(*T));

    printf("\nTesting MAKENULL function:\n");
    MAKENULL(T);
    display(*T);

    free(T);
    return 0;
}

tree* initTree(){
    tree* temp = (tree*)malloc(sizeof(tree));
    if(temp != NULL){
        int i;
        for(i=0;i<MAX;i++){
            (*temp)[i] = NO_CHILD;
        }
    }

    return temp;
}

void insert(int elem,int parent,tree* T){
    if(elem < MAX && elem>=0 && parent >=-1 && parent < MAX){
        if((*T)[elem] == NO_CHILD){
            (*T)[elem] = parent;
        }else{
            printf("Parent already in place\n\n");
        }
    }
}

void display(tree T){
    int i;
    printf("%-10s%-10s\n","child","parent");
    for(i=0;i<MAX;i++){
        printf("%-10d%-10d\n",i,T[i]);
    }
}

int PARENT(int n, tree T){
    return(T[n] != -2)? T[n]:-2;
}

int LEFTMOST_CHILD(int n, tree T){
    int i;
    for(i = 0; i <MAX && n != T[i]; i++){}

    return (i< MAX)? i:-2;
}

int RIGHT_SIBLING(int n, tree T){
    int i;
    int r = -2;
    int p = T[n];
    int ctr = 0;

    for(i = 0;i<MAX;i++){
        if(T[i] == p && i>n && ctr == 0){
            r = i;
            ctr++;
        }
    } 

    return r;
}

int Root(tree T){
    int i;
    for(i=0;i<MAX && T[i] != -1;i++){}

    return (i<MAX)? i:-2;
}

void MAKENULL(tree* T){
    int i; 
    for(i=0;i<MAX;i++){
        (*T)[i] = NO_CHILD;
    }
}