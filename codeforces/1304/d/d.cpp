/**
 * Author: hrynb
 * Time: 2020-02-15 21:42:44
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

char s[200010];
int ans[200010];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, cnt = 1;
        scanf("%d%s", &n, s + 1);
        V p;
        for (int i = 2; i < n; i++)
            if (s[i - 1] != s[i])
                p.push_back(i);
        reverse(p.begin(), p.end());
        p.push_back(1);
        int last = n, can = 1;
        for (auto i : p)
            if (s[i] == '<') {
                for (int j = i; j <= last; j++)
                    ans[j] = can++;
                last = i - 1;
            } else {
                for (int j = last; j > i; j--)
                    ans[j] = can++;
                last = i;
            }
        if (can != n + 1)
            ans[1] = can;
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i]);
        printf("\n");

        can = n, last = n;
        for (auto i : p)
            if (s[i] == '<') {
                for (int j = last; j > i; j--)
                    ans[j] = can--;
                last = i;
            } else {
                for (int j = i; j <= last; j++)
                    ans[j] = can--;
                last = i - 1;
            }
        if (can != 0)
            ans[1] = can;
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
}