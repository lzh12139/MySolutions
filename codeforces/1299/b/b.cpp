/**
 * Author: hrynb
 * Time: 2020-02-09 22:16:41
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

int x[100010], y[100010];
int pend(int x1, int y1, int x2, int y2)
{
    return 1ll * y1 * x2 == 1ll * y2 * x1
        && (1ll * x1 * x1 + 1ll * y1 * y1 == 1ll * x2 * x2 + 1ll * y2 * y2);
}
int main()
{
    IOS;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    x[n + 1] = x[1], y[n + 1] = y[1];
    if (n & 1) {
        cout << "NO";
        return 0;
    }
    for (int i = 1, j = n / 2 + 1; j <= n; i++, j++)
        if (!pend(x[i + 1] - x[i], y[i + 1] - y[i], x[j + 1] - x[j], y[j + 1] - y[j])) {
            cout << "NO";
            return 0;
        }
    cout << "YES";
}