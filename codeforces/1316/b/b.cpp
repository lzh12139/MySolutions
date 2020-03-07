/**
 * Author: hrynb
 * Time: 2020-03-04 23:04:42
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

pair<string, int> p[5010];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        string str;
        cin >> n >> str;
        for (int i = 1; i < n; i++) {
            string tmp = str.substr(0, i), tmp1 = str.substr(i, n - 1);
            if ((n - i) % 2)
                reverse(tmp.begin(), tmp.end());
            p[i].ff = tmp1 + tmp, p[i].ss = i + 1;
            //cout << tmp1 << " " << tmp << endl;
        }
        p[n] = { str, 1 };
        sort(p + 1, p + 1 + n);
        cout << p[1].ff << "\n"
             << p[1].ss << "\n";
    }
}