/**
 * Author: lzh12139
 * Time: 2019-10-16 22:47:52
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

int to[100010],a[100010],minn[100010];
int main(){
    int n;sc(n);
    for(int i=1;i<=n;i++){
        int x;sc(x);to[x]=i;
    }
    minn[n+1]=1e9;
    int ans=0;
    for(int i=1;i<=n;i++){
        int x;sc(x);a[i]=to[x];
    }
    for(int i=n;i>=1;i--)minn[i]=min(minn[i+1],a[i]);
    for(int i=1;i<=n;i++)if(a[i]>minn[i+1])ans++;
    printf("%d",ans);
}
