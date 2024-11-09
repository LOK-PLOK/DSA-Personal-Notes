#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int size ,int x) {
    int LB = 0, HB = size -1, MB = 0;
    while(LB <= HB && arr[(MB = (LB + HB) / 2)] != x) {
        if(arr[MB] < x) {
            LB = MB + 1;
        } else {
            HB = MB - 1;
        }
    }
    return (LB <= HB) ? MB : -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr,n, x);
    (result == -1) ? printf("Element is not present in array\n") : printf("Element is present at index %d\n", result);
}