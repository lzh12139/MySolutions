/**
 * Author: hrynb
 * Time: 2020-01-22 22:46:44
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("YES\n")
#define _no printf("NO\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, N;
        cin >> n;
        N = n;
        vector<int> ans;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) {
                while (n % i == 0)
                    n /= i, ans.pb(i);
            }
        if (n > 1)
            ans.pb(n);
        int ok = 0;
        for (int i = 0; i < ans.size(); i++) {
            for (int j = i + 1; j < ans.size() - 1; j++) {
                int tmp1 = 1, tmp2 = 1, tmp3 = 1;
                for (int o = 0; o <= i; o++)
                    tmp1 *= ans[o];
                for (int o = i + 1; o <= j; o++)
                    tmp2 *= ans[o];
                for (int o = j + 1; o < ans.size(); o++)
                    tmp3 *= ans[o];
                if (tmp1 != tmp2 && tmp1 != tmp3 && tmp2 != tmp3
                    && tmp1 > 1 && tmp2 > 1 && tmp3 > 1) {
                    _yes;
                    cout << tmp1 << " " << tmp2 << " " << tmp3 << endl;
                    ok = 1;
                    break;
                }
            }
            if (ok)
                break;
        }
        if (!ok)
            _no;
    }
}