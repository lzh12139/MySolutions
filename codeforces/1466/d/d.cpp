/**
 * Author: hrynb
 * Time: 2020-12-30 23:51:28
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

pii a[100010];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        ll ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i].ff), ans += a[i].ff, a[i].ss = 0;
        for (int i = 1; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            a[x].ss++, a[y].ss++;
        }

        sort(a + 1, a + 1 + n, [](pii& a, pii& b) {
            return a.ff > b.ff;
        });

        int last = 1;
        printf("%lld ", ans);
        for (int i = 2; i < n; i++) {
            while (a[last].ss == 1 && last <= n)
                last++;
            ans += a[last].ff;
            a[last].ss--;
            printf("%lld ", ans);
        }
        printf("\n");
    }
}