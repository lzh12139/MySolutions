/**
 * Author: hrynb
 * Time: 2020-02-13 23:39:58
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

vector<pair<int, string>> ans;
int p;
int push(int a, string b)
{
    if (p > a) {
        ans.push_back({ a, b }), p -= a;
        return 0;
    }
    ans.push_back({ p, b }), p = 0;
    return 1;
}
void put()
{
    printf("%d\n", ans.size());
    for (auto i : ans)
        printf("%d %s\n", i.ff, i.ss.c_str());
}
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    p = k;
    if (k > 4 * n * m - 2 * n - 2 * m) {
        _NO;
        return 0;
    }
    _YES;
    if (m == 1) {
        if (n != 1)
            if (push(n - 1, "D") || push(n - 1, "U")) {
                put();
                return 0;
            }
    }
    if (n == 1) {
        if (push(m - 1, "R") || push(m - 1, "L")) {
            put();
            return 0;
        }
    }
    for (int i = 1; i < n; i++)
        if (push(m - 1, "R") || push(m - 1, "L") || push(1, "D")) {
            put();
            return 0;
        }
    if (push(m - 1, "R") || push(n - 1, "U")) {
        put();
        return 0;
    }
    for (int i = 1; i < m; i++)
        if (push(n - 1, "D") || push(1, "L") || push(n - 1, "U")) {
            put();
            return 0;
        }
}