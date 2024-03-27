//Write a C Program to implement stack using SLL

#include<stdio.h>
#include<stdlib.h>

//Structure of Node
struct Node{
    int data;
    struct Node* next;
};
//Structure of Stack
struct Stack{
    struct Node* top;
};

//Function to create new node
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof (struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//Function to create empty stack
struct Stack* createStack(){
    struct Stack* stack = (struct Stcak*) malloc(sizeof(struct Stack));
    if(stack == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

//Function to check if the stack is empty
int isEmpty(struct Stack* stack){
    return (stack->top == NULL);
}

//Function to push an element onto stack
void push(struct Stack* stack, int data){
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed to stack.\n",data);
}

//Function to pop an element
int pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty Cannot pop.\n");
        exit(1);
    }
    struct Node* temp = stack->top;
    int poped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poped;
}

//Function to peek the top element
int peek(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty. No top element.\n");
        exit(1);
    }
    return stack->top->data;
}

//Function to display
void display(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty.No element to display.\n");
        return;
    }
    printf("Stack elements: ");
    struct Node* temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Stack* stack = createStack();
    int choice, element;

    do{
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(stack, element);
                break;
            case 2:
                if (!isEmpty(stack))
                    printf("Popped element: %d\n", pop(stack));
                break;
            case 3:
                if (!isEmpty(stack))
                    printf("Top element: %d\n", peek(stack));
                break;
            case 4:
                display(stack);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter again.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}