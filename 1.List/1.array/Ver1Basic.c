
#include <stdio.h>

#define MAX 10  // Define the maximum size of the array

// Structure definition
typedef struct {
    int data[MAX];
    int count;
} List;

// Function prototypes
void initList(List* A);
void insertEnd(List* A, int Elem);
void insertFirst(List* A, int Elem);
void insertPos(List* A, int Elem, int Pos);
void deleteElem(List* A, int Elem);
void deleteAtPos(List* A, int Pos);
void deleteAllOccur(List* A, int Elem);
void displayList(const List* A);

// Other operations that Im to lazy to do yet
// InsertSorted()
// InsertUniqueElem()
// bubbleSort()
// selectionSort()
// insertionSort()

int main() {
    List A;
    initList(&A);

    // Example usage of the functions
    insertEnd(&A, 5);
    insertEnd(&A, 10);
    insertFirst(&A, 1);
    insertPos(&A, 7, 2);
    displayList(&A);

    deleteElem(&A, 7);
    deleteAtPos(&A, 1);
    displayList(&A);

    insertEnd(&A, 5);
    deleteAllOccur(&A, 5);
    displayList(&A);

    return 0;
}

// Initialize the list
void initList(List* A) {
    A->count = 0;
}

// Insert an element at the end of the list
void insertEnd(List* A, int Elem) {
    if (A->count < MAX) {
        A->data[A->count++] = Elem;
    } else {
        printf("List is full, cannot insert element.\n");
    }
}

// Insert an element at the beginning of the list
void insertFirst(List* A, int Elem) {
    if (A->count < MAX) {
        for (int i = A->count; i > 0; i--) {
            A->data[i] = A->data[i - 1];
        }
        A->data[0] = Elem;
        A->count++;
    } else {
        printf("List is full, cannot insert element.\n");
    }
}

// Insert an element at a specific position
void insertPos(List* A, int Elem, int Pos) {
    if (Pos < 0 || Pos > A->count || A->count >= MAX) {
        printf("Invalid position or list is full, cannot insert element.\n");
    } else {
        for (int i = A->count; i > Pos; i--) {
            A->data[i] = A->data[i - 1];
        }
        A->data[Pos] = Elem;
        A->count++;
    }
}

// Delete the first occurrence of an element
void deleteElem(List* A, int Elem) {
    int i, found = 0;
    for (i = 0; i < A->count; i++) {
        if (A->data[i] == Elem) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (int j = i; j < A->count - 1; j++) {
            A->data[j] = A->data[j + 1];
        }
        A->count--;
    } else {
        printf("Element not found, cannot delete.\n");
    }
}

// Delete an element at a specific position
void deleteAtPos(List* A, int Pos) {
    if (Pos < 0 || Pos >= A->count) {
        printf("Invalid position, cannot delete element.\n");
    } else {
        for (int i = Pos; i < A->count - 1; i++) {
            A->data[i] = A->data[i + 1];
        }
        A->count--;
    }
}

// Delete all occurrences of an element
void deleteAllOccur(List* A, int Elem) {
    int i = 0;
    while (i < A->count) {
        if (A->data[i] == Elem) {
            deleteAtPos(A, i);  // Reuse the deleteAtPos function
        } else {
            i++;
        }
    }
}

// Display the list
void displayList(const List* A) {
    printf("List: ");
    for (int i = 0; i < A->count; i++) {
        printf("%d ", A->data[i]);
    }
    printf("\n");
}
