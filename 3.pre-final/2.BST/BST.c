#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}*Node;

Node initTree();
void insert(Node* node, int elem);
void insertIterative(Node* node, int elem);
void displayInorder(Node node);
void displayPreorder(Node node);
void displayPostorder(Node node);
bool isMember(Node node, int elem);


int main(){
    Node A = initTree();

    printf("\n");
    insertIterative(&A,13);
    insertIterative(&A,3);
    insertIterative(&A,14);
    insertIterative(&A,1);
    insertIterative(&A,4);
    insertIterative(&A,18);
    insertIterative(&A,2);
    insertIterative(&A,12);
    printf("PreOrder:\t");
    displayPreorder(A);
    printf("\n\n");
    printf("InOrder:\t");
    displayInorder(A);
    printf("\n\n");
    printf("PostOrder:\t");
    displayPostorder(A);
    printf("\n\n");

    printf("isMember(A,12): %d\n", isMember(A,12));
    return 0;
}

Node initTree(){
    Node temp = NULL;
    return temp; // or just return NULL directly
}

// recursive version
void insert(Node* node, int elem){
    if(*node == NULL){
        Node temp = (Node)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->data = elem;
            temp->left = temp->right = NULL;
            *node = temp;
        }
    }else{
        if(elem <= (*node)->data){
            insert(&(*node)->left, elem);
        }else{
            insert(&(*node)->right, elem);
        }
    }
}

//Iterative version
void insertIterative(Node* node, int elem){
    Node* trav, temp;
    for(trav = node; *trav != NULL;){
        trav = (elem < (*trav)->data)? &(*trav)->left: &(*trav)->right;
    }

    if(*trav == NULL){
        temp = (Node)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->data = elem;
            temp->left = temp->right = NULL;
            *trav = temp;
        }
    }
}


void displayPreorder(Node node){
    if(node != NULL){
        printf("%d ",node->data);
        displayPreorder(node->left);
        displayPreorder(node->right);
    }
}


void displayInorder(Node node){
    if(node != NULL){
        displayInorder(node->left);
        printf("%d ",node->data);
        displayInorder(node->right);
    }
}


void displayPostorder(Node node){
    if(node != NULL){
        displayPostorder(node->left);
        displayPostorder(node->right);
        printf("%d ",node->data);
    }
}

bool isMember(Node node, int elem){
    for(;node != NULL && node->data != elem;){
        node=(elem < node->data)? node->left:node->right;
    }

    return (node != NULL)? true:false;
}

// To be continued, Delete function
