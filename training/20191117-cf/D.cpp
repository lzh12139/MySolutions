#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
ll poww[100010],sum[100010];
const int inv2=(mod+1)/2;
int main(){
    int n,k;scanf("%d%d",&n,&k);
    poww[0]=1;
    for(int i=1;i<=100000;i++)
        if(i&1)poww[i]=poww[i-1]*k%mod;
        else poww[i]=poww[i-1];
    //for(int i=1;i<=n;i++)printf("%lld ",poww[i]);
    sum[0]=1;
    for(int i=1;i<=100000;i++)
        sum[i]=(sum[i-1]+poww[i])%mod;
    
    ll ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+poww[i]*sum[n-i]%mod)%mod;
    ans=(ans-1ll*n*(n-1)%mod*inv2%mod*k%mod+mod)%mod;
    printf("%lld\n",ans);
}