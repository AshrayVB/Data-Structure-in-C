//Dr. Joseph is a faculty member of CodeTantra University, who is handling a data
//structures course for software engineering department second-year students. One day,
//this faculty was handling a very interesting topic in data structures such as linked lists.
//He gave the following explanation for the linked list concept. A "linked list" is a
//sequence of links that contains items. Each link contains a connection to another link.
//Linked lists are the second most used data structure after arrays. The following are the
//important terms to understand the concept of linked list.
//Link - Each link of a linked list can store a piece of data called an element.
//Next - Each link of a linked list contains a link to the next link called Next.
//Linked list - A linked list contains the connection link to the first link called "First."
//During this lecture time, the last bench student was asked to take a surprise test for
//linked list concepts. So the faculty decided to conduct a test on the topic of linked lists.
//The question that was given to the last bench student's is: The nodes are deleted D
//times from the beginning of the given linked list.
//For example,
//        If the given linked list is 5 -> 10 -> 15 -> 20 -> 25, and we remove 2 nodes, Then the
//linked list becomes 15 -> 20 -> 25.
//Constraint:
//1 < N < 1000
//0 < D < N-1
//Input and Output layout:
//The first line contains the number of data: N.
//The second line contains N integers separated by space(the given linked list).
//The third line prints the entered linked list in the format mentioned in the visible test
//case.
//The fourth line contains the number of nodes to be deleted.
//The fifth line prints the resultant linked list after performing deletion


#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete nodes from the beginning of the linked list
void deleteNodes(struct Node** head, int count) {
    if (*head == NULL) {
        printf("Linked list is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    while (count > 0 && temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
        count--;
    }
    *head = temp;
}

// Function to display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    printf("Linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int N, D;
    printf("Enter the number of data: ");
    scanf("%d", &N);

    struct Node* head = NULL;
    printf("Enter the linked list data: ");
    for (int i = 0; i < N; i++) {
        int data;
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    printf("Entered linked list: ");
    display(head);

    printf("Enter the number of nodes to delete: ");
    scanf("%d", &D);
    if (D >= N) {
        printf("Invalid input: Number of nodes to delete exceeds the total nodes.\n");
        return 0;
    }

    deleteNodes(&head, D);
    printf("Resultant linked list after deletion: ");
    display(head);

    return 0;
}
