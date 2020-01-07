/**
 * Author: hrynb
 * Time: 2020-01-07 15:02:53
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
typedef pair<ll, ll> pii;
typedef map<int, int> mii;

pii p[1010];
map<ll,vector<pii>>m;
int ans[1010],f[1010];

int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&p[i].ff,&p[i].ss);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			ll dis=(p[i].ff-p[j].ff)*(p[i].ff-p[j].ff)+(p[i].ss-p[j].ss)*(p[i].ss-p[j].ss);
			m[dis].push_back({i,j});
		}

	for(auto i:m){
		if(i.ss.size()<=1)continue;
		for(auto j:i.ss)f[j.ff]++,f[j.ss]++;
	}
	V ans;
	for(int i=1;i<=n;i++)
		if(!f[i])ans.push_back(i);
	printf("%d\n",ans.size());
	for(auto i:ans)printf("%d ",i);
}
