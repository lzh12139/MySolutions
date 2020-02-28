/**
 * Author: hrynb
 * Time: 2020-02-24 22:39:26
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

int a[110], b[110];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i], b[i] = 0;
        for (int i = 1; i <= m; i++) {
            int x;
            cin >> x;
            b[x]++;
        }
        int gg = 0;
        for (int p = 1; p <= n; p++)
            for (int i = n - 1; i >= 1; i--)
                if (a[i] > a[i + 1])
                    if (b[i])
                        swap(a[i], a[i + 1]);
                    else {
                        gg++;
                        break;
                    }
        if (gg)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}