#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *insertion(struct node *root,int num);
struct node *newNode(int num);
void inorder(struct node *root);
struct node *deleteNode(struct node *root,int dvalue);
struct node *minValue(struct node *root);

struct node *minValue(struct node *root){
	struct node *current = root;
	while(current->left!=NULL){
		current = current->left;
	}
	return current;
}
struct node *deleteNode(struct node *root,int dvalue){
	if(root==NULL){
		return root;
	}
	if(dvalue < root->data){
		root->left = deleteNode(root->left,dvalue);
	}
	else if(dvalue > root->data){
		root->right = deleteNode(root->right,dvalue);
	}
	else{
		if(root->left==NULL){
			struct node *t = root->right;
			free(root);
			return t;
		}
		else if(root->right==NULL){
			struct node *t = root->left;
			free(root);
			return t;
		}
		struct node *t = minValue(root->right);
		root->data = t->data;
		root->right = deleteNode(root->right,t->data);
	}
	return root;
}
void inorder(struct node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
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
	if(root->data < num){
		root->right = insertion(root->right,num);
	}
	else{
		root->left = insertion(root->left,num);
	}
	return root;
}

int main(){
  printf("The number of nodes in tree: ");
  int n;scanf("%d",&n);
  int flag=0;
  struct node *root = NULL;
  printf("Enter the values: ");
  for(int i=0;i<n;i++){
  	int num;scanf("%d",&num);
  	if(flag==0){
  		root = insertion(root,num);
  		flag=1;
  		continue;
  	}
  	insertion(root,num);
  }
  printf("Before deletion: ");
  inorder(root);
  printf("\n");
  printf("Enter the value of node to be deeted: ");
  int dvalue;scanf("%d",&dvalue);
  struct node *temp = deleteNode(root,dvalue);
  inorder(root);
  printf("\n");
  return 0;
}
