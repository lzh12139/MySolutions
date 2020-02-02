/**
 * Author: hrynb
 * Time: 2020-01-31 11:27:23
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("Yes\n")
#define _no printf("No\n")
#define _YES printf("YES\n");
#define _NO printf("NO\n");

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

ll add[200010 << 2], val[200010 << 2];
void upd(int x, int curl, int curr, int l, int r, int v)
{
    if (l <= curl && curr <= r) {
        add[x] += v;
        val[x] += v;
        return;
    }
    val[x << 1] += add[x];
    add[x << 1] += add[x];
    val[x << 1 | 1] += add[x];
    add[x << 1 | 1] += add[x];
    add[x] = 0;
    
    int mid = curl + curr >> 1;
    if (r <= mid)
        upd(x << 1, curl, mid, l, r, v);
    else if (l > mid)
        upd(x << 1 | 1, mid + 1, curr, l, r, v);
    else {
        upd(x << 1, curl, mid, l, r, v);
        upd(x << 1 | 1, mid + 1, curr, l, r, v);
    }

    val[x] = min(val[x << 1], val[x << 1 | 1]);
}
int p[200010], a[200010];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    ll ans = 1e18;
    for (int i = 1; i <= n; i++)
        upd(1, 0, n, p[i], n, a[i]);
    for (int i = 1; i < n; i++) {
        upd(1, 0, n, p[i], n, -a[i]);
        upd(1, 0, n, 0, p[i] - 1, a[i]);
        ans = min(ans, val[1]);
    }
    printf("%lld\n", ans);
}