/**
 * Author: hrynb
 * Time: 2020-02-15 21:17:41
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

char s[110][55];
int vis[110];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    vector<pii> ans1;
    V ans2, ans;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            int ok = 1;
            for (int l = 1, r = m; l <= m; l++, r--)
                if (s[i][l] != s[j][r]) {
                    ok = 0;
                    break;
                }
            if (ok)
                if (i == j)
                    ans2.push_back(i);
                else
                    ans1.push_back({ i, j });
        }
    for (auto i : ans2) {
        V a, b;
        memset(vis, 0, sizeof vis);
        vis[i]++;
        for (auto j : ans1)
            if (!vis[j.ff] && !vis[j.ss]) {
                a.push_back(j.ff), b.push_back(j.ss);
                vis[j.ff]++, vis[j.ss]++;
            }
        if (a.size() * 2 + 1 > ans.size()) {
            ans.clear();
            for (auto j : a)
                ans.push_back(j);
            ans.push_back(i);
            reverse(b.begin(), b.end());
            for (auto j : b)
                ans.push_back(j);
        }
    }
    V a, b;
    memset(vis, 0, sizeof vis);
    for (auto j : ans1)
        if (!vis[j.ff] && !vis[j.ss]) {
            a.push_back(j.ff), b.push_back(j.ss);
            vis[j.ff]++, vis[j.ss]++;
        }
    if (a.size() * 2 > ans.size()) {
        ans.clear();
        for (auto j : a)
            ans.push_back(j);
        reverse(b.begin(), b.end());
        for (auto j : b)
            ans.push_back(j);
    }
    printf("%d\n", ans.size() * m);
    for (auto i : ans)
        printf("%s", s[i] + 1);
}