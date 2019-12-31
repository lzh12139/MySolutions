/**
 * Author: lzh12139
 * Time: 2019-09-05 22:45:33
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
typedef unsigned long long ull;
typedef vector<int> V;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<string, int> msi;

pii a[110];
int main(){
    int t;sc(t);
    while(t--){
        int n,x,maxx=0;sc(n),sc(x);
        for(int i=1;i<=n;i++){
            sc(a[i].ff),sc(a[i].ss);
            maxx=max(maxx,a[i].ff);
            int t=a[i].ff-a[i].ss;
            a[i].ss=a[i].ff,a[i].ff=t;
        }
        sort(a+1,a+1+n,greater<pii>());
        x-=maxx;
        if(x<=0){printf("1\n");continue;}
        if(a[1].ff<=0){printf("-1\n");continue;}
        int ans=1+x/a[1].ff+(x%a[1].ff!=0);
        pr(ans,'\n');
    }
}
