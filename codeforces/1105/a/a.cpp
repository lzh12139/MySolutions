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
typedef pair<int, int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back
const int N = (1 << 20) + 10;

ll aa[44];
ll basel[N], baser[N];
ll baselmod[N], basermod[N];
ll vl[12][N];
int _sort(ll *a, ll *b, ll p)
{
    for (int i = 0; i <= 9; i++)
        vl[i][0] = 0;
    for (int i = 1; i <= a[0]; i++)
    {
        int x = (a[i] / p) % 10;
        vl[x][++vl[x][0]] = a[i];
    }
    a[0] = b[0] = 0;
    p = p * 10;
    for (int i = 0; i <= 9; i++)
        for (int o = 1; o <= vl[i][0]; o++)
            a[++a[0]] = vl[i][o], b[++b[0]] = vl[i][o] % p;
    return vl[4][0];
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        ll ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &aa[i]);
        int l = n / 2, r = n - n / 2;
        basel[0] = baser[0] = 0;
        for (int i = (1 << l) - 1; i >= 1; i--)
        {
            int c = i, cnt = 1;
            ll cmp = 0;
            while (c)
            {
                if (c & 1)
                    cmp += aa[cnt];
                cnt++, c >>= 1;
            }
            basel[++basel[0]] = cmp;
        }
        for (int i = (1 << r) - 1; i >= 1; i--)
        {
            int c = i, cnt = l + 1;
            ll cmp = 0;
            while (c)
            {
                if (c & 1)
                    cmp += aa[cnt];
                cnt++, c >>= 1;
            }
            baser[++baser[0]] = cmp;
        }
        //printf("cur_ans=%lld\n",ans);
        //printf("%lld\n", ans);

        ll base = 1;
        for (int wei = 1; wei <= 9; wei++, base *= 10)
        {
            ll p = base * 10;
            ans += _sort(basel, baselmod, base);
            ans += _sort(baser, basermod, base);
            /*for (int i = 1; i <= basel[0]; i++)
                printf("%d ", basel[i]);
            printf("\n");*/

            int l = baser[0], r = baser[0];
            ll linf = 4 * base, rinf = 5 * base;
            for (int i = 1; i <= basel[0]; i++)
            {
                while (l >= 1 && baselmod[i] + basermod[l] >= linf)
                    l--;
                while (r >= 1 && baselmod[i] + basermod[r] >= rinf)
                    r--;
                //printf("%d %d\n", l, r);
                ans += r - l;
            }

            l = baser[0], r = baser[0];
            linf = 14 * base, rinf = 15 * base;
            for (int i = 1; i <= basel[0]; i++)
            {
                while (l >= 1 && baselmod[i] + basermod[l] >= linf)
                    l--;
                while (r >= 1 && baselmod[i] + basermod[r] >= rinf)
                    r--;
                //printf("%d %d\n", l, r);
                ans += r - l;
            }
        }

        printf("%lld\n", ans);
    }
}