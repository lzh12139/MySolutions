/**
 * Author: hrynb
 * Time: 2019-11-27 23:13:34
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

vector<pii>v[200010];
int a[200010],f[200010];
int m,n,k,t;
int check(int x){
    int cur=n+1,clear=0;
    for(int i=1;i<=n;i++){
        for(auto j:v[i]){
            if(j.ss>x){
                if(clear<j.ff){
                    cur+=2*(j.ff-clear);
                    clear=j.ff;
                }
            }
        }
        clear=max(clear,i);
    }

    if(cur<=t)return 1;
    else return 0;
}
int main(){
    sc(m),sc(n),sc(k),sc(t);
    for(int i=1;i<=m;i++)sc(a[i]);
    sort(a+1,a+1+m);
    for(int i=1;i<=k;i++){
        int x,y,z;sc(x),sc(y),sc(z);
        v[x].pb(mp(y,z));
    }

    int l=1,r=m;
    int ans=0;
    while(l<=r){
        int mid=l+r>>1;
        int cur=a[mid];
        if(check(cur))ans=max(ans,m-mid+1),r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",ans);
}
