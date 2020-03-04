/**
 * Author: hrynb
 * Time: 2020-03-04 19:32:30
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

ll a[200010];
const int N = 1e6 + 10;
ll prime[N + 10];
void init()
{
    for (int i = 2; i <= N; i++) {
        if (!prime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] <= N / i; j++) {
            prime[i * prime[j]]++;
            if (i % prime[j] == 0)
                break;
        }
    }
}
set<ll> s;
void put(ll x)
{
    if (x <= 1)
        return;
    for (int i = 1; i <= prime[0] && prime[i] * prime[i] <= x; i++)
        if (x % prime[i] == 0) {
            s.insert(prime[i]);
            while (x % prime[i] == 0)
                x /= prime[i];
        }
    if (x > 1)
        s.insert(x);
}
int main()
{
    init();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    mt19937_64 r(114514);
    shuffle(a + 1, a + 1 + n, r);
    for (int i = 1; i <= min(n, 100); i++) {
        put(a[i] - 1);
        put(a[i]);
        put(a[i] + 1);
    }
    ll ans = n;
    for (auto i : s) {
        ll tmp = 0;
        for (int j = 1; j <= n; j++)
            if (a[j] <= i)
                tmp += i - a[j];
            else
                tmp += min(a[j] % i, i - a[j] % i);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}