/**
 * Author: lzh12139
 * Time: 2020-11-21 22:55:12
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

char s1[1000010], s2[1000010];
int a[30], b[30];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s%s", s1 + 1, s2 + 1);
        for (int i = 1; i <= 26; i++)
            a[i] = b[i] = 0;
        for (int i = 1; i <= n; i++)
            a[s1[i] - 'a' + 1]++;
        for (int i = 1; i <= n; i++)
            b[s2[i] - 'a' + 1]++;
        for (int i = 1; i < 26; i++)
            if (a[i] != b[i]) {
                while (a[i] > b[i]) {
                    a[i] -= k, a[i + 1] += k;
                }
            }

        int ok = 1;
        for (int i = 1; i <= 26; i++)
            if (a[i] != b[i])
                ok = 0;
        ok ? _Yes : _No;
    }
}