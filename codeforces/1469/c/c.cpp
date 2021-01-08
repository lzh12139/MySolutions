/**
 * Author: hrynb
 * Time: 2020-12-28 22:53:54
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

int a[200010];
int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        int l = a[1], r = a[1], ok = 1;
        for (int i = 2; i <= n; i++) {
            l = max(a[i], l - k + 1);
            r = min(a[i] + k - 1, r + k - 1);
            if (l > r) {
                ok = 0;
                break;
            }
        }

        if (l != a[n])
            ok = 0;
        cout << (ok ? "YES" : "NO") << "\n";
    }
}