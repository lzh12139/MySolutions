#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

const int N = 1e5;
int a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 1e9;
    for (int i = 1; i <= 100; i++) {
        int tmp = 0;
        for (int j = 1; j <= n; j++)
            tmp += (a[j] - i) * (a[j] - i);
        ans = min(ans, tmp);
    }
    cout << ans;
}