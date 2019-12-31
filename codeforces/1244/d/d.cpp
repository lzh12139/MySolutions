/**
 * Author: hrynb
 * Time: 2019-10-13 20:41:09
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

int a[5][100010],color[8][100010],cnt=0;
vector<int>v[100010];

ll dfs(int x,int pre,int col1,int col2){
    int cur=6-col1-col2;
    ll res=a[cur][x];
    color[cnt][x]=cur;
    for(auto i:v[x])
        if(i!=pre)res+=dfs(i,x,cur,col1);
    return res;
}

int main(){
    int n;sc(n);
    for(int j=1;j<=3;j++)
        for(int i=1;i<=n;i++)sc(a[j][i]);
    for(int i=1;i<n;i++){
        int x,y;sc(x),sc(y);
        v[x].pb(y),v[y].pb(x);
    }
    for(int i=1;i<=n;i++)if(v[i].size()>=3){printf("-1");return 0;}
    for(int i=1;i<=n;i++)
        if(v[i].size()==1){
            ll ans=1e18,ansn=0;
            for(int j=1;j<=3;j++)
                for(int k=1;k<=3;k++)
                    if(j!=k){
                        cnt++;
                        color[cnt][i]=j,color[cnt][v[i][0]]=k;
                        ll tmp=a[j][i]+a[k][v[i][0]];
                        for(auto o:v[v[i][0]])
                            if(o!=i)tmp+=dfs(o,v[i][0],k,j);
                        
                        if(tmp<ans)ans=tmp,ansn=cnt;
                    }
            
            printf("%lld\n",ans);
            for(int i=1;i<=n;i++)printf("%d ",color[ansn][i]);
            return 0;
        }
}
