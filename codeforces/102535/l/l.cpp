/**
 * Author: hrynb
 * Time: 2020-02-29 22:38:27
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

const ll mod = 1e9;
string s[100010];
ll quick_mod(ll base, ll b)
{
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return res;
}
int main()
{
    IOS;
    string str = "MOOK";
    int n, k, cnt = 0;
    cin >> n >> k;
    ll ans = 0;
    V a;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    if (n == 2) {
        if (k & 1) {
            if (s[1] == str)
                ans += 2;
            if (s[2] == str)
                ans += 1;
        } else {
            if (s[1] == str)
                ans += 1;
            if (s[2] == str)
                ans += 2;
        }
        cout << ans << endl;
        return 0;
    }
    for (int i = n, j = 1; i >= 1; i--) {
        if (s[i] == str) {
            cnt++;
            if (j <= k)
                a.push_back(i - 1), j++;
            else
                ans = (ans + quick_mod(2, i - 1)) % mod;
        } else
            a.push_back(i - 1);
    }
    k = min(k, cnt);
    while (!a.empty() && k--) {
        ans = (ans + quick_mod(2, a.back())) % mod;
        a.pop_back();
    }
    cout << ans << endl;
}