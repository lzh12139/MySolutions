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

struct node {
	ll a,b;
	bool operator<(const node &bb)const {
		return b*bb.a>a*bb.b;
	}
} a[100010];
pii ans[100010];
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n,ansn=0,gg=0;
		ll c;
		scanf("%d%lld",&n,&c);
		up(i,1,n)scanf("%lld%lld",&a[i].a,&a[i].b);
		sort(a+1,a+1+n);

		ll sa=0,sb=0;
		up(i,1,n)sa+=-a[i].a,sb+=-a[i].b;
		pii l=mp(-a[1].b,a[1].a),r=mp(-a[2].b,a[2].a);
		
		ll x1=c-sb,x2=sa;
		if(x2==0){
			if(x1==0){
				printf("-1\n");continue;
			}
		}
		if(x2<0)x1=-x1,x2=-x2;
		if(x1*l.ss<=x2*l.ff&&x2!=0)ans[++ansn]=mp(x1,x2);
		sa+=2*a[1].a,sb+=2*a[1].b;
		
		up(i,2,n) {
			x1=c-sb,x2=sa;
			if(x2==0) {
				if(x1==0) {
					gg++;
					break;
				}
				else {
					l=r,r=mp(-a[i+1].b,a[i+1].a);
					sa+=2*a[i].a,sb+=2*a[i].b;
					continue;
				}
			}
			if(x2<0)x1=-x1,x2=-x2;
			if(l.ff*x2<l.ss*x1&&x1*r.ss<=x2*r.ff&&x2!=0)ans[++ansn]=mp(x1,x2);

			l=r,r=mp(-a[i+1].b,a[i+1].a);
			sa+=2*a[i].a,sb+=2*a[i].b;
		}

		x1=c-sb,x2=sa;
		if(x2==0){
			if(x1==0){
				printf("-1\n");
				continue;
			}
		}
		if(x2<0)x1=-x1,x2=-x2;
		if(l.ff*x2<l.ss*x1&&x2!=0)ans[++ansn]=mp(x1,x2);

		if(gg)printf("-1\n");
		else {
			printf("%d",ansn);
			up(i,1,ansn) {
				ll g=__gcd(abs(ans[i].ff),ans[i].ss);
				printf(" %lld/%lld",ans[i].ff/g,ans[i].ss/g);
			}
			printf("\n");
		}
	}
}
