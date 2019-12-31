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

int a[100010],vis[100010];
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i),vis[i]=1;
		vis[0]=1;
		priority_queue<pii>pq;
		up(i,1,n)if(i*2>n)pq.push(mp(a[i],i));
		int move=1;
		ll ans1=0,ans2=0;
		while(!pq.empty()){
			if(move&1){
				int p=pq.top().ss;
				ans1+=pq.top().ff,vis[p]--;
				if(!vis[p^1]&&p!=1)pq.push(mp(a[p/2],p/2));
				pq.pop();
			}else {
				int p=pq.top().ss;
				ans2+=pq.top().ff,vis[pq.top().ss]--;
				if(!vis[p^1]&&p!=1)pq.push(mp(a[p/2],p/2));
				pq.pop();
			}
			move++;
		}
		printf("%lld %lld\n",ans1,ans2);
	}
}
