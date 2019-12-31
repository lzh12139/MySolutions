#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
int w[210][210];
const int inf = 1e9;
pii p[210];
int r[210], endd[210], cnt, too[210];
inline int read()
{
    int res = 0;
    char c = getchar();
    while (c == ' ' || c == '\n')
        c = getchar();
    while (isdigit(c))
        res = res * 10 + (c - '0'), c = getchar();
    return res;
}
inline void out(int x)
{
    if (x)
    {
        out(x / 10);
        putchar(x % 10 + '0');
    }
}
inline void printff(int x)
{
    if (x)
    {
        out(x);
        puts("");
    }
    else
        puts("0");
}
inline void pre(int n)
{
    cnt = 0;
    sort(r + 1, r + 1 + n);
    sort(p + 1, p + 1 + n);
    for (int i = 2; i <= n; i++)
        if (r[i - 1] != r[i])
            endd[++cnt] = i - 1;
    endd[++cnt] = n;
    for (int i = 1; i <= n; i++)
        too[p[i].ss] = i;
}
struct node
{
    int to, val;
    node() {}
    node(int _to, int _val) : to(_to), val(_val) {}
    bool operator<(const node &a) const
    {
        return val > a.val;
    }
};
int dis[210], vis[210];
int dij(int s, int t, int n)
{
    if (s == t)
        return 0;
    vector<int> v;
    v.pb(s), v.pb(t);
    for (int i = 1; i <= n; i++)
        if (too[i] != s && too[i] != t)
            v.pb(too[i]);

    printf("v:");
    for (auto i : v)
        printf("%d ", i);
    printf("\n");

    for (int i = 1; i <= n; i++)
        vis[i] = 0,
        dis[i] = inf;
    dis[s] = 0, vis[s] = 1;
    priority_queue<node> pq;
    pq.push(node(s, 0));
    while (!pq.empty())
    {
        node tmp = pq.top();
        pq.pop();
        if (vis[tmp.to])
            continue;
        vis[tmp.to] = 1;
        for (auto i : v)
            if (!vis[i] && dis[tmp.to] + w[tmp.to][i] < dis[i])
            {
                dis[i] = dis[tmp.to] + w[tmp.to][i];
                pq.push(node(i, dis[i]));
            }
    }
    printf("dis=%d\n", dis[t]);
    return dis[t];
}
int main()
{
    int t = read();
    for (int kase = 1; kase <= t; kase++)
    {
        printf("Case #%d:\n", kase);
        int n = read(), q = read();
        for (int i = 1; i <= n; i++)
            r[i] = read(), p[i].ff = r[i], p[i].ss = i;
        pre(n);
        for (int i = 1; i <= n; i++)
            for (int o = 1; o <= n; o++)
                w[too[i]][too[o]] = read();
        for (int i = 0; i <= n; i++)
            printf("%d %d\n", r[i], too[i]);
        printf("\n");
        for (int i = 1; i <= q; i++)
        {
            int u = read(), v = read(), ww = read();
            ww = lower_bound(r + 0, r + 1 + n, ww) - r;
            printf("ww=%d endd=%d\n", ww, endd[ww]);
            if (ww == 0)
            {
                puts("0");
                continue;
            }
            printff(dij(too[u], too[v], endd[ww]));
        }
    }
}