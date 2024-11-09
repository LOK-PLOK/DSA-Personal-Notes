#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define ROOT -1
#define NO_CHILD -2

typedef int tree[MAX];

tree* initTree();
void insert(int elem,int parent,tree* T);
void display(tree T);
int PARENT(int child,tree T);
int LEFTMOST_CHILD(int node,tree T);
int RIGHT_SIBLING(int node,tree T);
int Root(tree T);
void MAKENULL(tree* T);

int main(){
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
    if(temp!= NULL){
        int i;
        for(i=0;i<MAX;i++){
            (*temp)[i] = NO_CHILD;
        }
    }
    return temp;
}

void insert(int elem,int parent,tree* T){
    if(elem < MAX && elem >= 0 && parent < MAX && parent >= -1){
        if ((*T)[elem] == NO_CHILD){
            (*T)[elem] = parent;
        }else{
            printf("Parent already in place\n\n");
        }
    }
}

void display(tree T){
    printf("%-10s%-10s\n","CHILD","PARENT");
    int i;
    for(i=0;i<MAX;i++){
        printf("%-10d%-10d\n",i,T[i]);
    }
}

int PARENT(int child,tree T){
    return(T[child] != NO_CHILD)? T[child]:NO_CHILD;
}

int LEFTMOST_CHILD(int node,tree T){
    int i;
    for(i=0;i<MAX&& node != T[i];i++){}

    return(i<MAX)? i:NO_CHILD;
}

int RIGHT_SIBLING(int node,tree T){
    int i;
    int p = T[node]; // Get the parent of the node
    int rightSibling = NO_CHILD; // Initialize right sibling to NO_CHILD

    for (i = 0; i < MAX; i++) {
        // Check if the current node has the same parent and a higher index than the given node
        if (T[i] == p && i > node && rightSibling == NO_CHILD) {
            rightSibling = i; // Set the right sibling
        }
    }

    return rightSibling;
}

int Root(tree T){
    int i;
    for(i=0;i<MAX&&T[i] != ROOT;i++){}

    return(i<MAX)? i:NO_CHILD;
}

void MAKENULL(tree* T){
    int i;
    for(i=0;i<MAX;i++){
        (*T)[i] = NO_CHILD;
    }
}
