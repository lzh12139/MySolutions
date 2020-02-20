/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos << 1)
#define rson (curpos << 1 | 1)
/* namespace */
using namespace std;
/* header end */

const ll mod = 1e9 + 7;

ll qp(ll a, ll b)
{
    ll ret = 1;
    a %= mod;
    while (b) {
        if (b & 1) {
            ret = ret * a % mod;
            b--;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ret;
}

const int N = 2e6 + 10;
ll fac[N + 10], inv[N + 10];

ll get(ll n)
{
    //printf("%lld\n", n);
    return fac[2 * n] * inv[n] % mod * inv[n] % mod * qp(n + 1, mod - 2) % mod;
}

int a[N];
int main()
{
    //freopen("test.in", "r", stdin);
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[N] = qp(fac[N], mod - 2);
    for (int i = N - 1; i >= 1; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;

    int n;
    ll ans = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    stack<int> st;
    int cnt = 1, pre = -1;
    for (int i = 1; i <= n; i++) {
        cnt = 1, pre = -1;
        // only left tree
        while (!st.empty() && a[i] < st.top()) {
            if (st.top() == pre) {
                cnt++;
            } else {
                ans = ans * get(cnt) % mod;
                pre = st.top(), cnt = 1;
            }
            st.pop();
        }
        // left tree
        ans = ans * get(cnt) % mod;

        st.push(a[i]);
    }

    // right tree
    cnt = 1, pre = -1;
    while (!st.empty()) {
        if (st.top() == pre) {
            cnt++;
        } else {
            ans = ans * get(cnt) % mod;
            pre = st.top(), cnt = 1;
        }
        st.pop();
    }
    ans = ans * get(cnt) % mod;

    printf("%lld\n", ans);
    return 0;
}