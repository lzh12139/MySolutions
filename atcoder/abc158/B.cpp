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
    ll n, a, b;
    cin >> n >> a >> b;
    cout << n / (a + b) * a + min(a, n % (a + b));
}