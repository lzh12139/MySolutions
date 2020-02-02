/**
 * Author: lzh12139
 * Time: 2020-01-29 22:37:22
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("Yes\n")
#define _no printf("No\n")
#define _YES printf("YES\n");
#define _NO printf("NO\n");

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n & 1)
            printf("7"), n -= 3;
        for (int i = 1; i <= n / 2; i++)
            printf("1");
        printf("\n");
    }
}