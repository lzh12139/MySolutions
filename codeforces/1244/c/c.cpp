/**
 * Author: hrynb
 * Time: 2019-10-17 10:50:27
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
    ll n,p,a,b;scl(n),scl(p),scl(a),scl(b);
    for(ll i=0;i<a;i++){
        if((p-b*i)%a==0){
            ll x=(p-b*i)/a;
            if(x<0||x>n||i>n||n-x-i<0||n-x-i>n)continue;
            printf("%lld %lld %lld\n",x,i,n-x-i);
            return 0;
        }
    }
    printf("-1");
}
