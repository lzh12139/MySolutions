#include <bits/stdc++.h>
using namespace std;
int ans[10][30][30], a[30];
int visc[10][10], visr[10][10];
void dfs(int cur, int sum, int n)
{
    if (cur == n * n) {
        if (!ans[n][sum][0]) {
            for (int i = 0; i < 25; i++)
                ans[n][sum][i] = a[i];
        }
        return;
    }

    int x = cur / n + 1, y = cur % n + 1;
    for (int i = 1; i <= n; i++)
        if (!visc[y][i] && !visr[x][i]) {
            visc[y][i]++, visr[x][i]++, a[cur] = i;
            if (x == y)
                dfs(cur + 1, sum + i, n);
            else
                dfs(cur + 1, sum, n);
            visc[y][i]--, visr[x][i]--;
        }
}
int main()
{
    dfs(0, 0, 2);
    dfs(0, 0, 3);
    dfs(0, 0, 4);
    dfs(0, 0, 5);

    int t;
    cin >> t;
    for (int kase = 1; kase <= t; kase++) {
        int n, k;
        cin >> n >> k;
        cout << "Case #" << kase << ": ";
        if (!ans[n][k][0])
            cout << "IMPOSSIBLE\n";
        else {
            cout << "POSSIBLE\n";
            for (int i = 0; i < n * n; i++)
                cout << ans[n][k][i] << " \n"[i % n == n - 1];
        }
    }
}