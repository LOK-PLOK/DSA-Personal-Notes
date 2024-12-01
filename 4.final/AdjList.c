#include "strucDef.h"

void initLabelAdjList(AdjListLL* List);
void displayAdjList(AdjListLL List);
void insertToAdjList(AdjListLL* List,int data[][MAXV],int size);
void insert(AdjListLL* List,int row,int col);

int main(){
    AdjListLL List;
    initLabelAdjList(&List);

    int graphUndirected[MAXV][MAXV] = {
        {INF,1,0,1,0,1},
        {1,INF,0,0,1,0},
        {0,0,INF,1,1,0},
        {1,0,1,INF,0,1},
        {0,1,1,0,INF,0},
        {1,0,0,1,0,INF}
    };

    insertToAdjList(&List,graphUndirected,MAXV);
    displayAdjList(List);

    return 0;
}

void initLabelAdjList(AdjListLL* List){
    int i;
    for(i=0;i<MAXV;i++){
        List->head[i] = NULL;
    }
    List->edgeCount = 0;
}

void insert(AdjListLL* List,int row,int col){
    int i;
    vert *trav,temp;
    //loop 3
    for(trav = &List->head[row]; *trav != NULL; trav = &(*trav)->next){}
    temp = (vert)malloc(sizeof(struct nodeV));
    if(temp != NULL){
        temp->v = col;
        temp->next = *trav;
        *trav = temp;
    }
}

void insertToAdjList(AdjListLL* List,int data[][MAXV],int size){
    int row,col;
    //loop 1
    for(row = 0; row < size; row++){
        //loop 2
        for(col = 0; col < size; col++){
            if(data[row][col] != 0 && data[row][col] != INF){
                insert(List,row,col);
            }
        }
    }
}

void displayAdjList(AdjListLL List){
    vert trav;
    int i;
    for(i = 0; i < MAXV; i ++){
        printf("%d: ", i);
        for(trav = List.head[i]; trav != NULL; trav = trav->next){
            printf("%d --> ",trav->v);
        }
        printf("NULL\n");
    }

    puts("");
}