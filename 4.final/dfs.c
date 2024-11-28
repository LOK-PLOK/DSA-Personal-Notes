#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 6

typedef int AdjMatrix[MAX][MAX];
typedef int Set[MAX];

void init(AdjMatrix G);
void displayMatrix(AdjMatrix G);
void addEdge(AdjMatrix  G, int row, int col);
void dfs(AdjMatrix G,int index,Set visited);

int main(){
    AdjMatrix G;
    Set visited = {0};
    init(G);
    displayMatrix(G);
    addEdge(G, 1, 2);
    addEdge(G, 2, 5);
    addEdge(G, 1, 4);
    addEdge(G, 4, 3);
    displayMatrix(G);
    dfs(G,1,visited);
}

void init(AdjMatrix G){
    int row,col;
    for(row = 0;row<MAX; row++){
        for(col = 0; col<MAX; col++){
            G[row][col] = 0;
        }
    }
}

void addEdge(AdjMatrix  G, int row, int col){
    G[row][col] = 1;
}

void dfs(AdjMatrix G,int index,Set visited){
    /**
     * recusive function calls
     * start from the given index and go further to its vertices that is connected
     * Note: this is Undirected Graph and Adjacency Matrix(values are 0 or 1)
     * 
     */
}

void displayMatrix(AdjMatrix G){
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
            printf("%d ",G[row][col]);
        }
        printf("|\n");
    }
    puts("");
}
