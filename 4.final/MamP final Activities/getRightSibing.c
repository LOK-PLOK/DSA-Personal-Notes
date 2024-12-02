#include <stdio.h>

#define TSIZE 10
typedef int Node;
typedef struct {
    Node parent;
    char label;
}TNode;

typedef TNode PTree[TSIZE];

/**
 * Given the node and the tree, function getRightSibling() will return to the calling function
 * the label of the right sibling of the given node. If the right sibling does note exist,
 * return a non-alphanumeric value e.g("#,&,!,@,$")
 * 
 * write the code of function getRightSibling().
 * Constraint: 1 return statement only, no break/exit statement.
 */

char getRightSibling(PTree tree, Node node);

/* Tree Illustration
                    A
                 /     \
               B         C
             /   \      /  \
            D    E     F    G
           / \  / 
          H  I  J
*/
int main(){

    PTree tree = {
        { -1, 'A' }, 
        { 0, 'B' },  
        { 0, 'C' },  
        { 1, 'D' },  
        { 1, 'E' },  
        { 2, 'F' },     
        { 2, 'G' },     
        { 3, 'H' },  
        { 3, 'I' },  
        { 4, 'J' }   
    };

    
    char rightLabel = getRightSibling(tree, 7);
    puts("");
    printf("%c",rightLabel);
    puts("");
    puts("");
    return 0;
}

//Perting sayona ra diay
char getRightSibling(PTree tree, Node node){
    Node rightSibling = -1;
    int i;
    for(i=node+1; i < TSIZE; i++){
        if(tree[i].parent == tree[node].parent){
            rightSibling = i;
        }
    }

    return(rightSibling != -1)? tree[rightSibling].label:'#';
}