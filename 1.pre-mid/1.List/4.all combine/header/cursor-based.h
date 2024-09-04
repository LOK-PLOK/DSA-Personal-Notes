/**
 * Cursor based implementations, definitions and funtions here
 */

#ifndef Array_implementation_H
#define Array_implementation_H

typedef struct node{
    char elem;
    struct node* next;
}*List;

void init (List* A){
    *A = NULL;
}

void display(){

}

#endif