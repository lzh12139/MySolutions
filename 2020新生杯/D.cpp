#include <bits/stdc++.h>
using namespace std;

int a[1010];
int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        int cur = 1;
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] %= (k + 1);
        }
        for (int i = n; i >= 1; i--) {
            if (a[i] == 1) {
                cur ^= 1;
            } else if (a[i] > 1) {
                cur ^= 1;
                break;
            }
        }
        cout << (cur ? "GreyThroat" : "Warfarin") << endl;
    }
}
