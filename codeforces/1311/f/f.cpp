/**
 * Author: hrynb
 * Time: 2020-02-25 00:06:10
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _Yes printf("Yes\n")
#define _No printf("No\n")
#define _YES printf("YES\n")
#define _NO printf("NO\n")
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

int lowbit(int x) { return x & (-x); }
struct TreeArray {
    int n;
    ll a[500001];
    void setRange(int N)
    {
        clear();
        n = N;
    }
    void clear()
    {
        n = 0;
        memset(a, 0, sizeof(a));
    }
    void modify(int pos, ll val)
    {
        for (int i = pos; i <= n; i += lowbit(i))
            a[i] += val;
    }
    ll query(int pos)
    {
        ll rnt = 0;
        for (int i = pos; i > 0; i -= lowbit(i))
            rnt += a[i];
        return rnt;
    }
};
TreeArray a, b;

struct node {
    int x, v, num;
    bool operator<(const node& b) const
    {
        return x != b.x ? x < b.x : v < b.v;
    }
} p[200010];
int main()
{
    int n;
    ll ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i].x);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i].v);
    sort(p + 1, p + 1 + n);
    a.setRange(n), b.setRange(n);
    for (int i = 1; i <= n; i++) {
        p[i].num = i;
        a.modify(i, p[i].x);
        b.modify(i, 1);
    }
    sort(p + 1, p + 1 + n, [](node a, node b) {
        return a.v != b.v ? a.v > b.v : a.x > b.x;
    });
    for (int i = 1; i <= n; i++) {
        a.modify(p[i].num, -p[i].x);
        b.modify(p[i].num, -1);
        ans += b.query(p[i].num) * p[i].x - a.query(p[i].num);
    }
    printf("%lld\n", ans);
}