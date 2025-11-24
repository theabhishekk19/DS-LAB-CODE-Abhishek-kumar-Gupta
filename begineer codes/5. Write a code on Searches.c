#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;   
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements (sorted for binary search):\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int pos1 = linearSearch(arr, n, key);
    if (pos1 != -1)
        printf("\nLinear Search: Element found at position %d\n", pos1 + 1);
    else
        printf("\nLinear Search: Element not found\n");

    int pos2 = binarySearch(arr, n, key);
    if (pos2 != -1)
        printf("Binary Search: Element found at position %d\n", pos2 + 1);
    else
        printf("Binary Search: Element not found\n");

    return 0;
}
