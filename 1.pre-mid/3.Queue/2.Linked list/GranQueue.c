#include "./header/Queue.h"

/**
 * Make the following programs 
 * void initQueue(); ++
 * bool isEmpty(); ++
 * void displayQ() ++
 * bool enqueue() ++
 * bool dequeue(); ++
 * Data front(); ++
 * void makeNull(); ++
 */

int main(){
    Queue Q;
    system("cls"); //<-- Windows
    // system("clear"); // <-- Linux
    printf("=================================================\n\n");
    printf("initQueue(): \n");
    initQueue(&Q);
    display(Q);
    printf("=================================================\n\n");
    Data examp5 = {23100209,{"Paul France","Detablan"},'M',"BSCS"};
    Data examp1 = {20104115,{"Katsu","Ito"},'M',"BSIS"};
    Data examp4 = {21800581,{"Timothy Andrei","Arevalo"},'M',"BSCS"};
    Data examp2 = {23101255,{"Jan Angeli","Villas"},'F',"BSIT"};
    Data examp3 = {23100244,{"Kenji","Tundag"},'M',"BSIT"};
 
    bool test1 = enqueue(&Q, examp1);
    bool test2 = enqueue(&Q, examp2);
    bool test3 = enqueue(&Q, examp3);
    bool test4 = enqueue(&Q, examp4);
    bool test5 = enqueue(&Q, examp5);
    printf("enqueue(examples 1-5): \n");
    display(Q);
    printf("\n=================================================\n");
    
    printf("front(): \n");
    Data top = front(Q);
    displayData(top);
    printf("\n=================================================\n");

    bool TestDeq = dequeue(&Q);
    printf("dequeue(): \n");
    display(Q);
    printf("\n=================================================\n");
    
    printf("makeNull(): \n");
    makeNull(&Q);
    display(Q);
    printf("\n=================================================\n");
    
    return 0;
}