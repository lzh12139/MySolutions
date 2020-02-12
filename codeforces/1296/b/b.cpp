/**
 * Author: hrynb
 * Time: 2020-02-04 22:43:35
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

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        cin >> n;
        while (n >= 10) {
            ans += n / 10 * 10;
            n = n - n / 10 * 9;
        }
        ans += n;
        cout << ans << "\n";
    }
}