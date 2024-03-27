//Given the salary of n employees of an organization. Design, Develop and Implement a code using heap data structure to find out the employee who draws the less salary in the
//organization.

#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted with node i which is an index in arr[]
void minHeapify(int arr[], int n, int i) {
    int smallest = i; // Initialize smallest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        // Recursively heapify the affected sub-tree
        minHeapify(arr, n, smallest);
    }
}

// Function to build a min heap from an array
void buildMinHeap(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

// Function to find the employee who draws the least salary in the organization using heap data structure
int findLeastSalaryEmployee(int arr[], int n) {
    // Build min heap
    buildMinHeap(arr, n);

    // Least salary employee is the root of the heap (min heap)
    return arr[0];
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    int salaries[n];
    printf("Enter the salaries of %d employees: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &salaries[i]);
    }

    int leastSalaryEmployee = findLeastSalaryEmployee(salaries, n);
    printf("The employee who draws the least salary in the organization earns %d.\n", leastSalaryEmployee);

    return 0;
}
