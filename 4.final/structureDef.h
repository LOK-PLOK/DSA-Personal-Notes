#ifndef GraphStructure_DEF
#define GraphStructure_DEF

#define VERTEX_SIZE 6
#define SENTINEL INT_MAX

typedef char vertexType; 
typedef int labelType;

typedef struct {
    vertexType tail;
    vertexType head;
    int weight;
}edgeType;

typedef struct {
    vertexType adjVertex;
    int weight;
}adjType;

typedef struct adjNode{
    adjType info;
    struct adjNode* link;
}*AdjList;


typedef struct {
    AdjList head[VERTEX_SIZE];  
    int edgeCount;
}directedAdjList;

typedef struct{
    labelType matrix[VERTEX_SIZE][VERTEX_SIZE];
    int edgeCount;
}labeledAdjMatrix;

#endif
