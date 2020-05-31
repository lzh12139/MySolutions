#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5020;
const int MAXM = 200010;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
struct edge {
    int to, cap, cost, rev; // rev为反向边
    edge() {};
    edge(int _to, int _cap, int _cost, int _rev)
        : to(_to)
        , cap(_cap)
        , cost(_cost)
        , rev(_rev) {};
};
int N; // 顶点数
vector<edge> G[MAXN];
int dist[MAXN], h[MAXN];
int prevv[MAXN], preve[MAXN];

void init(int n)
{
    N = n;
    for (int i = 0; i <= N; i++)
        G[i].clear();
}

void addedge(int from, int to, int cap, int cost)
{
    G[from].push_back(edge(to, cap, cost, G[to].size()));
    G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
}

// 求s到t流量为f的最小费用流
// 不能再增广时返回-1
int MinCost(int s, int t, int& f)
{
    int res = 0;
    fill(h, h + N + 1, 0);
    while (f > 0) {
        priority_queue<pii, vector<pii>, greater<pii>> que;
        fill(dist, dist + N + 1, INF);
        dist[s] = 0;
        que.push(make_pair(0, s));
        while (!que.empty()) {
            pii p = que.top();
            que.pop();
            int v = p.second;
            if (dist[v] < p.first)
                continue;
            for (int i = 0; i < G[v].size(); i++) {
                edge& e = G[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
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
        for (int v = t; v != s; v = prevv[v]) {
            edge& e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

char s[50][50];
const int dd[][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
int main()
{
    int flag=0;
    while (1) {
        char c;
        int last = 0, j = -1, n = 1, m = 0;
        while (c = getchar()) {
            if (c == EOF)
                {flag=1;break;}
            if (c == '\n') {
                last++;
                if (last == 2)
                    break;
                j = (j == -1 ? m : j);
                n++, m = 0;
            } else {
                last = 0;
                s[n][++m] = c;
            }
        }
        n--, m = j;
        if(flag)n++;
        //cout << n << " " << m << endl;
        /*for (int i = 1; i <= 5; i++)
            for (int j = 1; j <= m; j++)
                cout << s[i][j] << " \n"[j == m];*/

        // go
        int S = 0, T = n * m * 2 + 1;
        init(T + 1);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                int cnt1 = 2 * ((i - 1) * m + j);
                addedge(cnt1 - 1, cnt1, 1, 1);
                if (s[i][j] == 'W')
                    addedge(S, cnt1 - 1, 1, 1);
                if (s[i][j] == 'N')
                    addedge(cnt1, T, 1, 1);
                for (int k = 0; k < 4; k++) {
                    int dx = dd[k][0] + i, dy = dd[k][1] + j;
                    if (dx == 0 || dy == 0 || dx == n + 1 || dy == m + 1)
                        continue;
                    if ((s[i][j] == 'W' && s[dx][dy] == 'I') || (s[i][j] == 'I' && s[dx][dy] == 'N')) {
                        int cnt2 = 2 * ((dx - 1) * m + dy);
                        addedge(cnt1, cnt2 - 1, 1, 1);
                    }
                }
            }
        int f = 1e9;
        MinCost(S, T, f);
        cout << 1e9 - f << endl;
        if(flag)return 0;
    }
}
/*
WIIW
NNNN
IINN
WWWI

NINWN
INIWI
WWWIW
NNNNN
IWINN
*/