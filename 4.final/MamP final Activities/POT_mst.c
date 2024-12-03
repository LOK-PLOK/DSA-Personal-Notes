#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX 6
#define INF 999
typedef int vertex;
typedef int LabelAdjMat[MAX][MAX];
typedef struct {
	int u,v; // representing edge (u,v)
	int weight;
}edgeType;

#define MAX_SIZE 20
typedef struct {
	edgeType edges[MAX_SIZE];
	int lastNdx;
}minHeapOrList;

typedef struct {
	minHeapOrList eList;
	int cost;
}MST; // Prim's or Kruskal's

void displayAdjMatrix(LabelAdjMat Matrix);
minHeapOrList createMinHeap(LabelAdjMat G);

void minHeapifySubtree(minHeapOrList* heap,int idx); 
void displayHeap(minHeapOrList heap);
edgeType deleteMin(minHeapOrList* heap);
MST Kruskals(LabelAdjMat A);
MST Prims(LabelAdjMat A, vertex startV);

int main(){
	LabelAdjMat G = {
		{INF,   1,   5,   4,   6,   5},
        {  1, INF,   5, INF, INF,   6},
        {  5,   5, INF,   2, INF, INF},
        {  4, INF,   2, INF,   1, INF},
        {  6, INF, INF,   1, INF,   3},
        {  5,   6, INF, INF,   3, INF},
//			{INF,2,INF,8,INF,INF},
//			{2,INF,INF,5,6,INF},
//			{INF,INF,INF,INF,9,3},
//			{8,5,INF,INF,3,2},
//			{INF,6,9,3,INF,1},
//			{INF,INF,3,2,1,INF},
	};
	
	
	displayAdjMatrix(G);
	minHeapOrList heap = createMinHeap(G);
	displayHeap(heap);
	
	MST kruskal = Kruskals(G);
	puts("");
	displayHeap(kruskal.eList);

	// MST prim = Prims(G,0);
	// puts("");
	// displayHeap(prim.eList);
} 

minHeapOrList createMinHeap(LabelAdjMat G){
	minHeapOrList heap;
	heap.lastNdx  = -1;
	int i,j,idx;
	for(i = 0; i< MAX; i++){
		for(j=i + 1;j<MAX;j++){
			if(G[i][j] != INF){
				heap.edges[++heap.lastNdx].u = i;
				heap.edges[heap.lastNdx].v = j;
				heap.edges[heap.lastNdx].weight = G[i][j];
			}
		}
	}
	
	int LastNdx = heap.lastNdx;
	for(idx = (LastNdx - 1)/2; idx> 0; idx--){
		minHeapifySubtree(&heap,idx);
	}
	
	return heap;
}

void minHeapifySubtree(minHeapOrList* heap,int parent){
	int small = parent;
	int LC = parent * 2 + 1;
	int RC = LC + 1;
	
	if(LC <= heap->lastNdx && heap->edges[LC].weight <= heap->edges[small].weight){
		small = LC;
	}
	
	if(RC <= heap->lastNdx && heap->edges[RC].weight <= heap->edges[small].weight){
		small = RC;
	}
	
	
	if(small != parent){
		edgeType temp = heap->edges[small];
		heap->edges[small] = heap->edges[parent];
		heap->edges[parent] = temp;
		minHeapifySubtree(heap,small);
	}
}

edgeType deleteMin(minHeapOrList* heap){
	
	edgeType returnVal = {-1,-1,INF};
	if(heap->lastNdx != -1){
		returnVal = heap->edges[0];
		heap->edges[0] = heap->edges[heap->lastNdx];
		heap->edges[heap->lastNdx--] = returnVal;
		
		minHeapifySubtree(heap,0);
	}
	return returnVal;
}

MST Kruskals(LabelAdjMat A){
	MST kruskal;
	kruskal.cost = 0;
	kruskal.eList.lastNdx = -1;
	minHeapOrList heap = createMinHeap(A);
	int comp[MAX] = {0,1,2,3,4,5};
	int edgeCount,i;
	for(edgeCount = 1; edgeCount< MAX;){
		edgeType min = deleteMin(&heap);
		int uVal = comp[min.u];
		int vVal = comp[min.v];
		if(uVal != vVal){
			kruskal.eList.edges[++kruskal.eList.lastNdx] = min;
			kruskal.cost+= min.weight;
			for(i=0;i<MAX;i++){
				if(comp[i] == vVal){
					comp[i] = uVal;
				}
			}
			edgeCount++;
		}
	}
	return kruskal;
}

MST Prims(LabelAdjMat A, vertex startV) {
    // To be continued
}

void displayAdjMatrix(LabelAdjMat Matrix){
    int row,col;
    puts("");
    printf("    ");
    for (row = 0; row < MAX; row++) {
        printf("%d ", row);
    }
    puts("");
    for(row=0;row <MAX;row++){
        printf("%d | ",row);
        for(col = 0; col <MAX;col++){
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

void displayHeap(minHeapOrList heap){
	int i, cost=0;
	for(i = 0; i<= heap.lastNdx; i++){
		printf("%d: (%d,%d) => %d\n",i,heap.edges[i].u,heap.edges[i].v,heap.edges[i].weight);
		cost+=heap.edges[i].weight;
	}
	
	printf("total cost: %d \n\n",cost);
}


