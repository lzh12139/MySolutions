#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back
typedef pair<int,ll> pii;

struct node {
	int x,k;
	ll b;
	node() {};
	node(int _x,int _k,ll _b):x(_x),k(_k),b(_b) {};
} a[900010];

int main() {
	int n;
	ll ans=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		ll l,r;
		scanf("%lld%lld",&l,&r);
		a[3*i-2]=node(2*l, 1,-2*l);
		a[3*i-1]=node(l+r,-2,2*l+2*r);
		a[3*i]  =node(2*r, 1,-2*r);
	}
	sort(a+1,a+1+3*n,[&](node a,node b) {
		return a.x<b.x;
	});
	pii cur=mp(0,ans);
	for(int i=1; i<=3*n; i++) {
		int base=i;
		while(a[base].x==a[i].x&&i<=3*n)cur.ff+=a[i].k,cur.ss+=a[i].b,i++;
		ans=max(ans,cur.ss+max(1ll*cur.ff*a[base].x,1ll*cur.ff*a[i].x));
		i--;
	}
	printf("%lld\n",ans);
}
