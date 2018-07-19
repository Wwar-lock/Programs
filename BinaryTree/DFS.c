#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left,*right;
};

struct node *newNode(int num);
struct node *insertion(struct node *root,int num);
void print_dfs(struct node *root);
int height(struct node *root);
void print_level(struct node *root,int num);

void print_level(struct node *root,int num){
	if(root==NULL){
		return;
	}
	if(num==1){
		printf("%d ",root->data);
	}
	else{
		print_level(root->left,num-1);
		print_level(root->right,num-1);
	}
}
int height(struct node *root){
	if(root==NULL){
		return 0;
	}
	else{
		int l,r;
		l = height(root->left);
		r = height(root->right);
		
		if(l>r){
			return l+1;
		}
		else{
			return r+1;
		}
	}
}
void print_dfs(struct node *root){
	int h = height(root);
	for(int i=0;i<=h;i++){
		print_level(root,i);
	}
}
struct node *newNode(int num){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = num;
	temp->left = temp->right = NULL;
	return temp;
}
struct node *insertion(struct node *root,int num){
	if(root==NULL){
		return newNode(num);
	}
	else if(num<root->data){
		root->left = insertion(root->left,num);
	}
	else{
		root->right = insertion(root->right,num);
	}
	return root;
}

int main(){
	int n;printf("Enter the number of nodes: ");
	scanf("%d",&n);
	printf("Enter the nodes: ");
	struct node *root = NULL;
	int flag=0;
	for(int i=0;i<n;i++){
		int num;
		scanf("%d",&num);
		if(flag==0){
			root = insertion(root,num);
		}
		else{
			insertion(root,num);
		}
	}
	print_dfs(root);
	printf("\n");
	return 0;
}
