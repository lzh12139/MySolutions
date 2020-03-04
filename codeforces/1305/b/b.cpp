/**
 * Author: hrynb
 * Time: 2020-03-03 22:50:24
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

char s[1010];
vector<int> ans[1010];
int l[1010], r[1010];
int LL[1010], RR[1010];
int main()
{
    cin >> s + 1;
    int n = strlen(s + 1), cur = 0, last = 1, ansn = 0;
    for (int i = 1; i <= n; i++)
        LL[i] = (s[i] == '(' ? 1 : 0), l[i] = l[i - 1] + LL[i];
    for (int i = n; i >= 1; i--)
        RR[i] = (s[i] == ')' ? 1 : 0), r[i] = r[i + 1] + RR[i];
    while (1) {
        int tmp = 1;
        for (int i = 2; i < n; i++)
            if (min(l[i], r[i + 1]) > min(l[tmp], r[tmp + 1]))
                tmp = i;
        if (min(l[tmp], r[tmp + 1]) == 0)
            break;
        ++ansn;
        for (int i = 1, j = 1; i <= tmp && j <= min(l[tmp], r[tmp + 1]); i++)
            if (s[i] == '(' && LL[i])
                j++, ans[ansn].push_back(i), LL[i] = 0;
        for (int i = n, j = 1; i > tmp && j <= min(l[tmp], r[tmp + 1]); i--)
            if (s[i] == ')' && RR[i])
                j++, ans[ansn].push_back(i), RR[i] = 0;
        sort(ans[ansn].begin(), ans[ansn].end());
        for (int i = 1; i <= n; i++)
            l[i] = l[i - 1] + LL[i];
        for (int i = n; i >= 1; i--)
            r[i] = r[i + 1] + RR[i];
    }
    cout << ansn << endl;
    for (int i = 1; i <= ansn; i++) {
        cout << ans[ansn].size() << endl;
        for (auto j : ans[ansn])
            cout << j << " ";
        cout << endl;
    }
}