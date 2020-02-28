/**
 * Author: hrynb
 * Time: 2020-02-24 23:15:37
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
typedef pair<int, int> pii;

int num[5010], ans[5010];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, d, N;
        cin >> n >> d;
        N = n;
        if (d > n * (n - 1) / 2) {
            cout << "NO\n";
            continue;
        }
        int cur = 2, minn = 0, dep = 1;
        n--;
        while (1) {
            minn += min(cur, n) * dep;
            if (min(cur, n) == n)
                break;
            n -= cur, cur <<= 1, dep++;
        }
        if (d < minn) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        n = N;
        cur = n * (n - 1) / 2;
        for (int i = 1; i < n; i++)
            num[i] = ans[i] = 1;
        for (int j = n - 1; j >= 1 && cur != d; j--) {
            for (int i = 1; i < n; i++)
                if (num[i] && cur - j + i >= d) {
                    cur = cur - j + i;
                    num[i]--, ans[j]--;
                    num[i + 1] += 2, ans[i]++;
                    break;
                }
        }
        cur = 1;
        ans[0] = 1;
        for (int i = 1; i < n; i++) {
            int tmp = cur;
            for (int j = 1; j <= ans[i]; j += 2, cur++) {
                if (j == ans[i])
                    cout << cur << " ";
                else
                    cout << cur << " " << cur << " ";
            }
            cur = tmp + ans[i - 1];
        }
        cout << endl;
    }
}