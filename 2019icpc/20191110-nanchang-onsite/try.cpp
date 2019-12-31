#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll quick_pow(ll base,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*base%mod;
		b>>=1;base=base*base%mod;
	}
	return res;
}
const int N=1e5+10;
ll a[N],back[N],pre[N],fac[N];
ll Lagrange(ll n,ll k){
	if(k<=n)return a[k];
	back[n+1]=1,pre[0]=k%mod;
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]*((k-i)%mod)%mod;
	for(int i=n;i>=0;i--)back[i]=back[i+1]*((k-i)%mod)%mod;

	ll ans=a[0]*back[1]%mod*fac[n]%mod;
	if(n&1)ans=-ans;
	for(int i=1;i<=n;i++)
		if((n-i)&1)
			ans=(ans-a[i]*pre[i-1]%mod*back[i+1]%mod*fac[i]%mod*fac[n-i]%mod+mod)%mod;
		else 
			ans=(ans+a[i]*pre[i-1]%mod*back[i+1]%mod*fac[i]%mod*fac[n-i]%mod)%mod;
	return ans;
}

int main(){
	int t;scanf("%d",&t);

	const int T=1e5;
    ll cur=1;
	for(int i=1;i<=T;i++)cur=cur*i%mod;
	fac[T]=quick_pow(cur,mod-2);
	for(int i=T-1;i>=0;i--)fac[i]=fac[i+1]*(i+1)%mod;

    while(t--){
        ll n,k;scanf("%lld%lld",&n,&k);
        for(int i=1;i<=k+1;i++)
            a[i]=(quick_pow(i,k)+a[i-1])%mod;
        printf("%lld\n",Lagrange(k+1,n));
    }
}