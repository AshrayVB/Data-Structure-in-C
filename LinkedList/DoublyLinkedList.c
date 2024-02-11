#include<stdio.h>
#include<stdlib.h>

// Node Structure:
struct node {
  int data;
  struct node *next;
  struct node *prev;
};
// Global Variables:
struct node *start = NULL;
struct node *current = NULL;

// Function prototypes
void create();
void insert_bg();
void insert_pos();
void insert_end();
void deletion_beg();
void delete_pos();
void delete_end();
void display();

// Main function
int main() {
  int choice;
  while (1) {
    printf("1.Insert in beginning\n2.Insert in position\n3.Insert at end\n4.Delete from beginning\n5.Delete from position\n6.Delete from end\n7.Display\n8.Exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        insert_bg();
        break;
      case 2:
        insert_pos();
        break;
      case 3:
        insert_end();
        break;
      case 4:
        deletion_beg();
        break;
      case 5:
        delete_pos();
        break;
      case 6:
        delete_end();
        break
      case 7:
        display();
        break;
      case 8:
        exit(0);
      default:
        printf("Enter a valid choice\n");
    }
  }
  return 0;
}

// Creation of node
void create() {
  int ch;
  do {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    if (start == NULL) {
      start = newnode;
      current = newnode;
    } else {
      current->next = newnode;
      newnode->prev = current;
      current = newnode;
    }
    printf("Enter 0 to terminate, 1 to Continue: ");
    scanf("%d", &ch);
  } while(ch != 0);
}

// Insertion at beginning
void insert_bg() {
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  newnode->next = NULL;
  newnode->prev = NULL;
  printf("Enter the data: ");
  scanf("%d", &newnode->data);
  if (start == NULL) {
    start = newnode;
    current = newnode;
  } else {
    newnode->next = start;
    start->prev = newnode;
    start = newnode;
  }
}

// Insertion at position
void insert_pos() {
  int pos, i;
  struct node *newnode, *temp = start;
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->next = NULL;
  newnode->prev = NULL;
  printf("Enter the position at which you want to insert the node: ");
  scanf("%d", &pos);
  if (start == NULL) {
    start = newnode;
    current = newnode;
  } else {
    for (i = 0; i < pos - 2; i++) {
      temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
  }
}

// Insertion at end
void insert_end() {
  struct node *newnode;
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->next = NULL;
  newnode->prev = NULL;
  printf("Enter the data: ");
  scanf("%d", &newnode->data);
  if (start == NULL) {
    start = newnode;
    current = newnode;
  } else {
    current->next = newnode;
    newnode->prev = current;
    current = newnode;
  }
}

// Deletion at beginning
void deletion_beg() {
  struct node *temp = start;
  if (start == NULL) {
    printf("Empty list\n");
  } else {
    start = start->next;
    start->prev = NULL;
    free(temp);
  }
}

// Deletion at position
void delete_pos() {
  int pos, i;
  struct node *temp, *temp1;
  printf("Enter the position for deletion of node: ");
  scanf("%d", &pos);
  temp = start;
  for (i = 0; i < pos - 1; i++) {
    temp1 = temp;
    temp = temp->next;
  }
  temp1->next = temp->next;
  temp->next->prev = temp1;
  free(temp);
}

// Deletion at end
void delete_end() {
  struct node *temp = current;
  if (start == NULL) {
    printf("Empty list\n");
  } else {
    current = current->prev;
    current->next = NULL;
    free(temp);
  }
}

// Display
void display() {
  struct node *temp = start;
  if (temp == NULL) {
    printf("List is empty\n");
  } else {
    while (temp != NULL) {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}
