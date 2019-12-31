/**
 * Author: hrynb
 * Time: 2019-11-15 16:21:51
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

int a[200010],b[200010],c[200010];
int main(){
    int x,y,z;sc(x),sc(y),sc(z);
    int n=x+y+z;
    for(int i=1;i<=x;i++)sc(a[i]);sort(a+1,a+1+x);
    for(int i=1;i<=y;i++)sc(b[i]);sort(b+1,b+1+y);
    for(int i=1;i<=z;i++)sc(c[i]);sort(c+1,c+1+x);

    for(int i=0;i<=n;i++)
}
