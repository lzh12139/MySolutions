#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        while (m--) {
            int x, y;
            cin >> x >> y;
            x++, y++;
            int ceng = min(min(x, n - x + 1), min(y, n - y + 1));
            int ans = 1;
            for (int i = 1; i < ceng; i++)
                ans += 4 * (n - 2 * i + 1);

            int step = n - 2 * ceng + 1;
            if (ceng & 1) {
                if (x == ceng) {
                    ans += y - ceng;
                } else if (y == n - ceng + 1) {
                    ans += step + x - ceng;
                } else if (x == n - ceng + 1) {
                    ans += 2 * step - ceng - y + n + 1;
                } else {
                    ans += 3 * step - ceng - x + n + 1;
                }
            } else {
                if (y == ceng) {
                    ans += x - ceng;
                } else if (x == n - ceng + 1) {
                    ans += step + y - ceng;
                } else if (y == n - ceng + 1) {
                    ans += 2 * step - ceng - x + n + 1;
                } else {
                    ans += 3 * step - ceng - y + n + 1;
                }
            }

            cout << ans << endl;
        }
    }
}