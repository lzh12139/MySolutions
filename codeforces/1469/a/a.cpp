/**
 * Author: hrynb
 * Time: 2020-12-28 22:36:38
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

char s[1100];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> s + 1;
        int n = strlen(s + 1);
        if (n & 1) {
            _NO;
            continue;
        }
        if (s[1] == ')' || s[n] == '(' || (n & 1))
            _NO;
        else
            _YES;
    }
}