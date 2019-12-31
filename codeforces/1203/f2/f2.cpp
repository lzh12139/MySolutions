/**
 * Author: hrynb
 * Time: 2019-09-16 20:13:27
**/

#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;
typedef map<int, int> mii;

vector<pii>u,d;
int dp[110][60010];
int main(){
	int n,r;scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++){
		int x,y;scanf("%d%d",&x,&y);
		if(y>=0)u.push_back(mp(x,y));
		else {
			x=max(x,-y);
			d.push_back(mp(x,-y));
		}
	}
	sort(u.begin(),u.end());
	sort(d.begin(),d.end(),[&](pii a,pii b){
		return a.ff-a.ss>b.ff-b.ss;
	});
	//for(auto i:d)printf("d: %d %d\n",i.ff,i.ss);
	int ans=0,add=0,mod=1e9+7;
	for(auto i:u)if(r>=i.ff)ans++,r+=i.ss;
	dp[0][r]=1;
	//printf("ans: %d %d\n",ans,r);
	for(int i=0;i<d.size();i++)
		for(int o=0;o<=r;o++){
			if(o>=d[i].ff)
				dp[i+1][o-d[i].ss]=max(dp[i+1][o-d[i].ss],dp[i][o]+1);
			dp[i+1][o]=max(dp[i+1][o],dp[i][o]);
		}
	int sz=d.size();
	for(int i=0;i<=r;i++)add=max(add,dp[sz][i]);
	printf("%d\n",add+ans-1);
}
