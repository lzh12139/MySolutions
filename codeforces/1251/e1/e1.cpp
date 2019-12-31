/**
 * Author: lzh12139
 * Time: 2019-10-25 11:09:44
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

pii a[200010];
int vis[200010];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int m,p;scanf("%d%d",&m,&p);
			a[i]=mp(m,p);
		}
		int l=0,r=n;
		while(l<=r){
			int mid=l+r>>1;
			
		}
	}
}
