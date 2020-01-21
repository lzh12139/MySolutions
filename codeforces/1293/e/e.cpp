/**
 * Author: lzh12139
 * Time: 2020-01-19 23:17:10
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

int sz[2010], fa[2010], vis[2010], dep[2010];
vector<int> v[2010];
int dfs(int x, int pre)
{
    fa[x] = pre;
    int res = 1;
    for (auto i : v[x])
        if (i != pre) {
            res = max(res, dfs(i, x));
            sz[x] += sz[i];
        }
    sz[x]++;
    return dep[x] = res;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, -1);

    int maxx = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        if ((n - sz[i]) * (sz[i] - 1) > (n - sz[maxx]) * (sz[maxx] - 1))
            maxx = i;
    int x = maxx, y = fa[maxx];
    ans += (n - sz[maxx]) * (sz[maxx] - 1);
    vis[x]++, vis[y]++;

    memset(sz, 0, sizeof sz);
    dfs(x, -1);
    while (1) {
        int Xn = -1, Yn = -1;
        for (auto i : v[x])
            if (i != y && (Xn == -1 || sz[i] > sz))
    }
}