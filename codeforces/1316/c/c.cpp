/**
 * Author: hrynb
 * Time: 2020-03-04 22:46:46
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

int n, m, p;
int a[1000010], b[1000010], s[2000010];
ll get(int x)
{
    if (x < 0 || x > n + m - 2)
        return 0;
    ll tmp = 0;
    for (int i = max(0, x - m); i < min(n, x + 1); i++) {
        tmp += 1ll * a[i] * b[x - i] % p;
    }
    return tmp % p;
}
int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]), a[i] %= p;
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]), b[i] %= p;
    int N = n + m - 2;
    mt19937 mt(114514);
    for (int i = 0; i <= min(1000, N); i++)
        if (get(i)) {
            printf("%d\n", i);
            return 0;
        }
    for (int i = N; i >= max(0, N - 1000); i--)
        if (get(i)) {
            printf("%d\n", i);
            return 0;
        }
    for (int i = max(0, N / 2 - 10); i <= min(N, N / 2 + 10); i++)
        if (get(i)) {
            printf("%d\n", i);
            return 0;
        }
    for (int i = 0; i <= N; i += max(1, (N / 20)))
        if (get(i)) {
            printf("%d\n", i);
            return 0;
        }
    printf("%d\n", 5 / 0);
}