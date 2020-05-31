#include <bits/stdc++.h>
using namespace std;

int dis[110][10010], vis[110][10010], n, m, K;
struct node {
    int to, len, cost;
    node(int _to = 0, int _len = 0, int _cost = 0)
    {
        to = _to, len = _len, cost = _cost;
    }
    bool operator<(const node& b) const
    {
        return len > b.len;
    }
};
vector<node> v[110];

int dij()
{
    priority_queue<node> pq;
    pq.push(node(1, 0, 0));
    dis[0][1] = 0;
    while (!pq.empty()) {
        node x = pq.top();
        pq.pop();
        if (vis[x.cost][x.to])
            continue;
        vis[x.cost][x.to]++;
        for (auto i : v[x.to])
            if (!vis[i.cost + x.cost][i.to]) {
                dis[i.cost + x.cost][i.to] = min(dis[i.cost + x.cost][i.to],
                    dis[x.cost][x.to] + i.len);
                pq.push(node(i.to, i.len + dis[x.cost][x.to], x.cost + i.cost));
            }
    }
    int ans = dis[0][0];
    for (int i = 0; i <= K; i++)
        ans = min(ans, dis[i][n]);
    return (ans == 0x3f3f3f3f ? -1 : ans);
}

int main()
{
    memset(dis, 0x3f, sizeof dis);

    cin >> K >> n >> m;
    for (int i = 1, x, y, l, c; i <= m; i++) {
        cin >> x >> y >> l >> c;
        v[x].emplace_back(node(y, l, c));
    }
    cout << dij() << endl;
}
/*
5 6 7
1 2 2 4
2 4 3 3
3 4 2 4
1 3 4 1
4 6 2 1
3 5 2 1
5 4 3 2
*/