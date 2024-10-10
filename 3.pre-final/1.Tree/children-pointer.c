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


//This is to be continued

int main(){
    Tree T;
    initTree(&T);
    display(T);

    return 0;
}

void initTree(Tree* T){
    T->root = -1;

    int i;
    for(i=0;i<MAX;i++){
        T->Nodes[i] = NULL;
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
}
