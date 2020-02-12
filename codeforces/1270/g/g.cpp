/**
 * Author: hrynb
 * Time: 2020-02-06 23:10:55
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("Yes\n")
#define _no printf("No\n")
#define _YES printf("YES\n")
#define _NO printf("NO\n")
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

const int N = 1e6 + 10;
int vis[N], to[N];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            to[i] = i - x;
            vis[i] = 0;
        }
        int x = 1, p;
        while (!vis[x]) {
            vis[x]++;
            x = to[x];
        }
        V ans;
        p = x;
        do {
            ans.push_back(x);
            x = to[x];
        } while (x != p);
        printf("%d\n", ans.size());
        for (auto i : ans)
            printf("%d ", i);
        printf("\n");
    }
}