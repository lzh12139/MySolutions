#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define ff first
#define ss second
#define mp make_pair

const int N = 4e4 + 10;
const int mod = 1e9 + 7;
const int base = 133;

ll poww[N + 10], a[N + 10];
char s[N + 10];
pii p[N + 10];

int n, m, ans, ansn;
inline int gethash(int l, int r)
{
    int res = a[r] - a[l - 1] * poww[r - l + 1] % mod + mod;
    return res >= mod ? res - mod : res;
}
int check(int x)
{
    int cnt = 0;
    for (int l = 1, r = x; r <= n; l++, r++) {
        int res = gethash(l, r);
        p[++cnt] = { res, l - 1 };
    }
    sort(p + 1, p + 1 + cnt);
    int ok = 0, tmpn = 0, cur = 1, curn = p[1].ss;
    for (int i = 2; i <= cnt; i++)
        if (p[i - 1].ff != p[i].ff) {
            if (cur >= m)
                tmpn = max(tmpn, curn), ok = 1;
            cur = 1, curn = p[i].ss;
        } else
            cur++, curn = max(curn, p[i].ss);
    if (cur >= m)
        tmpn = max(tmpn, curn), ok = 1;

    if (ok) {
        ans = x, ansn = tmpn;
        return 1;
    }
    return 0;
}
int main()
{
    poww[0] = 1;
    for (int i = 1; i <= N; i++)
        poww[i] = poww[i - 1] * base % mod;
    while (~scanf("%d", &m) && m) {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        for (int i = 1; i <= n; i++) {
            a[i] = a[i - 1] * base % mod + s[i] - 'a' + 1;
            if (a[i] >= mod)
                a[i] -= mod;
        }

        int l = 1, r = n;
        ans = -1, ansn = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (check(mid))
                l = mid + 1;
            else
                r = mid - 1;
        }

        if (ans != -1)
            printf("%d %d\n", ans, ansn);
        else
            printf("none\n");
    }
}
