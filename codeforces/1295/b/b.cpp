/**
 * Author: lzh12139
 * Time: 2020-01-29 22:42:27
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("Yes\n")
#define _no printf("No\n")
#define _YES printf("YES\n");
#define _NO printf("NO\n");

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

char s[100010];
int sum[100010];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x, ans = 0;
        scanf("%d%d%s", &n, &x, s + 1);
        map<int, int> m;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0')
                sum[i] = sum[i - 1] + 1;
            else
                sum[i] = sum[i - 1] - 1;
            m[sum[i]]++;
        }
        ans = m[x];
        if (x == 0)
            ans++;
        if (sum[n] == 0) {
            if (m[x])
                ans = -1;
        } else
            for (auto i : m)
                if (1ll * (x - i.ff) * sum[n] > 0 && abs(x - i.ff) % abs(sum[n]) == 0)
                    ans += i.ss;
        printf("%d\n", ans);
    }
}