/**
 * Author: hrynb
 * Time: 2020-03-04 22:59:55
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

int a[1010];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m, sum = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i], sum += a[i];
        cout << min(sum, m) << endl;
    }
}