/**
 * Author: hrynb
 * Time: 2020-02-09 23:16:55
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _Yes printf("Yes\n")
#define _No printf("No\n")
#define _YES printf("YES\n")
#define _NO printf("NO\n")
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<double, double> pii;

const double eps = 1e-8;
const int N = 1e6;
inline int sgn(double x)
{
    if (fabs(x) < eps)
        return 0;
    if (x < 0)
        return -1;
    return 1;
}

struct Point {
    double x, y;
    Point(){};
    Point(double _x, double _y)
        : x(_x)
        , y(_y){};
    Point operator+(const Point& a) const
    {
        return Point(x + a.x, y + a.y);
    }
    Point operator-(const Point& a) const
    {
        return Point(x - a.x, y - a.y);
    }
    double operator*(const Point& a) const
    {
        return x * a.x + y * a.y;
    }
    double operator^(const Point& a) const
    {
        return x * a.y - y * a.x;
    }
};

double dist(Point a, Point b)
{
    return sqrt((a - b) * (a - b));
}

Point a[N + 10], st[N + 10];

bool cmp(Point b, Point c)
{
    int cmp = sgn((b - a[1]) ^ (c - a[1]));
    if (cmp == 1)
        return true;
    if (cmp == 0 && sgn(dist(b, a[1]) - dist(c, a[1])) == -1)
        return true;
    return false;
}

int Graphm(int n)
{
    int k = 1, num;
    sort(a + 2, a + 1 + n, cmp);

    if (n == 1) {
        st[1] = a[1];
        return 1;
    } else if (n == 2) {
        st[1] = a[1], st[2] = a[2];
        return 2;
    } else {
        st[1] = a[1], st[2] = a[2], num = 2;
        for (int i = 3; i <= n; i++) {
            while (num > 1 && sgn((st[num] - st[num - 1]) ^ (a[i] - st[num - 1])) <= 0)
                num--;
            st[++num] = a[i];
        }
        return num;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    a[1] = Point(0, 0);
    double PP = 0;
    for (int i = 2; i <= n + 1; i++) {
        scanf("%lf", &a[i].y);
        if (a[i].y < PP)
            PP = 1e18;
        else
            PP = a[i].y;
        a[i].y += a[i - 1].y, a[i].x = i - 1;
    }
    if (PP != 1e18) {
        for (int i = 2; i <= n + 1; i++)
            printf("%.9lf\n", a[i].y - a[i - 1].y);
        return 0;
    }
    int num = Graphm(n + 1), judge = 0;

    for (int i = 1; i <= n; i++)
        if (st[i].x == n) {
            judge = i;
            break;
        }
    Point pre = Point(1, 0);
    for (int i = 2; i <= judge; i++) {
        int r = st[i].x, l = pre.x;
        double ans = (st[i].y - pre.y) / (st[i].x - pre.x + 1);
        for (int j = pre.x; j <= r; j++)
            printf("%.9lf\n", ans);
        pre = Point(st[i].x + 1, st[i].y);
    }
}