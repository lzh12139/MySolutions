#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

const ll mod=1e9;
ll a[10010];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	a[0]=0,a[1]=1;
	ll ans=1;
	for(int i=2; i<=n; i++) {
		a[i]=(a[i-1]+a[i-2])%mod;
		ll res=a[i];
		for(int o=2; o<=m; o++)res=a[i]*res%mod;
		ans+=res;
		printf("%lld %lld\n",res,ans);
	}
}

