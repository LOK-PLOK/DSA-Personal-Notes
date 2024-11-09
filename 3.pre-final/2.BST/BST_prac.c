#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    int data;
    struct node* LC;
    struct node* RC;
}*Node;

// BST FUNCTIONS
void INITIALIZE(Node* root);
void insertItera(Node* root, int elem);
void insertRec(Node* root, int elem);
int isMemberItera(Node root,int elem);
int isMemberRec(Node root,int elem);
void deleteItera(Node* root, int elem);
void deleteAll(Node* root);

//BST Traversals
void preOrder(Node root);
void inOrder(Node root);
void postOrder(Node root);

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
    INITIALIZE(&root);

    insertItera(&root, 10);
    insertItera(&root, 3);
    insertItera(&root, 13);
    insertItera(&root, 1);
    insertItera(&root, 5);
    insertItera(&root, 11);
    insertItera(&root, 20);
    insertItera(&root, 4);
    insertItera(&root, 15);
    insertItera(&root, 14);

    printf("preOrder:\t");
    preOrder(root);
    printf("\n\n");
    printf("inOrder:\t");
    inOrder(root);
    printf("\n\n");
    printf("postOrder:\t");
    postOrder(root);
    printf("\n\n");

    printf("isMember(2): %s\n", isMemberRec(root,2)? "True":"False");
    printf("isMember(11): %s\n", isMemberRec(root,11)? "True":"False");
    printf("\n\n");

    // printf("delete 4: \n"); // no child
    // deleteItera(&root, 4);

    // printf("delete 15: \n"); // 1 child
    // deleteItera(&root, 15);

    printf("delete 3: \n"); // 2 child
    deleteItera(&root, 3);

    printf("preOrder:\t");
    preOrder(root);
    printf("\n\n");
    printf("inOrder:\t");
    inOrder(root);
    printf("\n\n");
    printf("postOrder:\t");
    postOrder(root);
    printf("\n\n");

    deleteAll(&root);

    return 0;
}

void INITIALIZE(Node* root){
    *root = NULL;
}

void insertItera(Node* root, int elem){
    Node *trav, temp;
    for(trav = root; *trav != NULL; trav = (elem < (*trav)->data)? &(*trav)->LC:&(*trav)->RC){}
    temp = (Node)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = elem;
        temp->LC = temp->RC = NULL;
        *trav = temp;
    }
}

void insertRec(Node* root, int elem){
    if(*root == NULL){
        Node temp = (Node)malloc(sizeof(struct node));
        if(temp != NULL){
        temp->data = elem;
        temp->LC = temp->RC = NULL;
        *root = temp;
        }
    }else if(elem < (*root)->data){
        insertRec(&(*root)->LC,elem);
    }else{
        insertRec(&(*root)->RC,elem);
    }
}

int isMemberItera(Node root,int elem){
    Node trav;
    for(trav = root; trav != NULL && trav->data != elem; trav = (elem < trav->data)? trav->LC:trav->RC){}

    return (trav != NULL)? 1:0;
}

int isMemberRec(Node root,int elem){
    if(root == NULL){
        return 0;
    }else if(elem == root->data){
        return 1;
    }else if(elem < root->data){
        isMemberRec(root->LC,elem);
    }else{
        isMemberRec(root->RC,elem);
    }
}

void deleteItera(Node* root, int elem){
    Node* trav, temp;
    for(trav = root; *trav != NULL&& (*trav)->data != elem;){
        trav = (elem<(*trav)->data)? &(*trav)->LC:&(*trav)->RC;
    }

    if(*trav != NULL){
        Node* min;
        if((*trav)->LC != NULL && (*trav)->RC != NULL){ // 2 child
            for(min = &(*trav)->LC; (*min)->RC != NULL; min = &(*min)->RC){}
            (*trav)->data = (*min)->data;
            temp = *min;
            *min = (*min)->LC;
        }else if((*trav)->LC == NULL && (*trav)->RC == NULL){// 0 child
            temp = *trav;
            *trav = NULL;
        }else{// 1 child
            temp = *trav;
            *trav = ((*trav)->LC != NULL)? (*trav)->LC:(*trav)->RC;
        }

        free(temp);
    }
}

void deleteAll(Node* root){
    if(*root != NULL){
        deleteAll(&(*root)->LC);
        deleteAll(&(*root)->RC);
        free(*root);
        *root = NULL;
    }
}

void preOrder(Node root){
    if(root != NULL){
        printf("%d ",root->data);
        preOrder(root->LC);
        preOrder(root->RC);
    }
}

void inOrder(Node root){
    if(root != NULL){
        inOrder(root->LC);
        printf("%d ",root->data);
        inOrder(root->RC);
    }
}

void postOrder(Node root){
    if(root != NULL){
        postOrder(root->LC);
        postOrder(root->RC);
        printf("%d ",root->data);
    }
}