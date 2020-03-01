/**
 * Author: hrynb
 * Time: 2020-03-01 00:09:25
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

ll sum[200010];
string s[200010];
int main()
{
    int cnt = 0;
    for (ll add1 = 2, add2 = 6;;) {
        sum[++cnt] = sum[cnt - 1] + add1;
        sum[++cnt] = sum[cnt - 1] + add1;
        add1 += add2, add2 += 4;

        if (sum[cnt] > 1e15)
            break;
    }
    s[1] = "s", s[2] = "p", s[3] = "d", s[4] = "f";
    s[5] = "g", s[6] = "h", s[7] = "i", s[8] = "j";
    s[9] = "k", s[10] = "l", s[11] = "m", s[12] = "n";
    s[13] = "o", s[14] = "q", s[15] = "r", s[16] = "t";
    s[17] = "u", s[18] = "v", s[19] = "w", s[20] = "x";
    s[21] = "y", s[22] = "z";
    for (int i = 23; i <= 200000; i++) {
        s[i] = s[i - 1];
        for (int j = s[i].length() - 1, add = 1; j >= 0; j--)
            if (s[i][j] == 'z' && add) {
                if (j)
                    s[i][j] = 'a';
                else {
                    int len = s[i].length();
                    s[i] = "";
                    for (int k = 1; k <= len + 1; k++)
                        s[i] += 'a';
                }
            } else {
                s[i][j]++;
                break;
            }
    }
    /*for (int i = 1; i <= 10000; i++)
        cout << s[i] << endl;*/

    int t = 0;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        int x = lower_bound(sum + 1, sum + 1 + cnt, n) - sum - 1;
        n -= sum[x];
        //cout << x << " " << n << endl;

        int a = x + 1 - x / 2, b = (x + 2) / 2;
        int l = 1, r = b, ansn = b;
        while (l <= r) {
            int mid = l + r >> 1;
            if (2ll * (1ll * b * b - 1ll * mid * mid) < n)
                ansn = min(mid, ansn), r = mid - 1;
            else
                l = mid + 1;
        }
        n -= 2ll * (1ll * b * b - 1ll * ansn * ansn);
        a += b - ansn, b -= b - ansn;
        cout << a << s[b] << n << endl;
    }
}