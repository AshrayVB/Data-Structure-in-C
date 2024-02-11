#include<stdio.h>
#define Max 5

// Structure to represent an element with priority
struct PriorityElement {
    int data;
    int priority;
};

struct PriorityElement Q[Max];
int r = -1, f = 0;

void enqueue(int element, int priority);
struct PriorityElement dequeue();
void display();

int main() {
    int element, priority, choice = 0;
    while (choice != 4) {
        printf("Enter choice 1.Enqueue 2.Dequeue 3.Display 4.Exit \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(element, priority);
                break;
            case 2:
                struct PriorityElement de_element = dequeue();
                if (de_element.data != -1) {
                    printf("%d with priority %d is dequeued\n", de_element.data, de_element.priority);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid input \n");
        }
    }

    return 0;
}

// Enqueue with priority
void enqueue(int element, int priority) {
    if (r == Max - 1) {
        printf("Overflow\n");
    } else {
        r++;
        Q[r].data = element;
        Q[r].priority = priority;
    }
}

// Dequeue based on priority
struct PriorityElement dequeue() {
    struct PriorityElement data;
    if (f > r) {
        printf("Underflow\n");
        data.data = -1;
        return data; // Return a special value or handle underflow condition
    } else {
        // Find the element with the highest priority
        int highestPriorityIdx = f;
        for (int i = f + 1; i <= r; i++) {
            if (Q[i].priority < Q[highestPriorityIdx].priority) {
                highestPriorityIdx = i;
            }
        }

        // Dequeue the element with the highest priority
        data = Q[highestPriorityIdx];

        // Shift the remaining elements to fill the gap
        for (int i = highestPriorityIdx; i < r; i++) {
            Q[i] = Q[i + 1];
        }

        r--;

        return data;
    }
}

// Display
void display() {
    if (r == -1) {
        printf("Priority Queue is empty\n");
    } else {
        for (int i = f; i <= r; i++) {
            printf("%d with priority %d\n", Q[i].data, Q[i].priority);
        }
    }
}
