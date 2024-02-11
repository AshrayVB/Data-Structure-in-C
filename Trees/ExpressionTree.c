// C program creates an expression tree from a given postfix expression and then evaluates the expression.

#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include<math.h>

typedef struct Node {
    int data;
    struct Node *llink;
    struct Node *rlink;
} Node;


Node* getNode() {
    Node* x = (Node*)malloc(sizeof(Node));
    if (x == NULL) {
        printf("OUT OF MEMORY");
        exit(0);
    }
    return x;
}

float eval(Node* root){
	float num;
	switch(root->data){
		case '+':
			return eval(root->llink)+eval(root->rlink);
			break;
		case '-':
			return eval(root->llink)-eval(root->rlink);
			break;
		case '*':
			return eval(root->llink)*eval(root->rlink);
			break;
		case '/':
			return eval(root->llink)/eval(root->rlink);
			break;
		case '^':
			return pow(eval(root->llink),eval(root->rlink));
			break;
		default:
			if(isalpha(root->data)){
				printf("%c",root->data);
				scanf("%f",&num);
				return num;
			} else {
				return root->data-'0';
			}
	}
}


Node* createTree(char postfix[]){
	Node *temp,*st[20];
	int i,k;
	char Symbol;
	for (i = 0, k = 0; (Symbol=postfix[i]) != '\0'; i ++){
		temp=getNode();
		temp->data=Symbol;
		temp->llink=NULL;
		temp->rlink=NULL;
		if (isalnum(Symbol)){
			st[k++]=temp;
		} else {
			temp->rlink=st[--k];
			temp->llink=st[--k];
			st[k++]=temp;
		}
	}
	return st[--k];
}

void main() {
    Node* root = NULL;
    int ch;
    char str[100];

    while (1) {
        printf("\nExpression Tree Operations:\n");
        printf("1. Create tree\n");
        printf("2. Evaluate\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter postfix Expression: ");
                scanf("%s",str);
                root=createTree(str);
                break;
            case 2:
                printf("Evaluation result : ");
                float r=eval(root);
                printf("%0.2f\n",r);
                break;
            case 3:
            	printf("Exit");
            	exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
