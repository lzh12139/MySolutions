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
ll fac[200010], inv[200010];
ll C(int m, int n)
{
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= 200000; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[200000] = qp(fac[200000], mod - 2);
    for (int i = 200000 - 1; i >= 1; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
    int n, k;
    cin >> n >> k;
    k = min(n - 1, k);
    for (int i = 1; i <= n; i++)
        dp[i] = C(i - 1, n - 1);
    ll ans = 1;
    for (int i = 1; i <= k; i++)
        ans = (ans + C(i, n) * dp[n - i] % mod) % mod;
    cout << ans;
}
