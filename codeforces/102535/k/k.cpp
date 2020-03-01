/**
 * Author: hrynb
 * Time: 2020-02-29 22:33:35
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

string str = "MOOK";
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            if (s == str)
                ans |= (1ll << i - 1);
        }
        cout << ans << "\n";
    }
}