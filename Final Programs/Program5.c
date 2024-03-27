//Write a c program to implement priority queue.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a priority queue
struct PriorityQueue {
    int* array;
    int size;
};

// Function to create a priority queue
struct PriorityQueue* createPriorityQueue() {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->array = (int*)malloc(MAX_SIZE * sizeof(int));
    pq->size = 0;
    return pq;
}

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain heap property (upward)
void heapifyUp(struct PriorityQueue* pq, int index) {
    while (index > 0 && pq->array[(index - 1) / 2] < pq->array[index]) {
        swap(&pq->array[(index - 1) / 2], &pq->array[index]);
        index = (index - 1) / 2;
    }
}

// Function to maintain heap property (downward)
void heapifyDown(struct PriorityQueue* pq, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < pq->size && pq->array[left] > pq->array[largest])
        largest = left;
    if (right < pq->size && pq->array[right] > pq->array[largest])
        largest = right;

    if (largest != index) {
        swap(&pq->array[index], &pq->array[largest]);
        heapifyDown(pq, largest);
    }
}

// Function to insert an element into the priority queue
void insert(struct PriorityQueue* pq, int item) {
    if (pq->size == MAX_SIZE) {
        printf("Priority queue is full. Cannot insert.\n");
        return;
    }
    pq->array[pq->size] = item;
    pq->size++;
    heapifyUp(pq, pq->size - 1);
}

// Function to remove and return the maximum element from the priority queue
int extractMax(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority queue is empty. Cannot extract maximum.\n");
        return -1;
    }
    int max = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return max;
}

// Function to get the maximum element from the priority queue without removing it
int getMax(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority queue is empty. No maximum element.\n");
        return -1;
    }
    return pq->array[0];
}

// Function to display the elements of the priority queue
void display(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority queue is empty. No elements to display.\n");
        return;
    }
    printf("Priority Queue elements: ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->array[i]);
    }
    printf("\n");
}

int main() {
    struct PriorityQueue* pq = createPriorityQueue();
    int choice, element;

    do {
        printf("\nPriority Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Extract Max\n");
        printf("3. Get Max\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insert(pq, element);
                break;
            case 2:
                printf("Extracted maximum element: %d\n", extractMax(pq));
                break;
            case 3:
                printf("Maximum element: %d\n", getMax(pq));
                break;
            case 4:
                display(pq);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);
    return 0;
}
