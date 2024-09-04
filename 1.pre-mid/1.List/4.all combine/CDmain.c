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

    printf("\nAssignment Area\n");
    printf("\ninsertSorted is done above\n");
    List SET1;
    List SET2;
    List SET3;
    initList(&SET1);
    initList(&SET2);
    initList(&SET3);
    insertLast(&SET1,&VH, 'A');
    insertLast(&SET1,&VH, 'B');
    insertLast(&SET1,&VH, 'C');
    insertLast(&SET1,&VH, 'D');
    insertLast(&SET2,&VH, 'A');
    insertLast(&SET2,&VH, 'B');
    insertLast(&SET2,&VH, 'C');
    insertLast(&SET2,&VH, 'D');
    insertLast(&SET3,&VH, 'D');
    insertLast(&SET3,&VH, 'C');
    insertLast(&SET3,&VH, 'B');
    insertLast(&SET3,&VH, 'A');

    printf("\nisEqualList(): sorted version \n");
    display(SET1,VH);
    display(SET2,VH);
    display(SET3,VH);

    boolean equal1 = isEqualList(SET1,SET2,VH);
    boolean equal2 = isEqualList(SET1,SET3,VH);

    printf("\n");
    printf("SET1 is %s to SET2\n", (equal1 == TRUE)? "Equal":"Not Equal");
    printf("SET1 is %s to SET3\n", (equal2 == TRUE)? "Equal":"Not Equal");

    displayAvail(VH);
    return 0;
}