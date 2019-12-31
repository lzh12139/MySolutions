#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1010;
const ll inf=1e17;
struct node{
    ll to,val;
    node(){}
    node(ll _t,ll _v):to(_t),val(_v){}
    bool operator<(const node &b)const{
        return val>b.val;
    }
};
vector<node>v[N+10];
bool vis[N+10];
ll dis[N+10],firedis[N+10];
ll d[N+10][N+10];
ll dij(int s,int n,int inv){
    memset(vis,false,sizeof vis);
    for(int i=1;i<=n;i++)dis[i]=inf;
    dis[s]=0;
    priority_queue<node>pq;
    pq.push(node(s,0));
    while(!pq.empty()){
        node tmp=pq.top();pq.pop();
        if(vis[tmp.to])continue;
        vis[tmp.to]=true;
        for(int i=1;i<=n;i++)
            if(!vis[i]&&dis[tmp.to]+d[tmp.to][i]<dis[i]){
                dis[i]=dis[tmp.to]+d[tmp.to][i];
                pq.push(node(i,dis[i]));
            }
    }
    ll res=0;
    for(int i=1;i<=n;i++)res=max(res,dis[i]);
    if(inv)for(int i=1;i<=n;i++)firedis[i]=min(dis[i],firedis[i]);
    return res;
}
int a[N+10];
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int v,e,s,k,c;
        scanf("%d%d%d%d%d",&v,&e,&s,&k,&c);
        for(int i=1;i<=k;i++)scanf("%d",&a[i]);
        for(int i=1;i<=v;i++)for(int o=1;o<=v;o++)d[i][o]=inf;
        for(int i=1;i<=v;i++)firedis[i]=inf;
        for(int i=1;i<=e;i++){
            int x,y,z;scanf("%d%d%d",&x,&y,&z);
            d[x][y]=d[y][x]=min(d[x][y],1ll*z);
        }
        ll hero=dij(s,v,0),fire=0;
        for(int i=1;i<=k;i++)dij(a[i],v,1);
        for(int i=1;i<=v;i++)fire=max(fire,firedis[i]);
        if(hero<=fire*c)printf("%lld\n",hero);
        else printf("%lld\n",fire);
    }
}