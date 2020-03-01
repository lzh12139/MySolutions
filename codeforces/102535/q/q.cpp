/**
 * Author: hrynb
 * Time: 2020-03-01 11:38:43
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

const int N = 1e6;
int a[N + 10], b[N + 10];
ll dp[N + 10];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        b[x - 1]++;
    }
    for (int i = N; i >= 1; i--) {
        int cnta = 0, cntb = 0;
        for (int j = i; j <= N; j += i) {
            cnta += a[j], cntb += b[j];
            dp[i] -= dp[j];
        }
        dp[i] += 1ll * cnta * cntb;
    }
    cout << dp[1];
}