/**
 * Author: hrynb
 * Time: 2020-01-22 23:18:25
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

vector<int> a[200010];
int x[200010];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        a[i].resize(m + 10);
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    }
    ll ans = 0;
    for (int j = 1; j <= m; j++) {
        int MOD = j % m, cnt = 0, add = n;
        for (int i = 0; i <= n; i++)
            x[i] = 0;
        for (int i = 1; i <= n; i++)
            if (a[i][j] % m != MOD || (a[i][j] + m - 1) / m > n)
                ans++, add--;
            else {
                int tmp = i - (a[i][j] + m - 1) / m;
                if (tmp < 0)
                    tmp += n;
                x[tmp]++;
            }
        int tmp = 1e9;
        for (int i = 0; i <= n; i++)
            tmp = min(tmp, add - x[i] + i);
        ans += tmp;
    }
    printf("%d\n", ans);
}