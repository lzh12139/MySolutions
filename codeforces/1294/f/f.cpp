/**
 * Author: hrynb
 * Time: 2020-01-22 23:41:56
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("Yes\n")
#define _no printf("No\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

V v[200010];
int dp[200010], dpn[200010];
void dfs0(int x, int pre)
{
    for (auto i : v[x])
        if (i != pre) {
            dfs0(i, x);
            if (dp[i] >= dp[x]) {
                dp[x] = dp[i] + 1;
                dpn[x] = dpn[i];
            }
        }
    if (!dp[x]) {
        dp[x] = 1, dpn[x] = x;
    }
}

int ans = 0, ansn[10];
void dfs(int x, int pre)
{
    /*printf("%d %d %d ", x, dp[x], dpn[x]);
    if (pre != -1)
        printf("%d %d", pre, dpn[pre]);
    printf("\n");*/
    vector<pii> res;
    for (auto i : v[x])
        res.pb(make_pair(dp[i], i));

    sort(res.begin(), res.end(), greater<pii>());
    int tmp = 0, tmpn[10];
    for (int i = 0; i < min(3, (int)res.size()); i++)
        tmp += res[i].ff, tmpn[i + 1] = dpn[res[i].ss];
    if (tmp > ans || (tmp == ans && !ansn[3])) {
        ans = max(ans, tmp);
        for (int i = 0; i < min(3, (int)res.size()); i++)
            ansn[i + 1] = tmpn[i + 1];
        if (res.size() < 3)
            ansn[res.size() + 1] = x;
    }

    for (auto i : v[x])
        if (i != pre) {
            int predpx = dp[x], predpi = dp[i], predpnx = dpn[x], predpni = dpn[i];
            if (res[0].ss == i) {
                if (res.size() >= 2) {
                    dp[x] = res[1].ff + 1;
                    dpn[x] = dpn[res[1].ss];
                    if (dp[x] >= dp[i] - 1)
                        dp[i] = dp[x] + 1, dpn[i] = dpn[x];
                } else {
                    dp[x] = 1;
                    dpn[x] = x;
                    if (dp[x] >= dp[i] - 1)
                        dp[i] = dp[x] + 1, dpn[i] = dpn[x];
                }
            } else {
                dp[x] = res[0].ff + 1;
                dpn[x] = dpn[res[0].ss];
                if (dp[x] >= dp[i] - 1)
                    dp[i] = dp[x] + 1, dpn[i] = dpn[x];
            }
            dfs(i, x);

            dp[x] = predpx, dp[i] = predpi;
            dpn[x] = predpnx, dpn[i] = predpni;
        }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].pb(y), v[y].pb(x);
    }
    dfs0(1, -1);
    dfs(1, -1);

    printf("%d\n", ans);
    for (int i = 1; i <= 3; i++)
        printf("%d ", ansn[i]);
}