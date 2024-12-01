#ifndef ADJ_REPRESENTATION
#define ADJ_REPRESENTATION

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// change the MAXV to 5 when using dijkstras algo
#define MAXV 5
#define MAXList 10
#define INF 999

typedef enum {FALSE,TRUE}Boolean;
typedef enum {visited,unvisited}Visited;

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