#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ff first
#define ss second
#define mp make_pair

const int N = 10010;
struct edge {
    int v, next;
} rds[N * 2];
int num;
int head[N];
void clear()
{
    num = 0;
    memset(head, -1, sizeof head);
}
void addedge(int u, int v)
{
    rds[num].v = v;
    rds[num].next = head[u];
    head[u] = num;
    ++num;
}
int f[N][20];
int depth[N];
int MaxL = 15;
void init(int x, int father, int d)
{
    depth[x] = d;
    f[x][0] = father;
    for (int i = 1; (1 << i) <= d; ++i) {
        f[x][i] = f[f[x][i - 1]][i - 1];
    }
    for (int v = head[x]; v != -1; v = rds[v].next)
        if (rds[v].v != father) {
            init(rds[v].v, x, d + 1);
        }
}
int getLCA(int u, int v)
{
    if (u == v)
        return u;
    if (depth[u] > depth[v]) {
        int t = u;
        u = v;
        v = t;
    }
    int len = depth[v] - depth[u];
    for (int i = 0; (1 << i) <= len; ++i)
        if ((1 << i) & len) {
            v = f[v][i];
        }
    for (int i = MaxL; i >= 0; --i)
        if (f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }
    if (u == v)
        return u;
    else
        return f[u][0];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        clear();
        printf("Case %d:\n", kase);
        int n, q;
        scanf("%d", &n);
        for (int i = 1, x, y; i < n; i++) {
            scanf("%d%d", &x, &y);
            addedge(x, y), addedge(y, x);
        }
        init(1, 0, 1);

        auto gao = [](int x, int y, pii& c1, pii& c2) {
            int lcaxy = getLCA(x, y);
            if (lcaxy != x && lcaxy != y)
                c1 = mp(lcaxy, x), c2 = mp(lcaxy, y);
            else if (lcaxy == x)
                c1 = mp(x, y), c2 = mp(-1, -1);
            else
                c1 = mp(y, x), c2 = mp(-1, -1);
            //printf("** %d %d %d %d %d %d\n", x, y, c1.ff, c1.ss, c2.ff, c2.ss);
        };
        auto solve = [](const pii& a, const pii& b) -> pii {
            pii res = mp(-1, -1);
            if (a.ff == -1 || b.ff == -1)
                return res;
            int lcaxy = getLCA(a.ff, b.ff);
            int lca = getLCA(a.ss, b.ss);
            if (lcaxy != a.ff && lcaxy != b.ff)
                return res;
            else if (lcaxy == a.ff && lcaxy == b.ff) {
                res.ff = a.ff;
                if (lca == a.ss)
                    res.ss = a.ss;
                else if (lca == b.ss)
                    res.ss = b.ss;
                else
                    res.ss = a.ff;
                //printf("%d %d\n", lcaxy, lca);
                //printf("%d %d %d %d\n", a.ff, a.ss, b.ff, b.ss);
                //printf("solve: %d %d\n", res.ff, res.ss);
            } else {
                if (depth[a.ff] <= depth[b.ss] || depth[b.ff] <= depth[a.ss]) {
                    res.ff = (depth[a.ff] <= depth[b.ff] ? b.ff : a.ff);
                    res.ss = (depth[a.ss] <= depth[b.ss] ? a.ss : b.ss);
                }
            }
            return res;
        };
        auto OR = [](pii a, pii b) {
            //printf("%d %d %d %d\n", a.ff, a.ss, b.ff, b.ss);
            if (a.ff == -1)
                return b;
            else if (b.ff == -1)
                return a;

            if (a.ff == b.ff) {
                if (depth[a.ss] >= depth[b.ss])
                    return a;
                return b;
            }
            return mp(-1, -1);
        };

        scanf("%d", &q);
        pii c1 = mp(-1, -1), c2 = mp(-1, -1);
        while (q--) {
            int k, gg = 0;
            scanf("%d", &k);
            for (int _k = 1, x, y; _k <= k; _k++) {
                scanf("%d%d", &x, &y);
                if (!gg)
                    if (_k == 1)
                        gao(x, y, c1, c2);
                    else {
                        pii t1 = mp(-1, -1), t2 = mp(-1, -1);
                        gao(x, y, t1, t2);

                        pii tmp1 = OR(solve(t1, c1), solve(t1, c2));
                        pii tmp2 = OR(solve(t2, c1), solve(t2, c2));
                        //printf("tmp1: %d %d\n", tmp1.ff, tmp1.ss);
                        //printf("tmp2: %d %d\n", tmp2.ff, tmp2.ss);

                        if (tmp1.ff == -1) {
                            if (tmp2.ff == -1)
                                gg++;
                            else
                                c1 = tmp2, c2 = tmp1;
                        } else {
                            if (tmp2.ff == -1)
                                c1 = tmp1, c2 = tmp2;
                            else {
                                c1 = tmp1, c2 = tmp2;
                            }
                        }
                    }
                //printf("c1&c2: %d %d %d %d %d\n", gg, c1.ff, c1.ss, c2.ff, c2.ss);
            }

            int ans = 0;
            if (c1.ff != -1 && !gg) {
                if (c2.ff != -1)
                    ans = depth[c1.ss] + depth[c2.ss] - 2 * depth[c1.ff] + 1;
                else
                    ans = depth[c1.ss] - depth[c1.ff] + 1;
            }
            printf("%d\n", ans);
        }
    }
}