#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

int main()
{
    int n, ans = 0;
    cin >> n;
    map<int, int> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    for (auto i : m)
        ans += i.ss / 2;
    cout << ans / 2;
}