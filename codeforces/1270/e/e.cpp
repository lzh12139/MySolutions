/**
 * Author: hrynb
 * Time: 2020-02-06 21:43:25
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

pii p[1010];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &p[i].ff, &p[i].ss);
    while (1) {
        V ans;
        for (int i = 1; i <= n; i++)
            if ((p[i].ff + p[i].ss) & 1)
                ans.push_back(i);
        if (ans.size() && ans.size() != n) {
            printf("%d\n", ans.size());
            for (auto i : ans)
                printf("%d ", i);
            return 0;
        }
        ans.clear();
        for (int i = 1; i <= n; i++)
            if (p[i].ff & 1)
                ans.push_back(i);
        if (ans.size() && ans.size() != n) {
            printf("%d\n", ans.size());
            for (auto i : ans)
                printf("%d ", i);
            return 0;
        }
        for (int i = 1; i <= n; i++)
            p[i].ff >>= 1, p[i].ss >>= 1;
    }
}