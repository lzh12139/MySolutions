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

int sz[2010];
vector<int> v[2010];
void dfs(int x, int pre)
{
    for (auto i : v[x])
        if (i != pre) {
            dfs(i, x);
            sz[x] += sz[i];
        }
    sz[x]++;
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
    for (int i = 1; i <= n; i++)
        if ((n - sz[i]) * (sz[i] - 1) > (n - sz[maxx]) * (sz[maxx] - 1))
            maxx = i;
}