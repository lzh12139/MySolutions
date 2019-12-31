#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10040;
const int MAXM = 300010;

#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back
const ll INF = 1e18;
typedef pair<ll, ll> pii;
struct edge
{
    int to, cap, rev;
    ll cost;
    edge(){};
    edge(int _to, int _cap, ll _cost, int _rev) : to(_to), cap(_cap), cost(_cost), rev(_rev){};
};
int N;
vector<edge> G[MAXN];
ll dist[MAXN], h[MAXN];
int prevv[MAXN], preve[MAXN];

void init(int n)
{
    N = n;
    for (int i = 0; i <= N; i++)
        G[i].clear();
}

void addedge(int from, int to, int cap, ll cost)
{
    G[from].push_back(edge(to, cap, cost, G[to].size()));
    G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
}

ll MinCost(int s, int t, int f)
{
    ll res = 0;
    fill(h, h + N + 1, 0);
    while (f > 0)
    {
        priority_queue<pii, vector<pii>, greater<pii>> que;
        for (int i = 0; i <= N; i++)
            dist[i] = INF;
        dist[s] = 0;
        que.push(make_pair(0, s));
        while (!que.empty())
        {
            pii p = que.top();
            que.pop();
            int v = p.second;
            if (dist[v] < p.first)
                continue;
            for (int i = 0; i < G[v].size(); i++)
            {
                edge &e = G[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to])
                {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v, preve[e.to] = i;
                    que.push(make_pair(dist[e.to], e.to));
                }
            }
        }

        if (dist[t] == INF)
            return -1;

        for (int v = 1; v <= N; v++)
            h[v] += dist[v];

        int d = f;
        for (int v = t; v != s; v = prevv[v])
            d = min(d, G[prevv[v]][preve[v]].cap);
        f -= d;
        res += d * h[t];
        for (int v = t; v != s; v = prevv[v])
        {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

pii p[5010];
int main()
{
    int n, f;
    scanf("%d%d", &n, &f);
    if(f==1){
    	printf("0\n");return 0;
	}
    init(2 * n + 3);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &p[i].ss, &p[i].ff);
    sort(p + 1, p + 1 + n);
    const ll uu = 1e14;
    for (int i = 1; i <= n; i++)
        addedge(0, 2 * i - 1, f, uu), addedge(2 * i - 1, 2 * i, 1, 0), addedge(2 * i, 2 * n + 1, 1, 0);
    for (int i = 1; i <= n; i++)
        for (int o = i + 1; o <= n; o++)
            addedge(2 * i, 2 * o - 1, 1, 1ll * (p[o].ff - p[i].ff) * p[o].ss - uu);

    int s0 = 2 * n + 2, t0 = 2 * n + 3;
    addedge(s0, 0, f, 0), addedge(2 * n + 1, t0, f, 0);

    ll ans = MinCost(s0, t0, f);
    printf("%lld\n", ans);
}
/*
4 4
1 1
1 2
1 3
1 4
*/
