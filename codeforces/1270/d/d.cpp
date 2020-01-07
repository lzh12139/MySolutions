/**
 * Author: hrynb
 * Time: 2020-01-07 14:55:46
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

pii a[510];
int main(){
    int n,k;scanf("%d%d",&n,&k);
    for(int i=1;i<=k+1;i++){
        printf("? ");
        for(int j=1;j<=k+1;j++){
            if(i!=j)printf("%d ",j);
        }
        printf("\n");
        fflush(stdout);

        scanf("%d %d",&a[i].ff,&a[i].ss);
    }

    int maxx=-1;
    for(int i=1;i<=k+1;i++)maxx=max(maxx,a[i].ss);

    int ans=0;
    for(int i=1;i<=k+1;i++)if(maxx==a[i].ss)ans++;
    printf("! %d\n",ans);
    fflush(stdout);
}
