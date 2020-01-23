/**
 * Author: hrynb
 * Time: 2020-01-22 23:11:29
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("Yes\n")
#define _no printf("No\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

const int N = 4e5 + 10;
int vis[N];
int main()
{
    int t, x;
    cin >> t >> x;
    int ans = 0, ansmod = 0;
    while (t--) {
        int n;
        cin >> n;
        n %= x;
        vis[n]++;
        while (vis[ansmod]) {
            vis[ansmod]--;
            ans++;
            ansmod = (ansmod + 1) % x;
        }
        cout << ans << endl;
    }
}