#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define up(i,a,b) for(int i=(a);i<=(b);i++)
#define down(i,a,b) for(int i=(a);i>=(b);i--)
#define pb emplace_back
typedef pair<ll,ll> pii;
typedef vector<int> V;

ll check(ll n,int m) {
	int cnt=0;
	for(ll i=n+1;; i++)
		if(__gcd(i,n)==1) {
			cnt++;
			if(cnt==m)return i;
		}
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		ll k;
		int m,ok=0;
		scanf("%lld%d",&k,&m);
		for(ll i=max(2ll,k-500ll); i<=k+500ll; i++)
			if(check(i,m)-i==(k^i)) {
				printf("%lld\n",i);
				ok++;
				break;
			}
		if(!ok)printf("-1\n");
	}
}
