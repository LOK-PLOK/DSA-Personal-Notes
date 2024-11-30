#ifndef ADJ_REPRESENTATION
#define ADJ_REPRESENTATION

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV 6
#define MAXList 10
#define x 999

// structure definition for Graph Adjacency Matrix representation
typedef int Adj_M[MAXV][MAXV];
typedef int labelAdj_M[MAXV][MAXV];

// structure definition for Graph Adjacency List representation 
/** Linked List Types */
//Adjacency List
typedef struct nodeV{
    int v;
    struct nodeV* next;
}*vert;


typedef struct{
    vert head[MAXV];
    int edgeCount;
}AdjListLL;

//Labeled Adjacency List
typedef struct nodeV2{
    int v;
    int weight;
    struct nodeV2* next;
}*vert2;

typedef struct{
    vert2 head[MAXV];
    int edgeCount;
}LabeledAdjListLL;


/** Cursor Types */
typedef int CAdjHead[MAXV];
typedef int CLabeledAdjHead[MAXV];
typedef int AdjList[MAXList];
typedef int LabeledAdjList[MAXList];

typedef struct{
    int u;
    int v;
}edgeType;

typedef struct{
    int head;
    int tail;
    int weight;
}edgeTypeL;

#endif