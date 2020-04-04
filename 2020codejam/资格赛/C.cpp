#include <bits/stdc++.h>
using namespace std;
struct node {
    int l, r, t, num;
    node(int _l = 0, int _r = 0, int _t = 0)
    {
        l = _l, r = _r, t = _t;
    }
    bool operator<(const node& b) const
    {
        return l != b.l ? l < b.l : r < b.r;
    }
} a[1010];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i].l >> a[i].r, a[i].t = 0, a[i].num = i;
        sort(a + 1, a + 1 + n);
        int last[5] = { 0 }, gg = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 2; j++)
                if (last[j] <= a[i].l) {
                    a[i].t = j, last[j] = a[i].r;
                    break;
                }
            if (!a[i].t)
                gg++;
        }
        cout << "Case #" << kase << ": ";
        if (gg)
            cout << "IMPOSSIBLE\n";
        else {
            sort(a + 1, a + 1 + n, [](node a, node b) {
                return a.num < b.num;
            });
            for (int i = 1; i <= n; i++)
                cout << (a[i].t == 1 ? "C" : "J");
            cout << "\n";
        }
    }
}