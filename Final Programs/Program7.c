//Write a C Program to perform following operations on Singly Linked List
//1). Create 2)Insert (At the mid position) 3)Delete (At the End) 4)Display

#include<stdio.h>
#include<stdlib.h>

//Structure to represent a node
struct Node{
    int data;
    struct Node* next;
};

//(1.)Function to create a new node
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//(2.)Function to insert at the mid position
void insertAtMid(struct Node** head, int data){
    if(*head == NULL){
        *head = createNode(data);
        return;
    }
    struct Node* slow = *head;
    struct Node* fast = (*head)->next;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    struct Node* newNode = createNode(data);
    newNode->next = slow->next;
    slow->next = newNode;
}

//(3.)Delete from last
void deleteAtEnd(struct Node** head){
    if(*head == NULL){
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

//(4.) Function to display
void display(struct Node* head){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked list: ");
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at Middle\n");
        printf("2. Delete at End\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at middle: ");
                scanf("%d", &data);
                insertAtMid(&head, data);
                break;
            case 2:
                deleteAtEnd(&head);
                printf("Deleted last node.\n");
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}