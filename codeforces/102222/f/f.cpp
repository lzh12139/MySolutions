#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <stack>
using namespace std;
#define mem(x, y) memset(x, (y), sizeof x)
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define sc(a) scanf("%d", &a)
#define scl(a) scanf("%lld", &a)
#define scs(a) scanf("%s", a)
#define pr(a, b) printf("%d%c", a, b)
#define prl(a, b) printf("%ll%c", a, b)
#define all(v) v.begin(), v.end()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define _yes printf("Yes\n")
#define _no printf("No\n")

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> V;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<string, int> msi;

struct qq
{
    int n, u, v, w;
    qq() {}
    qq(int _n, int _u, int _v, int _w) : n(_n), u(_u), v(_v), w(_w) {}
} que[20010];

int r[210], w[210][210], ans[20010], v[210], rr[210];
int main()
{
    int t;
    scanf("%d", &t);
    for (int qaq = 1; qaq <= t; qaq++)
    {
        printf("Case #%d:\n", qaq);
        int n, q;
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++)
            scanf("%d", &r[i]), rr[i] = r[i];
        sort(r + 1, r + 1 + n);

        for (int i = 1; i <= n; i++)
            for (int o = 1; o <= n; o++)
                scanf("%d", &w[i][o]);

        for (int i = 1; i <= q; i++)
            scanf("%d%d%d", &que[i].u, &que[i].v, &que[i].w), que[i].n = i;
        sort(que + 1, que + 1 + q, [&](qq a, qq b) {
            return a.w < b.w;
        });

        int pq = 1;
        r[n + 1] = 100001;
        for (int i = 0; i <= n; i++)
        {
            int ri = i;
            while (r[ri + 1] == r[i])
                ri++;
            int cnt = 0;
            for (int o = 1; o <= n; o++)
                if (rr[o] == r[i])
                    v[++cnt] = o;

            for (int o = 1; o <= cnt; o++)
                for (int j = 1; j <= n; j++)
                    for (int k = 1; k <= n; k++)
                        w[j][k] = min(w[j][k], w[j][v[o]] + w[v[o]][k]);
            /*
            for (int j = 1; j <= n; j++, printf("\n"))
                for (int k = 1; k <= n; k++)
                    printf("%d ", w[j][k]);
            */
            while (que[pq].w < r[ri + 1] && pq <= q)
            {
                //if (que[pq].u <= que[pq].v)
                ans[que[pq].n] = w[que[pq].u][que[pq].v];
                //else
                //    ans[que[pq].n] = w[que[pq].v][que[pq].u];
                pq++;
            }
            i = ri;
        }
        for (int i = 1; i <= q; i++)
            printf("%d\n", ans[i]);
    }
}