/**
 * Author: lzh12139
 * Time: 2020-01-19 22:31:10
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

int a[1010];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, s, k, hass = 0;
        cin >> n >> s >> k;
        int ans = 1e9 + 10;
        for (int i = 1; i <= k; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + k);
        for (int i = 1; i <= k; i++) {
            if (a[i] - 1 >= 1 && a[i] - 1 != a[i - 1])
                ans = min(ans, abs(a[i] - 1 - s));
            if (a[i] + 1 <= n && a[i] + 1 != a[i + 1])
                ans = min(ans, abs(a[i] + 1 - s));
            if (a[i] == s)
                hass = 1;
        }
        if (a[1] > 1)
            ans = min(ans, abs(s - a[1] + 1));
        if (a[k] < n)
            ans = min(ans, abs(a[k] + 1 - s));
        if (!hass)
            ans = 0;
        cout << ans << endl;
    }
}