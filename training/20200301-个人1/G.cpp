#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

ll jinum[200010], ji[200010];
ll ounum[200010], ou[200010];

int lowbit(int x) { return x & (-x); }
void upd(ll a[], int x, int n, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        a[i] += v;
}
ll query(ll a[], int x)
{
    ll res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += a[i];
    return res;
}

pii a[200010];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int n_ji = n - n / 2, n_ou = n / 2;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].ff), a[i].ss = i;
        if (i & 1)
            upd(jinum, i + 1 >> 1, n_ji, 1), upd(ji, i + 1 >> 1, n_ji, a[i].ff);
        else
            upd(ounum, i >> 1, n_ou, 1), upd(ou, i >> 1, n_ou, a[i].ff);
    }
    ll ans = 0;
    sort(a + 1, a + 1 + n, greater<pii>());
    int L = k + 1, R = 2 * n - k + 1;
    for (int i = 1; i <= n; i++) {
        int l, r;
        l = 2 * a[i].ss - k + 1, r = 2 * a[i].ss + k - 1;
        l = max(l, L), r = min(r, R);
        //printf("--pre %d %d\n", l, r);
        int len1 = min(abs(2 * a[i].ss - l), k), len2 = min(abs(r - 2 * a[i].ss), k);
        if (r <= 2 * a[i].ss)
            l = l - len1 >> 1, r = r - len2 >> 1;
        else if (l >= 2 * a[i].ss)
            l = l + len1 >> 1, r = r + len2 >> 1;
        else
            l = l - len1 >> 1, r = r + len2 >> 1;
        l = l + 1 >> 1, r = r + 1 >> 1;

        if ((k & 1) == (a[i].ss & 1)) {
            if (l <= r)
                ans += (query(jinum, r) - query(jinum, l - 1)) * a[i].ff
                    - query(ji, r) + query(ji, l - 1);
            //printf("%lld %lld %lld %lld\n", query(jinum, r), query(jinum, l - 1),
            //    query(ji, r), query(ji, l - 1));
        } else {
            if (l <= r)
                ans += (query(ounum, r) - query(ounum, l - 1)) * a[i].ff
                    - query(ou, r) + query(ou, l - 1);
        }
        if (a[i].ss & 1) {
            upd(jinum, a[i].ss + 1 >> 1, n_ji, -1);
            upd(ji, a[i].ss + 1 >> 1, n_ji, -a[i].ff);
        } else {
            upd(ounum, a[i].ss >> 1, n_ou, -1);
            upd(ou, a[i].ss >> 1, n_ou, -a[i].ff);
        }
        //printf("l,r: %d %d\n", l, r);
        //printf("%d %lld\n", a[i].ss, ans);
    }
    printf("%lld\n", ans);
}