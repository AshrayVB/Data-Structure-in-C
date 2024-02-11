#include<stdio.h>
#define Max 5

int Q[Max], r=-1, f=0;
void enqueue(int element); //enqueue
int dequeue(); //dequeue
void display(); //display

void main(){
    int element, choice=0, de_element;
    while (choice != 4){
        printf("Enter choice 1.Enqueue 2.Dequeue 3.Display 4.Exit \n");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter element: \n");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                de_element = dequeue();
                printf("%d is dequeued \n", de_element);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid input \n");
        }
    }
}

// Enqueue
void enqueue(int element){
    if (r == Max - 1){
        printf("Overflow\n");
    }else{
        r++;
        Q[r] = element;
    }
}

// Dequeue
int dequeue(){
    int data;
    if (f > r){
        printf("Underflow\n");
        return -1; // Return a special value or handle underflow condition
    }else{
        data = Q[f];
        f++;
        return data;
    }
}

// Display
void display(){
    if (r == -1){
        printf("Q is empty\n");
    }else{
        for (int i = f; i <= r; i++){
            printf("%d \n", Q[i]);
        }
    }
}
