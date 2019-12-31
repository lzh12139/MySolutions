/**
 * Author: hrynb
 * Time: 2019-10-09 11:37:10
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

int a[300010],dp[300010];
pii v[300010];
int main(){
    int t;sc(t);
    while(t--){
        int n;sc(n);
        for(int i=1;i<=n;i++)v[i]=mp(1e9,-1),dp[i]=1;
        for(int i=1;i<=n;i++)sc(a[i]),v[a[i]].ff=min(v[a[i]].ff,i),v[a[i]].ss=max(v[a[i]].ss,i);
        int cnt=0;
        for(int i=1;i<=n;i++)if(v[i].ff!=1e9)v[++cnt]=v[i];
        n=cnt;

        int ans=n;
        if(n==1){
            pr(0,'\n');continue;
        }
        for(int i=2;i<=n;i++){
            if(v[i-1].ss<v[i].ff)dp[i]=dp[i-1]+1;
            ans=min(ans,n-dp[i]);
        }
        pr(ans,'\n');
    }
}
