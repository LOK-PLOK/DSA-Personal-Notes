#include "strucDef.h"

typedef struct{
    edgeTypeL edges[MAXE];
    int count;
    int cost;
}MST;

void displayAdjMatrix(labelAdj_M Matrix);
void displayEdges(labelAdj_M Matrix);
void MST_prim(labelAdj_M Matrix);

int main(){
    labelAdj_M G = {
        {INF,   1,   5,   4,   6,   5},
        {  1, INF,   5, INF, INF,   6},
        {  5,   5, INF,   2, INF, INF},
        {  4, INF,   2, INF,   1, INF},
        {  6, INF, INF,   1, INF,   3},
        {  5,   6, INF, INF,   3, INF},
    };

    MST_prim(G);
    displayAdjMatrix(G);
}

//important to add comments on what you are doing

void MST_prim(labelAdj_M G){
    // Initialize MST matrix with INF (indicating no edges)
    labelAdj_M MST = {INF};
    // Initialize edge count
    int edgeNo = 0;
    // Array to keep track of visited vertices
    Boolean visit[MAXV] = {FALSE};
    // Start with the first vertex
    visit[0] = TRUE;

    int i, j, x, y;
    // Loop until we have added MAXV-1 edges to the MST
    while(edgeNo < MAXV - 1){
        int min = INF;
        // x and y will store the coordinates of the least weighted edge
        x = -1; // x is row 
        y = -1; // y is col
        // Iterate over all vertices
        for(i = 0; i < MAXV ; i++){
            // Check if the vertex is visited
            if(visit[i] == TRUE){
                // Iterate over all adjacent vertices
                for(j = 0; j < MAXV; j++){
                    // Check if the vertex is not visited and there is an edge
                    if(visit[j] == FALSE && G[i][j] != INF){
                        // Find the minimum weight edge
                        if(min > G[i][j]){
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        // If a valid edge is found
        if(y != -1){
            // Add the edge to the MST
            MST[x][y] = min;
            MST[y][x] = min;
            // Mark the vertex as visited
            visit[y] = TRUE;
            // Increment the edge count
            edgeNo++; 
        }
    }

    displayAdjMatrix(MST);
    displayEdges(MST);
}

void displayAdjMatrix(labelAdj_M Matrix){
    int row,col;
    puts("");
    printf("    ");
    for (row = 0; row < MAXV; row++) {
        printf("%d ", row);
    }
    puts("");
    for(row=0;row <MAXV;row++){
        printf("%d | ",row);
        for(col = 0; col <MAXV;col++){
            if(Matrix[row][col] != INF){
                printf("%d ",Matrix[row][col]);
            }else{
                printf("%s ","X");
            }
        }
        printf("|\n");
    }
    puts("");
}

void displayEdges(labelAdj_M Matrix){
    int totalCost = 0;
    puts("Edges and Weights:");
    for(int i = 0; i < MAXV; i++){
        for(int j = i + 1; j < MAXV; j++){
            if(Matrix[i][j] != 0 && Matrix[i][j] != INF){
                printf("Edge (%d, %d) with weight %d\n", i, j, Matrix[i][j]);
                totalCost += Matrix[i][j];
            }
        }
    }
    printf("Total cost of MST: %d\n", totalCost);
}