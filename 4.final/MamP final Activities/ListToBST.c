#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
    char name[30];
    char ID[10];
    char course[8];
    int yrLevel;
}studRec;

typedef struct node{
    studRec stud;
    struct node* prev; // NULL if node is used in the list.
                       // Points to the Left child if node is used in BST
    struct node* next; // Points to the next node if used in the list
                       // Points to the Right child if node is used in BST
}*ListBST;

/**
 * Write the code of the function convertList2BST(). The function will convert a given list
 * to a BST organized according to the ID. Any duplicate element will be discarded.
 * Note: Do not include unnecessary statements in your code.
 * Constraints: 1 return statement only if necessary, no break/exit statement.
 */

void displayList(ListBST list);
void populateList(ListBST* list,studRec data[]);
void insertList(ListBST* list, studRec data);

void convertList2BST(ListBST* list);
void inorder(ListBST BST);

int main (){
    //Note: These are not real ID numbers
    studRec data0 = {"Paul Detablan","23100209","BSCS",2};
    studRec data1 = {"Luis Ouano","23104201","BSIT",2};
    studRec data2 = {"Carlos Miguel","23100301","BSCS",2};
    studRec data3 = {"Jame Garcia","23100502","BSCS",2};
    studRec data4 = {"Justin Antonio","23100721","BSCS",2};
    studRec data5 = {"Paul Detablan","23100209","BSCS",2}; // Duplicate
    studRec data6 = {"Nash Munoz","23100124","BSCS",2};
    studRec data7 = {"Hash Abangan","23100841","BSCS",2};
    studRec data8 = {"Christine Pena","23100759","BSCS",2};
    studRec data9 = {"Zia Roca","23100167","BSCS",2};
    studRec data[MAX] = {data0,data1,data2,data3,data4,data5,data6,data7,data8,data9};

    ListBST list = NULL;
    populateList(&list,data);
    puts("");
    printf("Display List:\n");
    displayList(list);

    printf("Display BST(inorder):\n");
    convertList2BST(&list);
    inorder(list);
}

void insertList(ListBST* list, studRec data){
    ListBST temp = (ListBST)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->stud = data;
        temp->prev = NULL;
        temp->next = *list;
        *list = temp;
    }
}


void populateList(ListBST* list,studRec data[]){
    int i;
    for(i=0;i<MAX;i++){
        insertList(list,data[i]);
    }
}

void convertList2BST(ListBST* list){
    ListBST BST = NULL,temp,*trav;
    while(*list != NULL){
        temp = *list;
        *list = temp->next;
        temp->next = NULL;
        for(trav = &BST; *trav != NULL && strcmp(temp->stud.ID,(*trav)->stud.ID) != 0; 
            trav = (strcmp(temp->stud.ID,(*trav)->stud.ID) < 0)? &(*trav)->prev:&(*trav)->next){}

        if(*trav == NULL){
            *trav = temp;
        }else{
            free(temp);
        }
    }
    *list = BST;
}

void inorder(ListBST BST){
    if(BST != NULL){
        inorder(BST->prev);
        printf("%-20s %-20s %-10s %-10d\n",BST->stud.name,BST->stud.ID,BST->stud.course,BST->stud.yrLevel);
        inorder(BST->next);
    }
}

void displayList(ListBST list){
    if(list != NULL){
        ListBST trav;
        for(trav = list; trav != NULL; trav = trav->next){
            printf("%-20s %-20s %-10s %-10d\n",trav->stud.name,trav->stud.ID,trav->stud.course,trav->stud.yrLevel);
        }
    }else{
        printf("Empty");
    }
    puts("");
}
