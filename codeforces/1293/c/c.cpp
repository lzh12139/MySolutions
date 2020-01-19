/**
 * Author: lzh12139
 * Time: 2020-01-19 21:40:01
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("Yes\n")
#define _no printf("No\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

int dd[][2] = { -1, 1, -1, 0, -1, -1, 1, -1, 1, 0, 1, 1 };
int cnt[10][100010], a[5][100010];
int main()
{
    int n, q, ans = 0, add = 0;
    scanf("%d%d", &n, &q);
    for (int T = 1; T <= q; T++) {
        int x, y;
        scanf("%d%d", &x, &y);
        //if (T <= y + x - 2 + add || a[x][y]) {
            for (int i = 0; i < 6; i++) {
                int dx = x + dd[i][0], dy = y + dd[i][1];
                if (dx <= 0 || dy <= 0 || dx >= 3 || dy >= n + 1)
                    continue;
                if (a[x][y]) {
                    if (a[dx][dy])
                        ans--;
                    //add = max(add, T - (x + y - 2));
                } else {
                    if (a[dx][dy])
                        ans++;
                }
            }
            a[x][y] ^= 1;
            //printf("%d\n", add);
       // }

        if (ans == 0)
            _yes;
        else
            _no;
    }
}