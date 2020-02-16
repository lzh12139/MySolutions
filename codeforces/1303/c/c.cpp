/**
 * Author: hrynb
 * Time: 2020-02-12 22:47:50
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

char s[210];
set<int> v[30];
V ans;
int gg = 0, vis[30];
void out(int x)
{
    if (vis[x])
        return;
    ans.push_back(x);
    vis[x]++;
    for (auto i : v[x])
        if (!vis[i])
            out(i);
}
int check()
{
    for (int i = 1; i <= 26; i++)
        for (auto j : v[i]) {
            int ok = 0;
            for (int k = 1; k < 26; k++)
                if ((ans[k - 1] == i && ans[k] == j) || (ans[k - 1] == j && ans[k] == i)) {
                    ok = 1;
                    break;
                }
            if (!ok)
                return 0;
        }
    return 1;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 1; i <= 26; i++)
            v[i].clear();
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        for (int i = 2; i <= n; i++) {
            v[s[i] - 'a' + 1].insert(s[i - 1] - 'a' + 1);
            v[s[i - 1] - 'a' + 1].insert(s[i] - 'a' + 1);
        }
        int ok = 1;
        for (int i = 1; i <= 26; i++)
            if (v[i].size() > 2) {
                ok = 0;
                break;
            }
        if (ok) {
            gg = 0;
            ans.clear();
            for (int i = 1; i <= 26; i++)
                vis[i] = 0;
            for (int i = 1; i <= 26; i++)
                if (v[i].size() <= 1)
                    out(i);
            if (ans.size() != 26 || !check())
                printf("NO\n");
            else {
                printf("YES\n");
                for (auto i : ans)
                    printf("%c", i + 'a' - 1);
                printf("\n");
            }
        } else
            printf("NO\n");
    }
}