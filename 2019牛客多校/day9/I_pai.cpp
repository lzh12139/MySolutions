#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

int main() {
	ll ans=0,n,m,mod=1e9+7;scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	ans=(ans+((i*m)&m))%mod;
	printf("%lld\n",ans);
}
