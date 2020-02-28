/**
 * Author: lzh12139
 * Time: 2020-02-23 18:17:26
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
        int n, a, b, ans;
        cin >> n >> a >> b;
        cout << min(max(a + b - n + 1, 1), n) << " " << min(a + b - 1, n) << "\n";
    }
}