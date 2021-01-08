/**
 * Author: lzh12139
 * Time: 2020-11-21 22:47:41
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

char s[110];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q >> s + 1;
        while (q--) {
            int l, r;
            cin >> l >> r;
            int cur = l, fixl = 0, fixr = 0, ok = 0;
            for (int i = 1; i <= n; i++)
                if (s[i] == s[cur]) {
                    if (fixl == 0)
                        fixl = i;
                    fixr = i;
                    if (cur == r) {
                        if (fixl == l && fixr == r)
                            continue;
                        ok = 1;
                        break;
                    }
                    cur++;
                }

            ok ? _YES : _NO;
        }
    }
}