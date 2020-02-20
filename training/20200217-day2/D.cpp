#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

int w[2010][2010], vis[2010];
vector<int> v[2010];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        w[x][y]++;
        if (w[x][y] == 1)
            v[x].push_back(y);
    }
    vector<pii> ans;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (w[i][j] == 1) {
                for (int p = 1; p <= n; p++)
                    vis[p] = 0;
                int ok = 0;
                queue<int> q;
                q.push(i), vis[i]++;
                //printf("**%d %d\n", i, j);
                while (!q.empty() && !ok) {
                    int x = q.front();
                    
                    //printf("%d ", x);
                    q.pop();
                    for (auto p : v[x])
                        if (!vis[p]) {
                            if (p == j) {
                                if (x != i) {
                                    ok = 1;
                                    break;
                                }
                            } else {
                                vis[p]++;
                                q.push(p);
                            }
                        }
                }
                //printf("\n");
                if (!ok)
                    ans.push_back({ i, j });
            }
    printf("%d\n", ans.size());
    for (auto i : ans)
        printf("%d %d\n", i.ff, i.ss);
}
