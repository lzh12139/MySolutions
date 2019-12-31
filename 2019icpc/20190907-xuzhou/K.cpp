#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define mp make_pair
map<pii,int>m;
set<pii>s;
set<int>v[6000000];
pii a[1010];
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;scanf("%d%d",&x,&y);
        x*=2,y*=2;
        a[i]=mp(x,y);
        s.insert(mp(x,y));
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        for(int o=i;o<=n;o++){
            int x=(a[i].ff+a[o].ff)>>1,y=(a[i].ss+a[o].ss)>>1;

            int cur;
            if(!m[mp(x,y)])m[mp(x,y)]=++cnt,cur=cnt;
            else cur=m[mp(x,y)];

            v[cur].insert(i),v[cur].insert(o);
        }
    int ans=1e9;
    for(int i=1;i<=cnt;i++)ans=min(ans,n-(int)v[i].size());
    printf("%d\n",ans);
}