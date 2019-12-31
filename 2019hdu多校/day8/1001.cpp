#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

int a[1000010],b[1000010];
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		for(int i=1; i<=n; i++)scanf("%d%d",&a[i],&b[i]);
		a[n+1]=a[1],b[n+1]=b[1];
		if(n==1) {
			printf("0\n");
			continue;
		}
		ll ans=0,less=0;
		int l=2;
		for(int i=1; i<=n; i++) {
			int cmp=a[i];
			ll add=0;
			while(l<=n+1&&cmp) {
				if(l==i||(i==1&&l==n+1)) {
					if(i==1&&l==n+1)break;
					if(cmp<=less)ans+=cmp,less-=cmp,cmp=0,add+=b[l];
					else ans+=less,cmp-=less,less=0,add+=b[l],l++;
				} else {
					if(cmp<=less)ans+=cmp,less-=cmp,cmp=0;
					else if(cmp<=b[l]+less)ans+=cmp,b[l]-=cmp-less,less=0,cmp=0;
					else ans+=b[l]+less,cmp-=b[l]+less,less=0,b[l]=0,l++;
				}
			}
			if(cmp<=less)ans+=cmp,less-=cmp,cmp=0;
			else ans+=less,cmp-=less,less=0;
			less+=add;
		}
		printf("%lld\n",ans);
	}
}
