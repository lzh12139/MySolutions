#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

struct point {
    int x, y, b;
} p[1010];
pair<ll, ll> a[1010];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].b);
    sort(p + 1, p + 1 + n, [](point a, point c) {
        if (a.b != c.b)
            return a.b > c.b;
        return a.x < c.x;
    });
    int tmp1 = 0, tmp2 = 0;
    for (int i = 2; i <= n; i++) {
        if (p[i - 1].x <= p[i].x)
            tmp1++;
        if (p[i - 1].x >= p[i].x)
            tmp2++;
    }
    if (tmp1 == n - 1 || tmp2 == n - 1) {
        printf("Y");
        return 0;
    }
    sort(p + 1, p + 1 + n, [](point a, point c) {
        if (a.b != c.b)
            return a.b > c.b;
        return a.y < c.y;
    });
    tmp1 = 0, tmp2 = 0;
    for (int i = 2; i <= n; i++) {
        if (p[i - 1].y <= p[i].y)
            tmp1++;
        if (p[i - 1].y >= p[i].y)
            tmp2++;
    }
    if (tmp1 == n - 1 || tmp2 == n - 1) {
        printf("Y");
        return 0;
    }

    int cnt = 0;
    vector<pii> v[1010];
    v[++cnt].push_back({ p[1].x, p[1].y });
    for (int i = 2; i <= n; i++) {
        if (p[i - 1].b != p[i].b)
            cnt++;
        v[cnt].push_back({ p[i].x, p[i].y });
    }

    for (int j = 1; j <= n; j++)
        for (int k = j + 1; k <= n; k++) {
            if (p[j].x - p[k].x == 0)
                continue;
            ll deltay = p[j].y - p[k].y, deltax = p[j].x - p[k].x, add = 0, gg = 0;
            for (int i = 1; i <= cnt; i++) {
                a[i] = { 1e18, -1e18 };
                for (auto o : v[i]) {
                    ll tmp = deltay * o.ff - deltax * o.ss;
                    a[i].ff = min(a[i].ff, tmp), a[i].ss = max(a[i].ss, tmp);
                }
                if (i != 1) {
                    if (a[i].ff >= a[i - 1].ss && add != -1)
                        add = 1;
                    else if (a[i].ss <= a[i - 1].ff && add != 1)
                        add = -1;
                    else {
                        gg++;
                        break;
                    }
                }
            }
            if (!gg) {
                printf("Y");
                return 0;
            }
        }
    printf("N");
}