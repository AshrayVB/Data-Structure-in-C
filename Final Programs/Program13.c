//Franky is having data in the form of two one way link lists A and B, Both lists consists
//of N1 and N2 no of nodes respectively, Both link lists are entered in default sorted
//order( increasing order). Franky's task is to merge these two sorted linked lists.
//Input Format:
//First line of input contains the number of nodes in the linked lists A and B i.e. N1 and
//N2 ( Space separated).
//Second line of input is the N1 integer values used to store in order of occurrence in the
//linked structure.
//Third line of input is the N2 integer values used to store in order of occurrence in the
//linked structure.
//Output Format:
//Resultant list after performing merge operation.
//Constraints:
//0 ≤ N1, N2 ≤ 100
//-103 ≤ Data in Node ≤ 103
//Use concept of linked list to solve this problem.
//Sample Input:
//3 2 (First line consists of N1 and N2 (Separated by space))
//11 22 33 (Second line contains N1 data values in list A (Space separated))
//22 33 (Third line contains N2 data values in list B (Space separated))
//Sample Output 1: 11 22 22 33 33 (Resultant list)



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

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* head1, struct Node* head2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    if (head1 != NULL) {
        tail->next = head1;
    } else {
        tail->next = head2;
    }
    return dummy.next;
}

// Function to display the merged linked list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int N1, N2;
    printf("Enter the number of nodes in linked list A and B: ");
    scanf("%d %d", &N1, &N2);

    struct Node* headA = NULL;
    struct Node* headB = NULL;

    printf("Enter the values for linked list A: ");
    for (int i = 0; i < N1; i++) {
        int data;
        scanf("%d", &data);
        insertEnd(&headA, data);
    }

    printf("Enter the values for linked list B: ");
    for (int i = 0; i < N2; i++) {
        int data;
        scanf("%d", &data);
        insertEnd(&headB, data);
    }

    printf("Merged sorted linked list: ");
    struct Node* mergedList = mergeSortedLists(headA, headB);
    display(mergedList);

    return 0;
}
