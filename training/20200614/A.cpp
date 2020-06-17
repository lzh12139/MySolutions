#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
const int N = 2e5 + 10;
ll fac[N + 10], invfac[N + 10];

ll quickmod(ll base, ll b)
{
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * base % mod;
        base = base * base % mod, b >>= 1;
    }
    return res;
}

void init()
{
    fac[0] = invfac[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = fac[i - 1] * i % mod;
        invfac[i] = quickmod(fac[i], mod - 2);
    }
}
ll C(int m, int n)
{
    if (m < n || m < 0 || n < 0)
        return 0;
    return fac[m] * invfac[n] % mod * invfac[m - n] % mod;
}
int main()
{
    init();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        if (1ll * m * (n - 1) < k) {
            cout << 0 << endl;
            continue;
        }
        ll ans = 0;
        for (int i = 0;; i++) {
            if (k < i * n || m < i)
                break;
            ll add = C(m, i) * C(k + m - 1 - i * n, m - 1) % mod;
            if (i & 1)
                ans = (ans + mod - add) % mod;
            else
                ans = (ans + add) % mod;
        }
        cout << ans << endl;
    }
}