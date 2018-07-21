#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};

void print(struct node *root);
struct node *insertion(struct node *root,int num);
struct node *newNode(int num);
struct node *lowestCommonAncestor(struct node *root,int n1,int n2);

struct node *lowestCommonAncestor(struct node *root,int n1,int n2){
	if(root==NULL){
		return NULL;
	}
	if(root->data<n1 && root->data<n2){
		return lowestCommonAncestor(root->right,n1,n2);
	}
	if(root->data>n1 && root->data>n2){
		return lowestCommonAncestor(root->left,n1,n2);
	}
	return root;
}
struct node *newNode(int num){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = num;
	temp->left = temp->right = NULL;
	return temp;
}
void print(struct node *root){
	if(root!=NULL){
		printf("%d ",root->data);
		print(root->left);
		print(root->right);
	}
}
struct node *insertion(struct node *root,int num){
	if(root==NULL){
		return newNode(num);
	}
	else if(root->data > num){
		root->left = insertion(root->left,num);
	}
	else{
		root->right = insertion(root->right,num);
	}
	return root;
}

int main(){
	printf("Enter the number of nodes: ");
	int n;scanf("%d",&n);
	printf("Enter the value of nodes: ");
	struct node *root = NULL;
	int flag=0;
	for(int i=0;i<n;i++){
		int num;
		scanf("%d",&num);
		if(flag==0){
			root = insertion(root,num);
			flag=1;
			continue;
		}
		insertion(root,num);
	}
	printf("Enter the value of nodes: ");
	int n1,n2;scanf("%d %d",&n1,&n2);
	struct node *temp = lowestCommonAncestor(root,n1,n2);
	printf("LCA of %d and %d is %d",n1,n2,temp->data);
	//print(root);
	printf("\n");
	return 0;
}
