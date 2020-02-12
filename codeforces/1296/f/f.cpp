/**
 * Author: hrynb
 * Time: 2020-02-05 18:22:37
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("Yes\n")
#define _no printf("No\n")
#define _YES printf("YES\n")
#define _NO printf("NO\n")
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

vector<pii> v[5010];
int ans[5010];
struct node {
    int a, b, c;
} p[5010];
int dfs(int x, int y, int pre, int val, int& change)
{
    if (x == y)
        return 1;
    for (auto i : v[x])
        if (i.ff != pre && dfs(i.ff, y, x, val, change)) {
            if (!ans[i.ss] || ans[i.ss] == val)
                ans[i.ss] = val, change = 1;
            return 1;
        }
    return 0;
}
int main()
{
    IOS;
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back({ y, i });
        v[y].push_back({ x, i });
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> p[i].a >> p[i].b >> p[i].c;
    sort(p + 1, p + 1 + m, [](node x, node y) {
        return x.c > y.c;
    });
    int ok;
    for (int i = 1; i <= m; i++) {
        ok = 0;
        dfs(p[i].a, p[i].b, -1, p[i].c, ok);
        if (!ok) {
            printf("-1\n");
            return 0;
        }
    }
    for (int i = 1; i < n; i++)
        printf("%d ", max(ans[i], 1));
}