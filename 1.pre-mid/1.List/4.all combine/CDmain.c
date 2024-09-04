#include "./header/3.cursor-based.h"

int main(){
    List test;
    VirtualHeap VH;

    system("cls");
    printf("initList(): \n");
    initVH(&VH);
    initList(&test);
    display(test, VH);

    printf("\ninsertFirst(D,B,A): \n");
    insertFirst(&test,&VH,'D');
    insertFirst(&test,&VH,'B');
    insertFirst(&test,&VH,'A');
    display(test, VH);

    printf("\ninsertLast(E,F): \n");
    insertLast(&test,&VH,'E');
    insertLast(&test,&VH,'F');
    display(test, VH);

    printf("\ninsertSorted(C): \n");
    insertSorted(&test,&VH,'C');
    display(test, VH);

    printf("\ninsertAtPost(elem: F, post: 2): \n");
    insertAtPost(&test,&VH,'F',2);
    display(test, VH);

    printf("\nfindElem(B): \n");
    boolean isMember = findElem(test, VH, 'B');
    printf("%s", (isMember == TRUE)? "In List\n": "Not in List\n");
    display(test, VH);

    printf("\ndeleteElem(F): \n");
    deleteElem(&test, &VH,'F');
    display(test, VH);

    clean(&test,&VH);
    printf("\nInsertLast(A,B,B,A,A,B,A,B,A,A): \n");
    insertLast(&test, &VH, 'A');
    insertLast(&test, &VH, 'B');
    insertLast(&test, &VH, 'B');
    insertLast(&test, &VH, 'A');
    insertLast(&test, &VH, 'A');
    insertLast(&test, &VH, 'B');
    insertLast(&test, &VH, 'A');
    insertLast(&test, &VH, 'B');
    insertLast(&test, &VH, 'A');
    insertLast(&test, &VH, 'A');
    display(test, VH);

    printf("\ndeleteAllOccur(A): \n");
    deleteAllOccur(&test, &VH, 'A');
    display(test, VH);

    clean(&test, &VH);

    // printf("\nAssignment Area\n");
    // printf("\ninsertSorted is done above\n");
    // List SET1;
    // List SET2;
    // initList(&SET1);
    // initList(&SET2);
    // insertLast(&SET1, 'A');
    // insertLast(&SET1, 'B');
    // insertLast(&SET1, 'C');
    // insertLast(&SET1, 'D');
    // insertLast(&SET2, 'A');
    // insertLast(&SET2, 'B');
    // insertLast(&SET2, 'C');
    // insertLast(&SET2, 'D');

    // printf("\nisEqualList(): sorted version \n");
    // display(SET1);
    // display(SET2);

    // boolean equal = isEqualList(SET1,SET2);

    return 0;
}