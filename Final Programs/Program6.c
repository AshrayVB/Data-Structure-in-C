//Write C Program to implement Double Ended Queue

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a double ended queue
struct Deque {
    int* array;
    int front, rear;
    int capacity;
};

// Function prototypes
struct Deque* createDeque(int capacity);
int isFull(struct Deque* deque);
int isEmpty(struct Deque* deque);
void insertFront(struct Deque* deque, int item);
void insertRear(struct Deque* deque, int item);
void deleteFront(struct Deque* deque);
void deleteRear(struct Deque* deque);
int getFront(struct Deque* deque);
int getRear(struct Deque* deque);
void display(struct Deque* deque); // New function prototype

// Function to create a double ended queue
struct Deque* createDeque(int capacity) {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->capacity = capacity;
    deque->front = -1;
    deque->rear = 0;
    deque->array = (int*)malloc(deque->capacity * sizeof(int));
    return deque;
}

// Function to check if the deque is full
int isFull(struct Deque* deque) {
    return ((deque->front == 0 && deque->rear == deque->capacity - 1) ||
            deque->front == deque->rear + 1);
}

// Function to check if the deque is empty
int isEmpty(struct Deque* deque) {
    return deque->front == -1;
}

// Function to add an element to the front of the deque
void insertFront(struct Deque* deque, int item) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert at front.\n");
        return;
    }
    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0)
        deque->front = deque->capacity - 1;
    else
        deque->front = deque->front - 1;
    deque->array[deque->front] = item;
    printf("%d inserted at front.\n", item);
}

// Function to add an element to the rear of the deque
void insertRear(struct Deque* deque, int item) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert at rear.\n");
        return;
    }
    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->rear == deque->capacity - 1)
        deque->rear = 0;
    else
        deque->rear = deque->rear + 1;
    deque->array[deque->rear] = item;
    printf("%d inserted at rear.\n", item);
}

// Function to remove an element from the front of the deque
void deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from front.\n");
        return;
    }
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->front == deque->capacity - 1)
        deque->front = 0;
    else
        deque->front = deque->front + 1;
}

// Function to remove an element from the rear of the deque
void deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from rear.\n");
        return;
    }
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->rear == 0)
        deque->rear = deque->capacity - 1;
    else
        deque->rear = deque->rear - 1;
}

// Function to get the front element of the deque without removing it
int getFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. No front element.\n");
        return -1;
    }
    return deque->array[deque->front];
}

// Function to get the rear element of the deque without removing it
int getRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. No rear element.\n");
        return -1;
    }
    return deque->array[deque->rear];
}

// Function to display the elements of the deque
void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. No elements to display.\n");
        return;
    }
    printf("Deque elements: ");
    int i = deque->front;
    while (1) {
        printf("%d ", deque->array[i]);
        if (i == deque->rear)
            break;
        i = (i + 1) % deque->capacity;
    }
    printf("\n");
}

int main() {
    struct Deque* deque = createDeque(MAX_SIZE);
    int choice, element;

    do {
        printf("\nDouble Ended Queue (Deque) Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at front: ");
                scanf("%d", &element);
                insertFront(deque, element);
                break;
            case 2:
                printf("Enter element to insert at rear: ");
                scanf("%d", &element);
                insertRear(deque, element);
                break;
            case 3:
                deleteFront(deque);
                printf("Deleted element from front.\n");
                break;
            case 4:
                deleteRear(deque);
                printf("Deleted element from rear.\n");
                break;
            case 5:
                display(deque);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.");
        }
    } while (choice != 5);
    return 0;
}
