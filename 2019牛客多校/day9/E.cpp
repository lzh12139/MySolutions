#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back
#define ull unsigned long long

int f[100010],sz[100010];
int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}
ll ch1,ch2,cnt;
bool add(int x,int y) {
	int fx=find(x),fy=find(y);
	if(fx==fy)return false;
	cnt--;
	ch1=sz[fx],ch2=sz[fy];
	f[fy]=fx,sz[fx]+=sz[fy];
	return true;
}
ll init(int n) {
	ll res=1;
	int a[5];
	a[1]=2,a[2]=3,a[3]=4;
	for(int i=n; i>=n-3; i--) {
		int base=i;
		for(int o=1; o<=3; o++)if(base%a[o]==0)base/=a[o],a[o]=1;
		res=res*base;
	}
	return res;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	cnt=n;
	ll sum=n,ans=init(n);
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;

	for(int i=1; i<=m; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		if(!add(x,y))printf("%lld\n",ans);
		else if(ans){
			sum-=ch1*ch1+ch2*ch2;
			ans-=ch1*ch2*((1ll*(n-ch1-ch2)*(n-ch1-ch2)-sum)/2);
			sum+=(ch1+ch2)*(ch1+ch2);
			ans=max(ans,0ll);
			printf("%lld\n",ans);
		}else printf("0\n");
	}
}
