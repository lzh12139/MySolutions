/**
 * Author: hrynb
 * Time: 2020-02-12 22:40:58
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
    IOS;
    int t;
    cin >> t;
    while (t--) {
        ll n, g, b;
        cin >> n >> g >> b;
        ll N = n;
        n = (n + 1) / 2;
        ll ans = (n / g) * (g + b) + n % g;
        if (n % g == 0 && n / g != 0)
            ans -= b;
        cout << max(ans, N) << "\n";
    }
}