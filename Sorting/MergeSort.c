#include <stdio.h>

void mergesort(int arr[],int low,int high);
void merge(int arr[], int i1,int j1,int i2, int j2);

void merge(int arr[], int i1,int j1,int i2,int j2){
		int temp[1000];
		int i,j,k;
		i=i1;j=i2;k=0;
		while(i<=j1 && j<=j2){
			if(arr[i]<arr[j]){
				temp[k++]=arr[i++];
			}
			else{
					temp[k++]=arr[j++];
			}
		}
		while(i<=j1){
			temp[k++]=arr[i++];
		}
		while(j<=j2){
			temp[k++]=arr[j++];
		}
		for(i=i1,j=0;i<=j2;i++,j++){
			arr[i]=temp[j];
		}
}
void mergesort(int arr[],int low,int high){
	if(low<high){
		int mid;
		mid = (low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,mid+1,high);
	}
}

int main(){
	int arr[1000];
	printf("Enter the number of elements: ");
	int n;scanf("%d",&n);
	printf("Enter the Elements: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		}
	mergesort(arr,0,n-1);
	printf("The Sorted Array will be:\n");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
		}
	printf("\n");
	return 0;
}
