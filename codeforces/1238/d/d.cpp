/**
 * Author: lzh12139
 * Time: 2019-10-08 23:20:56
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
#define prl(a, b) printf("%lld%c", a, b)
#define all(v) v.begin(), v.end()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define _yes printf("Yes\n")
#define _no printf("No\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;
typedef map<int, int> mii;

char s[300010];
int change[300010],nextt[300010];
int main(){
	int n;sc(n),scs(s+1);
	ll ans=1ll*n*(n+1)/2-n;
	int cur=s[1],curn=1;
	for(int i=2;i<=n;i++)
		if(cur!=s[i]){
			for(int j=curn;j<i;j++)nextt[j]=i-1;
		}
}