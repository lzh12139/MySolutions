/**
 * Author: hrynb
 * Time: 2020-02-04 22:36:27
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
        int n, x, a = 0, b = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            if (x & 1)
                a++;
            else
                b++;
        }
        if (!a || (!b && n % 2 == 0))
            _NO;
        else
            _YES;
    }
}