#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int inv2 = (mod + 1) / 2;

int rev[4000];
void getrev(int len)
{
    int bit = 0;
    while ((1 << bit) < len)
        bit++;
    for (int i = 0; i < len; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
}

ll quickpow(ll base, ll b)
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

inline ll MOD(ll a)
{
    if (a >= mod)
        return a - mod;
    return a;
}

ll ans[2050][2050];
void fwt_xor(ll a[], ll b[], int n, int opt, int upd)
{
    ll TMP = quickpow(n, mod - 2);
    for (int i = 0; i < n; i++)
        if (i < rev[i])
            swap(b[i], b[rev[i]]);
    for (int i = 1; i < n; i <<= 1) {
        ll tmp = quickpow(3, (mod - 1) / (i * 2));
        if (opt == -1)
            tmp = quickpow(tmp, mod - 2);

        for (int j = 0, add = i << 1; j < n; j += add) {
            ll base = 1;
            for (int k = j; k < i + j; k++, base = base * tmp % mod) {
                int x = a[k], y = a[i + k];
                a[k] = (x + y) % mod, a[i + k] = (x - y + mod) % mod;

                int aa = b[k], bb = base * b[i + k] % mod;
                b[k] = (aa + bb) % mod, b[i + k] = (aa - bb + mod) % mod;

                if (opt == -1) {
                    a[k] = a[k] * inv2 % mod;
                    a[i + k] = a[i + k] * inv2 % mod;
                    if (upd) {
                        ans[k][k] = MOD(ans[k][k] + a[k] * b[k] % mod);
                        ans[i + k][i + k] = MOD(ans[i + k][i + k] + a[i + k] * b[i + k] % mod);
                        ans[k][i + k] = MOD(ans[k][i + k] + b[k] * a[i + k] % mod);
                        ans[i + k][k] = MOD(ans[i + k][k] + b[i + k] * a[k] % mod);
                    }
                }
            }
        }
    }
}

ll a[2050], b[2050];
int main()
{
    freopen("1.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        b[x]++;
    }

    getrev(1024);
    fwt_xor(b, a, 1024, 1, 0);
    for (int i = 0; i < 1024; i++) {
        a[i] = a[i] * a[i] % mod;
        b[i] = b[i] * b[i] % mod;
    }
    fwt_xor(b, a, 1024, -1, 0);
    ll tmp = quickpow(1024, mod - 2);
    for (int i = 0; i < 1024; i++)
        a[i] = a[i] * tmp % mod;

    getrev(2048);
    fwt_xor(b, a, 2048, 1, 0);
    for (int i = 0; i < 2048; i++) {
        a[i] = a[i] * a[i] % mod;
        b[i] = b[i] * b[i] % mod;
    }
    fwt_xor(b, a, 2048, -1, 1);

    ll ansn = 0, TMP = quickpow(2048, mod - 2);

    for (int i = 0; i < 2048; i++)
        if (a[i])
            printf("%d %d\n", i, a[i] * TMP % mod);
    for (int i = 0; i < 2048; i++)
        if (b[i])
            printf("%d %d\n", i, b[i]);

    for (int i = 0; i < 2048; i++) {
        tmp = TMP;
        for (int j = 0; j < 1024; j++) {
            //if (ans[i][j])
            //    printf("%d %d %lld\n", i, j, ans[i][j] * TMP % mod);
            ansn = MOD(ansn + 1ll * ans[i][j] * tmp % mod);
            tmp = tmp * i % mod;
        }
    }
    printf("%lld\n", ansn);
}