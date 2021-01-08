#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int minn = 0, maxx = 0;
        for (int i = 1, k; i <= n; i++) {
            cin >> k;
            if (i <= m)
                minn += k / 3 + (k % 3 != 0), maxx += (k + 1) / 2;
            else
                minn += k / 2 + 1, maxx += k;
        }
        cout << minn << " " << maxx << endl;
    }
}