/**
 * Author: hrynb
 * Time: 2020-02-04 23:18:48
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

int h[200010];
ll p[200010];
int main()
{
    IOS;
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    int cnt = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i] % (a + b) <= a && h[i] % (a + b) != 0)
            ans++;
        else {
            ll tmp = (h[i] - 2 * a) / (a + b), minn = 1e18;
            for (ll j = max(tmp - 10, 0ll); j <= tmp + 10; j++) {
                ll TT = (h[i] - 1ll * j * (a + b)) / a - 1;

                if ((h[i] - 1ll * j * (a + b)) % a)
                    TT++;

                if (TT > 0)
                    minn = min(minn, TT);
            }

            if (minn != 1e18)
                p[++cnt] = minn;
        }
    }
    sort(p + 1, p + 1 + cnt);
    for (int i = 1; i <= cnt; i++)
        if (k >= p[i])
            k -= p[i], ans++;
    cout << ans << "\n";
}