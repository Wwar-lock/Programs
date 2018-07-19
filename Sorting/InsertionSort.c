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
    int i,j,k;
    for(i=1;i<n;i++){
        k = arr[i];
        j = i-1;
        while(arr[j]>k && j>=0){
            arr[j+1]=arr[j];
            j=j-1;                          // increasing Order
        }
        arr[j+1] = k;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}