#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// return TRUE if ang Queue kay in asceding order based from ID
// isAscending(); functions accepts a list ang returns TRUE if ASCENDING and False if otherwise

typedef enum{TRUE, FALSE}boolean;

typedef struct {
    char fName[24];
    char lName[16];
}Name;

typedef struct {
    unsigned int ID;
    Name name;
    // naapatoy uban pero ID importante
}Element;

typedef struct node{
    Element stud;
    struct node* link;
}*qptr;

typedef struct {
    qptr front;
    qptr rear;
    int count;
}Queue;


void initQueue(Queue* Q);
boolean isEmpty(Queue Q);
Element front(Queue Q);
void enqueue(Queue* Q, Element stud);
void dequeue(Queue* Q);
void populateQ(Queue* Q,Element studs[], int size);
void displayQueue(Queue* Q);

boolean isAscending(Queue* Q);
boolean isAscendingV2(Queue* Q);
boolean isAscendingV3(Queue Q);

int main(){
    Queue Q;
    initQueue(&Q);

    Element stud1 = {1111,{"Paul","Detablan"}};
    Element stud2 = {2222,{"Luis","Ouano"}};
    Element stud3 = {3333,{"Kentward","Maratas"}};
    Element stud4 = {4444,{"Earl","Rondina"}};
    Element stud5 = {5555,{"Destin","Ecarma"}};
    Element stud6 = {6666,{"Zues","Elderfield"}};
    // Element studs[] = {stud1,stud2,stud3,stud4,stud5,stud6}; //checker for TRUE
    Element studs[] = {stud1,stud2,stud3,stud4,stud6,stud5};  // checker for FALSE
    populateQ(&Q,studs,6);
    displayQueue(&Q);

    // printf("isAscending(): %s\n", (isAscending(&Q) == TRUE)? "TRUE":"FALSE");
    // printf("isAscending(): %s\n", (isAscendingV2(&Q) == TRUE)? "TRUE":"FALSE");
    printf("isAscending(): %s\n", (isAscendingV3(Q) == TRUE)? "TRUE":"FALSE");
}

void initQueue(Queue* Q){
    Q->count = 0;
    Q->front = NULL;
    Q->rear = NULL;
}

boolean isEmpty(Queue Q){
    return(Q.count == 0)? TRUE: FALSE;
}

Element front(Queue Q){
    Element dummy = {0000,{"Xxxx","Xxxx"}};
    return (isEmpty(Q)== FALSE)? Q.front->stud:dummy; 
}

void enqueue(Queue* Q, Element stud){
    qptr temp = (qptr)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->stud = stud;
        temp->link = NULL;
        if(Q->front == NULL){
            Q->front = temp;
        }else{
            Q->rear->link = temp;
        }
        Q->rear = temp;
        Q->count++;
    }
}

void dequeue(Queue* Q){
    if(isEmpty(*Q) == FALSE){
        qptr temp = Q->front;
        Q->front = temp->link;
        if(Q->front == NULL){
            Q->rear = NULL;
        }
        free(temp);
        Q->count--;
    }
}

void populateQ(Queue* Q,Element studs[], int size){
    int i;
    for(i=0;i<size;i++){
        enqueue(Q,studs[i]);
    }
}

void displayQueue(Queue* Q){
    Queue temp;
    initQueue(&temp);

    for (; isEmpty(*Q) == FALSE; dequeue(Q)) {
        printf("ID: %d\n", Q->front->stud.ID);
        printf("Name: %s %s\n\n", Q->front->stud.name.lName, Q->front->stud.name.fName);
        enqueue(&temp, Q->front->stud);
    }

    for (; isEmpty(temp) == FALSE; dequeue(&temp)) {
        enqueue(Q, temp.front->stud);
    }
}

// using user-defined functions
boolean isAscending(Queue* Q){
    Queue temp;
    initQueue(&temp);
    Element prevStud = Q->front->stud;
    enqueue(&temp,prevStud);
    dequeue(Q);

    boolean check = TRUE;

    while(isEmpty(*Q) == FALSE && Q->front->stud.ID > prevStud.ID){
        prevStud = Q->front->stud;
        enqueue(&temp,prevStud);
        dequeue(Q);
    }

    if(isEmpty(*Q) == FALSE){
        check = FALSE;
    }

    while(isEmpty(temp)== FALSE){
        enqueue(Q,temp.front->stud);
        dequeue(&temp);
    }

    return check;
}

// without using user-defined functions
boolean isAscendingV2(Queue* Q) {
    Queue temp;
    temp.count = 0;
    temp.front = NULL;
    temp.rear = NULL;

    Element prevStud = Q->front->stud;

    temp.front = Q->front;
    temp.rear = Q->front;
    temp.front->link = NULL; 
    temp.count++;
    
    qptr removedNode = Q->front; 
    Q->front = Q->front->link; 
    Q->count--;
    free(removedNode); 

    boolean check = TRUE; 

    while (Q->front != NULL && Q->front->stud.ID > prevStud.ID) {
        prevStud = Q->front->stud;
        temp.rear->link = Q->front; 
        temp.rear = Q->front; 
        temp.rear->link = NULL; 
        temp.count++;

        removedNode = Q->front;
        Q->front = Q->front->link; 
        Q->count--;
        free(removedNode); 
    }

    if (Q->front != NULL) {
        check = FALSE; 
    }

    while (temp.front != NULL) {
        enqueue(Q, temp.front->stud);
        removedNode = temp.front;
        temp.front = temp.front->link; 
        temp.count--;
        free(removedNode); 
    }

    return check; 
}

//using front to move
boolean isAscendingV3(Queue Q){
    Element prevStud = Q.front->stud;
    Q.front = Q.front->link;
    Q.count--;

    while(Q.count != 0 && Q.front->stud.ID > prevStud.ID){
        prevStud = Q.front->stud;
        Q.front = Q.front->link;
        Q.count--;
    }

    return (Q.count == 0)? TRUE: FALSE;
}
