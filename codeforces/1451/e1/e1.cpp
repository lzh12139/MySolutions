/**
 * Author: lzh12139
 * Time: 2020-11-22 00:03:32
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

int queryand(int x, int y, int& tmp)
{
    printf("AND %d %d\n", x, y);
    fflush(stdout);
    scanf("%d", &tmp);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
        queryxor(1, i, i);

    int and12, and13, and23;
    queryand(1, 2, and12);
    queryand(1, 3, and13);
    queryand(2, 3, and23);

    for (int tmp = n >> 1; tmp; tmp >>= 1) {
        int tmp12 = ((a[2] & tmp) ? 2 : 0) | ((and12 & tmp) ? 1 : 0);
        int tmp13 = ((a[3] & tmp) ? 2 : 0) | ((and13 & tmp) ? 1 : 0);
        int tmp23 = (((a[2] ^ a[3]) & tmp) ? 2 : 0) | ((and23 & tmp) ? 1 : 0);

        if (tmp12 == 1) {
            ans[1] |= tmp, ans[2] |= tmp;
        }
        if (tmp13 == 1) {
            ans[1] |= tmp, ans[3] |= tmp;
        }
        if (tmp23 == 1) {
            ans[2] |= tmp, ans[3] |= tmp;
        }

        if (tmp12 == 2 && tmp13 == 2 && tmp23 == 0) {
            ans[1] |= tmp;
        }
        if (tmp12 == 2 && tmp23 == 2 && tmp13 == 0) {
            ans[2] |= tmp;
        }
        if (tmp13 == 2 && tmp23 == 2 && tmp12 == 0) {
            ans[3] |= tmp;
        }
    }

    printf("! %d %d %d ", ans[1], ans[2], ans[3]);
    for (int i = 4; i <= n; i++) {
        ans[i] = a[i] ^ ans[1];
        printf("%d ", ans[i]);
    }
}