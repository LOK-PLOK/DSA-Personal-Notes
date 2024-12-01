#include "strucDef.h"

void displayAdjMatrix(Adj_M G);
void dfs(Adj_M G,int curr,Set visited);
int main(){
    Adj_M G = {
        {0,1,1,0,0,0,0},
        {0,0,1,1,0,0,0},
        {1,0,0,0,0,0,0},
        {1,0,1,0,0,0,0},
        {0,0,0,0,0,1,1},
        {0,1,0,0,0,0,0},
        {0,0,0,1,0,1,0},
    };
    Set visited = {0};
    displayAdjMatrix(G);
    dfs(G,0,visited);
    puts("");
}

void dfs(Adj_M G,int curr,Set visited){
    visited[curr] = 1;
    printf("%d ",curr);
    int x;
    for(x = 0; x<MAXV;x++){
        if(G[curr][x] != 0 && visited[x] == FALSE){
            dfs(G,x,visited);
        }
    }
}

void displayAdjMatrix(Adj_M Matrix){
    int row,col;
    puts("");
    printf("    ");
    for (int row = 0; row < MAXV; row++) {
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