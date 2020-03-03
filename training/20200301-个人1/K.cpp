#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

int a[200010], n, m;
int check(int x)
{
    int cur = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] <= cur)
            cur++;
        else if (x)
            x--, cur++;
    if (cur >= m)
        return 1;
    return 0;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 0, r = m, ans = m;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid - 1, ans = min(ans, mid);
        else
            l = mid + 1;
    }
    cout << ans;
}