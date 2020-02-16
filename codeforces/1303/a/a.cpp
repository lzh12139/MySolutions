/**
 * Author: hrynb
 * Time: 2020-02-12 22:36:16
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
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        int l = 0, r = 0;
        for (int i = 1; i <= n; i++)
            if (s[i] == '1') {
                if (!l)
                    l = i;
                r = i;
            }
        if (!l)
            printf("0\n");
        else {
            int ans = 0;
            for (int i = l; i <= r; i++)
                if (s[i] == '0')
                    ans++;
            printf("%d\n", ans);
        }
    }
}