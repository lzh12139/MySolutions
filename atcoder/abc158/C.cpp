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
int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= 100000; i++)
        if (int(i * 0.08) == a && int(i * 0.1) == b) {
            cout << i;
            return 0;
        }
    cout << -1;
}