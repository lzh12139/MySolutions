/**
 * Author: hrynb
 * Time: 2020-02-13 22:39:10
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

int main()
{
    //IOS;
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        if (m == 0)
            cout << "0\n";
        else {
            ll ans = n * (n + 1) / 2;
            if (m > n / 2)
                ans -= n - m;
            else {
                ll tmp = (n - m) / (m + 1), less = (n - m) % (m + 1);
                ans -= less * (tmp + 1) * (tmp + 2) / 2 + (m + 1 - less) * tmp * (tmp + 1) / 2;
            }
            cout << ans << "\n";
        }
    }
}