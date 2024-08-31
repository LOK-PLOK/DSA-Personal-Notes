#include "./header/CBfunc.h"

int main(){
    List L;
    virtualHeap VH;

    initialize(&L,&VH);

    printf("insertFirst(1,2,3): \n");
    insertFirst(&L,&VH,1);
    insertFirst(&L,&VH,2);
    insertFirst(&L,&VH,3);
    display(L,VH);

    printf("\ninserLast(8,5,7): \n");
    insertLast(&L,&VH,8);
    insertLast(&L,&VH,5);
    insertLast(&L,&VH,7);
    display(L,VH);

    printf("\ndelete(1): \n");
    delete(&L,&VH,1);
    display(L,VH);

    printf("\ndelete(1): \n");
    clean(&L,&VH);
    display(L,VH);

    printf("\ninsertLast(1,2,2,1,1,1,2,1,1,1): \n");
    insertLast(&L,&VH,1);
    insertLast(&L,&VH,2);
    insertLast(&L,&VH,2);
    insertLast(&L,&VH,1);
    insertLast(&L,&VH,1);
    insertLast(&L,&VH,1);
    insertLast(&L,&VH,2);
    insertLast(&L,&VH,1);
    insertLast(&L,&VH,1);
    insertLast(&L,&VH,1);
    insertLast(&L,&VH,1);
    display(L,VH);

    printf("\ndeleteAllOccur(1): \n");
    deleteAllOccur(&L,&VH,1);
    display(L,VH);

    
    return 0;
}

