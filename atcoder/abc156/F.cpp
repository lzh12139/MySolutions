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

int a[5010], tmp[5010];
int main()
{
    IOS;
    int k, q;
    cin >> k >> q;
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    while (q--) {
        int ans = 0, n, x, m;
        cin >> n >> x >> m;
        n--;
        if (n <= k) {
            int last = x % m;
            for (int i = 1; i <= n; i++) {
                int cur = (last + a[i]) % m;
                if (last < cur)
                    ans++;
                last = cur;
            }
            cout << ans << "\n";
            continue;
        }
        int sum = 0;
        for (int i = 1; i <= k; i++)
            tmp[i] = tmp[i] % m, sum = (sum + tmp[i]) % m;

        int last = x % m,cur;
        int loop = n / k, loopless = n % k;
        for (int i = 1; i <= k; i++) {
            int add = loop;
            if (i <= loopless)
                add++;
            
        }

        cout << ans << "\n";
    }
}