/**
 * Author: lzh12139
 * Time: 2020-01-19 22:55:12
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("Yes\n")
#define _no printf("No\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

ll x[100], y[100];

int main()
{
    ll X0, Y0, ax, ay, bx, by, xs, ys, t;
    cin >> X0 >> Y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
    int cnt = 1;
    x[1] = X0, y[1] = Y0;
    while (1) {
        if ((1e18 - bx) / ax >= x[cnt] && (1e18 - by) / ay >= y[cnt]) {
            cnt++;
            x[cnt] = x[cnt - 1] * ax + bx;
            y[cnt] = y[cnt - 1] * ay + by;
        } else
            break;
    }
    int ans = 0;
    for (int i = 1; i <= cnt; i++)
        for (int j = 1; j <= cnt; j++) {
            ll tmp = 0;
            tmp += x[j] - x[i] + y[j] - y[i];
            tmp += min(abs(x[i] - xs) + abs(y[i] - ys), abs(x[j] - xs) + abs(y[j] - ys));

            if (tmp <= t)
                ans = max(ans, j - i + 1);
        }
    cout << ans << endl;
}