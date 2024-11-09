#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct node{
    int data;
    struct node* link;
}*Node;

typedef struct{
    Node List[MAX];
    int root;
}Tree;

void init(Tree* tree, int root);
void insert(Tree* tree, int elem, int parent);
void display(Tree tree);
int PARENT(int n, Tree T);
int LEFTMOST_CHILD(int n, Tree T);
int RIGHT_SIBLING(int n, Tree T);
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
        printf("RIGHTMOST_SIBLING(%d) = %d\n", i, RIGHT_SIBLING(i, tree));
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
        tree->List[i] = NULL;
    }
}

void insert(Tree* tree, int elem, int parent){
    if(parent < MAX && parent >= 0){
        Node* trav,temp;
        for(trav = &tree->List[parent]; *trav != NULL;trav= &(*trav)->link){}
        temp = (Node)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->data = elem;
            temp->link = *trav;
            *trav = temp;
        }
    }
}

void display(Tree tree){
    int i;
    Node trav;
    
    for(i=0;i<MAX;i++){
        printf("%d: ",i);
        for(trav = tree.List[i];trav != NULL; trav = trav->link){
            printf("%d --> ",trav->data);
        }
        printf("NULL\n");
    }
}

int PARENT(int n, Tree T){
    Node trav;
    int i,parent = -2;
    if(n != T.root){
        for(i=0;i<MAX;i++){
            for(trav = T.List[i];trav != NULL; trav = trav->link){
                if(trav->data == n){
                    parent = i;
                }
            }
        }
    }else{
        parent = -1;
    }
    return parent;
}

// n is the parent
int LEFTMOST_CHILD(int n, Tree T){
    return (n < MAX && T.List[n] != NULL)? T.List[n]->data:-2;
}

// n is the child
int RIGHT_SIBLING(int n, Tree T) {
    int parent = PARENT(n, T); // Get the parent of the node
    int rightmostSibling = -2; // Initialize rightmost sibling to NO_CHILD

    if (parent >=0 ) { // Check if the node has a parent
        Node trav;
        for (trav = T.List[parent]; trav != NULL; trav = trav->link) {
            if (trav->data != n) {
                rightmostSibling = trav->data; // Update rightmost sibling
            }
        }
    }

    return rightmostSibling; // Return the rightmost sibling
}

int ROOT(Tree T){
    return T.root;
}

int MAKENULL(Tree* T){
    int i;
    for(i=0;i<MAX;i++){
        T->List[i] = NULL;
    }
    T->root = -1;
}