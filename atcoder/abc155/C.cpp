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
    int n;
    cin >> n;
    map<string, int> m;
    while (n--) {
        string s;
        cin >> s;
        m[s]++;
    }
    vector<pair<int, string>> v;
    int ansn = -1;
    for (auto i : m)
        v.push_back({ i.ss, i.ff }), ansn = max(ansn, i.ss);
    sort(v.begin(), v.end());
    for (auto i : v) {
        if (i.ff == ansn)
            cout << i.ss << "\n";
    }
}