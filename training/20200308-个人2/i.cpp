#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second
#define int long long

const int N = 200010 << 2;
ll tr[N + 10], add[N + 10], ans[N + 10];
// ans维护当前区间的值是否相等
void upd(int x, int L, int R, int l, int r, ll v)
{
    int mid = L + R >> 1;
    if (l <= L && R <= r) {
        add[x] += v, tr[x] += 1ll * (R - L + 1) * v;
        return;
    }
    if (add[x]) {
        add[x << 1] += add[x], tr[x << 1] += 1ll * (mid - L + 1) * add[x];
        add[x << 1 | 1] += add[x], tr[x << 1 | 1] += 1ll * (R - mid) * add[x];
        add[x] = 0;
    }
    if (l <= mid)
        upd(x << 1, L, mid, l, r, v);
    if (r > mid)
        upd(x << 1 | 1, mid + 1, R, l, r, v);

    ans[x] = (ans[x << 1] && ans[x << 1 | 1]
        && tr[x << 1] == 0 && tr[x << 1 | 1] == 0);
    tr[x] = tr[x << 1] + tr[x << 1 | 1];
}
int query(int x, int L, int R, int l, int r)
{
    if (l <= L && R <= r)
        return ans[x];
    int mid = L + R >> 1;
    if (add[x]) {
        add[x << 1] += add[x], tr[x << 1] += 1ll * (mid - L + 1) * add[x];
        add[x << 1 | 1] += add[x], tr[x << 1 | 1] += 1ll * (R - mid) * add[x];
        add[x] = 0;
    }
    int res = 1;
    if (l <= mid)
        res &= query(x << 1, L, mid, l, r);
    if (r > mid)
        res &= query(x << 1 | 1, mid + 1, R, l, r);
    //printf("query: %d %d %d\n", L, R, res);
    return res;
}
ll q_sum(int x, int L, int R, int r)
{
    if (1 <= L && R <= r)
        return tr[x];
    int mid = L + R >> 1;
    if (add[x]) {
        add[x << 1] += add[x], tr[x << 1] += 1ll * (mid - L + 1) * add[x];
        add[x << 1 | 1] += add[x], tr[x << 1 | 1] += 1ll * (R - mid) * add[x];
        add[x] = 0;
    }
    ll res = 0;
    if (1 <= mid)
        res += q_sum(x << 1, L, mid, r);
    if (r > mid)
        res += q_sum(x << 1 | 1, mid + 1, R, r);
    return res;
}
signed main()
{
    int n, q;
    scanf("%lld%lld", &n, &q);
    for (int i = 1; i <= N; i++)
        ans[i] = 1;
    while (q--) {
        int op, l, r;
        scanf("%lld%lld%lld", &op, &l, &r);
        if (op == 1) {
            ll tmp1 = q_sum(1, 1, n, l), tmp2 = q_sum(1, 1, n, r);
            if (l == r)
                printf("%d\n", 1);
            else
                printf("%d\n", tmp1 == tmp2 && query(1, 1, n, l + 1, r));
        } else {
            int a, b;
            scanf("%lld%lld", &a, &b);
            upd(1, 1, n, l, l, a);
            if (l + 1 <= r)
                upd(1, 1, n, l + 1, r, b);
            if (r + 1 <= n)
                upd(1, 1, n, r + 1, r + 1, -a - 1ll * (r - l) * b);
        }
    }
}