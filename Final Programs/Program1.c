//Write C Program to convert the given infix expression to postfix expression

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100

//structure
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

//function to create stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

//to check weather stack is Full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

//to check weather stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

//Function to Push element
void push(struct Stack* stack, char item) {
    if(isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

//Function to Pop
char pop(struct Stack* stack) {
    if(isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}


//Function to Peek
char peek(struct Stack* stack) {
    if(isEmpty(stack))
        return '\0';
    return stack->array[stack->top];
}

//Function to Precedence
int precedence(char op) {
    if(op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

//function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack* stack = createStack(strlen(infix));
    int i, k;
    for (i = 0, k = -1; infix[i]; ++i) {
        if (isalnum(infix[i])) {
            postfix[++k] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[++k] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(')
                return;
            else
                pop(stack);
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack))) {
                postfix[++k] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }
    while (!isEmpty(stack)) {
        postfix[++k] = pop(stack);
    }
    postfix[++k] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strlen(infix) - 1] = '\0';

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    return 0;
}

//Commands: gedit filname.c
//            gcc filename.c
//            ./a.out
