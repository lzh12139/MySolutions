/**
 * Author: hrynb
 * Time: 2020-12-30 22:40:14
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
        int n, ans = 0;
        cin >> n;
        map<int, int> m;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (!m[x])
                ans++, m[x] = 1;
            else if (!m[x + 1])
                ans++, m[x + 1] = 1;
        }
        cout << ans << "\n";
    }
}