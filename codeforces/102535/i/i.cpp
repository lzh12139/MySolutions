/**
 * Author: hrynb
 * Time: 2020-02-29 16:33:59
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

const int dx[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
const int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
char s[1010][1010];
int vis[1010][1010];
pii pre[1010][1010];
pii S, T, can;
inline bool judge(int x, int y)
{
    return x > 0 && y > 0 && x <= can.ff && y <= can.ss
        && s[x][y] != 'X' && !vis[x][y];
}
void out(int x, int y)
{
    if ((pii){ x, y } == S)
        return;
    out(pre[x][y].ff, pre[x][y].ss);
    for (int i = 0; i < 8; i++)
        if (pre[x][y].ff + dx[i] == x && pre[x][y].ss + dy[i] == y) {
            cout << char('A' + i);
            return;
        }
}
void solve()
{
    queue<pii> q;
    q.push(S), vis[S.ff][S.ss]++;
    while (!q.empty()) {
        pii x = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int tx = x.ff + dx[i], ty = x.ss + dy[i];
            if (judge(tx, ty)) {
                vis[tx][ty]++, pre[tx][ty] = x;
                if ((pii){ tx, ty } == T) {
                    cout << "Whinny\n";
                    out(tx, ty);
                    cout << "\n";
                    return;
                }
                q.push({ tx, ty });
            }
        }
    }
    cout << "Neigh\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        can = { n, m };
        for (int i = 1; i <= n; i++) {
            cin >> s[i] + 1;
            for (int j = 1; j <= m; j++) {
                vis[i][j] = 0;
                if (s[i][j] == 'K')
                    S = { i, j };
                else if (s[i][j] == 'F')
                    T = { i, j };
            }
        }
        solve();
    }
}