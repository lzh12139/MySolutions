/**
 * Author: hrynb
 * Time: 2019-11-27 21:52:30
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

int main(){
    int t;sc(t);
    while(t--){
        int a,b;sc(a),sc(b);
        int tmp=b/a,less=b%a;
        ll ans=1ll*(a-less)*tmp*tmp+1ll*less*(tmp+1)*(tmp+1);
        printf("%lld\n",ans);
    }
}