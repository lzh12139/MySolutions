/**
 * Author: hrynb
 * Time: 2020-02-04 23:59:06
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

char s[200010];
int ans[200010];
int main()
{
    int n, ansn = 0;
    scanf("%d%s", &n, s + 1);
    for (int i = 1; i <= n; i++)
        ans[i] = 1;
    for (int j = 0; j < 26; j++) {
        int r = 0, maxx = 0;
        for (int i = 1; i <= n; i++)
            if (s[i] == 'a' + j)
                r = i;
        if (!r)
            continue;
        for (int i = r; i >= 1; i--)
            if (s[i] == 'a' + j)
                maxx = max(maxx, ans[i]);
            else if (s[i] > 'a' + j && ans[i] == maxx)
                ans[i]++;
        ansn = max(ansn, maxx);
    }
    if (ansn <= 2) {
        _YES;
        for (int i = 1; i <= n; i++)
            printf("%d", ans[i] - 1);
    } else
        _NO;
    /*printf("%d\n", ansn);
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);*/
}
