/**
 * Array implementations, definitions and funtions here
 */

#ifndef Array_implementation_H
#define Array_implementation_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    char elem[MAX];
    int count;
}List;

typedef enum{TRUE,FALSE}boolean;
/**
 * Functions to do:
 * insertFirst();
 * insertLast();
 * insertAtPos();
 * findElem();
 * deleteElem();
 * deleteAllOccur();
 * 
 * assignment:
 * insertSorted();
 * isEqualList(): <--- for sorted
 * isEqualList(): <--- for unsorted
 */
void initList(List* L){
    L->count = 0;
}

void display(List A){
    printf("Array List: ");
    if(A.count != 0){
        int i;
        for(i=0; i< A.count; i++){
            printf("%c ",A.elem[i]);
        }
        printf("\n");
    }else{
        printf("Empty \n");
    }
}

// List Operations //
void insertFirst(List* L, char elem){
    if(L->count != MAX){
        int i;
        for(i=L->count; i>0; i--){
            L->elem[i] = L->elem[i-1];
        }
        L->elem[0] = elem;
        L->count++;
    } 
}
void insertLast(List* L,char elem){
    if(L->count != MAX){
        int i;
        L->elem[L->count++] = elem;
    }

}

void insertSorted(List* L, char elem){
    if(L->count != MAX){
        int i,j;
        for(i=0;i<L->count && L->elem[i] < elem; i++){}
        if(i!= L->count){
            for(j = L->count; j>i; j--){
                L->elem[j] = L->elem[j-1];
            }
            L->elem[j] = elem;
            L->count++;
        }
    }
}

void insertAtPos(List* L,int elem, char pos){
    if(L->count != MAX && pos <= L->count && pos>=0){
        int i;
        for(i=L->count; i>pos; i--){
            L->elem[i] = L->elem[i-1];
        }
        L->elem[pos] = elem;
        L->count++;
    }
}

boolean findElem(List L, char elem){
    int i;
    for(i = 0; i<L.count && L.elem[i] != elem; i++){}
    return (i != L.count)? TRUE:FALSE;
}

void deleteElem(List* L,char elem){
    int i,j;
    for(i = 0; i < L->count && L->elem[i] != elem; i++){}
    if(i != L->count){
        for(j=i+1; j<L->count; j++){
            L->elem[j-1] = L->elem[j];
        }
        L->count--;
    }
}

void clean(List* L){
    L->count = 0;
}

void deleteAllOccur(List* L, char elem){
    int i,j;
    for(i=0; i<L->count;){
        if(L->elem[i] == elem){
            for(j= i+1; j< L->count; j++){
                L->elem[j-1] = L->elem[j];
            }
            L->count--;
        }else{
            i++;
        }
    }
}

// boolean isEqualList(List SET1,List SET2){
    
// }
#endif