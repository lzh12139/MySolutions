/**
 * Author: hrynb
 * Time: 2019-10-22 23:53:32
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

struct node{
	int l,r,n;
	node(){}
	node(int _l,int _r):l(_l),r(_r){}
	bool operator<(const node &b)const{
		return l!=b.l?l<b.l:r<b.r;
	}
};
int vis[200010],sum[200010];
node q[200010];

int main(){
	int n,k;sc(n),sc(k);
	for(int i=1;i<=n;i++){
		sc(q[i].l),sc(q[i].r),q[i].n=i;
	}
	sort(q+1,q+1+n);
	multiset<pii>pq;
	int cnt=1,ans=0;
	for(int i=1;i<=200000;i++){
		while(q[cnt].l==i)pq.insert(mp(q[cnt].r,q[cnt].n)),cnt++;
		while(pq.size()>k){
			auto x=pq.end();x--;
			vis[x->ss]++;
			ans++;pq.erase(x);
		}
		while(!pq.empty()&&pq.begin()->first==i)pq.erase(pq.begin());
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)if(vis[i])printf("%d ",i);
}
