//Write a C Program to store and display the specified student information using SLL

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure
struct Student{
    int roll;
    char name[50];
    float marks;
    struct Student* next;
};

//Function to create new student
struct Student* createStudent(int roll, const char* name, float marks){
    struct Student* newStudent = (struct Student*) malloc(sizeof(struct Student));
    if(newStudent == NULL){
        printf("Memory allocation");
        exit(1);
    }
    newStudent->roll = roll;
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->next = NULL;
    return newStudent;
}

//Function to insert a student at end
void insertStudent(struct Student** head, int roll, const char* name, float marks){
    struct Student* newStudent = createStudent(roll, name, marks);
    if(*head == NULL){
        *head = newStudent;
    } else {
        struct Student* temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

//Function to delete by roll number
void deleteStudent(struct Student** head, int roll){
    if(*head == NULL){
        printf("Student list is empty. Cannot delete.\n");
        return;
    }
    struct Student* current = *head;
    struct Student* prev = NULL;
    while (current != NULL){
        if(current->roll == roll){
            if(prev == NULL){
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Student with roll number %d deleted succesfully.\n", roll);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Student with roll number %d not found.\n",roll);
}


//Function to display
void display(struct Student* head){
    if(head == NULL){
        printf("No student records found.\n");
        return;
    }
    printf("Students Information.\n");
    printf("Roll no\tName\tMarks\n");
    while(head != NULL){
        printf("%d\t%s\t%.2f\n", head->roll, head->name, head->marks);
        head = head->next;
    }
}

int main(){
    struct Student* head = NULL;
    int choice, roll;
    char name[50];
    float marks;

    do{
        printf("\nStudent Record Operations:\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter marks: ");
                scanf("%f", &marks);
                insertStudent(&head, roll, name, marks);
                break;
            case 2:
                printf("Enter roll number of student to delete: ");
                scanf("%d", &roll);
                deleteStudent(&head, roll);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}