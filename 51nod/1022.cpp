#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

int dp[2010][2010], w[2010][2010];
int sum[2010];
const int inf = 0x3f3f3f3f;
int main()
{
    memset(w, 0x3f, sizeof w);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &sum[i]);
        sum[i + n] = sum[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        sum[i + 1] += sum[i];
        dp[i][i + 1] = sum[i + 1] - sum[i - 1];
        w[i][i + 1] = i;
    }
    for (int i = 3; i <= n; i++) {
        for (int l = 1, r = i; l <= n; l++, r++) {
            int kl = w[l][r - 1], kr = w[l + 1][r];
            int k = inf, tmp = inf;
            for (int j = kl; j <= kr; j++)
                if (dp[l][j] + dp[j + 1][r] < tmp) {
                    tmp = dp[l][j] + dp[j + 1][r];
                    k = j;
                }
            dp[l][r] = tmp + sum[r] - sum[l - 1];
            w[l][r] = k;
        }
        for (int l = n + 1, r = n + i; r <= 2 * n; l++, r++) {
            dp[l][r] = dp[l - n][r - n];
            w[l][r] = w[l - n][r - n] + n;
        }
    }
    int ans = inf;
    for (int l = 1, r = n; r <= 2 * n; l++, r++)
        ans = min(ans, dp[l][r]);
    printf("%d\n", ans);
}