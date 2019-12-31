/**
 * Author: lzh12139
 * Time: 2019-09-14 22:09:26
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

int a[15][2010],ans,cnt,va[2010][15],n,m;
int sortt[2010];
V v[15],findd;
void dfs(int x){
    if(x==cnt+1){
        int sum=0,sz=v[1].size();
        for(int o=0;o<sz;o++){
            int mm=0;
            for(int i=1;i<=cnt;i++)mm=max(mm,v[i][o]);
            sum+=mm;
        }
        ans=max(ans,sum);return;
    }
    do{
        dfs(x+1);
    }while(next_permutation(v[x].begin(),v[x].end()));
}
bool cmp(int a,int b){
    for(int i=1;i<=n;i++)if(va[a][i]!=va[b][i])return va[a][i]>va[b][i];
    return false;
}
int main(){
    int t;sc(t);
    while(t--){
        sc(n),sc(m);

        findd.clear();
        for(int i=1;i<=4;i++)v[i].clear();
        ans=cnt=0;

        for(int i=1;i<=n;i++)for(int o=1;o<=m;o++)sc(a[i][o]),va[o][i]=a[i][o];
        for(int i=1;i<=m;i++)sort(va[i]+1,va[i]+1+n,greater<int>());
        for(int i=1;i<=m;i++)sortt[i]=i;
        sort(sortt+1,sortt+1+m,cmp);
        for(int i=1;i<=min(n,m);i++)findd.pb(sortt[i]);
        for(auto i:findd){
            cnt++;
            for(int o=1;o<=n;o++)v[cnt].pb(a[o][i]);
            sort(v[cnt].begin(),v[cnt].end());
        }
        dfs(1);
        printf("%d\n",ans);
    }
}
