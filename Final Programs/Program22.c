//Develop a program to create and evaluate a Binary Tree evaluation of expression.
//Expression: 632-5*+2^3+

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Structure to represent a node in the binary tree
struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(char data) {
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

// Function to check if the character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to construct a binary tree from the expression
struct Node* constructTree(char postfix[]) {
    struct Node* stack[100]; // Stack to hold nodes
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        struct Node* newNode = createNode(postfix[i]);

        if (!isOperator(postfix[i])) {
            stack[++top] = newNode; // Push operands to stack
        } else {
            // Pop two nodes from stack
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode; // Push the operator node back to stack
        }
    }
    return stack[top]; // Root of the binary tree
}

// Function to evaluate the binary tree
int evaluateTree(struct Node* root) {
    if (root == NULL)
        return 0;

    if (!isOperator(root->data))
        return root->data - '0'; // Convert character to integer

    int leftVal = evaluateTree(root->left);
    int rightVal = evaluateTree(root->right);

    switch (root->data) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
        case '^': return (int)pow(leftVal, rightVal);
        default: return 0;
    }
}

int main() {
    char postfix[] = "632-5*+2^3+"; // Given postfix expression

    // Construct binary tree from postfix expression
    struct Node* root = constructTree(postfix);

    // Evaluate the binary tree
    int result = evaluateTree(root);

    printf("Result of expression %s is: %d\n", postfix, result);

    return 0;
}
