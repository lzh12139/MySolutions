/**
 * Author: hrynb
 * Time: 2020-01-22 22:36:22
**/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define _yes printf("YES\n")
#define _no printf("NO\n")

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, a, b, c;
        scanf("%d%d%d%d", &a, &b, &c, &n);
        int tmp = (a + b + c + n) / 3;
        if ((a + b + c + n) % 3 == 0 && tmp >= a && tmp >= b && tmp >= c)
            _yes;
        else
            _no;
    }
}