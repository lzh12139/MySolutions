/**
 * Author: lzh12139
 * Time: 2019-10-16 23:11:24
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
 
struct node{
    int x,y,z,n;
    node(){}
    node(int _x,int _y,int _z,int _n):x(_x),y(_y),z(_z),n(_n){}
    bool operator<(const node &b)const{
        if(y!=b.y)return y<b.y;
        return z<b.z;
    }
};
bool cmp(node a,node b){
    if(a.z!=b.z)return a.z<b.z;
    return a.y<b.y;
}
map<int,int>m;
vector<node>v[50010];
int has[50010],x[50010],y[50010],z[50010],hashh[50010];
node q[50010];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,cnt=0;sc(n);
    for(int i=1;i<=n;i++){
        sc(x[i]),sc(y[i]),sc(z[i]);
        hashh[i]=x[i];
    }
    sort(hashh+1,hashh+1+n);
    cnt=unique(hashh+1,hashh+1+n)-hashh-1;
    for(int i=1;i<=cnt;i++)m[hashh[i]]=i;
    for(int i=1;i<=n;i++)v[m[x[i]]].pb(node(x[i],y[i],z[i],i));
    for(int i=1;i<=cnt;i++)
        if(v[i].size()>=2){
            sort(all(v[i]));
            for(int o=0;o<v[i].size();o++)has[o]=1;
            for(int o=1;o<v[i].size();o++){
                if(v[i][o].y==v[i][o-1].y)
                    printf("%d %d\n",v[i][o].n,v[i][o-1].n),
                    has[o]=0,has[o-1]=0,o++;
            }
            vector<node>cur;
            for(int o=0;o<v[i].size();o++)if(has[o])cur.pb(v[i][o]);
 
            /*sort(all(cur),cmp);
            for(int o=0;o<cur.size();o++)has[o]=1;
            for(int o=1;o<cur.size();o++){
                if(cur[o].z==cur[o-1].z)
                    printf("%d %d\n",cur[o].n,cur[o-1].n),
                    has[o]=0,has[o-1]=0,o++;
            }
            vector<node>tmp;
            for(int o=0;o<cur.size();o++)if(has[o])tmp.pb(cur[o]);*/
 
            for(int o=1;o<cur.size();o+=2)printf("%d %d\n",cur[o].n,cur[o-1].n);
            if(cur.size()&1){
                node x=cur.back();
                v[i].clear();
                v[i].pb(x);
            }
            else v[i].clear();
        }
    node x;
    int has=0;
    for(int i=1;i<=cnt;i++)
        if(!v[i].empty()){
            q[++has]=v[i][0];
        }
    for(int o=2;o<=has;o+=2)printf("%d %d\n",q[o].n,q[o-1].n);
}
/*
8
0 0 0
0 0 1
0 1 0
0 1 1
1 0 0
1 0 1
1 1 0
1 1 1
*/