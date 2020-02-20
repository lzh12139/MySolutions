#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

char s[1000010];
int dp[1000010][3];
int main()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1), ans = 0;
    for (int i = 1; i <= n; i++) {
        int c = s[i] - '0';
        dp[i][0] = min(dp[i - 1][0] + c, dp[i - 1][1] + c + 1);
        dp[i][1] = min(dp[i - 1][0] + 10 - c, dp[i - 1][1] + 10 - (c + 1));
    }
    printf("%d\n", min(dp[n][0], dp[n][1]));
}
