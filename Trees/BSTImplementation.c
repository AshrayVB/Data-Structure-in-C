#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left,*right;
};
typedef struct Node*NODE;
NODE root=NULL;

void insert(int ele){
    NODE nn=(NODE)malloc(sizeof(struct Node));
    nn->data=ele;
    nn->left=nn->right=NULL;
    if(root==NULL){
        root=nn;
        return ;
    }
    NODE curr = root, prev=NULL;
    while(curr!=NULL){
        prev=curr;
        if(ele<curr->data)
            curr=curr->left;
        else
            curr=curr->right;
    }
    if(ele<prev->data)
        prev->left=nn;
    else
        prev->right=nn;
}

void search(int ele){
    if(root == NULL){
        printf("Tree is empty\n");
        return;
    }
    NODE curr = root;
    while(curr != NULL){
        if(ele == curr->data){
            printf("Search successful\n");
            return;
        }
        else if(ele < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    printf("Search not found\n");
}

void INO(NODE root){
    if(root==NULL){
        return;
    }
    INO(root->left);
    printf("%d ",root->data);
    INO(root->right);
}

void PREE(NODE root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    PREE(root->left);
    PREE(root->right);
}

void POST(NODE root){
    if(root==NULL){
        return;
    }
    POST(root->left);
    POST(root->right);
    printf("%d ",root->data);
}

void Min(NODE root){
    if(root==NULL){
        printf("Trees is empty");
        return;
    }
    NODE curr=root;
    while(curr->left!=NULL){
        curr=curr->left;
    }
    printf("The minimum element is %d",curr->data);
}

void Max(NODE root){
    if(root==NULL){
        printf("Tree is empty");
        return;
    }
    NODE curr=root;
    while(curr->right!=NULL){
        curr=curr->right;
    }
    printf("The maximum element is %d",curr->data);
}

int main(){
    int ch,ele,n;
    while(1){
        printf("\nEnter the choice :\n1.insert,2.search,3.Inorde,4.Postorder,\n5.Preeorder,6.Minimum,7.Maximum,8.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the NU of Element :");
                    scanf("%d",&n);
                    printf("Enter the element :");
                    for(int i=0;i<n;i++){
                        scanf("%d",&ele);
                        insert(ele);
                    }
            break;
            case 2 :printf("enter the element :");
                    scanf("%d",&ele);
                    search(ele);
            break;
            case 3:printf("Inorder : ");
                    INO(root);
            break;
            case 4 :printf("Preeorder :");
                    PREE(root);
            break;
            case 5 : printf("Postorder :");
                    POST(root);
            break;
            case 6 : Min(root);
            break;
            case 7 : Max(root);
            break;
            case 8 : exit(0);
            default:printf("Enter the valid choise : \n");
                    
        }
    }
}