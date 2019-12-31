/**
 * Author: lzh12139
 * Time: 2019-10-25 11:40:22
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

pii a[200010];
int n;ll s;
// 1-small 0-big
int check(int x){
    int d=0,u=0;
    ll tmp=0;
    for(int i=1;i<=n;i++)
        if(a[i].ss<x)tmp+=a[i].ff,d++;
        else if(a[i].ff>x)tmp+=a[i].ff,u++;

    if(d>n/2)return 0;
    if(u>n/2)return 1;
    
    for(int i=1;i<=n;i++)
        if(a[i].ff<=x&&x<=a[i].ss){
            if(d<n/2)tmp+=a[i].ff,d++;
            else tmp+=x;
        }

    return tmp<=s;
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d%lld",&n,&s);
        for(int i=1;i<=n;i++)scanf("%d%d",&a[i].ff,&a[i].ss);
        sort(a+1,a+1+n);
        int l=1,r=1e9;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid))l=mid+1;
            else r=mid-1;
        }
        printf("%d\n",l-1);
    }
}
