
#include <stdio.h>

void display(int arr[],int n){
    for(int i=n-1;i>=0;i--){
        printf("%d",arr[i]);
    }
}

int fibbo(int arr[],int arr1[],int n){
    int i=0,j=0;
    int carry = 0;
    int a=0;
    while(a<n){
        int p = arr[i]+arr1[j]+carry;
        arr[i++] = p%10;
        carry = p/10;
        j++;
        a++;
    }
    while(carry){
        arr[i++] = carry%10;
        carry = carry/10;
    }
    return i;
}

void fib(int n){
    int a[3001]={0};
    int b[3001] = {0};
    a[0] =0;
    b[0]=1;
    int s1 = 1,s2=1;
    for(int i=2;i<=n;i++){
        int t=s1>s2?s1:s2;
        if(i%2==0){
           s1= fibbo(a,b,t);
        }
        else{
          s2=  fibbo(b,a,t);
        }
         
    }
    if(n%2==0){
        display(a,s1);
    }
    else{
        display(b,s2);
    }


}

int main(){
    int n;
   printf("Enter the position at which you want term of fibonacci sequence\n");
    scanf("%d",&n);
    fib(n);
    return 0;
}