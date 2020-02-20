#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

int c[110];
pii p[1100];
int w[1100][1100];
const int INF = 0x7f7f7f7f;
struct PathNode {
    int to, val;
    PathNode() {}
    PathNode(int _to, int _val)
    {
        to = _to;
        val = _val;
    }
    bool operator<(const PathNode& b) const
    {
        return val > b.val;
    }
};
vector<PathNode> v[200010];
int dis[200010];
priority_queue<PathNode> pq;
bool vis[200010];
void dijkstra(int s)
{
    memset(vis, false, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    pq = priority_queue<PathNode>();
    pq.push(PathNode(s, 0));
    while (!pq.empty()) {
        PathNode tmp = pq.top();
        pq.pop();
        if (vis[tmp.to])
            continue;
        vis[tmp.to] = true;
        int len = v[tmp.to].size();
        for (int i = 0; i < len; ++i)
            if (!vis[v[tmp.to][i].to] && dis[tmp.to] + v[tmp.to][i].val < dis[v[tmp.to][i].to]) {
                dis[v[tmp.to][i].to] = dis[tmp.to] + v[tmp.to][i].val;
                pq.push(PathNode(v[tmp.to][i].to, dis[v[tmp.to][i].to]));
            }
    }
}

int dist(pii a, pii b)
{
    int len = (a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss);
    int s = sqrt(len);
    if (s * s != len)
        s++;
    return s;
}

int base, B;
void addedge(int a, int b, int c)
{
    int len = dist(p[a], p[b]);
    for (int i = 0; i <= B - len; i++) {
        v[i * base + a].push_back(PathNode((i + len) * base + b, c * len));
        v[i * base + b].push_back(PathNode((i + len) * base + a, c * len));
    }
}

vector<pii> inf[1010];
int main()
{
    pii s, t;
    scanf("%d%d%d%d", &s.ff, &s.ss, &t.ff, &t.ss);
    int T, n;
    scanf("%d%d%d", &B, &c[0], &T);
    for (int i = 1; i <= T; i++)
        scanf("%d", &c[i]);
    scanf("%d", &n);
    p[n + 1] = s, p[n + 2] = t, base = n + 3;
    addedge(n + 1, n + 2, c[0]);
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d%d%d", &p[i].ff, &p[i].ss, &k);
        addedge(n + 1, i, c[0]);
        addedge(n + 2, i, c[0]);
        while (k--) {
            int x, y;
            scanf("%d%d", &x, &y);
            inf[i].push_back({ x, y });
            //addedge(i, x + 1, c[y]);
        }
    }
    for (int i = 1; i <= n; i++)
        for (auto j : inf[i])
            addedge(i, j.ff + 1, c[j.ss]);

    dijkstra(n + 1);
    int ans = INF;
    for (int i = 0; i <= B; i++)
        ans = min(ans, dis[i * base + n + 2]);
    /*for (int i = 0; i <= B; i++)
        for (int j = 1; j < base; j++)
            printf("%d%c", dis[i * base + j], " \n"[j == base - 1]);*/
    if (ans == INF)
        ans = -1;
    printf("%d\n", ans);
}