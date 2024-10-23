#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int elem;
    struct node* LC;
    struct node* RC;
}*Node;

void initTree(Node* root);
void insertRec(Node* root, int elem);
void preOrder(Node root);
void inOrder(Node root);
void postOrder(Node root);
int isMember(Node root, int elem);
void delete(Node* root, int elem);

/**
 *            Tree illustration:
 *                  10
 *                 /  \
 *                3    13
 *               / \   / \
 *              1   5 11  20
 *                 /      /
 *                4      15
 *                      /
 *                     14
 */

int main(){
    Node root;
    initTree(&root);

    //insert recursive version
    insertRec(&root, 10);
    insertRec(&root, 3);
    insertRec(&root, 13);
    insertRec(&root, 1);
    insertRec(&root, 5);
    insertRec(&root, 11);
    insertRec(&root, 20);
    insertRec(&root, 4);
    insertRec(&root, 15);
    insertRec(&root, 14);

    printf("preOrder:\t");
    preOrder(root);
    printf("\n\n");
    printf("inOrder:\t");
    inOrder(root);
    printf("\n\n");
    printf("postOrder:\t");
    postOrder(root);
    printf("\n\n");

    printf("isMember(2): %s\n", isMember(root,2)? "True":"False");
    printf("isMember(11): %s\n", isMember(root,11)? "True":"False");
    printf("\n\n");

    // printf("delete 4: \n"); // no child
    // delete(&root, 4);

    // printf("delete 15: \n"); // 1 child
    // delete(&root, 15);

    printf("delete 3: \n"); // 2 child
    delete(&root, 3);

    printf("preOrder:\t");
    preOrder(root);
    printf("\n\n");
    printf("inOrder:\t");
    inOrder(root);
    printf("\n\n");
    printf("postOrder:\t");
    postOrder(root);
    printf("\n\n");


    return 0;
}

// difficulty - very easy
void initTree(Node* root){
    *root = NULL;
}

// recursive version, difficulty - medium
void insertRec(Node* root, int elem){
    if(*root == NULL){
        Node temp = (Node)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->elem = elem;
            temp->LC = temp->RC = NULL;
            *root = temp;
        }
    }else if (elem < (*root)->elem){
        insertRec(&(*root)->LC,elem);
    }else{
        insertRec(&(*root)->RC,elem);
    }
}

// recursive version, difficulty - easy
void preOrder(Node root){
    if(root != NULL){
        printf("%d ",root->elem);
        preOrder(root->LC);
        preOrder(root->RC);
    }
}

// recursive version, difficulty - easy
void inOrder(Node root){
    if(root != NULL){
        inOrder(root->LC);
        printf("%d ",root->elem);
        inOrder(root->RC);
    }
}

// recursive version, difficulty - easy
void postOrder(Node root){
    if(root != NULL){
        postOrder(root->LC);
        postOrder(root->RC);
        printf("%d ",root->elem);
    }
}

// Iterative version, difficulty - easy
int isMember(Node root, int elem){
    Node trav;
    for(trav = root; trav != NULL && trav->elem != elem;){
        trav = (elem < trav->elem)? trav->LC:trav->RC;
    }

    return (trav != NULL)? 1:0;
}

// iterative version, difficulty - medium to hard
void delete(Node* root, int elem){
    Node *trav,temp;

    for(trav = root; *trav != NULL && (*trav)->elem != elem;){
        trav = (elem < (*trav)->elem)? &(*trav)->LC:&(*trav)->RC;
    }

    if(*trav != NULL){
        Node* minNode;
        if((*trav)->LC != NULL && (*trav)->LC != NULL){
            for(minNode = &(*trav)->LC; (*minNode)->RC != NULL; minNode = &(*minNode)->RC){}
            (*trav)->elem = (*minNode)->elem;
            temp = *minNode;
            *minNode = NULL;
        }else if((*trav)->LC == NULL && (*trav)->LC == NULL){
            temp = *trav;
            *trav = ((*trav)->LC != NULL)? (*trav)->LC:(*trav)->RC;
        }else{
            temp = *trav;
            *trav = NULL;
        }

        free(temp);   
    }
}
