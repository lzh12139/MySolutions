/**
 * Author: hrynb
 * Time: 2020-02-29 16:00:09
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

int a[100010];
int main()
{
    int n, m, ans = 0;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x + 1]++, mp[x - 1]++;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + m);
    for (int i = 1; i <= m; i++)
        if (mp[a[i]])
            ans++;
    cout << ans << endl;
}