/**
 * Author: hrynb
 * Time: 2020-02-29 15:57:55
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
    int n, m;
    cin >> n >> m;
    if (n == m - 1 || n == m + 1)
        cout << "GOOD LUCK AGENT P\n";
    else
        cout << "CURSE YOU\n";
}