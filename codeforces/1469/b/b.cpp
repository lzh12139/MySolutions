/**
 * Author: hrynb
 * Time: 2020-12-28 22:41:35
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

int a[110], b[110];
int suma[110], sumb[110];
int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i], suma[i] = suma[i - 1] + a[i];
        cin >> m;
        for (int i = 1; i <= m; i++)
            cin >> b[i], sumb[i] = sumb[i - 1] + b[i];
        int ans = 0;
        for (int i = 1; i <= n + m; i++) {
            int tmp = 0;
            for (int j = max(0, i - m); j <= min(n, i); j++)
                tmp = max(tmp, suma[j] + sumb[i - j]);
            ans = max(ans, tmp);
        }

        cout << ans << "\n";
    }
}