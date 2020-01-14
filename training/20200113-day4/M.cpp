#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second

const int N = 1e7 + 6e6 + 10;
int fac[20], num[20];
ll fac_num[20], facc[N];
ll exgcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a; //gcd(a,b)
    }
    ll gcd_ab = exgcd(b, a % b, x, y);
    ll temp = x;
    x = y;
    y = temp - a / b * y;
    return gcd_ab;
}
ll inv(ll x, ll mod)
{
    ll x, y;
    exgcd(x, mod, x, y);
    return x < 0 ? x + mod : x;
}
ll quick_pow(ll base, ll b, ll mod)
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
ll cal(ll x, ll y, ll mod)
{
    if (x <= y)
        return 1;
    return quick_pow(fac[y - 1], x / y, mod) * fac[x % y] % mod * cal(x / y, y, mod) % mod;
}
ll cal(ll x, ll mod)
{
    ll less = 4e18;
    for (int i = 1; i <= fac[0]; i++) {
        ll tmp = x / fac[i];
        fac_num[i] = 0;
        while (tmp)
            fac_num[i] += tmp, tmp /= fac[i];
        less = min(less, fac_num[i] / num[i]);
    }

    for (int i = 1; i < (1 << fac[0]); i++) {
        int tmp = i, cnt = 0, cur = 1;
        ll curfac = 1;
        while (tmp) {
            if (tmp & 1)
                cnt++, curfac *= fac[cur];
            cur++, tmp >>= 1;
        }
    }
}
int main()
{
    ll m, n, d;
    cin >> m >> n >> d;
    ll tmpd = d;
    for (int i = 2; i * i <= tmpd; i++)
        if (tmpd % i == 0) {
            fac[++fac[0]] = i;
            while (tmpd % i == 0)
                num[fac[0]]++, tmpd /= i;
        }
    if (tmpd)
        fac[++fac[0]] = tmpd, num[fac[0]]++;

    facc[0] = 1;
    for (int i = 1; i <= fac[1]; i++)
        facc[i] = facc[i - 1] * i % d;

    ll ans = cal(m, )
}