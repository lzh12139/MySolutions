/**
 * Author: hrynb
 * Time: 2020-02-12 23:11:29
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

int a[100010];
ll p2[70];
int numn[70], num[70];
int main()
{
    //IOS;
    p2[1] = 1;
    for (int i = 2; i <= 40; i++)
        p2[i] = p2[i - 1] * 2;

    int t;
    cin >> t;
    while (t--) {
        for (int i = 1; i <= 40; i++)
            numn[i] = num[i] = 0;

        ll n, m, sum = 0;
        cin >> n >> m;
        for (int i = 1; i <= 40; i++)
            if (n & p2[i])
                numn[i]++;
        for (int i = 1; i <= m; i++) {
            cin >> a[i], sum += a[i];
            for (int j = 1; j <= 40; j++)
                if (p2[j] == a[i]) {
                    num[j]++;
                    break;
                }
        }
        if (n > sum) {
            cout << "-1\n";
            continue;
        }
        int ans = 0, last = 0;
        for (int i = 1; i <= 40; i++)
            if (numn[i]) {
                if (num[i]) {
                    num[i]--, numn[i]--;
                    if (num[i] && last) {
                        ans += i - last;
                        for (int j = last; j < i; j++) {
                            num[j]++;
                            if (j == last)
                                num[j]++;
                            if (numn[j])
                                num[j]--;
                            num[j + 1] += num[j] / 2, num[j] %= 2;
                        }
                        num[i]--;
                        last = 0;
                    }
                    num[i + 1] += num[i] / 2, num[i] %= 2;
                } else {
                    if (!last)
                        last = i;
                }
            } else {
                if (num[i]) {
                    if (last) {
                        ans += i - last;
                        for (int j = last; j < i; j++) {
                            num[j]++;
                            if (j == last)
                                num[j]++;
                            if (numn[j])
                                num[j]--;
                            num[j + 1] += num[j] / 2, num[j] %= 2;
                        }
                        num[i]--;
                        last = 0;
                    }
                    num[i + 1] += num[i] / 2, num[i] %= 2;
                }
            }
        cout << ans << "\n";
    }
}