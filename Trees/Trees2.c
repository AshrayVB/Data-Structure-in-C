// C program implements operations on a binary search tree (BST), including insertion, deletion,
// traversal (inorder, preorder, and postorder),
// and searching for a specific item.

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    int high;
    struct Node *left;
    struct Node *right;
} Node;


Node* getNode() {
    Node* x = (Node*)malloc(sizeof(Node));
    if (x == NULL) {
        printf("OUT OF MEMORY");
        exit(0);
    }
    return x;
}


Node* insert(int item, Node* root) {
    Node *temp, *cur, *prev;
    temp = getNode();
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL) {
        return temp;
    }
    prev = NULL;
    cur = root;
    while (cur != NULL) {
        prev = cur;
        if (item == cur->data) {
            printf("Duplicate not allowed!!");
            free(temp);
            return root;
        }
        if (item < cur->data) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    if (item < prev->data) {
        prev->left = temp;
    } else {
        prev->right = temp;
    }
    return root;
}


void search(int item, Node* root) {
    Node* cur = root;
    if (root == NULL) {
        printf("Item not found!!");
        return;
    }
    while (cur != NULL) {
        if (cur->data == item) {
            printf("Item Found!!");
            return;
        }
        if (cur->data > item) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    printf("Item not found!!");
}


void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    printf("root->high = %d ",root->high);
    inorder(root->right);
    if (root->left != NULL && root->left->data > root->high) {
        root->high = root->left->data;
    }
    if (root->right != NULL && root->right->data > root->high) {
        root->high = root->right->data;
    }
}


void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}


void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

Node* deleteNode(int item, Node* root) {
    if (root == NULL) {
        printf("Item not found!\n");
        return root;
    }
    if (item < root->data) {
        root->left = deleteNode(item, root->left);
    } else if (item > root->data) {
        root->right = deleteNode(item, root->right);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(temp->data, root->right);
    }
    return root;
}

int main() {
    Node *root = NULL;
    int ch, item, searchItem;

    while (1) {
        printf("\nBinary Tree Operations:\n");
        printf("1. Insert Node 2. Inorder Traversal 3. Preorder Traversal\n4. Postorder Traversal 5. Search Item 6. Delete Node 7. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &item);
                root = insert(item, root);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter Item to Search: ");
                scanf("%d", &searchItem);
                search(searchItem, root);
                printf("\n");
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &item);
                root = deleteNode(item, root);
                break;
            case 7:
                printf("Program Closed\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
