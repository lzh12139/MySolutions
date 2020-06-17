#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> pdd;
#define ff first
#define ss second
const double pi = acos(-1.0);
double solve(double a, double b, double h, double c)
{
    double beta = 0;
    pdd x, y;
    if (a <= h) {
        x.ff = 0;
        x.ss = a;
    } else {
        x.ff = sqrt(a * a - h * h);
        x.ss = h;
        beta = acos(1.0 * h / (a));
    }
    double afa = acos(1.0 * (a * a + b * b - c * c) / (2 * a * b));
    if (afa > pi/2 || pi / 2 - beta - afa < 0)
        return 1e9;
    afa = pi / 2 - beta - afa;
    y.ff = cos(afa) * b;
    y.ss = sin(afa) * b;
    double ans = max(y.ff, x.ff);
    //printf("%lf ", ans);
    if (y.ss - h > 0 || y.ff < 0 || y.ss < 0)
        return 1e9;
    return ans;
}
double pend(double a, double b, double c, double w)
{
    double afa = (a * a + c * c - b * b) / (2.0 * a * c);
    double len = max(0.0, afa * a) + max(0.0, (b * b + c * c - a * a) / (2 * b * c) * b);
    afa = sqrt(1.0 - afa * afa);
    double h = a * afa;
    double ans = min(h, len), ped = max(h, len);
    //printf("%lf %lf\n", ans, ped);
    if (ans > w)
        return 1e9;
    else if (ped > w)
        return ped;
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int x1, x2, x3, y1, y2, y3, w;
        scanf("%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &w);
        double a[10];
        a[1] = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        a[2] = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
        a[3] = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
        //printf("%lf %lf %lf\n", a[1], a[2], a[3]);

        double ans = 1e9;
        sort(a + 1, a + 1 + 3);
        do {
            ans = min(ans, solve(a[1], a[2], w, a[3]));
            ans = min(ans, pend(a[1], a[2], a[3], w));
        } while (next_permutation(a + 1, a + 1 + 3));
        if (ans == 1e9)
            printf("impossible\n");
        else
            printf("%.9lf\n", ans);
    }
}