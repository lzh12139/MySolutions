#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
struct point {
    int x, y;
    point(int _x = 0, int _y = 0)
    {
        x = _x;
        y = _y;
    }
    bool operator<(const point& b) const
    {
        return x != b.x ? x < b.x : y < b.y;
    }
};
point a[N + 10], bx[N + 10], by[N + 10];
double dist(point a, point b)
{
    return sqrt(1ll * (a.x - b.x) * (a.x - b.x) + 1ll * (a.y - b.y) * (a.y - b.y));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &a[i].x, &a[i].y);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &bx[i].x, &bx[i].y);
            by[i] = point(bx[i].y, bx[i].x);
        }
        sort(bx + 1, bx + 1 + n);
        sort(by + 1, by + 1 + n);

        double ans = dist(a[1], bx[1]);
        for (int i = 1; i <= n; i++) {
            int x = lower_bound(bx + 1, bx + 1 + n, a[i]) - bx;
            for (int j = max(1, x - 30); j <= min(n, x + 30); j++)
                ans = min(ans, dist(a[i], bx[j]));

            x = lower_bound(by + 1, by + 1 + n, point(a[i].y, a[i].x)) - by;
            for (int j = max(1, x - 30); j <= min(n, x + 30); j++)
                ans = min(ans, dist(a[i], point(by[j].y, by[j].x)));
        }
        printf("%.3lf\n", ans);
    }
}