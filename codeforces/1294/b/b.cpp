/**
 * Author: hrynb
 * Time: 2020-01-22 22:42:40
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("YES\n")
#define _no printf("NO\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

pii p[1010];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> p[i].ff >> p[i].ss;
        sort(p + 1, p + 1 + n);
        int ans = 1;
        for (int i = 2; i <= n; i++)
            if (p[i - 1].ss > p[i].ss) {
                ans = 0;
                break;
            }
        if (!ans) {
            _no;
            continue;
        }
        _yes;
        p[0] = { 0, 0 };
        for (int i = 1; i <= n; i++) {
            for (int j = p[i - 1].ff; j < p[i].ff; j++)
                printf("R");
            for (int j = p[i - 1].ss; j < p[i].ss; j++)
                printf("U");
        }
        printf("\n");
    }
}