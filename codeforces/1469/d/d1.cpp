/**
 * Author: hrynb
 * Time: 2020-12-30 21:57:15
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

int main()
{
    // IOS;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pii> ans, ans1;
        ll now = 2;
        while (now < n) {
            ll nxt = min(now * now, (ll)n);
            for (int i = now + 1; i < nxt; i++)
                ans.emplace_back((pii) { i, n });
            ans1.emplace_back((pii) { nxt, now });
            ans1.emplace_back((pii) { nxt, now });
            now = nxt;
        }
        reverse(ans1.begin(), ans1.end());

        cout << ans.size() + ans1.size() << "\n";
        for (auto i : ans)
            cout << i.first << " " << i.second << "\n";
        for (auto i : ans1)
            cout << i.first << " " << i.second << "\n";
    }
}