#include "../strucDef.h"

void displayLabelAdj(labelAdj_M G);
int* dijkstra(labelAdj_M C, int start);

int main() {
    labelAdj_M G = {
        { INF, 10, INF, 30, 100 },
        { INF, INF, 50, INF, INF },
        { 20, INF, INF, INF, 10 },
        { INF, INF, 20, INF, 60 },
        { INF, INF, INF, INF, INF }
    };

    int* setCatcher = dijkstra(G, 0);
    int i;
    puts("");
    for (i = 0; i < MAXV; i++) {
        printf("%d ", setCatcher[i]);
    }
    puts("");
    displayLabelAdj(G);

    free(setCatcher);
    return 0;
}

int* dijkstra(int G[MAXV][MAXV], int start) {
    int* D = (int*)malloc(MAXV * sizeof(int));
    Boolean S[MAXV] = { FALSE }; // Track visited vertices

    // Initialize distances
    for (int i = 0; i < MAXV; i++) {
        D[i] = G[start][i];
    }
    D[start] = 0;

    // Main loop: Find shortest paths
    for (int remainingVertices = 0; remainingVertices < MAXV; remainingVertices++) {
        // Find the vertex with the minimum distance
        int min = INF;
        int minIndex = -1;

        for (int i = 0; i < MAXV; i++) {
            if (S[i] == FALSE && D[i] < min) {
                min = D[i];
                minIndex = i;
            }
        }

        // If no unvisited vertex is found, all reachable vertices have been processed
        if (minIndex != -1) {
            S[minIndex] = TRUE;

            // Update distances to adjacent vertices
            for (int i = 0; i < MAXV; i++) {
                if(D[minIndex] + G[minIndex][i] < D[i]){
                    D[i] = D[minIndex] + G[minIndex][i] ;
                }
            }
        }
    }

    return D;
}

int* dijkstraCompWord(int G[MAXV][MAXV], int start) {
    int* D = (int*)malloc(MAXV * sizeof(int));
    unsigned int S = 0;

    // Initialize distances
    for (int i = 0; i < MAXV; i++) {
        D[i] = G[start][i];
    }
    D[start] = 0;

    // Main loop: Find shortest paths
    for (int remainingVertices = 0; remainingVertices < MAXV; remainingVertices++) {
        // Find the vertex with the minimum distance
        int min = INF;
        int minIndex = -1;
        for (int i = 0; i < MAXV; i++) {
            if ((S & (1<<i)) == FALSE && D[i] < min) {
                min = D[i];
                minIndex = i;
            }
        }

        // If no unvisited vertex is found, all reachable vertices have been processed
        if (minIndex != -1) {
            S|= (1<<minIndex);

            // Update distances to adjacent vertices
            for (int i = 0; i < MAXV; i++) {
                if(D[minIndex] + G[minIndex][i] < D[i]){
                    D[i] = D[minIndex] + G[minIndex][i] ;
                }
            }
        }
    }

    return D;
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