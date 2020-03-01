/**
 * Author: hrynb
 * Time: 2020-02-29 16:15:18
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

char s[1000010];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int w;
        cin >> w >> s + 1;
        int n = strlen(s + 1), sum = 0;
        for (int i = 1; i <= n; i++)
            sum += s[i] - 'A' + 1;
        if (sum > w)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}