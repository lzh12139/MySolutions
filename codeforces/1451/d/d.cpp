/**
 * Author: lzh12139
 * Time: 2020-11-21 23:16:13
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
        ll d, k;
        cin >> d >> k;
        ll tmp1 = 1.0 * d * d / k / k;
        ll tmp2 = 1.0 * tmp1 / 2.0;

        ll ans1 = sqrt(tmp2);
        if (ans1 * ans1 + (ans1 + 1) * (ans1 + 1) <= tmp1)
            cout << "Ashish\n";
        else
            cout << "Utkarsh\n";
    }
}