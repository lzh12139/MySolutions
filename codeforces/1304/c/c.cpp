/**
 * Author: hrynb
 * Time: 2020-02-15 21:06:45
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

pair<int, pii> a[110];
int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i].ff >> a[i].ss.ff >> a[i].ss.ss;
        int ok = 1, l = m, r = m;
        for (int i = 1; i <= n; i++) {
            l = max(a[i].ss.ff, l - a[i].ff + a[i - 1].ff);
            r = min(a[i].ss.ss, r + a[i].ff - a[i - 1].ff);
            if (l > r) {
                ok = 0;
                break;
            }
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}