/**
 * Author: lzh12139
 * Time: 2020-01-29 23:16:56
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("Yes\n")
#define _no printf("No\n")
#define _YES printf("YES\n");
#define _NO printf("NO\n");

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

ll fac[30], num[30];
int main()
{
    int t;
    cin >> t;
    //for (int I = 1; I <= 100; I++)
    //    for (int J = 1; J <= 100; J++)
    while (t--) {
        ll a, n, ans = 0, N;
        //a = I, n = J;
        cin >> a >> n;
        N = n;
        ll g = __gcd(a, n);
        n /= g;
        int cnt = 0;
        for (ll i = 2; i * i <= n; i++)
            if (n % i == 0) {
                fac[++cnt] = i;
                num[cnt] = 0;
                while (n % i == 0)
                    n /= i, num[cnt]++;
            }
        if (n > 1)
            fac[++cnt] = n, num[cnt] = 1;
        n = N;
        for (int i = 0; i < (1 << cnt); i++) {
            int cur = i, j = 1, CNT = 0;
            ll mul = g;
            while (cur) {
                if (cur & 1)
                    mul *= fac[j], CNT++;
                j++, cur >>= 1;
            }
            //printf("%lld %d %lld %lld\n", mul, CNT, (a + n - 1) / mul, (a - 1) / mul);
            if (CNT & 1)
                ans -= (a + n - 1) / mul - (a - 1) / mul;
            else
                ans += (a + n - 1) / mul - (a - 1) / mul;
        }
        printf("%lld\n", ans);

        /*int ANS = 0;
            for (ll i = a; i < a + n; i++)
                if (__gcd(i, n) == g)
                    ANS++;
            if (ANS != ans)
                printf("%d %d %d %d\n", I, J, ans, ANS);*/
    }
}