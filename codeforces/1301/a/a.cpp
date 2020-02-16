/**
 * Author: hrynb
 * Time: 2020-02-13 23:26:13
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

char a[110], b[110], c[110];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s%s%s", a + 1, b + 1, c + 1);
        int n = strlen(a + 1);
        int ok = 1;
        for (int i = 1; i <= n; i++)
            if (a[i] == c[i] || b[i] == c[i])
                ;
            else
                ok = 0;
        if (ok)
            _YES;
        else
            _NO;
    }
}