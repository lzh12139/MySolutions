#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define mp make_pair
#define pb emplace_back

int vis[100010],monster[100010],f[100010],sz[100010];
vector<int>v[100010],mon;
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
void add(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy){
        f[fx]=fy;sz[fy]+=sz[fx],sz[fx]=sz[fy];
    }
}
void dfs_ans(int x){
    vis[x]++;
    for(auto i:v[x])
    if(!vis[i])
        if(!monster[i])dfs_ans(i);
        else mon.pb(i);
}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n,m,k;scanf("%d%d%d",&n,&m,&k);
        memset(vis,0,sizeof vis);
        memset(monster,0,sizeof monster);
        for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;
        mon.clear();
        for(int i=1;i<=n;i++)v[i].clear();

        for(int i=1;i<=m;i++){
            int a,b;scanf("%d%d",&a,&b);
            v[a].pb(b),v[b].pb(a);
        }
        for(int i=1;i<=k;i++){
            int a;scanf("%d",&a);
            monster[a]++;
        }
        dfs_ans(1);
        for(int i=1;i<=n;i++)
            if(!monster[i])
                for(auto o:v[i])
                    if(!monster[o])add(i,o);
        /*printf("sz: ");
        for(int i=1;i<=n;i++)printf("%d ",sz[find(i)]);printf("\n");
        printf("find: ");
        for(int i=1;i<=n;i++)printf("%d ",find(i));printf("\n");*/
        pii cur=mp(0,100000);
        int find1=find(1);
        for(auto i:mon){
            int u=0,d=v[i].size();
            for(auto o:v[i])if(find(o)!=find1&&!monster[o])u+=sz[find(o)];
            if(1ll*u*cur.ss>1ll*d*cur.ff)cur=mp(u,d);
        }
        printf("%.6lf\n",sz[find1]+1.0*cur.ff/cur.ss);
    }
}