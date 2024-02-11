#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

void IO(struct Node *root) { // Inorder traversing: left->root->right
    if (root == NULL) {
        return;
    } else {
        IO(root->left);
        printf("%d ", root->data);
        IO(root->right);
    }
}

void PREO(struct Node *root) { // Preorder traversing: root->left->right
    if (root == NULL) {
        return;
    } else {
        printf("%d ", root->data);
        PREO(root->left);
        PREO(root->right);
    }
}

void POST(struct Node *root) { // Postorder traversing: left->right->root
    if (root == NULL) {
        return;
    } else {
        POST(root->left);
        POST(root->right);
        printf("%d ", root->data);
    }
}

struct Node *getnode() { // getnode: Allocates memory for a new node and returns a pointer to it
    struct Node *x;
    x = (struct Node *)malloc(sizeof(struct Node));
    if (x == NULL) {
        printf("Out of Memory\n");
        exit(0);
    }
    return x;
}

struct Node *ins(int item, struct Node *root) { // ins: Inserts a new node with the specified data into the BST while maintaining the BST property
    struct Node *temp, *curr, *prev;
    temp = getnode();
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL) {
        return temp;
    }
    prev = NULL;
    curr = root;
    while (curr != NULL) {
        prev = curr;
        if (item == curr->data) {
            printf("Duplicate not allowed\n");
            free(temp);
            return root;
        }
        if (item < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (item < prev->data)
        prev->left = temp;
    else
        prev->right = temp;
    return root;
}

int search(int item, struct Node *root) {
    struct Node *curr = root;
    while (curr != NULL) {
        if (curr->data == item) {
            return 1; // Element found
        }
        if (item < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return 0; // Element not found
}

void main() {
    struct Node *root = NULL;
    int ch, item;
    while (1) {
        printf("\n1)Insert 2)Preorder Traversal 3)Postorder Traversal \n4)Inorder Traversal 5)Search 6)Exit\nEnter choice :");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter item :");
                scanf("%d", &item);
                root = ins(item, root);
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is Empty\n");
                    exit(0);
                }
                printf("Preorder Traversal\n");
                PREO(root);
                break;
            case 3:
                if (root == NULL) {
                    printf("Tree is Empty\n");
                    exit(0);
                }
                printf("Postorder Traversal\n");
                POST(root);
                break;
            case 4:
                if (root == NULL) {
                    printf("Tree is Empty\n");
                    exit(0);
                }
                printf("Inorder Traversal\n");
                IO(root);
                break;
            case 5:
                printf("Enter item to search : ");
                scanf("%d", &item);
                if (search(item, root)) {
                    printf("Element found\n");
                } else {
                    printf("Element not found\n");
                }
                break;
            case 6:
                printf("Program Closed\n");
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
}
