#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int inv2 = (mod + 1) / 2;
const int g = 3; // 原根
const int _N = 2048;
const int _M = 512;

ll quickpow(ll base, ll b)
{
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ans % mod;
}

int rev[2 * _N + 10];
void getrev(int len)
{
    int bit = 0;
    while ((1 << bit) < len)
        bit++;
    for (int i = 0; i < len; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
}

void ntt(ll x[], int len, int opt)
{
    for (int i = 0; i < len; i++)
        if (i < rev[i])
            swap(x[i], x[rev[i]]);
    for (int mid = 1; mid < len; mid <<= 1) {
        ll tmp = quickpow(g, (mod - 1) / (mid * 2));
        if (opt == -1)
            tmp = quickpow(tmp, mod - 2);
        for (int i = 0, add = mid << 1; i < len; i += add) {
            ll base = 1;
            for (int j = i; j < i + mid; j++, base = base * tmp % mod) {
                ll a = x[j], b = base * x[j + mid] % mod;
                x[j] = (a + b) % mod, x[j + mid] = (a - b + mod) % mod;
            }
        }
    }
}

void fwt_xor(ll a[], int n, int opt)
{
    for (int i = 1; i < n; i <<= 1)
        for (int j = 0, add = i << 1; j < n; j += add)
            for (int k = 0; k < i; k++) {
                ll x = a[j + k], y = a[i + j + k];
                a[j + k] = (x + y) % mod, a[i + j + k] = (x - y + mod) % mod;
                if (opt == -1)
                    a[j + k] = a[j + k] * inv2 % mod, a[i + j + k] = a[i + j + k] * inv2 % mod;
            }
}

int a[100010], b[100010];
ll f1[_N + 10][_M + 10], f2[_M + 10][_N + 10];

int main()
{
    int n, m, N = 0, M = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i), N = max(N, a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", b + i), M = max(M, b[i]);
    for (int i = 1; i <= n; i++)
        f1[a[i]][b[i]]++;

    n = N * 4, m = M;
    N = M = 1;
    while (N <= n)
        N <<= 1;
    while (M <= m)
        M <<= 1;

    for (int i = 0; i < N; i++) {
        fwt_xor(f1[i], M, 1);
        for (int j = 0; j < M; j++)
            f2[j][i] = f1[i][j];
    }
    getrev(N);
    for (int i = 0; i < M; i++) {
        ntt(f2[i], N, 1);
        for (int j = 0; j < N; j++)
            f2[i][j] = quickpow(f2[i][j], 4);
        ntt(f2[i], N, -1);
        for (int j = 0; j < N; j++)
            f1[j][i] = f2[i][j];
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        fwt_xor(f1[i], M, -1);
        ll tmp = 1;
        for (int j = 0; j < M; j++) {
            ans += f1[i][j] * tmp % mod;
            if (ans >= mod)
                ans -= mod;
            tmp = tmp * i % mod;
        }
    }
    printf("%lld\n", ans * quickpow(N, mod - 2) % mod);
}