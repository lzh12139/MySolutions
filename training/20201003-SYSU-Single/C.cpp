#include <bits/stdc++.h>
using namespace std;

#define pdd pair<double, double>
#define ff first
#define ss second

double dist(pdd a, pdd b)
{
    return sqrt((a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss));
}

double solve(pdd p, pdd p0, pdd p1)
{
    // if (p1.ff - p0.ff == 0) {
    //     if ((p1.ss - p0.ss) * (p.ss - p0.ss) >= 0)
    //         return fabs(p.ff - p0.ff);
    //     return dist(p, p0);
    // } else if (p1.ss - p0.ss == 0) {
    //     if ((p1.ff - p0.ff) * (p.ff - p0.ff) >= 0)
    //         return fabs(p.ss - p0.ss);
    //     return dist(p, p0);
    // }

    double t = ((p.ff - p0.ff) * (p1.ff - p0.ff) + (p.ss - p0.ss) * (p1.ss - p0.ss)) / ((p1.ff - p0.ff) * (p1.ff - p0.ff) + (p1.ss - p0.ss) * (p1.ss - p0.ss));
    // cout << "t=" << setprecision(11) << t << endl;
    if (t >= 0) {
        pdd x;
        x.ff = p0.ff + (p1.ff - p0.ff) * t;
        x.ss = p0.ss + (p1.ss - p0.ss) * t;
        // cout << "**" << setprecision(11) << x.ff << " " << x.ss << endl;
        return dist(x, p);
    }
    return dist(p0, p);
}

int main()
{
    int t;
    // scanf("%d", &t);
    cin >> t;
    while (t--) {
        pdd p0, p1, p2;
        // scanf("%lf%lf%lf%lf%lf%lf", &p0.ff, &p0.ss, &p1.ff, &p1.ss, &p2.ff, &p2.ss);
        cin >> p0.ff >> p0.ss >> p1.ff >> p1.ss >> p2.ff >> p2.ss;
        int n;
        // scanf("%d", &n);
        cin >> n;
        while (n--) {
            pdd p;
            // scanf("%lf%lf", &p.ff, &p.ss);
            cin >> p.ff >> p.ss;
            cout << setiosflags(ios::fixed) << setprecision(10) << min(solve(p, p0, p1), solve(p, p0, p2)) << endl;
            // printf("%.6lf\n", min(solve(p, p0, p1), solve(p, p0, p2)));
        }
    }
}