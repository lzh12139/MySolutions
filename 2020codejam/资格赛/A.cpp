#include <bits/stdc++.h>
using namespace std;
int a[110][110], vis[110];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += a[i][i];
        cout << "Case #" << kase << ": " << ans << " ";
        ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                vis[j] = 0;
            for (int j = 1; j <= n; j++) {
                vis[a[i][j]]++;
                if (vis[a[i][j]] >= 2) {
                    ans++;
                    break;
                }
            }
        }
        cout << ans << " ";
        ans = 0;
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= n; i++)
                vis[i] = 0;
            for (int i = 1; i <= n; i++) {
                vis[a[i][j]]++;
                if (vis[a[i][j]] >= 2) {
                    ans++;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}