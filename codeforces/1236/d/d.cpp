/**
 * Author: hrynb
 * Time: 2019-10-22 18:52:56
**/
 
#include<bits/stdc++.h>
using namespace std;
#define mem(x, y) memset(x, (y), sizeof x)
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define sc(a) scanf("%d", &a)
#define scl(a) scanf("%lld", &a)
#define scs(a) scanf("%s", a)
#define pr(a, b) printf("%d%c", a, b)
#define prl(a, b) printf("%ll%c", a, b)
#define all(v) v.begin(), v.end()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define _yes printf("Yes\n")
#define _no printf("No\n")
 
typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;
typedef map<int, int> mii;
 
set<int>r[100010],c[100010];
int main(){
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)r[i].insert(0),r[i].insert(m+1);
	for(int i=1;i<=m;i++)c[i].insert(0),c[i].insert(n+1);
	r[1].insert(1),c[1].insert(1);
	for(int i=1;i<=k;i++){
		int x,y;scanf("%d%d",&x,&y);
		r[x].insert(y);c[y].insert(x);
	}
	int x=1,y=1,cur=0;
	int minr=0,maxr=m+1,minc=1,maxc=n+1;
	ll ans=1;
	while(1){
		//printf("%d %d %lld %d\n",x,y,ans,cur);
		if(cur==0){
			auto j=r[x].upper_bound(y);
			maxr=min(*j-1,maxr-1);
			if(y==maxr&&(x!=1||y!=1))break;
			ans+=maxr-y;
			y=maxr;
		}
		else if(cur==1){
			auto j=c[y].upper_bound(x);
			maxc=min(*j-1,maxc-1);
			if(x==maxc)break;
			ans+=maxc-x;
			x=maxc;
		}
		else if(cur==2){
			auto j=r[x].upper_bound(y);j--;
			minr=max(*j+1,minr+1);
			if(y==minr)break;
			ans+=y-minr;
			y=minr;
		}
		else if(cur==3){
			auto j=c[y].upper_bound(x);j--;
			minc=max(*j+1,minc+1);
			if(x==minc)break;
			ans+=x-minc;
			x=minc;
		}
		cur=(cur+1)%4;
	}
	if(ans==1ll*n*m-k)_yes;
	else _no;
}