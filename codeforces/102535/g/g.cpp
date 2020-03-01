/**
 * Author: hrynb
 * Time: 2020-02-29 16:25:09
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
        ll n;
        cin >> n;
        if (n % 3 == 0)
            cout << "AGENT 003\n";
        if (n % 5 == 0)
            cout << "AGENT 005\n";
        if (n % 7 == 0)
            cout << "AGENT 007\n";
        if (n % 3 && n % 5 && n % 7)
            cout << "NONE\n";
        cout << "---\n";
    }
}