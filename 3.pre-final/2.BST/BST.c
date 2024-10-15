#include <stdio.h>
#include <stdlib.h>

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

    return 0;
}

Node initTree(){
    Node temp = NULL;
    return temp; // or just return NULL directly
}

/**
 * @brief Inserts an element into the Binary Search Tree (BST).
 *
 * This function inserts a new element into the BST. If the tree is empty,
 * it creates a new node with the given element. If the tree is not empty,
 * it recursively finds the correct position for the new element and inserts it.
 *
 * @param node A pointer to the root node of the BST.
 * @param elem The element to be inserted into the BST.
 */
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

/**
 * @brief Displays the elements of the Binary Search Tree (BST) in Preorder.
 *
 * This function prints the elements of the BST in Preorder traversal.
 * Preorder traversal visits the root node first, then the left subtree,
 * and finally the right subtree.
 *
 * @param node The root node of the BST.
 */
void displayPreorder(Node node){
    if(node != NULL){
        printf("%d ",node->data);
        displayPreorder(node->left);
        displayPreorder(node->right);
    }
}

/**
 * @brief Displays the elements of a binary search tree (BST) in inorder traversal.
 *
 * This function recursively traverses the BST in an inorder manner (left subtree, root, right subtree)
 * and prints the data of each node.
 *
 * @param node The root node of the BST to be traversed.
 */
void displayInorder(Node node){
    if(node != NULL){
        displayInorder(node->left);
        printf("%d ",node->data);
        displayInorder(node->right);
    }
}


/**
 * @brief Displays the nodes of a binary search tree (BST) in postorder traversal.
 *
 * This function recursively traverses the given binary search tree in postorder
 * (left subtree, right subtree, root) and prints the data of each node.
 *
 * @param node The root node of the binary search tree to be traversed.
 */
void displayPostorder(Node node){
    if(node != NULL){
        displayPostorder(node->left);
        displayPostorder(node->right);
        printf("%d ",node->data);
    }
}