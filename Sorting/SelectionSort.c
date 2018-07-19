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
    int min_index;
    for(int i=0;i<n-1;i++){
        min_index = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index = j;                  // incresing order
            }                                   // for decreasing change '<' with '>' in if condition
        }
        int temp;
        temp = arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}