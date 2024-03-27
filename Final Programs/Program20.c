//Design, Develop and Implement a menu driven Program in C for the following operations on Binary Search Tree (BST) of Integers.
//a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 5, 2.
//b. Display the minimum element in the tree.
//c. Traverse the tree using pre order.
//d. Search the BST for a given element (KEY) and report the appropriate message.
//e. Traverse the tree using Inorder.
//f. Exit

#include <stdio.h>
#include <stdlib.h>

// Structure for a node of the Binary Search Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to find the minimum element in the BST
int findMin(struct Node* root) {
    if (root == NULL) {
        printf("BST is empty.\n");
        return -1;
    }
    struct Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

// Function to perform pre-order traversal of the BST
void preorder(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Function to search for a given element in the BST
void search(struct Node* root, int key) {
    if (root == NULL) {
        printf("Element %d not found in BST.\n", key);
        return;
    }

    if (root->data == key) {
        printf("Element %d found in BST.\n", key);
        return;
    }

    if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

// Function to perform in-order traversal of the BST
void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Function to free the memory allocated for the BST
void freeBST(struct Node* root) {
    if (root == NULL)
        return;
    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;
    int choice, key;

    // Create BST
    root = insert(root, 6);
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 15);
    root = insert(root, 24);
    root = insert(root, 14);
    root = insert(root, 7);
    root = insert(root, 5);
    root = insert(root, 2);

    do {
        printf("\n----- Binary Search Tree Operations -----\n");
        printf("1. Display minimum element\n");
        printf("2. Traverse the tree using pre-order\n");
        printf("3. Search for an element\n");
        printf("4. Traverse the tree using in-order\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Minimum element in the BST: %d\n", findMin(root));
                break;
            case 2:
                printf("Pre-order traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                search(root, key);
                break;
            case 4:
                printf("In-order traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    // Free the memory allocated for BST
    freeBST(root);

    return 0;
}
