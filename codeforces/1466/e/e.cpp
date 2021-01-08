/**
 * Author: hrynb
 * Time: 2020-12-31 00:32:52
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

ll a[500010];
int sum[100];
const int mod = 1e9 + 7;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        memset(sum, 0, sizeof sum);

        ll cur = 1, ans = 0;
        for (int j = 1; j <= 60; j++, cur <<= 1) {
            for (int i = 1; i <= n; i++)
                if (a[i] & cur)
                    sum[j]++;
        }

        for (int i = 1; i <= n; i++) {
            cur = 1;
            ll l = 0, r = 0;
            for (int j = 1; j <= 60; j++, cur <<= 1) {
                if (a[i] & cur) {
                    l = (l + cur % mod * sum[j] % mod) % mod;
                    r = (r + cur % mod * n % mod) % mod;
                } else {
                    r = (r + cur % mod * sum[j] % mod) % mod;
                }
            }
            ans = (ans + l * r % mod) % mod;
        }

        printf("%lld\n", ans);
    }
}