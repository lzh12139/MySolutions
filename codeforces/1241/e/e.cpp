/**
 * Author: hrynb
 * Time: 2019-10-09 12:34:50
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
#define prl(a, b) printf("%lld%c", a, b)
#define all(v) v.begin(), v.end()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define _yes printf("Yes\n")
#define _no printf("No\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;
typedef map<int, int> mii;

struct edge{
    int u,v,w;
    edge(){}
    edge(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
}e[500010];
int a[500010];
int main(){
    int t;sc(t);
    while(t--){
        int n,k;sc(n),sc(k);
        for(int i=1;i<n;i++){
            int u,v,w;sc(u),sc(v),sc(w);
            e[i]=edge(u,v,w);
        }
        sort(e+1,e+n,[&](edge a,edge b){
            return a.w>b.w;
        });
        for(int i=1;i<=n;i++)a[i]=k;
        ll ans=0;
        for(int i=1;i<n;i++){
            if(a[e[i].u]&&a[e[i].v])ans+=e[i].w,a[e[i].u]--,a[e[i].v]--;
        }
        prl(ans,'\n');
    }
}