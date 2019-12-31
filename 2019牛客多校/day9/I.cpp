#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

vector<ll>sum;
int main() {
	ll n,m;
	scanf("%lld%lld",&n,&m);
	ll p=m+m;
	ll ans=m,mod=1e9+7;
	ll f=-1,add=0;
	sum.pb(0);
	sum.pb(m);
	ll base=1,cmp=m;
	while(cmp){
		cmp>>=1,base<<=1;
	}
	base--;
	for(ll i=2; i<=n; i++)
		if((p&base)==m) {
			f=i-1;
			break;
		}
		else ans=(ans+(p&m))%mod,sum.pb(ans),p+=m;
	if(f==-1)printf("%lld\n",ans);
	else printf("%lld\n",(ans*(n/f)%mod+sum[n%f])%mod);
}
// 1000000000000000000 100000000000
