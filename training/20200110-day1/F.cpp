//POJ-3259 spfa bfs 判负权回路
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long
using namespace std;
const int MAX = 900 + 10; //点数最大值
const int INF = 1e9;

struct pair_edge {
    int to, len;
    pair_edge(int a = 0, int b = 0)
    {
        to = a, len = b;
    }
};

vector<pair_edge> edge[MAX];
int num_point, num_positive_edge, num_negative_edge; //点数，正边数，负边数（视情况而定）
int cnt[MAX]; //记录各点被入队的次数
int dis[MAX]; //到起点的距离

bool spfa()
{
    queue<int> que;
    dis[1] = 0;
    cnt[1]++; //被入队
    que.push(1);

    while (!que.empty()) {
        int from = que.front();
        que.pop();

        int l = edge[from].size();
        for (int i = 0; i < l; ++i) {
            pair_edge temp = edge[from][i];
            if (dis[temp.to] > dis[from] + temp.len) {
                dis[temp.to] = dis[from] + temp.len;
                que.push(temp.to);
                cnt[temp.to]++; //被入队
                if (cnt[temp.to] >= num_point)
                    return true; //若被入队超过n次，说明有负权回路
            }
        }
    }
    //无负权回路
    return false;
}

int a[35][35];
pair<int, int> p[35][35];
int T[35][35];

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) && n && m) {
        num_point = n * m;
        //初始化
        for (int i = 1; i <= num_point; ++i) {
            dis[i] = INF;
            edge[i].clear();
            cnt[i] = 0;
        }

        memset(a, 0, sizeof a);
        memset(T, -1, sizeof T);
        int G;
        scanf("%d", &G);
        for (int i = 1; i <= G; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            a[x + 1][y + 1] = -1;
        }
        scanf("%d", &G);
        for (int i = 1; i <= G; i++) {
            int x[10];
            for (int j = 1; j <= 5; j++)
                scanf("%d", x + j);
            a[x[1] + 1][x[2] + 1] = 1;
            p[x[1] + 1][x[2] + 1] = make_pair(x[3] + 1, x[4] + 1);
            T[x[1] + 1][x[2] + 1] = x[5];
        }
        int dd[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (a[i][j] == -1 || (i == n && j == m))
                    continue;
                if (!a[i][j])
                    for (int k = 0; k < 4; k++) {
                        int dx = i + dd[k][0], dy = j + dd[k][1];
                        if (dx <= 0 || dy <= 0 || dx > n || dy > m)
                            continue;
                        if (a[dx][dy] != -1) {
                            edge[(i - 1) * m + j].push_back(pair_edge(
                                (dx - 1) * m + dy, 1));
                        }
                    }
                else
                    edge[(i - 1) * m + j].push_back(pair_edge(
                        (p[i][j].first - 1) * m + p[i][j].second, T[i][j]));
            }

        if (spfa())
            printf("Never\n");
        else {
            if (dis[n * m] == INF)
                printf("Impossible\n");
            else
                printf("%d\n", dis[n * m]);
        }
    }
}
