#ifndef QueueType_H
#define QueueType_H

#include "./Mydata.h"

typedef Student Data;
typedef struct node{
    Data elem;
    struct node* link;
}Nodetype,*NodePtr;

typedef struct{
    NodePtr head;
    NodePtr tail;
}Queue;

#endif