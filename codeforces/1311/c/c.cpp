/**
 * Author: hrynb
 * Time: 2020-02-24 22:47:32
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

char s[200010];
int sum[2000010][30];
ll ans[30];
int main()
{
    freopen("hack.txt", "r", stdin);
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m >> s + 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 26; j++)
                sum[i][j] = sum[i - 1][j];
            sum[i][s[i] - 'a' + 1]++;
        }
        for (int i = 1; i <= 26; i++)
            ans[i] = sum[n][i];
        for (int i = 1; i <= m; i++) {
            int x;
            cin >> x;
            for (int j = 1; j <= 26; j++)
                ans[j] += sum[x][j];
        }
        for (int i = 1; i <= 26; i++)
            cout << ans[i] << " \n"[i == 26];
    }
}