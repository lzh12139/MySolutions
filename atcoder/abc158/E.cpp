#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

char s[200010];
int a[200010], cnt[10010];
int main()
{
    int n, p;
    scanf("%d%d%s", &n, &p, s + 1);
    cnt[0]++;
    for (int i = n, cur = 1; i >= 1; i--) {
        a[i] = ((s[i] - '0') * cur % p + a[i + 1]) % p;
        cur = cur * 10 % p;
        cnt[a[i]]++;
    }
    ll ans = 0;
    if (p == 2 || p == 5) {
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= n; i++)
            if ((s[i] - '0') % p == 0)
                ans += i;
    } else
        for (int i = 1; i <= n; i++) {
            cnt[a[i]]--;
            ans += cnt[a[i]];
        }
    cout << ans << endl;

    /*for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = i; j <= n; j++) {
            tmp = (tmp * 10 % p + s[j] - '0') % p;
            if (!tmp)
                ans--;
        }
    }
    printf("%lld\n", ans);*/
}
