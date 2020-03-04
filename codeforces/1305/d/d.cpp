/**
 * Author: hrynb
 * Time: 2020-03-03 23:41:57
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

vector<int> v[1010];
void A(int x)
{
    cout << "! " << x << "\n";
    cout.flush();
}
int Q(int x, int y)
{
    cout << "? " << x << " " << y << "\n";
    cout.flush();
    int res;
    cin >> res;
    if (res == x || res == y) {
        A(res);
        return -1;
    }
    return res;
}

pii cur;
void dfs(int x, int d, int p)
{
    if (d >= cur.ss && v[x].size() == 1)
        cur = { x, d };
    for (auto i : v[x])
        if (i != p) {
            dfs(i, d + 1, x);
        }
}
int res1, res2;
int dfs2(int x, int p)
{
    if (v[x].size() == 1) {
        if (res1 == -1)
            res1 = x;
        else if (res2 == -1)
            res2 = x;
        return 1;
    }
    for (auto i : v[x])
        if (i != p && dfs2(i, x) && p != -1)
            return 1;
    return 0;
}
int dfs1(int x, int y, int p)
{
    if (x == y)
        return 1;
    for (auto i : v[x])
        if (i != p)
            if (dfs1(i, y, x))
                return 1;
    return 0;
}
void remove(int x, int y, int z)
{
    vector<int> del;
    for (int i = 0; i < v[x].size(); i++)
        if (dfs1(v[x][i], y, x) || dfs1(v[x][i], z, x))
            del.push_back(i);
    sort(del.begin(), del.end(), greater<int>());
    for (auto i : del)
        v[x].erase(v[x].begin() + i);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y), v[y].push_back(x);
    }
    cur = { 0, 0 };
    dfs(1, 0, -1);
    pii d1 = cur;

    cur = { 0, 0 };
    dfs(d1.ff, 0, -1);
    pii d2 = cur;

    int tmp = Q(d1.ff, d2.ff), dd1, dd2;
    remove(tmp, d1.ff, d2.ff);
    dd1 = tmp;
    if (tmp == -1)
        return 0;
    while (1) {
        cur = { 0, 0 };

        if (v[dd1].size() >= 2) {
            res1 = res2 = -1;
            dfs2(dd1, -1);
            int res = Q(res1, res2);
            if (res == dd1)
                remove(dd1, res1, res2);
            else if (res != -1) {
                dd1 = res;
                remove(res, res1, res2);
            } else
                return 0;
        } else if (v[dd1].size() == 1) {
            dfs(dd1, 0, -1);
            dd2 = cur.ff;

            int res = Q(dd1, dd2);
            if (res == -1)
                return 0;
            remove(res, dd1, dd2);
            dd1 = res;
        } else {
            A(dd1);
            return 0;
        }
    }
}