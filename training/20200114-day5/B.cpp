#include <bits/stdc++.h>
using namespace std;
int lowbit(int x) { return x & (-x); }
struct TreeArray {
    int n;
    int a[3000001];
    int sa[3000001];
    void setRange(int N) { n = N; }
    void clear()
    {
        memset(a, 0, sizeof(a));
        memset(sa, 0, sizeof(sa));
    }
    void modify(int pos, int val)
    {
        val = val - sa[pos];
        sa[pos] = val;
        for (int i = pos; i <= n; i += lowbit(i))
            a[i] += val;
    }
    int query(int pos)
    {
        int rnt = 0;
        for (int i = pos; i > 0; i -= lowbit(i))
            rnt += a[i];
        return rnt;
    }
};
TreeArray tr;
map<string, int> Map;
string str[3000001];
char ch[101];
int main()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", ch);
        str[i] = ch;
    }
    for (int i = 0; i < m; ++i) {
        int v;
        scanf("%s%d", ch, &v);
        Map[string(ch)] = v;
    }
    tr.setRange(n);
    tr.clear();
    for (int i = 1; i <= n; ++i) {
        tr.modify(i, Map[str[i]]);
    }
    while (q--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x;
            scanf("%d%s", &x, ch);
            tr.modify(x, Map[string(ch)]);

        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            int s = tr.query(r) - tr.query(l - 1);
            if (s <= 30 * (r - l + 1))
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
}