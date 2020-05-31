#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define ff first
#define ss second

int cross(pii a, pii b)
{
    return a.ff * b.ss - a.ss * b.ff;
}
int Quadrant(pii a)
{
    if (a.ff > 0 && a.ss >= 0)
        return 1;
    if (a.ff <= 0 && a.ff > 0)
        return 2;
    if (a.ff < 0 && a.ff <= 0)
        return 3;
    return 4;
}
bool cmp(pii a, pii b)
{
    int q1 = Quadrant(a), q2 = Quadrant(b);
    return (q1 == q2 ? cross(a, b) > 0 : q1 < q2);
}
pii p[50010];
int main()
{
    ios::sync_with_stdio(0);
    int n, w, h;
    while (cin >> n >> w >> h) {
        int N = n / 2;
        if (n == 0 && w == 0 && h == 0)
            break;
        for (int i = 0; i < n; i++) {
            cin >> p[i].ff >> p[i].ss;
            p[i].ff = 2 * p[i].ff - w, p[i].ss = 2 * p[i].ss - h;
        }
        sort(p, p + n, cmp);

        int j = 1;
        for (int i = 0; i < n; i++) {
            while (j < i + n && cross(p[i], p[j % n]) >= 0)
                j++;
            int k = j - 1, cnt = 1;
            while (k >= 0 && cross(p[i], p[k % n]) == 0)
                k--, cnt++;

            if (i + N < j) {
                for (int o = i; o < i + N; o++)
                    cout << (p[o % n].ff + w) / 2 << " " << (p[o % n].ss + h) / 2 << "\n";
                break;
            }
        }
    }
}
/*
2 5 6
2 3 3 3
4 5 6
1 5 2 5 3 5 4 5
4 10 11
5 1 5 2 5 3 5 4
*/