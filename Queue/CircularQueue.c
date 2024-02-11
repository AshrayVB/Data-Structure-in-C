#include<stdio.h>
#define MAX 6

int Queue[MAX];
int front = -1, rear = -1;

void enqueue(int ele) {
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        Queue[rear] = ele;
    } else if ((rear + 1) % MAX == front) {
        printf("Overflow\n");
    } else {
        rear = (rear + 1) % MAX;
        Queue[rear] = ele;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is Underflow \n");
    } else {
        printf("Dequeued element is %d\n", Queue[front]);
        front = (front + 1) % MAX;
    }
}

void display() {
    int i = front;
    if (front == -1 && rear == -1) {
        printf("Queue is empty \n");
    } else {
        printf("Elements in the queue are: ");
        while (i != (rear + 1) % MAX) {
            printf("%d ", Queue[i]);
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    int choice = 1, c;

    while (1) {
        printf("Enter your choice: 1.Insert 2.Delete 3.Display 4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &c);
                enqueue(c);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
                break; // Added else for better readability
        }
    }

    return 0;
}
