/**
 * Author: hrynb
 * Time: 2020-02-09 22:49:09
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

int a[100010], num[60], ind[60];
int main()
{
    IOS;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int x = a[i], cnt = 1;
        while (x) {
            if (x & 1) {
                num[cnt]++;
                ind[cnt] = i;
            }
            cnt++, x >>= 1;
        }
    }
    int choose = 1;
    for (int i = 50; i >= 1; i--)
        if (num[i] == 1) {
            choose = ind[i];
            break;
        }
    printf("%d ", a[choose]);
    for (int i = 1; i <= n; i++)
        if (i != choose)
            printf("%d ", a[i]);
}