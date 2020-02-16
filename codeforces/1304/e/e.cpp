/**
 * Author: hrynb
 * Time: 2020-02-15 22:27:01
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

V v[100010];
int f[100010][20], dep[100010];
const int MAXL = 18;
void init(int x, int fa, int d)
{
    dep[x] = d;
    f[x][0] = fa;
    for (int i = 1; (1 << i) <= d; ++i)
        f[x][i] = f[f[x][i - 1]][i - 1];
    for (auto i : v[x])
        if (i != fa)
            init(i, x, d + 1);
}
int getlca(int x, int y)
{
    if (dep[x] > dep[y])
        swap(x, y);
    int len = dep[y] - dep[x];
    for (int i = 0; (1 << i) <= len; i++)
        if ((1 << i) & len)
            y = f[y][i];
    for (int i = MAXL; i >= 0; i--)
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    if (x == y)
        return x;
    return f[x][0];
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y), v[y].push_back(x);
    }
    init(1, -1, 0);
    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y, a, b, k;
        scanf("%d%d%d%d%d", &x, &y, &a, &b, &k);
        int lcaab = getlca(a, b);
        int tmp1 = dep[a] + dep[b] - 2 * dep[lcaab];
        //printf("lcaab=%d\n", lcaab);
        if (k >= tmp1 && (k - tmp1) % 2 == 0) {
            _YES;
            continue;
        }
        int lcaxa = getlca(x, a), lcaxb = getlca(x, b);
        int lcaya = getlca(y, a), lcayb = getlca(y, b);
        int tmp2 = dep[a] + dep[x] - 2 * dep[lcaxa] + dep[b] + dep[y] - 2 * dep[lcayb] + 1;
        int tmp3 = dep[a] + dep[y] - 2 * dep[lcaya] + dep[b] + dep[x] - 2 * dep[lcaxb] + 1;
        if (k >= tmp2 && (k - tmp2) % 2 == 0) {
            _YES;
            continue;
        }
        if (k >= tmp3 && (k - tmp3) % 2 == 0) {
            _YES;
            continue;
        }
        _NO;
    }
}