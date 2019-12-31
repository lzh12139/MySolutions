#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

int cnt[10][110];
void pre() {
	for(int i=1; i<=100; i++) {
		int cmp=i;
		while(cmp) {
			cnt[cmp%10][i]++;
			cmp/=10;
		}
		for(int o=0; o<=9; o++)cnt[o][i]+=cnt[o][i-1];
	}
}
ll cal(ll d,ll x) {
	ll base=x;
	int a[30],c=0;
	while(x>100)a[++c]=x%10,x/=10;
	ll res=cnt[d][x],now=x;
	for(int i=c; i>=1; i--) {
		res=res*10+now+1;
		for(ll o=now*10+9; o>now*10+a[i]; o--) {
			ll cmp=o;
			while(cmp) {
				if(cmp%10==d)res--;
				cmp/=10;
			}
		}
		if(res<0)return -1;
		now=now*10+a[i];
	}
	return res-base;
}
int main() {
	pre();
	//printf("%lld\n",cal(1,199981));
	int t;
	scanf("%d",&t);
	while(t--) {
		ll d,n;
		scanf("%lld%lld",&d,&n);
		if(n==0) {
			printf("0\n");
			continue;
		}
		if(d==1&&n<199981) {
			printf("1\n");
			continue;
		}
		if(cal(d,n)==0) {
			printf("%lld\n",n);
			continue;
		}
		ll rr=cal(d,n);
		if(rr>0)rr=1;
		else rr=-1;
		ll l_=cal(d,199981);
		if(l_>0)l_=1;
		else l_=-1;
		ll l=199981,r=n;
		ll ans=0;
		while(l<=r) {
			ll mid=l+r>>1;
			ll x=cal(d,mid);
			if(x<0)r=mid-1;
			if(x==0)ans=max(ans,mid),l=mid+1;
			else if(x*rr>0)r=mid-1;
			else l=mid+1;
		}
		printf("%lld\n",ans);
	}
}
