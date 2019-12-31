#include<bits/stdc++.h>
using namespace std;
int a[230];
int main(){
    int n=20;
    for(int p=1;p<=10;p++){
        for(int i=0;i<n;i++)a[i]=0;
        a[0]=1;
        int cur=0;
        for(int i=2;i<=n;i++){
            int cmp=p+1;
            while(cmp){
                cur=(cur+1)%n;
                if(!a[cur])cmp--;
            }
            a[cur]=i;
        }
        for(int i=0;i<n;i++)printf("%2d ",a[i]);printf("\n");
    }
}