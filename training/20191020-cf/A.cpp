#include<bits/stdc++.h>
using namespace std;
int x[1010],y[1010],r[1010],vis[1100],ok=0;
vector<int>v[1100];
double dist(int i,int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
void push(int i,int j){
    //printf("%d %d\n",i,j);
    v[i].push_back(j),v[j].push_back(i);
}
int sgn(double x){
    if(fabs(x)<1e-6)return 0;
    if(x<0)return -1;
    return 1;
}
void dfs(int x,int fin1,int fin2){
    if(ok)return;
    if(x==fin1||x==fin2){
        ok=1;return;
    }
    vis[x]++;
    for(auto i:v[x])
        if(!vis[i]){
            //vis[i]++;
            dfs(i,fin1,fin2);
            //vis[i]--;
        }
}
int main(){
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)
        scanf("%d%d%d",&x[i],&y[i],&r[i]);
    //push(k+3,k+2);push(k+3,k+4);push(k+1,k+2);
    for(int i=1;i<=k;i++){
        if(x[i]-r[i]<=0)push(k+2,i);
        if(y[i]-r[i]<=0)push(k+1,i);
        if(x[i]+r[i]>=n)push(k+4,i);
        if(y[i]+r[i]>=m)push(k+3,i);
    }
    for(int i=1;i<=k;i++)
        for(int j=i+1;j<=k;j++){
            if(sgn(dist(i,j)-r[i]-r[j])<=0)push(i,j);
        }
    vis[k+1]++;
    dfs(k+1,k+2,k+3);

    memset(vis,0,sizeof vis);

    vis[k+4]++;
    dfs(k+4,k+2,k+3);
    
    if(!ok)printf("S");
    else printf("N");
}