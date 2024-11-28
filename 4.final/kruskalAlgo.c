#include <stdio.h>
#include <stdlib.h>

#define MAX 6
#define MAX_ELEM 99
#define X 999 //sentinel value

typedef int LabelAdjMat[MAX][MAX];
typedef int component[MAX];

typedef struct {
    int u,v; // representing edge(u,v)
    int weight;
}edgeType;

typedef struct{
    edgeType edges[MAX_ELEM];
    int count;
}edgeList;

typedef struct{
    edgeType edges[MAX_ELEM];
    int count;
    int cost;
}MST;

void initMat(LabelAdjMat M);
void displayMatrix(LabelAdjMat MAT);
void displayEdgeList(edgeList list);
edgeList createEdgeList(LabelAdjMat M);
MST MST_kruskal(LabelAdjMat M);
void displayMST_kruskal(MST K);


int main(){
    // LabelAdjMat MAT;
    // initMat(MAT);
    // displayMatrix(MAT);
    LabelAdjMat M = {
        {X, 2, X, 8, X, X},
        {2, X, X, 5, 6, X},
        {X, X, X, X, 9, 3},
        {8, 5, X, X, 3, 2},
        {X, 6, 9, 3, X, 1},
        {X, X, 3, 2, 1, X},
    };
    displayMatrix(M);
    edgeList list = createEdgeList(M);
    displayEdgeList(list);

    MST K = MST_kruskal(M);
    displayMST_kruskal(K);
}
void initMat(LabelAdjMat M){
    int row,col;
    for(row = 0;row < MAX; row++){
        for(col = 0; col < MAX; col++){
            M[row][col] = X;
        }
    }
}

void displayMatrix(LabelAdjMat MAT){
    int row,col;
    puts("");
    printf("    ");
    for (int row = 0; row < MAX; row++) {
    printf("%d ", row);
    }
    puts("");
    for(row=0;row <MAX;row++){
        printf("%d | ",row);
        for(col = 0; col <MAX;col++){
            if(MAT[row][col] != X){
                printf("%d ",MAT[row][col]);
            }else{
                printf("%s ","X");
            }
        }
        printf("|\n");
    }
    puts("");
}

/**
 * Given the labeled adjacency matrix of an undirected graph, function createEdgeList() will create a list of edges arranged in ascending order according to weights.
 * Newly created list will be returned to the calling function.
 * 
 * write the code of function createEdgeList()
 */

edgeList createEdgeList(LabelAdjMat M){
    edgeList L = {.count = 0};
    int row,col,x;

    for(row = 0; row < MAX; row++){
        for(col = row+1; col < MAX; col++){
            if(M[row][col] != X && L.count < MAX_ELEM){
                edgeType temp;
                temp.u = row;
                temp.v = col;
                temp.weight = M[row][col];
                for(x=L.count-1;x>=0 && temp.weight < L.edges[x].weight;x--){
                        L.edges[x+1] = L.edges[x];
                }
                L.edges[x+1] = temp;
                L.count++;
            }
        }
    }

    return L;
}

void displayEdgeList(edgeList list){
    int i;
    for(i = 0; i < list.count; i++){
        printf("%d: (%d,%d) => %d\n",i,list.edges[i].u,list.edges[i].v,list.edges[i].weight);
    }
    puts("");
}

MST MST_kruskal(LabelAdjMat M){
    MST kruskal = {.count = 0,.cost = 0};
    edgeList List = createEdgeList(M);
    component comp;
    int i,j;
    for(i = 0; i < MAX; i++){
        comp[i] = i ;
    }

    for(i=0;i<List.count;i++){
        int u = List.edges[i].u;
        int v = List.edges[i].v;
        int compUVal = comp[u];
        int compVVal = comp[v];
        if(compUVal != compVVal){
            for(j = 0; j < MAX; j++){
                if(comp[j] == compVVal){
                    comp[j] = compUVal;
                }
            }
            kruskal.edges[kruskal.count++] = List.edges[i];
            kruskal.cost += List.edges[i].weight;
        }
    }

    return kruskal;
}

void displayMST_kruskal(MST K){
    int i;
    printf("Count: %d\n",K.count);
    printf("Cost: %d\n",K.cost);
    for(i = 0; i < K.count; i++){
        printf("%d: (%d,%d) => %d\n",i,K.edges[i].u,K.edges[i].v,K.edges[i].weight);
    }
    puts("");
}