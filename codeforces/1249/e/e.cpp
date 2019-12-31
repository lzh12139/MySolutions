/**
 * Author: hrynb
 * Time: 2019-10-22 22:58:06
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

int a[200010],b[200010];
int ans[200010][2],sum[200010],sub[200010],pre[200010];
int main(){
    int n,c;sc(n),sc(c);n--;
    for(int i=1;i<=n;i++)sc(a[i]),sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)sc(b[i]),sub[i]=a[i]-b[i];
    sub[0]=-1e9;
    ans[1][0]=a[1],ans[1][1]=b[1]+c;
    printf("0 %d ",min(ans[1][0],ans[1][1]));
    for(int i=2;i<=n;i++){
        ans[i][0]=min(ans[i-1][0],ans[i-1][1])+a[i];
        ans[i][1]=min(ans[i-1][0]+c,ans[i-1][1])+b[i];
        printf("%d ",min(ans[i][0],ans[i][1]));
        //printf("%d %d\n",ans[i][0],ans[i][1]);
    }
}
