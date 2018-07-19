#include <stdio.h>
#include <stdlib.h>
int main(){
    int arr[10000];
    printf("Enter the size of Array: ");
    int n;scanf("%d",&n);
    printf("Enter the Elements of Array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];          // decreasing order
                arr[j]=temp;            // for increasing change '>' with '<' in if condition
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}