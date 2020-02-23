#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
ll qp(ll base, ll b)
{
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return res;
}
ll C(int m, int n)
{
    ll res = 1;
    for (int i = n - m + 1; i <= n; i++)
        res = res * i % mod;
    for (int i = 1; i <= m; i++)
        res = res * qp(i, mod - 2) % mod;
    return res;
}
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    ll ans = (qp(2, n) - 1 - C(a, n) - C(b, n) + 2 * mod) % mod;
    cout << ans;
}
