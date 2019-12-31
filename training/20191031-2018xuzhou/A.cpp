#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long ;

ull k1,k2;
ull cal(){
    ull k3=k1,k4=k2;
    k1=k4;
    k3^=k3<<23;
    k2=k3^k4^(k3>>17)^(k4>>26);
    return k2+k4;
}

struct node{
    int u,v;
    ull w;
}a[100010];

int n,m;
int f[100010];
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
bool add(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy){
        f[fx]=fy;
        return 1;
    }
    return 0;
}

void solve(){
    scanf("%d%d%llu%llu",&n,&m,&k1,&k2);
    for(int i=1;i<=m;i++){
        a[i].u=cal()%n+1;
        a[i].v=cal()%n+1;
        a[i].w=cal();
    }

    sort(a+1,a+1+m,[](node a,node b){
        return a.w<b.w;
    });
    for(int i=1;i<=100;i++)printf("%llu\n",a[i].w);
    const int mod=1e9+7;
    ull ans=0;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        if(add(a[i].u,a[i].v))ans=ans+a[i].w;
    }
    printf("%llu\n",ans%mod);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
}