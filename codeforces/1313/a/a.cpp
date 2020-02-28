/**
 * Author: lzh12139
 * Time: 2020-02-23 18:08:05
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
        int a, b, c, ans = 0;
        cin >> a >> b >> c;
        int maxx = max(max(a, b), c);
        int minn = min(min(a, b), c);
        int sum = a + b + c;
        a = maxx, c = minn, b = sum - maxx - minn;
        if (a)
            a--, ans++;
        if (b)
            b--, ans++;
        if (c)
            c--, ans++;
        if (a && b)
            a--, b--, ans++;
        if (a && c)
            a--, c--, ans++;
        if (b && c)
            b--, c--, ans++;
        if (a && b && c)
            ans++;
        cout << ans << "\n";
    }
}