/**
 * Author: lzh12139
 * Time: 2020-02-02 22:36:44
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

char s[3010];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d%s", &n, s + 1);
        int a = -1, b = -1;
        for (int i = 1; i <= n; i++)
            if ((s[i] - '0') & 1) {
                if (a == -1)
                    a = i;
                else {
                    b = i;
                    break;
                }
            }
        if (a != -1 && b != -1) {
            for (int i = a; i <= b; i++)
                printf("%c", s[i]);
            printf("\n");
        } else
            printf("-1\n");
    }
}