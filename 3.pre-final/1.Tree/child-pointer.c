#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
    int data;
    struct node* link;
}*List;

typedef struct { // similar to a open-hashing data structure
    List ptr[MAX];
    int root;
}Tree;

void init(Tree* tree, int root);
void insert(Tree* tree, int elem, int parent);
void display(Tree tree);
int PARENT(int n, Tree T);
int LEFTMOST_CHILD(int n, Tree T);
int RIGHTMOST_SIBLING(int n, Tree T);
int ROOT(Tree T);
int MAKENULL(Tree* T);

int main(){
    // system("cls");
    system("clear");
    Tree tree;
    init(&tree, 5);

    insert(&tree, 2, 5);
    insert(&tree, 4, 5);
    insert(&tree, 0, 5);
    insert(&tree, 7, 2);
    insert(&tree, 1, 2);
    insert(&tree, 8, 0);
    insert(&tree, 6, 1);

    printf("Initial tree:\n");
    display(tree);

    printf("\nTesting PARENT function:\n");
    for (int i = 0; i < MAX; i++) {
        printf("PARENT(%d) = %d\n", i, PARENT(i, tree));
    }

    printf("\nTesting LEFTMOST_CHILD function:\n");
    for (int i = 0; i < MAX; i++) {
        printf("LEFTMOST_CHILD(%d) = %d\n", i, LEFTMOST_CHILD(i, tree));
    }

    printf("\nTesting RIGHTMOST_SIBLING function:\n");
    for (int i = 0; i < MAX; i++) {
        printf("RIGHTMOST_SIBLING(%d) = %d\n", i, RIGHTMOST_SIBLING(i, tree));
    }

    printf("\nTesting ROOT function:\n");
    printf("ROOT = %d\n", ROOT(tree));

    printf("\nTesting MAKENULL function:\n");
    MAKENULL(&tree);
    display(tree);

    return 0;
}

void init(Tree* tree, int root){
    tree->root = root;
    int i;
    for(i=0;i<MAX;i++){
        tree->ptr[i] = NULL;
    }
}

void insert(Tree* tree, int elem, int parent){
    if(parent >=0 && parent < MAX){
        List *trav,temp;
        for(trav = &tree->ptr[parent]; *trav != NULL; trav = &(*trav)->link){}
        temp = (List)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->data = elem;
            temp->link = *trav;
            *trav = temp;
        }
    }
}

void display(Tree tree){
    int i;
    List trav;

    for(i = 0; i<MAX;i++){
        printf("%d: ",i);
        for(trav = tree.ptr[i]; trav != NULL;trav = trav->link){
            printf("%d --> ", trav->data);
        }
        printf("NULL\n");
    }
}

int PARENT(int n, Tree T){
    List trav;
    int i, p = -2;
    for(i = 0; i < MAX; i++){
        for(trav = T.ptr[i]; trav != NULL;trav = trav->link){
            if(trav->data == n){
                p = i;
            }
        }
    }

    return p;
}

int LEFTMOST_CHILD(int n, Tree T){
    return (n < MAX && T.ptr[n] != NULL)? T.ptr[n]->data: -2;
}

int RIGHTMOST_SIBLING(int n, Tree T){
    int parent = PARENT(n, T);
    if (parent == -2) {
        return -2; 
    }

    List trav = T.ptr[parent];
    int rightmostSibling = -2;

    while (trav != NULL) {
        if (trav->data != n) {
            rightmostSibling = trav->data;
        }
        trav = trav->link;
    }

    return rightmostSibling;
}

int ROOT(Tree T){
    return T.root;
}

int MAKENULL(Tree* T){
    int i;
    for(i=0;i<MAX;i++){
        T->ptr[i] = NULL;
    }
}
