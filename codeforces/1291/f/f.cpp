/**
 * Author: lzh12139
 * Time: 2020-02-03 00:06:09
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

void Q(int x)
{
    printf("? %d\n", x);
    fflush(stdout);
}
void R()
{
    printf("R\n");
    fflush(stdout);
}
int vis[2048];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int ans = n;
    if (k == 1) {
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) {
                Q(i);
                char x[4];
                scanf("%s", x + 1);
                Q(j);
                scanf("%s", x + 1);
                R();
                if (x[1] == 'Y')
                    vis[j]++;
            }
        for (int i = 1; i <= n; i++)
            if (vis[i])
                ans--;
        printf("! %d\n", ans);
        return 0;
    }
    int len = k / 2;
    for (int i = 0; i < 2 * n / k; i++) {
        for (int j = i + 1; j < 2 * n / k; j++) {
            for (int o = 1; o <= len; o++) {
                Q(i * len + o);
                char x[4];
                scanf("%s", x + 1);
                if (x[1] == 'Y')
                    vis[i * len + o]++;
            }
            for (int o = 1; o <= len; o++) {
                Q(j * len + o);
                char x[4];
                scanf("%s", x + 1);
                if (x[1] == 'Y')
                    vis[j * len + o]++;
            }
            R();
        }
    }
    for (int i = 1; i <= n; i++)
        if (vis[i])
            ans--;
    printf("! %d\n", ans);
}