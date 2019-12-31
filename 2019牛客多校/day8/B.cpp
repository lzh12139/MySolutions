#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		int x;
		scanf("%d",&x);
		v[x].pb(i);
	}
	ll ans=0;
	for(int i=1; i<=n; i++)ans+=1ll*i*(n-i+1);
	for(int i=1; i<=n; i++) {
		if(v[i].size()<=1)continue;
		int sz=v[i].size();
		for(int o=0; o<sz-1; o++) {
			int l,r;

			l=v[i][o];

			r=n-v[i][o+1]+1;

			ans-=1ll*l*r;
		}
	}
	printf("%lld\n",ans);
}
