/**
 * Author: lzh12139
 * Time: 2019-10-17 21:41:00
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

const ll mod=1e9+7;
ll quick(ll base,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*base%mod;
        base=base*base%mod;b>>=1;
    }
    return res;
}

int main(){
    int n,m;sc(n),sc(m);
    printf("%lld\n",quick((quick(2,m)-1+mod)%mod,n));
}
