/**
 * Author: hrynb
 * Time: 2020-12-31 01:41:41
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

int f[500010];
const int mod = 1e9 + 7;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int add(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx == fy)
        return 0;
    f[fx] = fy;
    return 1;
}
ll quickpow(ll base, ll b)
{
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m + 1; i++)
        f[i] = i;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int k, a, b;
        scanf("%d", &k);
        if (k == 1) {
            int x;
            scanf("%d", &x);
            if (add(x, m + 1))
                ans.emplace_back(i);
        } else {
            int x, y;
            scanf("%d%d", &x, &y);
            if (add(x, y))
                ans.emplace_back(i);
        }
    }

    printf("%lld %d\n", quickpow(2, ans.size()), ans.size());
    for (auto i : ans)
        printf("%d ", i);
}