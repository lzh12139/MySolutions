/**
 * Author: hrynb
 * Time: 2020-02-24 22:56:38
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
        int a, b, c, ans = 1e9;
        cin >> a >> b >> c;
        int ansa, ansb, ansc;
        for (int i = 1; i <= 11000; i++) {
            int tmp = min(c % i, i - c % i) + abs(i - b), tmp2 = min(a - 1, abs(a - i));
            int tmpa, tmpc;
            if (c % i > i - c % i)
                tmpc = c + i - c % i;
            else
                tmpc = c - c % i;
            if (a - 1 > abs(a - i))
                tmpa = i;
            else
                tmpa = 1;
            for (int j = 2; j * j <= i; j++)
                if (i % j == 0) {
                    int cur = min(abs(a - j), abs(a - i / j));
                    if (cur < tmp2) {
                        tmp2 = cur;
                        if (abs(a - j) < abs(a - i / j))
                            tmpa = j;
                        else
                            tmpa = i / j;
                    }
                }
            if (tmp + tmp2 < ans)
                ans = tmp + tmp2, ansa = tmpa, ansb = i, ansc = tmpc;
        }
        cout << ans << "\n";
        cout << ansa << " " << ansb << " " << ansc << "\n";
    }
}