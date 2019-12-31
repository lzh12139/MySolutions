#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

ll exgcd(ll aa,ll bb,ll &x,ll &y) {
	if(bb==0) {
		x=1;
		y=0;
		return aa;
	}
	ll gcd_ab=exgcd(bb,aa%bb,x,y);
	ll temp=x;
	x=y;
	y=temp-aa/bb*y;
	return gcd_ab;
}

ll x0=0,c0=1;
ll a[150],mod[150];

bool ex_china(int num) {
	x0=a[0];
	c0=mod[0];
	for(int i=1; i<num; ++i) {
		ll right=a[i]-x0;
		ll holder0=0,holder1=0;
		ll gcd=exgcd(c0,mod[i],holder0,holder1);
		if(right%gcd!=0) {
			return false;
		}

		holder1=mod[i]/gcd;
		holder0*=right/gcd;
		holder0=(holder0%holder1+holder1)%holder1;
		x0+=holder0*c0;
		c0*=holder1;
		x0=(x0%c0+c0)%c0;
	}
	return true;
}

int main() {
	int n;
	ll maxx;
	scanf("%d%lld",&n,&maxx);
	for(int i=0; i<n; i++)scanf("%d%d",mod+i,a+i);
	if(ex_china(n)) {
		if(x0>=0&&x0<=maxx)printf("%lld\n",x0);
		else printf("he was probably lying\n");
	} else printf("he was definitely lying\n");
}
