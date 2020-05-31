#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-8;
const int N = 100000;

typedef long long ll;

struct Point {
    ll x, y;
    Point() {};
    Point(ll _x, ll _y)
        : x(_x)
        , y(_y) {};
    Point operator+(const Point& a) const
    {
        return Point(x + a.x, y + a.y);
    }
    Point operator-(const Point& a) const
    {
        return Point(x - a.x, y - a.y);
    }
    ll operator*(const Point& a) const
    {
        return x * a.x + y * a.y;
    }
    ll operator^(const Point& a) const
    {
        return x * a.y - y * a.x;
    }
};

Point a[N + 10], st[N + 10];

bool cmp(const Point& a, const Point& b)
{
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

int ConvexHull(int n)
{
    sort(a, a + n, cmp);
    int m = 0;
    for (int i = 0; i < n; i++) {
        while (m > 1 && ((a[m - 1] - a[m - 2]) ^ (a[i] - a[m - 2])) < 0)
            m--;
        st[m++] = a[i];
    }
    int k = m;
    for (int i = n - 2; i >= 0; i--) {
        while (m > k && ((a[m - 1] - a[m - 2]) ^ (a[i] - a[m - 2])) < 0)
            m--;
        st[m++] = a[i];
    }
    if (n > 1)
        m--;
    return m;
}

int rotating_calipers(Point p[], int n)
{
    if (n == 2)
        return n;
    int ans = n;
    Point v;
    int cur = 1;
    for (int i = 0; i < n; i++) {
        v = p[i] - p[(i + 1) % n];
        while ((v ^ (p[cur] - p[(i + 1) % n])) >= (v ^ (p[(cur + 1) % n] - p[(i + 1) % n])))
            cur = (cur + 1) % n;
        int tmp = cur + 1 - (i + 1) % n;
        if (tmp < 1)
            tmp += n;
        ans = min(ans, tmp);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;

    int num = ConvexHull(n);
    if (num > n)
        cout << n << endl;
    else
        cout << rotating_calipers(st, num) + 1 << endl;
}
