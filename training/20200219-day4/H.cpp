#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

int h[100010];
ll tmp[100010], minn[100010], maxx[100010];
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i <= n; i++)
        scanf("%d", &h[i]);
    while (q--) {
        double g, ans = -1;
        scanf("%lf", &g);
        int G = round(g * 10);
        for (int i = 0; i <= n; i++)
            tmp[i] = h[i] - G * i;
        minn[0] = tmp[0], maxx[n] = tmp[n];
        for (int i = 1; i <= n; i++)
            minn[i] = min(minn[i - 1], tmp[i]);
        for (int i = n - 1; i >= 0; i--)
            maxx[i] = max(maxx[i + 1], tmp[i]);

        for (int i = 0; i <= n; i++) {
            int l = i + 1, r = n, ansn = -1;
            while (l <= r) {
                int mid = l + r >> 1;
                if (maxx[mid] >= tmp[i])
                    l = mid + 1, ansn = max(ansn, mid);
                else
                    r = mid - 1;
            }
            if (ansn != -1) {
                if (ansn == n)
                    ans = max(ans, (double)(n - i));
                else
                    //printf("//%d %lld %lld %lld\n", ansn, tmp[i], tmp[ansn], tmp[ansn + 1]),
                    ans = max(ans, 1.0 * (tmp[i] - tmp[ansn]) / (tmp[ansn + 1] - tmp[ansn]) + ansn - i);
            }
        }
        for (int i = n; i >= 0; i--) {
            int l = 0, r = i - 1, ansn = 1e9;
            while (l <= r) {
                int mid = l + r >> 1;
                if (minn[mid] <= tmp[i])
                    r = mid - 1, ansn = min(ansn, mid);
                else
                    l = mid + 1;
            }
            if (ansn != 1e9) {
                if (ansn == 0)
                    ans = max(ans, (double)i);
                else
                    //printf("??%d %lld %lld %lld\n", ansn, tmp[i], tmp[ansn], tmp[ansn - 1]),
                    ans = max(ans, 1.0 * (tmp[i] - tmp[ansn]) / (tmp[ansn - 1] - tmp[ansn]) + i - ansn);
            }
        }

        if (ans == -1)
            printf("-1\n");
        else
            printf("%.10lf\n", ans);
    }
}