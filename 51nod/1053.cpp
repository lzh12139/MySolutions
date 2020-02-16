#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<ll, int> pii;

struct node {
    ll a, v;
    int x;
    node(ll _a = 0, ll _v = 0, int _x = 0)
    {
        a = _a, v = _v, x = _x;
    }
    bool operator<(const node& b) const
    {
        return a > b.a;
    }
};
int vis[50010], f[50010];
ll val[50010];
int find(int x)
{
    return f[x] == x ? f[x] = find(f[x]) : f[x];
}
void add(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy)
        f[fy] = fx;
}
int main()
{
    int n, m, cnt = 0;
    scanf("%d%d", &n, &m);
    ll sum = 0, g = 1, ans = 0;
    priority_queue<node> pq;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (g == 1) {
            if (x >= 0)
                sum += x;
            else {
                if (cnt) {
                    pq.push(node(sum, sum, cnt)), m--;
                    val[cnt] = sum;
                    ans += sum;
                }
                cnt++, sum = x, g = -1;
            }
        } else {
            if (x <= 0)
                sum += x;
            else {
                pq.push(node(-sum, sum, cnt));
                val[cnt] = sum;
                cnt++, sum = x, g = 1;
            }
        }
        f[cnt] = cnt;
    }
    pq.push(node(abs(sum), sum, cnt++));

    while (m < 0 && !pq.empty()) {
        node x = pq.top();
        pq.pop();
        if (vis[x.x])
            continue;
        m++;
        ans -= x.a;
        ll tmp = val[find(x.x - 1)] + val[find(x.x)] + val[find(x.x + 1)];
        val[f]
        vis[find(x.x - 1)]++, vis[find(x.x)]++, vis[find(x.x + 1)];

        add(x.x, x.x - 1), add(x.x, x.x + 1);
        pq.push(node(abs(tmp), tmp, x.x));
    }

    printf("%lld\n", ans);
}