/**
 * Author: hrynb
 * Time: 2020-12-30 22:50:33
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

char s[100010];
int cnt[100010];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s + 1);
        int n = strlen(s + 1), ans = 0, l = 1;

        for (int i = 1; i <= n; i++)
            cnt[i] = 0;
        for (int i = 1; i <= n; i++) {
            if (i + 1 <= n && s[i] == s[i + 1] && !cnt[i + 1] && !cnt[i])
                cnt[i + 1]++, ans++;
            if (i + 2 <= n && s[i] == s[i + 2] && !cnt[i + 2] && !cnt[i])
                cnt[i + 2]++, ans++;
        }
        printf("%d\n", ans);
    }
}