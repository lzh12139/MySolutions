#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

int vis[1010], deg[1010], gg = 0;
vector<int> v[1010];
vector<pii> ans;
void dfs(int x)
{
    vis[x]++;
    vector<pii> choose;
    set<int> has;
    for (auto i : v[x])
        choose.push_back({ v[i].size(), i }), has.insert(i);
    sort(choose.begin(), choose.end(), greater<pii>());
    for (auto i : choose)
        if (!vis[i.ss]) {
            int gg = 0, k = 0;
            auto j = has.begin();
            for (; j != has.end() && k < v[i.ss].size(); j++)
                if (*j == v[i.ss][k])
                    k++;
            if (k == v[i.ss].size()) {
                ans.push_back({ x, i.ss });
                dfs(i.ss);

                for (auto p : v[i.ss])
                    has.erase(p);
                has.erase(i.ss);
            }
        }
    if (!has.empty())
        gg++;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1, j, k; i <= n; i++) {
        scanf("%d", &j);
        while (j--) {
            scanf("%d", &k), v[i].push_back(k);
            deg[k]++;
            if (k == i) {
                printf("NO\n");
                return 0;
            }
        }
        sort(v[i].begin(), v[i].end());
    }
    for (int i = 1, j = 0; i <= n; i++) {
        if (deg[i] == 0) {
            if (j) {
                printf("NO\n");
                return 0;
            }
            dfs(i), j++;
        }
    }
    if (ans.size() == n - 1 && !gg) {
        sort(ans.begin(), ans.end());
        printf("YES\n");
        for (auto i : ans)
            printf("%d %d\n", i.ff, i.ss);
    } else
        printf("NO\n");
}