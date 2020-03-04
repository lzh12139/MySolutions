/**
 * Author: hrynb
 * Time: 2020-03-04 17:57:04
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

int a[1010];
int main()
{
    int n, m;
    cin >> n >> m;
    if (n > m)
        cout << 0 << endl;
    else {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        ll ans = 1;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                ans = ans * abs(a[i] - a[j]) % m;
        cout << ans << endl;
    }
}