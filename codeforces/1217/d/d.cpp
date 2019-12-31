/**
 * Author: lzh12139
 * Time: 2019-09-05 23:37:36
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

set<int> v[5010];
int ans[5010],vis[5010],over[5010];

int dfs(int x){
    vis[x]++;
    for(auto i:v[x])
        if(vis[i]){
            if(!over[i])return 1;
        }
        else return dfs(i);
    over[x]++;
    return 0;
}

int main(){
    int n,m;sc(n),sc(m);
    for(int i=1;i<=m;i++){
        int x,y;sc(x),sc(y);
        v[x].insert(y);
        if(x>y)ans[i]=2;
        else ans[i]=1;
    }
    int ansn=1;

    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        memset(over,0,sizeof over);
        if(dfs(i)){
            ansn=2;break;
        }
    }
    
    printf("%d\n",ansn);
    if(ansn==2)for(int i=1;i<=m;i++)printf("%d ",ans[i]);
    else for(int i=1;i<=m;i++)printf("1 ");
}
