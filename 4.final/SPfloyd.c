#include "strucDef.h"

void displayLabelAdj(labelAdj_M G);
void floyd(labelAdj_M A, labelAdj_M C);

int main() {
    labelAdj_M G = {
        { INF, 10, INF, 30, 100 },
        { INF, INF, 50, INF, INF },
        { 20, INF, INF, INF, 10 },
        { INF, INF, 20, INF, 60 },
        { INF, INF, INF, INF, INF }
    };

    labelAdj_M A = {INF};
    floyd(A,G);
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

void floyd(labelAdj_M A, labelAdj_M C){
    int i,j,k;
    // Copy the Labeled Adjacency Graph C to A
    for(i=0;i<MAXV;i++){
        for(j=0;j<MAXV;j++){
            A[i][j] = C[i][j];
        }
    }
    // Set the Diagonal Line to 0
    for(i=0;i<MAXV;i++){
        A[i][i] = 0;
    }
    
    // Floyd-Warshall algorithm to find shortest paths
    for(k=0;k<MAXV;k++){
        for(i=0;i<MAXV;i++){
            for(j=0;j<MAXV;j++){
                // Update shortest path if a shorter path is found
                if(A[i][k] + A[k][j] < A[i][j]){
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
    }
}

void displayLabelAdj(labelAdj_M G) {
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