#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> pii;
typedef long long ll;
#define ff first
#define ss second
#define mp make_pair

const double pi = acos(-1.0);
pii p[200010];
int main()
{
    double cur = 0, curx = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        double x, y, z;
        scanf("%lf%lf%lf", &x, &y, &z);
        double l = z - min(pi, x / y), r = z + min(pi, x / y);
        //printf("------ %lf %lf\n", l, r);
        if (l < 0) {
            curx += y;
            cur += x - y * z;
            l += 2 * pi;
        }
        if (r > 2 * pi) {
            curx -= y;
            cur += x - y * (2 * pi - z);
            r -= 2 * pi;
        }
        p[3 * i - 2] = mp(l, y);
        p[3 * i - 1] = mp(z, -2 * y);
        p[3 * i] = mp(r, y);
    }
    sort(p + 1, p + 1 + 3 * n);

    p[0] = mp(0, 0);
    p[3 * n + 1] = mp(2 * pi, 0);
    double ans = cur;
    for (int i = 0; i <= 3 * n; i++) {
        while (p[i].ff == p[i + 1].ff) {
            curx += p[i + 1].ss;
            cur -= p[i + 1].ff * p[i + 1].ss;
            i++;
        }
        double tmp = max(curx * p[i].ff, curx * p[i + 1].ff) + cur;
        ans = max(ans, tmp);
        curx += p[i + 1].ss;
        cur -= p[i + 1].ff * p[i + 1].ss;
    }
    printf("%.10lf\n", ans);
}