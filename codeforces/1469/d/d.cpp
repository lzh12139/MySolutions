/**
 * Author: hrynb
 * Time: 2020-12-28 23:33:17
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
    // IOS;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> sq(1, n);
        int tmp = n, f = -1;
        while (tmp > 1)
            sq.push_back(tmp = sqrt(tmp));
        // reverse(sq.begin(), sq.end());

        for (int pp = 0; pp < sq.size(); pp++) {
            int ans = pp * (1 + pp) / 2 + n - 3;
            tmp = sq[pp];
            while (tmp > 1)
                tmp = ceil(1.0 * tmp / 2), ans++;

            if (ans > n + 5)
                continue;

            f = pp;

            vector<pii> ansn;
            map<int, int> mp;
            for (int i = 0; i <= f; i++)
                mp[sq[i]] = 1;

            for (int i = 3; i <= n; i++)
                if (!mp[i])
                    ansn.push_back({ i, n });

            vector<int> val;
            for (int i = 0; i <= f; i++) {
                int ans = sq[i];
                for (int j = i + 1; j <= f; j++)
                    ansn.push_back({ sq[i], sq[j] }), ans = ceil(1.0 * ans / sq[j]);
                val.push_back(ans);
            }
            val.push_back(sq[f]);

            int maxn = 0;
            for (int i = 1; i <= f; i++)
                if (val[i] > val[maxn])
                    maxn = i;
            for (int i = 0; i <= f; i++)
                if (i != maxn)
                    ansn.push_back({ sq[i], sq[maxn] });
            // cout << val[maxn] << "val \n";
            for (int i = val[maxn]; i > 1; i = ceil(1.0 * i / 2))
                ansn.push_back({ sq[maxn], 2 });

            if (ansn.size() <= n + 5) {
                cout << ansn.size() << "\n";
                for (auto i : ansn)
                    cout << i.first << " " << i.second << "\n";
            }

            break;
        }
    }
}