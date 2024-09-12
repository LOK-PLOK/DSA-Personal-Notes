#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *elem;
    int count;
    int max;
}Set;

typedef char Set;

Set createSet(int max);
void initSet(Set* S, int max);
bool addElem(Set* S, int elem);
bool removeElem(Set* S, int elem);
void displaySet(Set S);
bool isElem(Set S, int elem);
bool isSubset(Set A, Set B);

Set UnionSet(Set A, Set B);
Set Intersect(Set A, Set B);
Set DifferenceSet(Set A, Set B);
Set symmetricDifference(Set A, Set B);


/**
 * 
 * take into account into different maxes
 */

