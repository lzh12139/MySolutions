#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

int dp[1010][20010];
int sum[20010];
const int mod = 1e9 + 7;
int inline MOD(int a)
{
    return a < mod ? a : a - mod;
}
int main()
{
    dp[2][0] = dp[2][1] = 1;
    for (int i = 3; i <= 1000; i++) {
        sum[0] = dp[i - 1][0];
        dp[i][0] = dp[i - 1][0];
        for (int j = 1; j <= 20000; j++) {
            sum[j] = MOD(sum[j - 1] + dp[i - 1][j]);
            if (j - i >= 0)
                dp[i][j] = MOD(sum[j] - sum[j - i] + mod);
            else
                dp[i][j] = sum[j];
        }
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("%d\n", dp[n][k]);
    }
}