/**
 * Author: hrynb
 * Time: 2020-02-04 22:48:51
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

char s[200010];
const int dd[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
const char f[] = { "RLUD" };
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d%s", &n, s + 1);
        map<pii, vector<int>> m;
        pii cur = { 0, 0 };
        m[cur].push_back(0);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 4; j++)
                if (s[i] == f[j]) {
                    cur = { cur.ff + dd[j][0], cur.ss + dd[j][1] };
                    break;
                }
            m[cur].push_back(i);
        }
        pii ans = { -1, 1e9 };
        for (auto i : m)
            if (i.ss.size() >= 2) {
                auto l = i.ss.begin();
                auto r = l;
                r++;
                while (r != i.ss.end()) {
                    if (ans.ss - ans.ff > *r - *l)
                        ans = { *l + 1, *r };
                    l++, r++;
                }
            }
        if (ans.ff != -1)
            printf("%d %d\n", ans.ff, ans.ss);
        else
            printf("-1\n");
    }
}