/**
 * Author: hrynb
 * Time: 2020-12-30 22:36:09
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

int a[5010];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        set<int> s;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                s.insert(a[j] - a[i]);
        cout << s.size() << "\n";
    }
}