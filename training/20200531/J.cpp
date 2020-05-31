#include <bits/stdc++.h>
 
using namespace std;
const int mod = 1e9 + 7;
long long dp[100004][2][2];//0 1 wa ac
pair<int, int> p[100004];
int wa[100004];
 
void dfs(int u) {
    if (u == 0)return;
    int l = p[u].first;
    int r = p[u].second;
    dfs(l);
    dfs(r);
    dp[u][0][0] = dp[l][0][1] * dp[r][0][1] % mod
                  + dp[l][0][1] * dp[r][1][1] % mod
                  + dp[l][1][1] * dp[r][0][1] % mod;
    dp[u][0][1] = dp[l][0][0] * dp[r][0][0] % mod
                  + dp[l][0][0] * dp[r][1][1] % mod
                  + dp[l][1][1] * dp[r][0][0] % mod;
    dp[u][0][1] %= mod;
    dp[u][0][0] %= mod;
    long long lone = (dp[l][0][1] + dp[l][1][1]) % mod;
    long long lzero = (dp[l][0][0] + dp[l][1][0]) % mod;
    long long rone = (dp[r][0][1] + dp[r][1][1]) % mod;
    long long rzero = (dp[r][0][0] + dp[r][1][0]) % mod;
    long long one = lone * rzero % mod + lzero * rone % mod + lzero * rzero % mod;
    one %= mod;
    long long zero = lone * rone % mod;
    dp[u][1][0] = (zero - dp[u][0][0] + mod) % mod;
    dp[u][1][1] = (one - dp[u][0][1] + mod) % mod;
    if (wa[u] == 1) {
        dp[u][0][1] += dp[u][1][0];
        dp[u][1][1] += dp[u][0][0];
        dp[u][1][0] = dp[u][0][0] = 0;
        dp[u][0][1] %= mod;
        dp[u][1][1] %= mod;
    } else if (wa[u] == 0) {
        dp[u][0][0] += dp[u][1][1];
        dp[u][1][0] += dp[u][0][1];
        dp[u][1][1] = dp[u][0][1] = 0;
        dp[u][0][0] %= mod;
        dp[u][1][0] %= mod;
    }
}
 
int main() {
    int n;
    int x, y, f;
    scanf("%d", &n);
    dp[0][0][0] = dp[0][0][1] = 0;
    dp[0][1][0] = dp[0][1][1] = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d", &x, &y, &f);
        p[i].first = x;
        p[i].second = y;
        wa[i] = f;
    }
    dfs(1);
    cout << (dp[1][0][0] + dp[1][0][1]) % mod << endl;
}