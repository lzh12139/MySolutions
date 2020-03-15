#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);
double cal(int r, double afa)
{
    return 1.0 * r / 2.0 * r * afa;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d%d", &a, &b);
        double ans = 1.0 * a / 2.0 * (a + b);
        double afa = atan2(a + b, a);
        ans -= cal(a, pi / 2.0) + cal(b, pi / 2.0 - afa);
        ans += cal(a, pi - 2.0 * afa) - 1.0 * a / 2.0 * a * sin(pi - 2.0 * afa);
        printf("%.10lf\n", abs(ans));
    }
}