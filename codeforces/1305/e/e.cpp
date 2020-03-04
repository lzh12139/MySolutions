/**
 * Author: hrynb
 * Time: 2020-03-04 17:24:52
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

vector<int> ans;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        if (m >= (i - 1) / 2)
            m -= (i - 1) / 2, ans.push_back(i);
        else {
            map<int, int> mp;
            for (int j = 1; j < i; j++)
                for (int p = j + 1; p < i; p++)
                    mp[j + p]++;
            for (auto j : mp)
                if (m == j.ss && j.ff >= i) {
                    ans.push_back(j.ff);
                    break;
                }
            m = 0;
            break;
        }
    int tmp = 1e9;
    while (ans.size() < n)
        ans.pb(tmp), tmp -= 1e5;
    sort(ans.begin(), ans.end());
    if (ans.size() > n || m)
        cout << -1 << endl;
    else {
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }
}