/**
 * Author: hrynb
 * Time: 2020-02-24 22:36:31
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
    int t;
    cin >> t;
    while (t--) {
        int a, b, ans = 0;
        cin >> a >> b;
        if (a < b) {
            int less = b - a;
            if (less & 1)
                ans = 1;
            else
                ans = 2;
        } else if (a > b) {
            int less = a - b;
            if (less & 1)
                ans = 2;
            else
                ans = 1;
        }
        cout << ans << "\n";
    }
}