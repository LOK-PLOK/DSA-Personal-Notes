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
void insertMinHeap(minHeapOrList* heap, edgeType elem);

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

	MST prim = Prims(G,0);
	puts("");
	displayHeap(prim.eList);
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
	for(idx = (LastNdx - 1)/2; idx>= 0; idx--){
		minHeapifySubtree(&heap,idx);
	}
	
	return heap;
}


void insertMinHeap(minHeapOrList* heap, edgeType elem){
    if(heap->lastNdx < MAX_SIZE-1){
        // Insert at end
        heap->edges[++heap->lastNdx] = elem;
        
        // Bubble up
        int curr = heap->lastNdx;
        while(curr > 0 && heap->edges[(curr-1)/2].weight > heap->edges[curr].weight){
            edgeType temp = heap->edges[curr];
            heap->edges[curr] = heap->edges[(curr-1)/2];
            heap->edges[(curr-1)/2] = temp;
            curr = (curr-1)/2;
        }
    }
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
	kruskal.eList.lastNdx=-1;
	minHeapOrList heap = createMinHeap(A);
	int comp[MAX] = {0,1,2,3,4,5};
	int edgeNo;
	int i,j,k;
	for(edgeNo = 1; edgeNo< MAX;){
		edgeType min = deleteMin(&heap);
		int X = min.u;
		int V = min.v;
		if(comp[X] != comp[V]){
			for(i=0;i<MAX;i++){
				if(comp[i] == comp[V]){
					comp[i] = comp[X];
				}
			}

			kruskal.eList.edges[++kruskal.eList.lastNdx] = min;
			kruskal.cost+= min.weight;
			edgeNo++;
		}
	}
	return kruskal;
}

MST Prims(LabelAdjMat A, vertex startV) {
    MST prim;
	prim.cost = 0;
	prim.eList.lastNdx = -1;
	minHeapOrList heap;
	heap.lastNdx = -1;
	int visited[MAX] = {0};

	visited[startV] = 1;
	int i,j,x,y;
	// insert the values of the connected to the starting vertice except infinity
	for(i = 0; i< MAX;i++){
		if(A[startV][i] != INF){
			edgeType temp = {startV,i,A[startV][i]};
			insertMinHeap(&heap,temp);
		}
	}

	int edgeNo = MAX-1;
	while(prim.eList.lastNdx + 1< edgeNo){
		edgeType min = deleteMin(&heap);

		if(visited[min.u] != visited[min.v]){
			prim.eList.edges[++prim.eList.lastNdx] = min;
			prim.cost+= min.weight;

			int notVisited = (visited[min.u] == 0)? min.u:min.v;
			visited[notVisited] = 1;

			for(i=0;i<MAX;i++){
				if(A[notVisited][i] != INF && visited[i] == 0){
					edgeType temp = {notVisited,i,A[notVisited][i]};
					insertMinHeap(&heap,temp);
				}
			}
		}
	}
	return prim;
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


