/**
 * Author: lzh12139
 * Time: 2020-02-02 22:26:40
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("Yes\n")
#define _no printf("No\n")
#define _YES printf("YES\n");
#define _NO printf("NO\n");

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

const int N = 3e5 + 10;
const int inf = 1e9 + 5;
int a[N], b[N], c[N];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        b[0] = -1;
        c[n + 1] = -1;
        for (int i = 1; i <= n; i++)
            if (a[i] >= b[i - 1] + 1)
                b[i] = b[i - 1] + 1;
            else
                b[i] = inf;
        for (int i = n; i >= 1; i--)
            if (a[i] >= c[i + 1] + 1)
                c[i] = c[i + 1] + 1;
            else
                c[i] = inf;
        int ok = 0;
        for (int i = 1; i <= n; i++)
            if (b[i - 1] != inf && c[i + 1] != inf 
            && b[i] != inf && c[i] != inf 
            && (b[i] > c[i + 1] || c[i] > b[i - 1])) {
                ok = 1;
                break;
            }
        if (ok)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}