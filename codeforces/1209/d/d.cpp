/**
 * Author: lzh12139
 * Time: 2019-09-14 21:34:38
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
typedef unsigned long long ull;
typedef vector<int> V;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<string, int> msi;

pii deg[100010];
int eat[100010],ans=0;
map<pii,int>m;
vector<int>v[100010];
void dfs(int x){
	eat[x]++;
	for(auto i:v[x])
		if(!eat[i])dfs(i),ans++;
}
int main(){
	int n,k;sc(k),sc(n);
	for(int i=1;i<=n;i++){
		int a,b;sc(a),sc(b);
		v[a].pb(b),v[b].pb(a);
		deg[a].ff++,deg[b].ss++;
	}
	for(int i=1;i<=k;i++)deg[i].ss=i;
	sort(deg+1,deg+1+k,greater<pii>());
	for(int i=1;i<=k;i++){
		if(eat[deg[i].ss])continue;
		dfs(deg[i].ss);
	}
	printf("%d\n",n-ans);
}
