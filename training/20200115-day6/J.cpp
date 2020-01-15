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
    double sum = 0, cur = 0, curx = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        double x, y, z;
        scanf("%lf%lf%lf", &x, &y, &z);
        sum += x;
        if (z <= pi) {
            p[2 * i - 1] = mp(z, y);
            p[2 * i] = mp(z + pi, -y);
            cur += x - z * y;
            curx -= y;
        } else {
            p[2 * i - 1] = mp(2 * pi - z, y);
            p[2 * i] = mp(z, -y);
            cur -= x - (2 * pi - z) * y;
            curx += y;
        }
    }
    sort(p + 1, p + 1 + 2 * n);
    p[2 * n + 1] = p[1];
    double ans = cur;
    for (int i = 1; i <= 2 * n; i++) {
        while (p[i].ff == p[i + 1].ff) {
            curx += 2 * p[i].ss;
            cur -= 2 * p[i].ff * p[i].ss;
            i++;
        }
        double tmp = max(curx * p[i].ff, curx * p[i + 1].ff) + cur;
        ans = max(ans, tmp);
        curx += 2 * p[i].ss;
        cur -= 2 * p[i].ff * p[i].ss;
    }
    printf("%.6lf\n", ans + sum);
}