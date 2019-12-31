#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

ll p[80];
struct node {
	ll n;
	int x,y;
} a[1000010];

int base;
void dfs(int n,ll cur,int x,int y,int k) {
	//printf("%d %lld %d %d %d\n",n,cur,x,y,k);
	if(k==0) {
		a[n].n=cur;
		return;
	}
	if(x<=p[k-1]) {
		if(y<=p[k-1]){
			if(base==1)base=2;
			else if(base==2)base=1;
			else if(base==3)cur+=2*p[2*(k-1)],base=3;
			else cur+=2*p[2*(k-1)],base=4;
			dfs(n,cur,x,y,k-1);
		}
		else {
			if(base==1)cur+=3*p[2*(k-1)],base=3;
			else if(base==2)cur+=p[2*(k-1)],base=2;
			else if(base==3)cur+=3*p[2*(k-1)],base=1;
			else cur+=p[2*(k-1)],base=4;
			dfs(n,cur,x,y-p[k-1],k-1);
		}
	} else {
		if(y<=p[k-1]) {
			if(base==1)cur+=p[2*(k-1)],base=1;
			else if(base==2)cur+=3*p[2*(k-1)],base=4;
			else if(base==3)cur+=p[2*(k-1)],base=3;
			else cur+=3*p[2*(k-1)],base=2;
			dfs(n,cur,x-p[k-1],y,k-1);
		} else 	{
			if(base==1)cur+=2*p[2*(k-1)],base=1;
			else if(base==2)cur+=2*p[2*(k-1)],base=2;
			else if(base==3)base=4;
			else base=3;
			dfs(n,cur,x-p[k-1],y-p[k-1],k-1);
		}		
	}
}

int main() {
	for(int i=0; i<=61; i++)p[i]=(1ll<<i);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++) {
		base=1;
		scanf("%d%d",&a[i].x,&a[i].y);
		dfs(i,0,a[i].x,a[i].y,k);
	}
	sort(a+1,a+1+n,[&](node a,node b) {
		return a.n<b.n;
	});
	for(int i=1; i<=n; i++)printf("%d %d\n",a[i].x,a[i].y);
}
