#include <bits/stdc++.h>
using namespace std;

int w[15][15], deg[15], vis[15];
int l = -1, r = -1;

int dfs(int x, int cur)
{
    int res = 0;
    for (int j = 1; j <= 9; j++)
        if (w[x][j] && !vis[j]) {
            vis[j]++;
            res += dfs(j, cur);
            vis[j]--;
        }
    int tmp = 0;
    if (cur == 0) {
        if (w[x][l])
            tmp += dfs(r, 1);
        if (w[x][r])
            tmp += dfs(l, 1);
    }
    return tmp + (cur == 1 ? res + 1 : 0);
}
const int dd[8][2] = { { 1, 3 }, { 4, 6 }, { 7, 9 }, { 1, 7 }, { 2, 8 }, { 3, 9 }, { 1, 9 }, { 3, 7 } };
int main()
{
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            w[i][j] = 1;
    for (int i = 0; i < 8; i++)
        w[dd[i][0]][dd[i][1]] = w[dd[i][1]][dd[i][0]] = 0;
    for (int i = 1; i <= 9; i++)
        w[i][i] = 0;

    int n, ans = 0;
    cin >> n;
    if (n == 0) {
        for (int i = 1; i <= 9; i++)
            ans += dfs(i, 1);
        cout << ans << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        deg[x]++, deg[y]++;
    }
    for (int i = 1; i <= 9; i++)
        if (deg[i] == 2)
            vis[i] = 1;
        else if (deg[i] == 1) {
            vis[i] = 1;
            if (l == -1)
                l = i;
            else
                r = i;
        }
    for (int i = 1; i <= 9; i++)
        if (!vis[i])
            ans += dfs(i, 0);
    ans += dfs(l, 1) + dfs(r, 1);
    cout << ans << endl;
}