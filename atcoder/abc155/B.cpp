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
    int n, ok = 1;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (x % 2 == 0)
            if (x % 3 && x % 5) {
                ok = 0;
                break;
            }
    }
    if (ok)
        cout << "APPROVED";
    else
        cout << "DENIED";
}