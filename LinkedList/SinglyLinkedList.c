#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};
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
        break;
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

// Create node
void create() {
  int ch;
  do {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    printf("Enter the data for new node: ");
    scanf("%d", &newnode->data);
    if (start == NULL) {
      start = newnode;
      current = newnode;
    } else {
      current->next = newnode;
      current = newnode;
    }
    printf("Enter 1 to continue, 0 to exit: ");
    scanf("%d", &ch);
  } while (ch != 0);
}

// Insert at beginning
void insert_bg() {
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  newnode->next = NULL;
  printf("Enter the data for new node: ");
  scanf("%d", &newnode->data);
  if (start == NULL) {
    start = newnode;
    current = newnode;
  } else {
    newnode->next = start;
    start = newnode;
  }
}

// Insert at position
void insert_pos() {
  int pos, i;
  struct node *newnode, *temp, *temp1;
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->next = NULL;
  if (start == NULL) {
    start = newnode;
    current = newnode;
  } else {
    printf("Enter the position: ");
    scanf("%d", &pos);
    temp = start;
    for (i = 0; i < pos - 2; i++) {
      temp = temp->next;
    }
    temp1 = temp->next;
    temp->next = newnode;
    newnode->next = temp1;
  }
}

// Insert at end
void insert_end() {
  struct node *newnode;
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->next = NULL;
  printf("Enter the data for new node: ");
  scanf("%d", &newnode->data);
  if (start == NULL) {
    start = newnode;
    current = newnode;
  } else {
    current->next = newnode;
    current = newnode;
  }
}

// Delete from beginning
void deletion_beg() {
  struct node *temp1;
  if (start == NULL) {
    printf("List is empty\n");
  } else {
    temp1 = start;
    start = start->next;
    free(temp1);
  }
}

// Delete from position
void delete_pos() {
  int pos, i;
  struct node *temp, *temp1;
  if (start == NULL) {
    printf("List is empty\n");
    exit(0);
  } else {
    printf("Enter the position: ");
    scanf("%d", &pos);
    temp = start;
    for (i = 0; i < pos - 1; i++) {
      temp1 = temp;
      temp = temp->next;
    }
    temp1->next = temp->next;
    free(temp);
  }
}

// Delete from end
void delete_end() {
  struct node *temp, *temp1;
  if (start == NULL) {
    printf("List is empty\n");
  } else {
    temp = start;
    while (temp->next != current) {
      temp1 = temp;
      temp = temp->next;
    }
    temp1->next = NULL;
    current = temp1;
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
