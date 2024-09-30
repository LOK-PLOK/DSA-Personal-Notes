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