/**
 * Author: lzh12139
 * Time: 2020-02-02 22:54:46
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("Yes\n")
#define _no printf("No\n")
#define _YES printf("YES\n");
#define _NO printf("NO\n");

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

char s[200010];
int sum[200010][30];
int main()
{
    scanf("%s", s + 1);
    int q, n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 26; j++)
            sum[i][j] = sum[i - 1][j];
        sum[i][s[i] - 'a' + 1]++;
    }
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l == r)
            _yes;
        else {
            int num = 0;
            for (int i = 1; i <= 26; i++)
                if (sum[r][i] != sum[l - 1][i])
                    num++;
            if (num >= 3 || (num == 2 && s[l] != s[r]))
                _yes;
            else
                _no;
        }
    }
}