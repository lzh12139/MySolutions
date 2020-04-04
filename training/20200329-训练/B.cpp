#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define ff first
#define ss second

pii p[20], res[10];
int ans = 0, vis[20], cnt;
bool judge(pii a, pii b)
{
    return (a.ff * b.ss == a.ss * b.ff ? true : false);
}
void dfs(int l, int r, int tmp)
{
    if (l == r + 1) {
        ans = max(ans, tmp);
        //cout << cnt << endl;
        return;
    }
    if (vis[l]) {
        dfs(l + 1, r, tmp);
        return;
    }
    cnt++;
    for (int i = l + 1; i <= r; i++)
        if (!vis[i]) {
            res[cnt] = { p[l].ff - p[i].ff, p[l].ss - p[i].ss };
            vis[i]++, vis[l]++;
            int tmpb = 0;
            for (int j = 1; j < cnt; j++)
                tmpb += (res[cnt].ff * res[j].ss == res[cnt].ss * res[j].ff);

            dfs(l + 1, r, tmp + tmpb);

            vis[i]--, vis[l]--;
        }
    cnt--;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].ff >> p[i].ss;
    dfs(1, n, 0);
    cout << ans << endl;
}