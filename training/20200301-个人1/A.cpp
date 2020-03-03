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
    int n, m;
    cin >> n >> m;
    if (n > m && __gcd(m, n - m) == m)
        cout << m << " " << n - m;
    else
        cout << -1;
}