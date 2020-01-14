/**
 * Author: lzh12139
 * Time: 2020-01-10 22:53:45
**/

#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("Yes\n")
#define _no printf("No\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

int ans;
void dfs(int n,V cur,int res){
    //printf("------%d %d\n",n,res);
    //for(auto i:cur)printf("%d ",i);printf("\n");
    if(!n||cur.empty()){ans=min(ans,res);return;}
    if(res>=ans)return;

    V v0,v1;
    int wei=1<<n-1;
    for(auto i:cur){
        if(i&wei)v1.pb(i);
        else v0.pb(i);
    }

    if(v0.empty())dfs(n-1,v1,res);
    else if(v1.empty())dfs(n-1,v0,res);
    else{
        dfs(n-1,v0,res+wei);
        dfs(n-1,v1,res+wei);
    }
}

int main(){
    int n,maxx=0;scanf("%d",&n);
    vector<int>a(n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]),maxx=max(maxx,a[i]);
    ans=maxx;
    int cnt=0;
    while(maxx)maxx>>=1,cnt++;

    dfs(cnt,a,0);
    printf("%d\n",ans);
}