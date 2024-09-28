#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    char elem[MAX];
    int top;
}Stack;

Stack initStack();
void displayStack(Stack A);
void displayStackV2(Stack* A);
char topElem(Stack A);
bool isEmpty(Stack A);
bool isFull(Stack A);

void Push(Stack* A, char elem);
void Pop(Stack* A);

bool isValid(Stack A);

int main(){
    system("cls");
    Stack test1 = initStack();
    Push(&test1, ')');
    Push(&test1, '(');
    printf("Test Case 1: ");
    displayStack(test1);
    printf("isValid(): %s\n\n",isValid(test1)? "TRUE":"FALSE");

    Stack test2 = initStack();
    Push(&test2,']');
    Push(&test2,'[');
    Push(&test2,'}');
    Push(&test2,'{');
    Push(&test2,')');
    Push(&test2,'(');
    printf("Test Case 2: ");
    displayStack(test2);
    printf("isValid(): %s\n\n",isValid(test2)? "TRUE":"FALSE");

    Stack test3 = initStack();
    Push(&test3,'}');
    Push(&test3,'(');
    printf("Test Case 3: ");
    displayStack(test3);
    printf("isValid(): %s\n\n",isValid(test3)? "TRUE":"FALSE");

    Stack test4 = initStack();
    Push(&test4, ')');
    Push(&test4, ']');
    Push(&test4, '[');
    Push(&test4, '(');
    printf("Test Case 4: ");
    displayStack(test4);
    printf("isValid(): %s\n\n",isValid(test4)? "TRUE":"FALSE");
    

    return 0;
}

Stack initStack(){
    Stack temp;
    temp.top = -1;
    return temp;
}

void Push(Stack* A, char elem){
    if(isFull(*A) != 1){
        A->elem[++A->top] = elem;
    } 
}

void Pop(Stack* A){
    if(isEmpty(*A) != 1){
        A->top--;
    }
}

char topElem(Stack A){
    return (A.top != -1)? A.elem[A.top]: '-';
}

bool isEmpty(Stack A){
    return (A.top == -1)? 1:0;
}
bool isFull(Stack A){
    return (A.top == MAX -1)? 1:0;
}

void displayStack(Stack A){
    if(!isEmpty(A)){
        Stack temp = initStack();

        while(A.top != -1){
            printf("%c ",A.elem[A.top]);
            Push(&temp, A.elem[A.top]);
            Pop(&A);
        }

        while(temp.top != -1){
            Push(&A, temp.elem[temp.top]);
            Pop(&temp);
        }

        printf("\n");
    }else{
        printf("Empty\n");
    }
    
}

void displayStackV2(Stack* A){
    int top = A->top;
    while(!isEmpty(*A)){
        printf("%c ",A->elem[A->top]);
        A->top -= 1;
    }
    A->top = top;
}

bool isValid(Stack A){
    Stack temp = initStack(); 
    char topChar;

    while (!isEmpty(A)) {
        char current = A.elem[A.top];
        
        if (current == '(' || current == '{' || current == '[') {
            Push(&temp, current);
        }else if (current == ')' || current == '}' || current == ']') {

            if (isEmpty(temp)) {
                return false; 
            }
            
            topChar = topElem(temp);
            if ((current == ')' && topChar != '(') || (current == '}' && topChar != '{') || (current == ']' && topChar != '[')) {
                return false; 
            }
            Pop(&temp); 
        }
        
        Pop(&A); 
    }

    return isEmpty(temp); 
}
