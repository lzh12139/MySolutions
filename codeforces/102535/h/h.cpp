/**
 * Author: hrynb
 * Time: 2020-02-29 16:29:25
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

const string a = "BEEP", b = "BOOP";
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, gg = 0;
        cin >> n;
        while (n--) {
            string s;
            cin >> s;
            if (s != a && s != b)
                gg++;
        }
        cout << (gg ? "IT'S NOT A BOP!" : "IT'S A BOP!") << "\n";
    }
}