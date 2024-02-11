//Stack Implementation
#include<stdio.h>

int Stack[15], i, top=-1, n, choice; // Corrected the array size to 15

void pop();
void push();
void display();

void main(){
    printf("Enter the size of Array: \n");
    scanf("%d", &n); // Corrected the variable name from 'choice' to 'n'

    while (1) {
        printf("1.Push\n2.Pop\n3.Display\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}

// Push
void push(){
    int x;
    printf("Enter the value: \n");
    scanf("%d", &x);
    if (top == n - 1) { // Changed the condition to use 'n' instead of 'top'
        printf("Stack overflow \n");
    } else {
        Stack[++top] = x;
    }
}

// Pop
void pop(){
    if (top == -1){
        printf("Stack underflow \n");
    } else {
        printf("%d \n", Stack[top]);
        top--;
    }
}

// Display
void display(){
    if (top == -1){
        printf("Stack is empty \n");
    } else {
        printf("Elements are: \n");
        for (i = top; i >= 0; i--)
            printf("%d \n", Stack[i]);
    }
}
