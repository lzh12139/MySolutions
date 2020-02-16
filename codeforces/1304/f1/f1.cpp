/**
 * Author: hrynb
 * Time: 2020-02-15 23:12:52
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _Yes printf("Yes\n")
#define _No printf("No\n")
#define _YES printf("YES\n")
#define _NO printf("NO\n")
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

ll a[55][20010];
ll dp[55][20010];
ll ml[20010], mr[20010];
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%lld", &a[i][j]);
    for (int i = 1; i <= n + 1; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    for (int i = 1; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            ll add = a[i + 1][j] - a[i - 1][j] - a[i + 1][j - k] + a[i - 1][j - k];
            dp[i][j] = max(ml[j - k], mr[j + k]) + add;
            for (int o = max(k, j - k + 1); o <= min(j + k - 1, m); o++) {
                int l = max(j - k, o - k), r = min(j, o);
                dp[i][j] = max(dp[i][j], dp[i - 1][o] + add - (a[i][r] + a[i - 1][l] - a[i][l] - a[i - 1][r]));
            }
        }
        for (int j = 1; j <= m; j++)
            ml[j] = max(ml[j - 1], dp[i][j]);
        for (int j = m; j >= 1; j--)
            mr[j] = max(mr[j + 1], dp[i][j]);
    }
    /*for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            printf("%-3lld%c", dp[i][j], " \n"[j == m]);*/
    ll ans = 0;
    for (int i = k; i <= m; i++)
        ans = max(ans, dp[n][i]);
    printf("%lld\n", ans);
}