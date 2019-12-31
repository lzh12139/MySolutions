/**
 * Author: hrynb
 * Time: 2019-08-29 15:44:42
**/

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <stack>
using namespace std;
#define mem(x, y) memset(x, (y), sizeof x)
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define sc(a) scanf("%d", &a)
#define scl(a) scanf("%lld", &a)
#define scs(a) scanf("%s", a)
#define pr(a, b) printf("%d%c", a, b)
#define prl(a, b) printf("%ll%c", a, b)
#define all(v) v.begin(), v.end()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define _yes printf("Yes\n")
#define _no printf("No\n")

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> V;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<string, int> msi;

int a[500010], n;
int b[500010];
ll sum[500010];

int check(int val)
{
    for (int i = 1; i <= n; i++)
        b[i] = a[i];
    b[n + 1] = val;
    for (int i = n; i >= 1; i--)
        if (b[i] < b[i + 1])
            swap(b[i], b[i + 1]);

    for (int i = 1; i <= n + 1; i++)
        sum[i] = sum[i - 1] + b[i];

    for (int i = 1; i <= n + 1; i++)
    {
        int x = upper_bound(b + 1, b + 2 + n, i, greater<int>()) - b;
        ll r = 1ll * i * (i - 1);

        if (x == n + 2)
            r += 1ll * (n + 1 - i) * i;
        else if (x <= i + 1)
            r += sum[n + 1] - sum[i];
        else
            r += sum[n + 1] - sum[x - 1] + 1ll * (x - i - 1) * i; // i+1 -> x-1

        //printf("i=%d x=%d l=%lld r=%lld\n", i, x, sum[i], r);
        if (sum[i] > r)
        {
            if (i < val + 1)
                return 1; // big
            else
                return -1; // small
        }
    }
    return 0;
}

int main()
{
    int add = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), add += (a[i] & 1);
    sort(a + 1, a + 1 + n, greater<int>());
    if (add & 1)
        add = 1;
    else
        add = 0;
    int left = -1, right = -1, linf, rinf;
    linf = 0, rinf = (n - add) / 2;
    int l = linf, r = rinf;
    //printf("%d %d\n", linf, rinf);
    //for (int i = 0; i <= n; i++)
    //    printf("i=%d check=%d\n", i, check(i));
    // if (n == 10)
    //    for (int i = 0; i <= n; i++)
    //        printf("%d\n", check(i));
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(mid * 2 + add) != -1)
            r = mid - 1, left = mid;
        else
            l = mid + 1;
    }
    //printf("%d %d\n", l, r);

    l = left, r = rinf;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(mid * 2 + add) != 1)
            l = mid + 1, right = mid;
        else
            r = mid - 1;
    }
    //printf("%d %d\n", l, r);
    //printf("%d %d\n", left, right);
    if (left != -1 && right != -1)
        for (int i = left * 2 + add; i <= right * 2 + add; i += 2)
            printf("%d ", i);
    else
        printf("-1\n");
}