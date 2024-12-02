#include <stdio.h>

#define MAX 23

typedef int LIST[MAX];
typedef enum{TRUE,FALSE}Boolean;

/**
 * Description of the List: The number of elements of the list is stored at index zero
 * and actual elements are stored starting at index 1
 * 
 * Given a sorted list and an element "X", function findElement() will return TRUE if "X" is
 * in the sorted list; otherwise FALSE. The method used in finding the element is Binary Search
 * Technique.
 * 
 */

Boolean findElement1(LIST data,int X);
Boolean findElement2(LIST data,int X);

int main(){
    LIST arr = {10,2,5,8,14,17,19,25,28,36,40};

    Boolean BS1 = findElement1(arr,40);
    Boolean BS2 = findElement2(arr,40);

    printf("%s\n",(BS1 == TRUE)? "TRUE":"FALSE");
    printf("%s\n",(BS2 == TRUE)? "TRUE":"FALSE");
}

/** This is a understandable binary search technique */
Boolean findElement1(LIST data,int X){
    int LB = 1, HB = data[0];
    int MB = (LB+HB)/2;
    while(LB<=HB && data[MB] != X){
        if(X<data[MB]){
            HB = MB-1;
        }else{
            LB = MB+1;
        }
        MB = (LB+HB)/2;
    }

    return (LB<=MB)? TRUE:FALSE;
}

/** While this is still understandable but very simplified to the extreme */
Boolean findElement2(LIST data,int X){
    int LB = 1, HB = data[0],MB = 0;
    while(LB<=HB && data[(MB = (LB+HB)/2)] != X){
        (X<data[MB])? (HB = MB-1):(LB = MB+1);
    }

    return (LB<=HB)? TRUE:FALSE;
}
