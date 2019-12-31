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

struct node {
	int x,y,k,t;
} a[20];
int cnt[40];
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0; i<=30; i++)cnt[i]=0;
		for(int i=1; i<=n; i++)scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].k,&a[i].t);
		sort(a+1,a+1+n,[&](node &a,node &b) {
			return a.y-a.x>b.y-b.x;
		})
		ll ans=0;

		int l=-m,r=a[1].y-a[1].x;
		for(int i=1; i<=n+1; i++) {
			int add=(r-l+1)/30;
			for(int p=0; p<30; p++) {
				for(int o=1; o<=n; o++) {
					if(o<i&&(p-(a[o].y-a[o].x+a[o].t)%30+9000)%30%a[o].k==0)cnt[p]++;
					else if(o>=i&&((a[o].y-a[o].x-a[o].t)%30+9000-p)%30%a[o].k==0)cnt[p]++;
				}
			}


			if(i<n)l=r+1,r=a[i+1].y-a[i+1].x;
			else l=r,r=m;
		}

		printf("%lld\n",ans);
	}
}
