#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

const int N = 50010;
int a[N];
ll dp[N];
int minn[N], maxx[N];
ll solve(int n)
{
    for (int i = 1; i <= n; i++)
        dp[i] = minn[i] = maxx[i] = 0;
    for (int i = 1; i <= n; i++)
        if (dp[i - 1] > 0) {
            dp[i] = dp[i - 1] + a[i];
            minn[i] = min(0, min(a[i], minn[i - 1]));
        } else {
            dp[i] = a[i];
            minn[i] = min(0, a[i]);
        }
    for (int i = n; i >= 1; i--)
        maxx[i] = max(maxx[i + 1], a[i]);

    //for (int i = 1; i <= n; i++)
    //    printf("%d %d %d\n", dp[i], minn[i], maxx[i]);

    ll ans = max(0ll, dp[n]);
    for (int i = 1; i < n; i++)
        ans = max(ans, dp[i] + max(0, maxx[i + 1] - minn[i]));
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    ll ans = solve(n);
    reverse(a + 1, a + 1 + n);
    ans = max(ans, solve(n));
    printf("%d\n", ans);
}