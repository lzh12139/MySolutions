/**
 * Author: hrynb
 * Time: 2020-03-03 22:36:53
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

int a[110], b[210];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << "\n";
        for (int i = 1; i <= n; i++)
            cout << b[i] << " ";
        cout << "\n";
    }
}