#include "strucDef.h"

void initAdjMatrix(Adj_M Matrix);
void displayAdjMatrix(Adj_M Matrix);
void addEdge(int row,int col,Adj_M Matrix);
            
int main(){
    Adj_M Matrix;
    initAdjMatrix(Matrix);

    addEdge(0,1,Matrix);
    addEdge(0,3,Matrix);
    addEdge(0,5,Matrix);
    addEdge(1,4,Matrix);
    addEdge(2,4,Matrix);
    addEdge(2,3,Matrix);
    addEdge(3,5,Matrix);
    displayAdjMatrix(Matrix);
    return 0;
}

void initAdjMatrix(Adj_M Matrix){
    int row,col;
    for(row = 0; row<MAXV; row++){
        for(col = 0; col < MAXV; col++){
            (row == col)? (Matrix[row][col] = INF):(Matrix[row][col] = 0);
        }
    }
}

void addEdge(int row,int col,Adj_M Matrix){
    Matrix[row][col] = 1;
    Matrix[col][row] = 1;
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
