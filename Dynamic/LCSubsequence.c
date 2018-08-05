#include <stdio.h>
#include <string.h>

int max(int a,int b);
int lcs(char *s1,char *s2,int x,int y);

int lcs(char *s1,char *s2,int x,int y){
    if(x==0 || y==0){
        return 0;
    }
    else if(s1[x-1]==s2[y-1]){
        return 1 + lcs(s1,s2,x-1,y-1);
    }
    else{
        return max(lcs(s1,s2,x-1,y),lcs(s1,s2,x,y-1));
    }
}

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

int main(){
    char s1[100],s2[100];
    printf("Enter the String 1: ");
    scanf("%s",s1);
    printf("Enter the String 2: ");
    scanf("%s",s2);
    int x=strlen(s1);
    int y=strlen(s2);
    //printf("%d %d",x,y);
    int ans = lcs(s1,s2,x,y);
    printf("The Ans. is %d\n",ans);
}