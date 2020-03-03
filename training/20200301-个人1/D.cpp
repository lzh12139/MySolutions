#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

int a[310], b[310], deg[310], ans_list[310], vis[310];
int pre[310];
char s[310];
V v[310];
vector<pii> ans;
void gao(int n)
{
    int cnt = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!deg[i]) {
            q.push(i);
            if (b[i])
                ans_list[++cnt] = i;
        }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto i : v[x])
            if ((--deg[i]) == 0) {
                q.push(i);
                if (b[i])
                    ans_list[++cnt] = i;
            }
    }
}
void add(int x, int t)
{
    while (x != t) {
        ans.push_back({ x, pre[x] });
        x = pre[x];
    }
}
int bfs(int s)
{
    queue<int> q;
    memset(vis, 0, sizeof vis);
    q.push(s), vis[s]++;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto j : v[x])
            if (!vis[j]) {
                vis[j]++, pre[j] = x;
                q.push(j);

                if (a[j]) {
                    a[j]--;
                    add(j, s);
                    return 1;
                }
            }
    }
    return 0;
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1, x; i <= k; i++)
        scanf("%d", &x), a[x]++;
    for (int i = 1, x; i <= k; i++)
        scanf("%d", &x), b[x]++;
    for (int i = 1; i <= 300; i++)
        if (a[i] && b[i])
            a[i]--, b[i]--, k--;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++)
            if (s[j] == '1')
                v[j].push_back(i), deg[i]++;
    }
    gao(n);
    for (int i = 1; i <= k; i++)
        if (!bfs(ans_list[i])) {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    printf("%d\n", ans.size());
    for (auto i : ans)
        printf("%d %d\n", i.ff, i.ss);
}