/**
 * Author: lzh12139
 * Time: 2020-01-29 22:57:40
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("Yes\n")
#define _no printf("No\n")
#define _YES printf("YES\n");
#define _NO printf("NO\n");

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

char s[100010], t[100010];
vector<int> v[30];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s%s", s + 1, t + 1);
        int n = strlen(s + 1), m = strlen(t + 1);
        for (int i = 1; i <= 26; i++)
            v[i].clear();
        for (int i = 1; i <= n; i++)
            v[s[i] - 'a' + 1].pb(i);
        int ans = 1, pre = 1;
        for (int i = 1; i <= m; i++) {
            if (v[t[i] - 'a' + 1].empty()) {
                ans = -1;
                break;
            }
            int j = t[i] - 'a' + 1;
            auto x = lower_bound(v[j].begin(), v[j].end(), pre);
            if (x == v[j].end())
                ans++, pre = *v[j].begin() + 1;
            else
                pre = *x + 1;
        }
        printf("%d\n", ans);
    }
}