#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
    int data;
    struct node* link;
}*Parent;


typedef struct{
    Parent Nodes[MAX];
    int root;
}Tree;

void initTree(Tree* T);
void display(Tree T);

void insertRoot(int elem,Tree* T);
void insert(int elem, int parent, Tree* T);
void preorder(int root, Tree T);
void inorder(int root, Tree T);
void postorder(int root, Tree T);

//This is to be continued

int main(){
    Tree T;
    initTree(&T);
    printf("Tree initalization:\n");
    display(T);

    insertRoot(5,&T);
    insert(2,5,&T);
    insert(4,5,&T);
    insert(0,5,&T);
    insert(7,2,&T);
    insert(1,2,&T);
    insert(6,1,&T);
    insert(8,0,&T);
    printf("After insertion:\n");
    display(T);

    printf("Preorder Traversal:\n");
    preorder(T.root,T);
    printf("\n\n");
    
    printf("Inorder Traversal:\n");
    inorder(T.root,T);
    printf("\n\n");

    printf("Postorder Traversal:\n");
    postorder(T.root,T);
    printf("\n\n");
    return 0;
}

void initTree(Tree* T){
    T->root = -1;

    int i;
    for(i=0;i<MAX;i++){
        T->Nodes[i] = NULL;
    }
}

void insertRoot(int elem,Tree* T){
    T->root = elem;
}

void insert(int elem, int parent, Tree* T){
    if(parent < MAX && parent >=0){
        Parent* trav,temp;
        for(trav = &T->Nodes[parent];*trav != NULL;trav = &(*trav)->link){}
        temp = (Parent)malloc(sizeof(struct node));
        if(temp!= NULL){
            temp->data = elem;
            temp->link = *trav;
            *trav = temp;
        }
    }
}

void display(Tree T){
    int i;
    Parent trav;
    for(i=0;i<MAX;i++){
        printf("%d: ",i);
        for(trav = T.Nodes[i]; trav!= NULL; trav = trav->link){
            printf("%d --> ",trav->data);
        }
        printf("NULL\n");
    }
    printf("\n\n");
}

void preorder(int root, Tree T){
    if(root != 1){
        printf("%d ", root);

        Parent trav;
        for(trav = T.Nodes[root]; trav != NULL; trav = trav->link){
            preorder(trav->data,T);
        }
    }
}

// This is Copilot generated
void inorder(int root, Tree T) {
    Parent trav = T.Nodes[root];
    
    if (trav != NULL) {
        inorder(trav->data, T); // Visit the first child (left subtree)
        trav = trav->link; // Move to the next sibling
    }
    
    printf("%d ", root); // Visit the root node
    
    for (; trav != NULL; trav = trav->link) {
        inorder(trav->data, T); // Visit the remaining children (right subtree)
    }
}
void postorder(int root, Tree T){
    if(root != -1){
        Parent trav;

        for(trav = T.Nodes[root]; trav != NULL; trav = trav->link){
            postorder(trav->data,T);
        }
            printf("%d ",root);
    }
}
