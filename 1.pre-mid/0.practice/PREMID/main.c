#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Data.h"
#include "Stack.h"

bool addProductBaseOnExpiry(Inventory *i, Product p) {
    // To do code logic here.
    if(i->currQty + p.prodQty > 100){
        return false;
    }
    NodePtr store = i->top;
    NodePtr temp = malloc(sizeof(NodeType));
    if(temp == NULL){
    return false;
    }
    temp->prod = p;
    if(isEmpty(*i) || dateDifference(i->top->prod.expiry, p.expiry) < dateDifference(p.expiry, i->top->prod.expiry)){
        temp->link = i->top;
        i->top = temp;
        i->currQty += p.prodQty;
        return true;
    }
    
    
    for(; i->top->link != NULL && dateDifference(i->top->link->prod.expiry, p.expiry) > dateDifference(p.expiry, i->top->link->prod.expiry); i->top = i->top->link){}
    temp->link = i->top->link;
    i->top->link = temp;
    
    
    i->top = store;
    i->currQty += p.prodQty;
    return true;
    
}

int main() {
    ProductList myProd;
    int numCount, selection;

    printf("Enter sequence or selection: (1-6): ");
    scanf("%d", &selection);
    printf("Enter the number of data: ");
    scanf("%d", &numCount);

    createAndPopulate(&myProd, selection, numCount);

    Inventory myInventory;
    initInventory(&myInventory);

    printf("\nORIGINAL PRODUCT:\n");
    for(int i = 0; i < myProd.count; ++i) {
        displayProduct(myProd.prods[i]);
        printf("\n");
    }

    for(int i = 0; i < myProd.count; ++i) {
        printf("\n[%d.] Adding %s (%d): %s\n", i+1, myProd.prods[i].prodName, myProd.prods[i].prodQty, addProductBaseOnExpiry(&myInventory, myProd.prods[i])? "Success":"Fail");
        visualize(myInventory);
    }

    printf("\nUSING ADD PRODUCT:\n");
    visualize(myInventory);


    return 0;
}