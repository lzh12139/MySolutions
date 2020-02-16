/**
 * Author: hrynb
 * Time: 2020-02-13 22:52:50
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
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int l = 1e9 + 10, r = 0, ans1 = 0, ans2 = 0;
        for (int i = 1; i < n; i++)
            if (a[i] == -1) {
                if (a[i + 1] != -1)
                    l = min(l, a[i + 1]), r = max(r, a[i + 1]);
            } else {
                if (a[i + 1] == -1)
                    l = min(l, a[i]), r = max(r, a[i]);
                else 
                    ans1 = max(ans1, abs(a[i] - a[i + 1]));
            }
        if (l == 1e9 + 10)
            l = 0;
        int tmp = r - l;
        tmp = tmp + 1 >> 1;
        ans1 = max(tmp, ans1), ans2 = l + tmp;
        cout << ans1 << " " << ans2 << "\n";
    }
}