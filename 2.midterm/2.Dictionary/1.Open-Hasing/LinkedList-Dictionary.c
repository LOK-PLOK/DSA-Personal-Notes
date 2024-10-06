#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10

typedef enum{TRUE = 1, FALSE = 0}boolean;

typedef struct node{
    int elem;
    struct node* next;
}*Node;

typedef Node Dictionary[SIZE];
typedef int Set[SIZE];

int hash(int elem);

void  initDic(Dictionary D);
void displayDic(Dictionary D);
void insert(Dictionary D, int elem);
void populateDic(Set A, Dictionary D);
void delete(Dictionary D, int elem);
boolean isMember(Dictionary D, int elem);

int main(){
    system("cls");
    Dictionary D;
    initDic(D);
    displayDic(D);
    Set A = {0,13,20,28,30,33,45,48,108};
    
    populateDic(A,D);
    printf("\n\n");
    displayDic(D);

    delete(D,48);
    printf("\n\n");
    displayDic(D);

    int num = 48;
    // int num = 108;
    printf("The number %d is %s",num,(isMember(D,num))? "A member":"Not a member");

    return 0;
}

int hash(int elem){
    return elem % 10;
}

void  initDic(Dictionary D){
    int i;
    for(i = 0; i< SIZE; i++){
        D[i] = NULL;
    }
}

void insert(Dictionary D, int elem){

    Node* trav,temp;
    for(trav = &D[hash(elem)]; *trav != NULL && (*trav)->elem != elem; trav = &(*trav)->next){}
    if(*trav == NULL){
        temp = (Node)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->elem = elem;
            temp->next = *trav;
            *trav = temp;
        }
    }
}

void populateDic(Set A, Dictionary D){
    int i;
    for(i = 0; i< SIZE; i++){
        insert(D, A[i]);
    }
}

void delete(Dictionary D, int elem){
    Node* trav, temp;
    
    for(trav = &D[hash(elem)]; *trav != NULL && (*trav)->elem != elem; trav = &(*trav)->next){}
    if(*trav != NULL){
        temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

boolean isMember(Dictionary D, int elem){
    Node trav;
    for(trav = D[hash(elem)]; trav != NULL && trav->elem != elem; trav = trav->next){}
    return (trav != NULL)? TRUE:FALSE;
}

void displayDic(Dictionary D){
    int i;
    Node trav = NULL;
    for(i = 0; i< SIZE; i++){
        printf("%d: ",i);
        for(trav = D[i]; trav!= NULL; trav = trav->next){
            if(trav != NULL){
                printf("%d --> ",trav->elem);
            }
        }
        printf("NULL ");
        printf("\n");
    }
}
