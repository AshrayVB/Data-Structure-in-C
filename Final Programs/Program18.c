//Given the marks of n students in a class. Design, Develop and Implement a code using heap data structure to find out the topper of the class.

#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted with node i which is an index in arr[]
void maxHeapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

// Function to build a max heap from an array
void buildMaxHeap(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

// Function to find the topper of the class using heap data structure
int findTopper(int arr[], int n) {
    // Build max heap
    buildMaxHeap(arr, n);

    // Topper is the root of the heap (max heap)
    return arr[0];
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    int marks[n];
    printf("Enter the marks of %d students: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &marks[i]);
    }

    int topper = findTopper(marks, n);
    printf("The topper of the class scored %d marks.\n", topper);

    return 0;
}
