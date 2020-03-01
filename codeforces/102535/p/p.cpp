/**
 * Author: hrynb
 * Time: 2020-02-29 23:14:26
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
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        if (__gcd(a, b - 1) == 1)
            cout << "COOL\n";
        else
            cout << "NOT COOL\n";
    }
}