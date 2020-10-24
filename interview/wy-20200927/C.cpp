#include <bits/stdc++.h>
using namespace std;
#define ll long long

int x[25][15], y[25];
struct node {
    int v, w, num;
    node() { }
    node(int _v, int _w, int _num)
    {
        v = _v, w = _w, num = _num;
    }
};
vector<node> v[1010];
int T, n;
ll sum[1010][25], vis[1010];

void dfs(int cur, int del)
{
    if (vis[cur])
        return;
    vis[cur]++;
    if (cur < T) {
        for (int i = 1; i <= n; i++)
            sum[cur][i] = x[i][cur];
        return;
    }
    for (auto i : v[cur]) {
        if (i.num != del)
            dfs(i.v, del);
    }
    for (int i = 1; i <= n; i++) {
        sum[cur][i] = 0;
        for (auto j : v[cur]) {
            sum[cur][i] += sum[j.v][i] * j.w;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= d; j++)
                cin >> x[i][j];
            cin >> y[i];
        }

        int m, k, cnt = 0;
        cin >> m >> k;
        int N = d + 1;
        for (int i = 1, tmp; i <= m; i++)
            cin >> tmp, N += tmp;

        for (int i = 1; i <= N; i++)
            v[i].clear();

        map<string, int> mp;
        for (int i = 1; i <= d; i++)
            mp["input_" + to_string(i)] = ++cnt;
        mp["output"] = ++cnt;
        T = cnt;

        for (int i = 1; i <= k; i++) {
            string x, y;
            int w;
            cin >> x >> y >> w;
            if (!mp[x])
                mp[x] = ++cnt;
            if (!mp[y])
                mp[y] = ++cnt;
            v[mp[y]].push_back(node(mp[x], w, i));
        }

        N = cnt ;

        // for (int i = 1; i <= cnt; i++) {
        //     for (auto j : v[i])
        //         cout << i << " " << j.v << " " << j.w << " " << j.num << endl;
        //     // cout << endl;
        // }

        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= n; k++)
                sum[j][k] = 0;
            vis[j] = 0;
        }
        dfs(T, -1);
        // cout << "---\n";
        // for (int j = 1; j <= N; j++)
        //     for (int k = 1; k <= n; k++)
        //         cout << sum[j][k] << " \n"[k == n];
        // cout << "---\n";
        ll base = 0;
        for (int i = 1; i <= n; i++)
            base += abs(y[i] - sum[T][i]);
        ll ans = base;

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= N; j++) {
                for (int k = 1; k <= n; k++)
                    sum[j][k] = 0;
                vis[j] = 0;
            }
            dfs(T, i);
            int conn = 0;
            for (int j = 1; j < T; j++) {
                if (vis[j])
                    conn = 1;
            }
            if (!conn)
                continue;
            ll tmp = 0;
            for (int j = 1; j <= n; j++)
                tmp += abs(y[j] - sum[T][j]);
            ans = min(ans, tmp);
        }
        if (ans == base)
            ans = -1;
        else
            ans = base - ans;
        cout << ans << endl;
    }
}
/*
3
1 2
3 4 7
1 5
2
input_1 hidden_1_1 4
input_2 hidden_1_1 -2
input_2 hidden_1_2 1
hidden_1_1 output 2
hidden_1_2 output -2
2 2
3 4 0
4 3 17
1 5
2
input_1 hidden_1_1 4
input_2 hidden_1_1 -2
input_2 hidden_1_2 1
hidden_1_1 output 2
hidden_1_2 output -2
2 3
1 2 3 2
2 3 4 8
2 12
3 2
input_1 hidden_1_1 -3
input_2 hidden_1_2 -1
input_3 hidden_1_3 2
input_1 hidden_1_2 -3
input_3 hidden_1_2 1
hidden_1_1 hidden_2_1 5
hidden_1_1 hidden_2_2 -5
hidden_1_2 hidden_2_1 -2
hidden_1_2 hidden_2_2 -1
hidden_1_3 hidden_2_1 -2
hidden_2_1 output 2
hidden_2_2 output -2
*/