#include<bits/stdc++.h>
using namespace std;
#define check1(x) x>=1&&x<=n&&vis[x]==0
#define check2(x) x>=n+1&&x<=2*n&&vis[x]==0
int vis[100],ans,n;
void dfs(int x,int less){
    //printf("%d ",x);
    if(less==1){
        //for(int i=1;i<=2*n;i++)printf("%d ",vis[i]);
        ans++;return;
    }
    vis[x]++;
    if(x>n){
        for(int i=-1;i<=1;i++)
            if(check1(x-n+i))dfs(x-n+i,less-1);
        if(check2(x-1))dfs(x-1,less-1);
        if(check2(x+1))dfs(x+1,less-1);
    }
    else{
        for(int i=-1;i<=1;i++)
            if(check2(x+n+i))dfs(x+n+i,less-1);
        if(check1(x-1))dfs(x-1,less-1);
        if(check1(x+1))dfs(x+1,less-1);
    }
    vis[x]--;
}
int main(){
    while(~scanf("%d",&n)){
        ans=0;
        for(int i=1;i<=2*n;i++){
            memset(vis,0,sizeof vis);
            dfs(i,2*n);
        }
        printf("%d\n",ans);
    }
}
/*
2 24 96 416 1536 5504 18944 64000 212992 702464 2301952
*/