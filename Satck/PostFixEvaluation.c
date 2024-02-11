#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack implementation for operators
typedef struct {
    char stack[MAX_SIZE];
    int top;
} OperatorStack;

void initStack(OperatorStack *s) {
    s->top = -1;
}

int isEmpty(OperatorStack *s) {
    return s->top == -1;
}

void push(OperatorStack *s, char op) {
    if (s->top < MAX_SIZE - 1) {
        s->stack[++s->top] = op;
    } else {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
}

char pop(OperatorStack *s) {
    if (!isEmpty(s)) {
        return s->stack[s->top--];
    } else {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
}

char peek(OperatorStack *s) {
    if (!isEmpty(s)) {
        return s->stack[s->top];
    } else {
        return '\0'; // Empty stack, return null character
    }
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    }
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[]) {
    OperatorStack stack;
    initStack(&stack);

    int i, j;
    char ch;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (infix[i] == ' ' || infix[i] == '\t') {
            continue; // Skip whitespaces
        }

        if (isdigit(infix[i]) || isalpha(infix[i])) {
            postfix[j++] = infix[i];
        } else if (isOperator(infix[i])) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) == '(') {
                pop(&stack); // Pop '('
            }
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    OperatorStack stack;
    initStack(&stack);

    int i, operand, op1, op2;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            operand = postfix[i] - '0';
            push(&stack, operand);
        } else if (isOperator(postfix[i])) {
            op2 = pop(&stack);
            op1 = pop(&stack);

            switch (postfix[i]) {
                case '+':
                    push(&stack, op1 + op2);
                    break;
                case '-':
                    push(&stack, op1 - op2);
                    break;
                case '*':
                    push(&stack, op1 * op2);
                    break;
                case '/':
                    if (op2 != 0) {
                        push(&stack, op1 / op2);
                    } else {
                        printf("Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    break;
            }
        }
    }

    return pop(&stack);
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result after evaluation: %d\n", result);

    return 0;
}
