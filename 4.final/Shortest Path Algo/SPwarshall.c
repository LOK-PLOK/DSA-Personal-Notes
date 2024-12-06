#include "../strucDef.h"

void displayLabelAdj(Adj_M G);
void warshall(Adj_M A, Adj_M C);

int main() {
    Adj_M G = {
        { 0, 1, 0, 1, 1 },
        { 0, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 1 },
        { 0, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 0 }
    };

    Adj_M A = {0};
    warshall(A,G);
    int i,j;
    puts("");
    for(i=0;i<MAXV;i++){
        for (j = 0; j < MAXV; j++) {
            printf("%d ", A[i][j]);
        }
        puts("");
    }
    puts("");
    displayLabelAdj(G);
    displayLabelAdj(A);

    return 0;
}

void warshall(Adj_M A, Adj_M C){
    int i,j,k;
    for(i=0;i<MAXV;i++){
        for(j=0;j<MAXV;j++){
            A[i][j] = C[i][j];
        }
    }

    /**
     * Applies the Floyd-Warshall algorithm to find the transitive closure.
     * Updates adjacency matrix A to reflect reachability of vertices.
     * 1 indicates a path, 0 indicates no path.
     */
    for(k=0;k<MAXV;k++){
        for(i=0;i<MAXV;i++){
            for(j=0;j<MAXV;j++){
                if(A[i][j] == 0){
                    A[i][j] = A[i][k] && A[k][j];
                }
            }
        }
    }
}

void displayLabelAdj(Adj_M G) {
    int row, col;
    puts("");
    printf("    ");
    for (row = 0; row < MAXV; row++) {
        printf("%d\t", row);
    }
    puts("");
    for (row = 0; row < MAXV; row++) {
        printf("%d | ", row);
        for (col = 0; col < MAXV; col++) {
            if (G[row][col] != INF) {
                printf("%d\t", G[row][col]);
            } else {
                printf("%s\t", "X");
            }
        }
        printf("\n");
    }
    puts("");
}