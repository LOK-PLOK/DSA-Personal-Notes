/**
 * TODO: Array, Linked List Implementation and Curso based Example
 * 
 * Important: cursor based is different .c file
 */

#include "./header/1.array.h"
// #include "./header/2.LinkedList.h"

int main(){
    system("cls");
    List test;
    printf("initList(): \n");
    initList(&test);
    display(test);


    printf("\ninsertFirst(D,B,A): \n");
    insertFirst(&test,'D');
    insertFirst(&test,'B');
    insertFirst(&test,'A');
    display(test);

    printf("\ninsertLast(E,F): \n");
    insertLast(&test,'E');
    insertLast(&test,'F');
    display(test);
    
    printf("\ninsertSorted(C): \n");
    insertSorted(&test, 'C');
    display(test);

    printf("\ninsertAtPos(elem: F, pos: 2): \n");
    insertAtPos(&test,'F', 2);
    display(test);


    printf("\nfindElem(B): \n");
    boolean isMember = findElem(test, 'B');
    printf("%s", (isMember == TRUE)? "In List\n": "Not in List\n");
    display(test);

    printf("\ndeleteElem(F): \n");
    deleteElem(&test,'F');
    display(test);

    clean(&test);
    printf("\nInsertLast(A,B,B,A,A,B,A,B,A,A): \n");
    insertLast(&test,'A');
    insertLast(&test,'B');
    insertLast(&test,'B');
    insertLast(&test,'A');
    insertLast(&test,'A');
    insertLast(&test,'B');
    insertLast(&test,'A');
    insertLast(&test,'B');
    insertLast(&test,'A');
    insertLast(&test,'A');
    display(test);


    printf("\ndeleteAllOccur(A): \n");
    deleteAllOccur(&test, 'A');
    display(test);

    clean(&test);

    
    printf("\nAssignment Area\n");
    printf("\ninsertSorted is done above\n");
    List SET1;
    List SET2;
    List SET3;
    initList(&SET1);
    initList(&SET2);
    initList(&SET3);
    insertLast(&SET1, 'A');
    insertLast(&SET1, 'B');
    insertLast(&SET1, 'C');
    insertLast(&SET1, 'D');
    insertLast(&SET2, 'A');
    insertLast(&SET2, 'B');
    insertLast(&SET2, 'C');
    insertLast(&SET2, 'D');
    insertLast(&SET3, 'D');
    insertLast(&SET3, 'C');
    insertLast(&SET3, 'B');
    insertLast(&SET3, 'A');

    printf("\nisEqualList(): sorted version \n");
    display(SET1);
    display(SET2);
    display(SET3);


    boolean equal1 = isEqualList(SET1,SET2);
    boolean equal2 = isEqualList(SET1,SET3);

    printf("\n");
    printf("SET1 is %s to SET2\n", (equal1 == TRUE)? "Equal":"Not Equal");
    printf("SET1 is %s to SET3\n", (equal2 == TRUE)? "Equal":"Not Equal");
    
    return 0;
}