#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

pii p[200010];
ll mul(pii a, pii b, pii c)
{
    pii x = { c.ff - a.ff, c.ss - a.ss }, y = { b.ff - a.ff, b.ss - a.ss };
    return 1ll * x.ss * y.ff - 1ll * x.ff * y.ss;
}
int main()
{
    IOS;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].ff >> p[i].ss;
    p[n + 1] = p[1], p[n + 2] = p[2];
    ll ans = 4e18 + 10;
    for (int i = 1; i <= n; i++)
        ans = min(ans, mul(p[i], p[i + 1], p[i + 2]));
    cout << ans;
}