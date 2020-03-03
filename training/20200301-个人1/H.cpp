#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

vector<int> vis[200010];
char s[200010];
struct node {
    int x, y, d;
    node(int _x = 0, int _y = 0, int _d = 0)
    {
        x = _x, y = _y, d = _d;
    }
};
const int dd[4][2] = { -1, 0, 1, 0, 0, 1, 0, -1 };
int n, m;
inline int judge(int x, int y)
{
    return x > 0 && y > 0 && x <= n && y <= m && !vis[x][y];
}
int main()
{
    int k;
    scanf("%d%d%d", &n, &m, &k);
    queue<node> q;
    pii S, T;
    for (int i = 1; i <= n; i++) {
        vis[i] = V(m + 1, 0);
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++)
            if (s[j] == 'S')
                S = { i, j };
            else if (s[j] == 'F')
                T = { i, j };
            else if (s[j] == 'M') {
                q.push(node(i, j, 0));
                vis[i][j]++;
            }
    }
    while (!q.empty()) {
        node x = q.front();
        q.pop();
        if (x.d == k)
            break;
        for (int i = 0; i < 4; i++) {
            int dx = x.x + dd[i][0], dy = x.y + dd[i][1];
            if (judge(dx, dy)) {
                vis[dx][dy]++;
                q.push(node(dx, dy, x.d + 1));
            }
        }
    }

    while (!q.empty())
        q.pop();
    if (vis[S.ff][S.ss] || vis[T.ff][T.ss]) {
        printf("-1\n");
        return 0;
    }
    q.push(node(S.ff, S.ss, 0));
    vis[S.ff][S.ss]++;
    while (!q.empty()) {
        node x = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dx = x.x + dd[i][0], dy = x.y + dd[i][1];
            if (judge(dx, dy)) {
                if (dx == T.ff && dy == T.ss) {
                    printf("%d\n", x.d + 1);
                    return 0;
                }
                vis[dx][dy]++;
                q.push(node(dx, dy, x.d + 1));
            }
        }
    }
    printf("-1\n");
}