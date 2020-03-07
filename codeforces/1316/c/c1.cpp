/**
 * Author: hrynb
 * Time: 2020-03-04 23:48:17
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

int main()
{
    freopen("in3.txt", "w", stdout);
    int n = 1e6, p = 2;
    printf("%d %d %d\n", n, n, p);
    for (int i = 1; i <= n; i++)
        printf("%d ", rand() + 1);
    printf("\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", rand() + 1);
}