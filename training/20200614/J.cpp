#include <bits/stdc++.h>
using namespace std;

int st[20][100010], sum[100010], val[100010];
int dp[100010];

int query(int l, int r)
{
    int t = log2(r - l + 1);
    return max(st[t][l], st[t][r - (1 << t) + 1]);
}
void init(int n)
{
    for (int i = 1, t = 1; t <= n; i++, t <<= 1)
        for (int j = 1; j <= t + n; j++)
            st[i][j] = max(st[i - 1][j], st[i - 1][j + t]);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> st[0][i], sum[i] = 0;
        init(n);

        int preans = 0, pre = 0;
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1], val[i] = val[i - 1];
            if (st[0][i] > pre) {
                preans++, pre = st[0][i];
                sum[i]++, val[i] = st[0][i];
            }
        }
        for (int i = n; i >= 1; i--) {
            int l = i + 1, r = n, ans = 1e9;
            while (l <= r) {
                int mid = l + r >> 1;
                if (query(i + 1, mid) > st[0][i])
                    r = mid - 1, ans = min(ans, mid);
                else
                    l = mid + 1;
            }
            dp[i] = (ans == 1e9 ? 0 : dp[ans]) + 1;
        }

        while (m--) {
            int p, q;
            cin >> p >> q;
            if (q <= val[p - 1]) {
                int l = p + 1, r = n, ans = 1e9;
                while (l <= r) {
                    int mid = l + r >> 1;
                    if (query(p + 1, mid) > val[p - 1])
                        r = mid - 1, ans = min(ans, mid);
                    else
                        l = mid + 1;
                }
                cout << (sum[p - 1] + (ans == 1e9 ? 0 : dp[ans])) << "\n";
                continue;
            }
            int l = p + 1, r = n, ans = 1e9;
            while (l <= r) {
                int mid = l + r >> 1;
                if (query(p + 1, mid) > q)
                    r = mid - 1, ans = min(ans, mid);
                else
                    l = mid + 1;
            }
            cout << (sum[p - 1] + 1 + (ans == 1e9 ? 0 : dp[ans])) << "\n";
        }
    }
}