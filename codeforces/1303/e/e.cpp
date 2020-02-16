/**
 * Author: hrynb
 * Time: 2020-02-13 16:13:14
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

int dp[410][410];
char a[410], b[410];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s%s", a + 1, b + 1);
        int n = strlen(a + 1), m = strlen(b + 1);

        int ok = 0;
        for (int k = 1; k <= m; k++) {
            memset(dp, -1, sizeof dp);
            dp[0][0] = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= k && j <= i; j++) {
                    dp[i][j] = dp[i - 1][j];
                    if (j > 0 && dp[i - 1][j - 1] != -1 && a[i] == b[j])
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                    if (dp[i - 1][j] != -1 && a[i] == b[dp[i - 1][j] + k + 1])
                        dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
                }
            }
            if (dp[n][k] == m - k) {
                ok = 1;
                break;
            }
        }
        if (ok)
            _YES;
        else
            _NO;
    }
}