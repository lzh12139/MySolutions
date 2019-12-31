#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll C(int k,int n){
    ll u=1,d=1;
    for(int i=1;i<=k;i++)d=d*i;
    for(int i=1;i<=n-k;i++)d=d*i;
    for(int j=1;j<=n;j++)u=u*j;
    return u/d;
}
int main(){
    //printf("%lld\n",C(3,5));
    for(int i=2;i<=20;i++){
        int ans=0;
        for(int j=0;j<=i;j++)if(C(j,i)&1)ans++;
        printf("%d %d\n",i,ans);
    }
}