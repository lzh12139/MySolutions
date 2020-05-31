#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define ff first
#define ss second

map<pii, int> mp;
const int N = 200010;
struct edge {
    int v, next, w;
} rds[N * 2];
int num = 0, head[N];
void addedge(int u, int v, int w)
{
    rds[num].v = v;
    rds[num].next = head[u];
    rds[num].w = w;
    head[u] = num;
    ++num;
}
int f[N][20], depth[N];
int maxx[N][20];
int MaxL = 17;
void init(int x, int father, int d, int w)
{
    //cout << x << d << endl;
    depth[x] = d;
    f[x][0] = father;
    maxx[x][0] = w;
    for (int i = 1; (1 << i) <= d; ++i) {
        f[x][i] = f[f[x][i - 1]][i - 1];
        maxx[x][i] = max(maxx[f[x][i - 1]][i - 1], maxx[x][i - 1]);
    }
    for (int v = head[x]; v != -1; v = rds[v].next)
        if (rds[v].v != father) {
            init(rds[v].v, x, d + 1, rds[v].w);
        }
}
int solve(int u, int v)
{
    if (depth[u] > depth[v]) {
        int t = u;
        u = v;
        v = t;
    }
    int len = depth[v] - depth[u];
    int ans = 0;
    for (int i = 0; (1 << i) <= len; ++i)
        if ((1 << i) & len) {
            ans = max(ans, maxx[v][i]);
            v = f[v][i];
        }
    if (u == v)
        return ans;
    for (int i = MaxL; i >= 0; --i)
        if (f[u][i] != f[v][i]) {
            ans = max(ans, max(maxx[u][i], maxx[v][i]));
            u = f[u][i], v = f[v][i];
        }
    if (u != v)
        ans = max(ans, max(maxx[u][0], maxx[v][0]));
    return ans;
}

edge e[N];
int _f[N];
int find(int x)
{
    return _f[x] == x ? x : _f[x]=find(_f[x]);
}
int kruskal(int n, int m)
{
    sort(e + 1, e + 1 + m, [](edge a, edge b) {
        return a.next < b.next;
    });
    for (int i = 1; i <= n; i++)
        _f[i] = i;
    int sum = 0, cnt = 0;
    for (int i = 1; i <= m; i++) {
        int u = find(e[i].w), v = find(e[i].v);
        if (u != v) {
            addedge(e[i].w, e[i].v, e[i].next);
            addedge(e[i].v, e[i].w, e[i].next);
            mp[{ e[i].w, e[i].v }] = 0;
            _f[u] = v;
            cnt++, sum += e[i].next;
            if (cnt == n - 1)
                return sum;
        }
    }
    return sum;
}

int main()
{
    memset(head, -1, sizeof head);

    int n, r, q;
    scanf("%d%d", &n, &r);
    for (int i = 1, x, y, z; i <= r; i++) {
        scanf("%d%d%d", &e[i].w, &e[i].v, &e[i].next);
        mp[{ e[i].w, e[i].v }] = e[i].next;
    }
    int mst = kruskal(n, r);
    init(1, -1, 0, 0);

    scanf("%d", &q);
    while (q--) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (mp[{ u, v }] == 0)
            printf("%d\n", mst);
        else
            printf("%d\n", mst + mp[{ u, v }] - solve(u, v));
    }
}
/*
3 3
1 2 10
2 3 5
1 3 7
3
2 3
1 2
1 3

4 4
1 2 1
2 4 1
2 3 100
1 4 50
1
1 4

5 7
1 2 8
1 3 10
2 4 5
2 3 12
4 5 4
3 5 14
1 5 20
3
2 3
1 5
3 5
*/