#include <bits/stdc++.h>
using namespace std;

int cnt[10010], num[10010];
int main()
{
    int k, n;
    cin >> k >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= k; i++)
        num[cnt[i]]++;
    if ((n - 1) % k == 0) {
        int x = (n - 1) / k;
        if (num[x] == k - 1 && num[x + 1] == 1) {
            for (int j = 1; j <= k; j++)
                if (cnt[j] == x + 1) {
                    cout << "-" << j << endl;
                    return 0;
                }
        }
    }
    if ((n + 1) % k == 0) {
        int x = (n + 1) / k;
        if (x >= 1 && num[x] == k - 1 && num[x - 1] == 1) {
            for (int j = 1; j <= k; j++)
                if (cnt[j] == x - 1) {
                    cout << "+" << j << endl;
                    return 0;
                }
        }
    }
    if (n % k == 0) {
        int x = n / k;
        if (x >= 1 && num[x - 1] == 1 && num[x + 1] == 1 && num[x] == k - 2) {
            int minn = -1, maxx = -1;
            for (int j = 1; j <= k; j++)
                if (cnt[j] == x - 1)
                    minn = j;
                else if (cnt[j] == x + 1)
                    maxx = j;
            cout << "-" << maxx << " +" << minn << endl;
            return 0;
        }
    }
    cout << "*" << endl;
}