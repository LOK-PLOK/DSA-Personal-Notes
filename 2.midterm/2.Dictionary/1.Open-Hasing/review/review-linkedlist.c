#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct node{
    int data;
    struct node* next;
}*Dic;

typedef Dic Dictionary[SIZE];
typedef enum{TRUE = 1, FALSE = 0}boolean;
typedef int Set[SIZE];

void initDic(Dictionary D);
void displayDic(Dictionary D);
int hash(int elem);
void insert(Dictionary D, int elem);
void populateDic(Dictionary D, Set A);
void delete(Dictionary D, int elem);
boolean isMember(Dictionary D, int elem);

int main(){
    // system("cls");
    Dictionary D;
    initDic(D);
    printf("\n\n");
    displayDic(D);

    Set A = {0,13,20,28,30,33,45,48,108};
    populateDic(D,A);
    printf("\n\n");
    displayDic(D);
    
    delete(D, 48);
    printf("\n\n");
    displayDic(D);

    // int num = 48;
    int num = 108;
    printf("\nThe value %d is %s\n",num, (isMember(D,num))? "a member":"not a member");

    return 0;
}

void initDic(Dictionary D){
    int i;
    for(i=0;i<SIZE;i++){
        D[i] = NULL;
    }
}

int hash(int elem){
    return elem % 10;
}

void insert(Dictionary D, int elem){
    Dic* trav, temp;
    for(trav = &D[hash(elem)]; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->next){}
    if(*trav == NULL){
        temp = (Dic)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->data = elem;
            temp->next = *trav;
            *trav = temp;
        }
    }
}

void populateDic(Dictionary D, Set A){
    int i;
    for(i=0;i<SIZE;i++){
        insert(D,A[i]);
    }
}

void delete(Dictionary D, int elem){
    Dic* trav, temp;
    for(trav = &D[hash(elem)]; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->next){}
    if(*trav != NULL){
        temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

boolean isMember(Dictionary D, int elem){
    Dic trav;
    for(trav = D[hash(elem)]; trav != NULL && trav->data != elem; trav = trav->next){}
    
    return (trav != NULL)? TRUE:FALSE;
}

void displayDic(Dictionary D){
    Dic trav;
    int i;
    for(i = 0; i<SIZE; i++){
        printf("%d: ",i);
        for(trav = D[i]; trav != NULL; trav = trav->next){
            printf("%d --> ",trav->data);
        }
        printf("NULL\n");
    }
}
