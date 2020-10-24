#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long

const int N = 2e6;
const int mod = 998244353;
ll fac[N + 10], inv[N + 10];
ll quickpow(ll base, ll b)
{
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ans;
}
void pre()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[N] = quickpow(fac[N], mod - 2);
    for (int i = N - 1; i >= 1; i--) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}
ll C(ll n, ll m)
{
    return fac[m] * inv[n] % mod * inv[m - n] % mod;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << n << endl;
        return 0;
    } else if (m == 2) {
        cout << n * (n + 1) / 2 << endl;
        return 0;
    }

    pre();
    ll ans = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = (sum + C(m - 2, m + i - 3)) % mod;
        ans = (ans + sum) % mod;
    }

    cout << ans << endl;
}