/**
 * Author: lzh12139
 * Time: 2020-11-22 01:01:11
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

int a[(1 << 16) + 10], ans[(1 << 16) + 10];
vector<int> v[(1 << 16) + 10];

void queryxor(int x, int y, int i)
{
    printf("XOR %d %d\n", x, y);
    fflush(stdout);
    scanf("%d", &a[i]);
    v[a[i]].push_back(i);
}

void solve(int n)
{
    for (int i = 0; i < n; i++)
        if (v[i].size() >= 2) {
            int x = v[i][0], y = v[i][1], tmp;
            printf("AND %d %d\n", x, y);
            fflush(stdout);
            scanf("%d", &ans[x]);
            ans[1] = a[x] ^ ans[x];

            return;
        }
    if (v[0].size()) {
        int x = v[0][0];
        printf("AND %d %d\n", 1, x);
        fflush(stdout);
        scanf("%d", &ans[1]);
        return;
    }

    // 元素两两不同
    int tmp1, tmp2;
    printf("AND %d %d\n", 1, v[1][0]);
    fflush(stdout);
    scanf("%d", &tmp1);
    printf("AND %d %d\n", 1, v[n - 2][0]);
    fflush(stdout);
    scanf("%d", &tmp2);
    ans[1] = tmp1 | tmp2;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
        queryxor(1, i, i);

    solve(n);

    printf("! %d ", ans[1]);
    for (int i = 2; i <= n; i++) {
        ans[i] = a[i] ^ ans[1];
        printf("%d ", ans[i]);
    }
}