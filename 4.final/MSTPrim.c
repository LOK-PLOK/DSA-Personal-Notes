#include "strucDef.h"

typedef struct{
    edgeTypeL edges[MAXE];
    int count;
    int cost;
}MST;

void displayAdjMatrix(labelAdj_M Matrix);
void displayMST_prim(MST P);
MST MST_prim(labelAdj_M Matrix, int start);

int main(){
    labelAdj_M G = {
        {INF,   1,   5,   4,   6,   5},
        {  1, INF,   5, INF, INF,   6},
        {  5,   5, INF,   2, INF, INF},
        {  4, INF,   2, INF,   1, INF},
        {  6, INF, INF,   1, INF,   3},
        {  5,   6, INF, INF,   3, INF},
    };

    MST prim = MST_prim(G, 0);
    displayAdjMatrix(G);
    displayMST_prim(prim);
    printf("\nTotal Cost: %d\n\n",prim.cost);
}

//important to add comments on what you are doing

MST MST_prim(labelAdj_M G, int start){
    // Initialize MST
    MST prim;
    prim.cost = 0;
    prim.count = 0;

    // initialize A component to mark FALSE => Not yet visited
    Boolean visit[MAXV] = {FALSE};
    visit[start] = TRUE; // initialize the starting vertices to TRUE
    int edgeNo = 1;

    int i,j,x,y;
    //while no of edges is not yet = to the number of vertices
    while(edgeNo < MAXV){
        int min = INF;
        x = -1; // x represents the row
        y = -1; // y represents the column
        //visiting every edges to find the most minimum weight
        for(i = 0; i < MAXV; i++){
            // edges on the visited vertices are checked
            if(visit[i] == TRUE){
                for(j = 0; j < MAXV; j++){
                    // check if the vertice is not yet visited and check if its not infinity and if its the most minimum
                    if(visit[j] == FALSE && G[i][j] != INF && min > G[i][j]){
                        min = G[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        //if y is change, we insert to the MST and add the cost, also set the visit at index y to visited
        if(y != -1){
            edgeTypeL temp = {y,x,min};
            visit[y] = TRUE;
            prim.edges[prim.count++] = temp;
            prim.cost+=min;
            edgeNo++;
        }
    }
    return prim;
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

void displayMST_prim(MST P){
    int i;
    printf("Count: %d\n",P.count);
    printf("Cost: %d\n",P.cost);
    for(i = 0; i < P.count; i++){
        printf("%d: (%d,%d) => %d\n",i,P.edges[i].tail,P.edges[i].head,P.edges[i].weight);
    }
}