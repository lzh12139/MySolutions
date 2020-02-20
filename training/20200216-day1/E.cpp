#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

char s[100010];
ll poww[100010];
const int base = 131;
const int mod = 1e9 + 7;
int lowbit(int x) { return x & (-x); }
struct TreeArray {
    int n;
    ll a[500001];
    void setRange(int N) { n = N; }
    void clear()
    {
        n = 0;
        memset(a, 0, sizeof(a));
    }
    void modify(int pos, ll val)
    {
        for (int i = pos; i <= n; i += lowbit(i))
            a[i] = (a[i] + val + mod) % mod;
    }
    ll query(int pos)
    {
        ll rnt = 0;
        for (int i = pos; i > 0; i -= lowbit(i))
            rnt = (rnt + a[i] + mod) % mod;
        return rnt;
    }
};
TreeArray a, b;

int main()
{
    poww[0] = 1;
    for (int i = 1; i <= 100000; i++)
        poww[i] = poww[i - 1] * base % mod;
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        scanf("%s", s + 1);
        a.clear(), b.clear();
        a.setRange(n), b.setRange(n);
        for (int i = 1; i <= n; i++)
            a.modify(i, poww[i] * (s[i] - 'a' + 1) % mod);

        for (int i = n, j = 1; i >= 1; i--, j++)
            b.modify(j, poww[j] * (s[i] - 'a' + 1) % mod);

        while (m--) {
            int q, x, y;
            scanf("%d", &q);
            if (q == 1) {
                char que[10];
                scanf("%d%s", &x, que + 1);
                ll add = que[1] - s[x];
                a.modify(x, (mod + add * poww[x] % mod) % mod);
                b.modify(n + 1 - x, (mod + add * poww[n + 1 - x] % mod) % mod);
                s[x] = que[1];
            } else {
                scanf("%d%d", &x, &y);
                ll qa = (a.query(y) - a.query(x - 1) + mod) % mod,
                   qb = (b.query(n + 1 - x) - b.query(n - y) + mod) % mod;
                if (y < n + 1 - x)
                    qa = qa * poww[n + 1 - x - y] % mod;
                else
                    qb = qb * poww[y - (n + 1 - x)] % mod;
                if (qa == qb)
                    printf("Adnan Wins\n");
                else
                    printf("ARCNCD!\n");
            }
        }
    }
}