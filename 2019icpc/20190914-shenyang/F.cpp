#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define mp make_pair
#define pb emplace_back

int a[500010],n,k;
int checkr(int x){
	ll less=k;
	for(int i=n;i>=1;i--)
		if(a[i]<=x)return less>=0;
		else less-=a[i]-x;
	return less>=0;
}
int checkl(int x){
	ll less=k;
	for(int i=1;i<=n;i++)
		if(a[i]>=x)return less>=0;
		else less-=x-a[i];
	return less>=0;
}
int main(){
	while(~scanf("%d%d",&n,&k)){
		ll sum=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
		sort(a+1,a+1+n);

		ll a1=sum/n,a2=sum%n,bal=0,inf;
		if(a2==0)inf=1;
		for(int i=inf;i<=n;i++)bal+=max(0ll,a[i]-a1);
		if(bal<=k){
			if(a2==0)printf("0\n");
			else printf("1\n");
			continue;
		}

		int l=1,r=1e9,mid;
		while(l<=r){
			mid=l+r>>1;
			if(checkr(mid)==0)l=mid+1;
			else r=mid-1;
		}
		int ansr=r;
		if(checkr(r)==0)ansr++;

		l=1,r=1e9;
		while(l<=r){
			mid=l+r>>1;
			if(checkl(mid)==1)l=mid+1;
			else r=mid-1;
		}
		int ansl=l;
		if(checkl(l)==0)ansl--;
		printf("%d\n",ansr-ansl);
	}
}