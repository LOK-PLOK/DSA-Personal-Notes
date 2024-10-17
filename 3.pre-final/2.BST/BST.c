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
void displayInorder(Node node);
void displayPreorder(Node node);
void displayPostorder(Node node);
bool isMember(Node node, int elem);


int main(){
    Node A = initTree();

    printf("\n");
    insert(&A,13);
    insert(&A,3);
    insert(&A,14);
    insert(&A,1);
    insert(&A,4);
    insert(&A,18);
    insert(&A,2);
    insert(&A,12);
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
