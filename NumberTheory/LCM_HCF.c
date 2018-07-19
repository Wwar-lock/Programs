#include <stdio.h>
int HCF(int n1,int n2);

int HCF(int n1,int n2){
	if(n1<n2){
		for(int i=2;i<=n1/2;i++){
			if((n1%i==0)&&(n2%i==0)){
				return i;
			}
		}
	}
	else if(n2<n1){
		for(int i=2;i<=n2/2;i++){
			if((n1%i==0)&&(n2%i==0)){
				return i;
			}
		}
	}
	return 1;
}

int main(){
	int n1,n2;printf("Enter two numbers: ");
	scanf("%d %d",&n1,&n2);
	printf("The LCM will be: ");
	int hcf = HCF(n1,n2);
	if((n1%n2==0)||(n2%n1==0)){
		if(n1>n2){
			printf("%d\n",n1);
		}
		else{
			printf("%d\n",n2);
		}
	}
	else{
		printf("%d\n",n1*n2/hcf);
	}
	return 0;
}
