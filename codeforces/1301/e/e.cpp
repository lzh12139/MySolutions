/**
 * Author: hrynb
 * Time: 2020-02-14 00:12:40
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

char str[510][510];
int sum[7][510][510];
set<pii> s[510];
int main()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
        scanf("%s", str[i] + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[1][i][j] = (str[i][j] == 'R' ? 1 : 0) - sum[1][i - 1][j - 1] + sum[1][i][j - 1] + sum[1][i - 1][j];
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; j--)
            sum[2][i][j] = (str[i][j] == 'G' ? 1 : 0) - sum[2][i - 1][j + 1] + sum[2][i][j + 1] + sum[2][i - 1][j];
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= m; j++)
            sum[3][i][j] = (str[i][j] == 'Y' ? 1 : 0) - sum[3][i + 1][j - 1] + sum[3][i][j - 1] + sum[3][i + 1][j];
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
            sum[4][i][j] = (str[i][j] == 'B' ? 1 : 0) - sum[4][i + 1][j + 1] + sum[4][i][j + 1] + sum[4][i + 1][j];
    /*for (int k = 1; k <= 4; k++) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                printf("%d%c", sum[k][i][j], " \n"[j == m]);
        printf("------------\n");
    }*/
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (str[i][j] == 'R' && str[i][j + 1] == 'G' && str[i + 1][j] == 'Y' && str[i + 1][j + 1] == 'B') {
                int big;
                for (int k = 2;; k++) {
                    int tmp = 0;
                    if (i >= k && j >= k && sum[1][i][j] + sum[1][i - k][j - k] - sum[1][i - k][j] - sum[1][i][j - k] == k * k)
                        tmp++;
                    if (i >= k && j + k <= m && sum[2][i][j + 1] + sum[2][i - k][j + k + 1] - sum[2][i - k][j + 1] - sum[2][i][j + k + 1] == k * k)
                        tmp++;
                    if (i + k <= n && j >= k && sum[3][i + 1][j] + sum[3][i + k + 1][j - k] - sum[3][i + k + 1][j] - sum[3][i + 1][j - k] == k * k)
                        tmp++;
                    if (i + k <= n && j + k <= m && sum[4][i + 1][j + 1] + sum[4][i + k + 1][j + k + 1] - sum[4][i + k + 1][j + 1] - sum[4][i + 1][j + k + 1] == k * k)
                        tmp++;
                    if (tmp != 4) {
                        big = k - 1;
                        break;
                    }
                }
                //printf("--%d %d %d\n", i, j, big);
                s[i].insert({ big, j });
            }
    while (q--) {
        int r1, c1, r2, c2;
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        int ans = 0;
        for (int i = r1; i <= r2; i++)
            for (auto j = s[i].rbegin(); j != s[i].rend(); j++)
                if (ans < j->ff && ans < min(i - r1 + 1, r2 - i)) {
                    int minn = min(min(i - r1 + 1, r2 - i), min(j->ss - c1 + 1, c2 - j->ss));
                    minn = min(minn, j->ff);
                    ans = max(ans, minn);
                } else
                    break;
        printf("%d\n", 4 * ans * ans);
    }
}