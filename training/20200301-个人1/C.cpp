#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

pii p[200010];
int main()
{
    IOS;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].ff >> p[i].ss;
    sort(p + 1, p + 1 + n, [](pii a, pii b) {
        return a.ss != b.ss ? a.ss < b.ss : a.ff < b.ff;
    });
    V ans;
    int cur = 0;
    for (int i = 1; i <= n; i++)
        if (cur < p[i].ff)
            cur = p[i].ss, ans.push_back(cur);
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << " ";
}