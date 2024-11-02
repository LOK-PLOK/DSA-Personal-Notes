#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct {
    int data;
    int LC;
    int RC;
}Cell;

typedef struct {
    Cell Node[MAX];
    int avail;
}vheap;

typedef int Node;

void initHeap(vheap* heap);
int getSpace(vheap* heap);
int freeSpace(vheap* heap, int index);
void displayHeap(vheap heap);

void initTree(Node* root);
void insertRec(vheap* heap,Node* root, int elem);
void insertIterati(vheap* heap,Node* root, int elem);
void preOrder(vheap heap, Node root);
void inOrder(vheap heap, Node root);
void postOrder(vheap heap, Node root);

int isMember(vheap heap, Node root, int elem);
int isMemberRec(vheap heap, Node root, int elem);

void delete(vheap* heap, Node* root, int elem);

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
    vheap heap;
    initHeap(&heap);
    // displayHeap(heap);

    Node root;
    initTree(&root);

    insertRec(&heap,&root, 10);
    insertRec(&heap,&root, 3);
    insertRec(&heap,&root, 13);
    insertRec(&heap,&root, 1);
    insertRec(&heap,&root, 5);
    insertRec(&heap,&root, 11);
    insertRec(&heap,&root, 20);
    insertRec(&heap,&root, 4);
    insertRec(&heap,&root, 15);
    insertRec(&heap,&root, 14);

    printf("preOrder:\t");
    preOrder(heap,root);
    printf("\n\n");
    printf("inOrder:\t");
    inOrder(heap,root);
    printf("\n\n");
    printf("postOrder:\t");
    postOrder(heap,root);
    printf("\n\n");

    printf("isMember(2): %s\n",isMemberRec(heap,root,2)? "True":"False");
    printf("isMember(11): %s\n",isMemberRec(heap,root,11)? "True":"False");

    printf("\n\n");
    // printf("delete 4: \n"); // no child
    // delete(&heap,&root,4);

    // printf("delete 15: \n"); // 1 child
    // delete(&heap,&root,15);
    
    printf("delete 3: \n"); // 2 child
    delete(&heap,&root,3);

    printf("preOrder:\t");
    preOrder(heap,root);
    printf("\n\n");
    printf("inOrder:\t");
    inOrder(heap,root);
    printf("\n\n");
    printf("postOrder:\t");
    postOrder(heap,root);
    printf("\n\n");

    return 0;
}

void initTree(Node* root){
    *root = -1;
}

void insertRec(vheap* heap,Node* root, int elem){
    if(*root == -1){
        int temp = getSpace(heap);
        if(temp != -1){
            heap->Node[temp].data = elem;
            heap->Node[temp].LC = heap->Node[temp].RC = -1;
            *root = temp;
        }
    }else if (elem < heap->Node[*root].data){
        insertRec(heap,&heap->Node[*root].LC,elem);
    }else{
        insertRec(heap,&heap->Node[*root].RC,elem);
    }
}

void insertIterati(vheap* heap,Node* root, int elem){
    int* trav,temp;
    for(trav = root; *trav != -1; trav = (elem < heap->Node[*trav].data)? &heap->Node[*trav].LC:&heap->Node[*trav].RC){}
    if(* trav == -1){
        temp = getSpace(heap);
        if(temp != -1){
            heap->Node[temp].data = elem;
            heap->Node[temp].LC = heap->Node[temp].RC = -1;
            *trav = temp;
        }
    }
}

void preOrder(vheap heap, Node root){
    if(root != -1){
        printf("%d ",heap.Node[root].data);
        preOrder(heap,heap.Node[root].LC);
        preOrder(heap,heap.Node[root].RC);
    }
}

void inOrder(vheap heap, Node root){
    if(root != -1){
        inOrder(heap,heap.Node[root].LC);
        printf("%d ",heap.Node[root].data);
        inOrder(heap,heap.Node[root].RC);
    }
}

void postOrder(vheap heap, Node root){
    if(root != -1){
        postOrder(heap,heap.Node[root].LC);
        postOrder(heap,heap.Node[root].RC);
        printf("%d ",heap.Node[root].data);
    }
}

int isMember(vheap heap, Node root, int elem){
    int trav;
    for(trav = root; trav != -1 && heap.Node[trav].data != elem; trav = (elem<heap.Node[trav].data)? heap.Node[trav].LC:heap.Node[trav].RC){}

    return (trav != -1)? 1:0;
}

int isMemberRec(vheap heap, Node root, int elem){
    if (root != -1 && elem < heap.Node[root].data){
        isMemberRec(heap,heap.Node[root].LC,elem);
    }else if (root != -1 && elem > heap.Node[root].data){
        isMemberRec(heap,heap.Node[root].RC,elem);
    }else{
        return (root != -1)? 1:0;
    }
}

void delete(vheap* heap, Node* root, int elem){
    int* trav,temp;
    for(trav = root; *trav != -1 && heap->Node[*trav].data != elem;){
        trav = (elem < heap->Node[*trav].data)? &heap->Node[*trav].LC:&heap->Node[*trav].RC;
    }

    if(*trav != -1){
        if(heap->Node[*trav].LC != -1 && heap->Node[*trav].RC != -1){
            int* minSearch;
            for(minSearch = &heap->Node[*trav].LC; heap->Node[*minSearch].RC != -1; minSearch = &heap->Node[*minSearch].RC){}
            heap->Node[*trav].data = heap->Node[*minSearch].data;
            temp = *minSearch;
            *minSearch = -1;
        }else if(heap->Node[*trav].LC == -1 && heap->Node[*trav].RC == -1){
            temp = *trav;
            *trav = -1;
        }else{
            temp = *trav;
            *trav = (heap->Node[*trav].LC != -1)? heap->Node[*trav].LC:heap->Node[*trav].RC;
        }

        freeSpace(heap, temp);
    }
}

void initHeap(vheap* heap){
    int i;
    for(i = MAX-1; i>=0; i--){
        heap->Node[i].LC = -1;
        heap->Node[i].RC = i-1;
    }
    heap->avail = MAX-1;
}

int getSpace(vheap* heap){
    int space = heap->avail;
    heap->avail = heap->Node[space].RC;

    return space;
}

int freeSpace(vheap* heap, int index){
    heap->Node[index].RC = heap->avail;
    heap->avail = index;
}

void displayHeap(vheap heap){
    int i;
    for(i=0;i<MAX;i++){
        printf("Node %d LC:%d RC:%d\n",i,heap.Node[i].LC,heap.Node[i].RC);
    }
}