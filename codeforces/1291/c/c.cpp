/**
 * Author: lzh12139
 * Time: 2020-02-02 22:09:38
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

int a[4000];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (k >= m)
            k = m - 1;
        int ans = 0;
        for (int l1 = 0, r1 = k; r1 >= 0; l1++, r1--) {
            int tmp = 1e9 + 5;
            for (int l2 = 0, r2 = m - k - 1; r2 >= 0; l2++, r2--) {
                tmp = min(tmp, max(a[l1 + l2 + 1], a[n - r1 - r2]));
            }
            if (tmp == 1e9 + 5)
                tmp = a[l1 + 1];
            //cout << tmp << "--\n";
            ans = max(ans, tmp);
        }
        cout << ans << "\n";
    }
}