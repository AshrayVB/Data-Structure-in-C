//Write a C Program to implement a stack data structure using characters.

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5

//Structure
struct Stack{
    int top;
    unsigned capacity;
    char* array;
};

//Function to create
struct Stack* createStack(unsigned capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

//Function to check if the stack is full
int isFull(struct Stack* stack){
    return stack->top == stack->capacity - 1;
}

//Function to check if the stack is empty
int isEmpty(struct Stack* stack){
    return stack->top == -1;
}

//Push an element
void push(struct Stack* stack, char item){
    if(isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

//Pop an element
int pop(struct Stack* stack){
    if(isEmpty(stack))
        return '\0';        //indicates stack underflow
    return stack->array[stack->top--];
}

//return the top element
char peek(struct Stack* stack){
    if(isEmpty(stack))
        return '\0';
    return stack->array[stack->top];
}

//Display
void display(struct Stack* stack) {
    if(isEmpty(stack)) {
        printf("Stack is empty. No elements to display.\n");
        return;
    }
    printf("Elements in the stack: ");
    for(int i = stack->top; i >= 0; i--) {
        printf("%c ", stack->array[i]);
    }
    printf("\n");
}

int main(){
    struct Stack* stack = createStack(MAX_SIZE);
    char choice, item;
    do{
        printf("\nStack Operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter element to push: ");
                scanf(" %c", &item);
                push(stack, item);
                printf("%c pushed to stack.\n", item);
                break;
            case '2':
                item = pop(stack);
                if (item != '\0')
                    printf("Poped element: %c\n", item);
                else
                    printf("Stack is empty. Cannot pop\n");
                break;
            case '3':
                item = peek(stack);
                if (item != '\0')
                    printf("Top element: %c\n", item);
                else
                    printf("Stack is empty. No top element.\n");
                break;
            case '4':
                display(stack);
                break;
            case '5':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }while (choice != '5');
        return 0;
}
