#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *left,*right;
};
void print_inorder(struct node *root);
void print_postorder(struct node *root);
void print_preorder(struct node *root);
struct node *insertion(struct node *root,int num);
struct node *newNode(int num);

struct node *newNode(int num){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = num;
	temp->left = temp->right = NULL;
	return temp;
}
struct node *insertion(struct node *root,int num){
	if(root==NULL){
		return newNode(num);
	}
	else if(root->data>num){
		root->left = insertion(root->left,num);
	}
	else{
		root->right = insertion(root->right,num);
	}
	return root;
}
void print_preorder(struct node *root){
	if(root!=NULL){
		printf("%d ",root->data);
		print_preorder(root->left);
		print_preorder(root->right);
	}	
}
void print_postorder(struct node *root){
	if(root!=NULL){
		print_postorder(root->left);
		print_postorder(root->right);
		printf("%d ",root->data);
	}
}
void print_inorder(struct node *root){
	if(root!=NULL){
		print_inorder(root->left);
		printf("%d ",root->data);
		print_inorder(root->right);
	}
}
int main(){
	int n;printf("Enter the number of nodes: ");
	scanf("%d",&n);
	struct node *root = NULL;
	int flag=0;
	printf("Enter the nodes: ");
	for(int i=0;i<n;i++){
		int num;scanf("%d",&num);
		if(flag==0){
			root = insertion(root,num);
			flag=1;
		}
		else{
		insertion(root,num);
		}
	}
	printf("The preorder Traversal is: ");
	print_preorder(root);
	printf("\nThe inorder Traversal is: ");
	print_inorder(root);
	printf("\nThe postorder Traversal is: ");
	print_postorder(root);
	printf("\n");
	return 0;
}
