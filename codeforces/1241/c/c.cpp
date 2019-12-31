/**
 * Author: hrynb
 * Time: 2019-10-09 11:00:39
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

int p[200010],a,b,x,y;
ll base,k;
ll sum[200010];
int check(int cur){
    ll res=0;
    int i=cur/base,o=cur/a,p=cur/b;
    o-=i,p-=i;
    res+=sum[min(cur,i)]*(x+y);
    res+=(sum[min(cur,i+o)]-sum[min(cur,i)])*x;
    res+=(sum[min(cur,i+o+p)]-sum[min(cur,i+o)])*y;
    //res+=sum[cur]-sum[min(cur,i+o+p)];
    return res>=k;
}
int main(){
    int t;sc(t);
    while(t--){
        int n;sc(n);
        for(int i=1;i<=n;i++)sc(p[i]),p[i]/=100;
        sort(p+1,p+1+n,greater<int>());
        for(int i=1;i<=n;i++)sum[i]=sum[i-1]+p[i];sc(x),sc(a),sc(y),sc(b);scl(k);
        base=1ll*a*b/__gcd(a,b);
        if(x<y)swap(x,y),swap(a,b);

        int l=1,r=n,ans=1e9;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid))r=mid-1,ans=min(mid,ans);
            else l=mid+1;
        }
        if(ans==1e9)pr(-1,'\n');
        else pr(ans,'\n');
    }
}
