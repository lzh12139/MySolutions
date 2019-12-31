/**
 * Author: lzh12139
 * Time: 2019-12-15 17:16:36
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
    int a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
    int ans=0;
    for(int i=0;i<=a;i++){
        if(d<i)continue;
        ans=max(ans,i*e+f*max(min(d-i,min(b,c)),0));
    }
    cout<<ans<<endl;
}
