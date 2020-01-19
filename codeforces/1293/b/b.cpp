/**
 * Author: lzh12139
 * Time: 2020-01-19 22:28:29
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

int main()
{
    int n;
    scanf("%d", &n);
    double ans = 0;
    for (int i = 1; i <= n; i++)
        ans += 1.0 / i;
    printf("%.10lf\n", ans);
}