#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 20
/**
 * Open hashing: 
 * Closed hashing: 
 * 
 */

typedef struct {
  int studID;
  char studName[30];
  char program[10];
  int year;
}Student;

typedef struct node {
  Student stud;
  struct node *link;
}NodeType, *NodePtr;

typedef struct {
  NodePtr elems[MAX];
  int count;
}HashTable;

/**
 * Get the hash based on the summation of the first 3 letters of the name plus the letters in the program and must be able to return a value from 0 -19
 */
int getHash(Student s);
void initDictionary(HashTable *ht);
Student createStudent(char *name, char *course, int id, int year);

/**
 * Use insert sorted if multiple data are already in the list
 */
int insert(HashTable *ht, Student s);
int delete(HashTable *ht, Student s);
void visualizeTable(HashTable ht);

int main(){
    HashTable D;
    initDictionary(&D);

    printf("\n\n");
    visualizeTable(D);

    Student examp1 = createStudent("Paul France M. Detablan", "BSCS", 23100209, 2);
    Student examp2 = createStudent("Luis Andrei E. Ouano", "BSCS", 23100210, 2);
    Student examp3 = createStudent("Kentward M. Maratas", "BSCS", 23100211, 2);
    Student examp4 = createStudent("Andrei A. Arevalo", "BSCS", 23100208, 1);
    insert(&D,examp1);
    insert(&D,examp2);
    insert(&D,examp3);
    insert(&D,examp4);
    printf("\n\n");
    visualizeTable(D);

    delete(&D,examp3);
    printf("\n\n");
    visualizeTable(D);

    return 0;
}

// create function definitions here
void initDictionary(HashTable *ht){
    ht->count =0;
    int i;
    for(i=0;  i<MAX; i++){
        ht->elems[i] = NULL;
    }
}

int getHash(Student s){
    int nameSum = s.studName[0] + s.studName[1] + s.studName[2];
    int courseSum = 0;
    for(int i=0; s.program[i] != '\0'; i++){
        courseSum += s.program[i];
    }

    return (nameSum + courseSum) % MAX;
}

Student createStudent(char *name, char *course, int id, int year){
    Student temp;
    temp.studID = id;
    temp.year = year;
    strcpy(temp.studName,name);
    strcpy(temp.program,course);

    return temp;
}

int insert(HashTable *ht, Student s){
    int start = getHash(s);
    NodePtr* trav, temp;
    for(trav = &ht->elems[start]; *trav != NULL && (*trav)->stud.studID < s.studID; trav = &(*trav)->link){}

    if(*trav != NULL && (*trav)->stud.studID == s.studID){
        return 0;
    }

    temp = (NodePtr)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->stud = s;
        temp->link = *trav;
        *trav = temp;
        ht->count++;
        return 1;
    }

    return 0;
}

int delete(HashTable *ht, Student s){
    int start = getHash(s);
    NodePtr* trav, temp;
    for(trav = &ht->elems[start]; *trav != NULL && (*trav)->stud.studID != s.studID; trav = &(*trav)->link){}

    if(*trav != NULL){
        temp = *trav;
        *trav = temp->link;
        free(temp);
        ht->count--;
        return 1;
    }
    return 0;
}

void visualizeTable(HashTable ht){
    int i;
    NodePtr trav;
    for(i=0 ;i<MAX;i++){
        printf("%d: ",i);
        for(trav = ht.elems[i]; trav != NULL; trav=trav->link){
            printf("%s ==> ", trav->stud.studName);
        }
        printf("NULL\n");
    }
}
