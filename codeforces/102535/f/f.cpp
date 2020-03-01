/**
 * Author: hrynb
 * Time: 2020-02-29 16:20:32
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

char s[510][510];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int r, c, ans = 0;
        cin >> r >> c;
        r--;
        for (int i = 1; i <= r; i++)
            cin >> s[i] + 1;
        for (int j = 1; j <= c; j++)
            for (int i = r; i >= 1; i--)
                if (s[i][j] == '#')
                    break;
                else if (s[i][j] == 'X')
                    ans++;
        cout << ans << endl;
    }
}