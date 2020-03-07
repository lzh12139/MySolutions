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

const int mod = 998244353;
pii p[200010];
int a[200010];
ll dp[200010], n;
int tr[200010 << 2];
void upd(int x, int L, int R, int ind, int v)
{
    //printf("%d\n", x);
    if (L == R && L == ind) {
        tr[x] = v;
        return;
    }
    int mid = L + R >> 1;
    if (ind <= mid)
        upd(x << 1, L, mid, ind, v);
    else
        upd(x << 1 | 1, mid + 1, R, ind, v);
    tr[x] = max(tr[x << 1], tr[x << 1 | 1]);
}
int query(int x, int L, int R, int l, int r)
{
    if (l >= r)
        return l;
    if (l <= L && R <= r)
        return tr[x];
    int mid = L + R >> 1, res = l;
    if (l <= mid)
        res = max(res, query(x << 1, L, mid, l, r));
    if (r > mid)
        res = max(res, query(x << 1 | 1, mid + 1, R, l, r));
    return res;
}
int main()
{
    //IOS;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].ff >> p[i].ss;
    sort(p + 1, p + 1 + n);
    dp[n] = 2, dp[n + 1] = 1;
    upd(1, 1, n, n, n);
    for (int i = n - 1; i >= 1; i--) {
        int x = lower_bound(p + 1, p + 1 + n, (pii){ p[i].ff + p[i].ss, 0 }) - p - 1;
        int tmp = query(1, 1, n, i, x);
        dp[i] = (dp[i + 1] + dp[tmp + 1]) % mod;
        upd(1, 1, n, i, tmp);
    }
    cout << dp[1];
}
