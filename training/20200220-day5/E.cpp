#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

struct S {
    static const int N = 1e6 + 10;
    char s[N];
    int l[N], r[N], t[N], a[N], ans[N], shul[N], shur[N];
    int ind, n;
    void read()
    {
        scanf("%s", s + 1);
        ind = 1, n = strlen(s + 1);
    }
    void solve()
    {
        while ((s[ind] == ',' || s[ind] == '(' || s[ind] == ')') && ind <= n)
            ind++;
        if (ind == n + 1)
            return;
        int tmp = a[0], cur = t[0];
        if (s[ind] == '[') {
            ind++;
            for (int cur = 0; ind <= n; ind++)
                if (s[ind] == ',')
                    a[++a[0]] = cur, cur = 0;
                else if (s[ind] >= '0' && s[ind] <= '9')
                    cur = cur * 10 + s[ind] - '0';
                else {
                    a[++a[0]] = cur, ind++;
                    break;
                }
            return;
        } else if (s[ind] == 'c') {
            ind += 7;
            solve();
            solve();
        } else if (s[ind] == 's' && s[ind + 1] == 'h') {
            ind += 8;
            t[0]++, cur++;
            solve();
            l[cur] = tmp + 1, r[cur] = a[0], t[cur] = 1;
        } else if (s[ind] == 's' && s[ind + 1] == 'o') {
            ind += 7;
            t[0]++, cur++;
            solve();
            l[cur] = tmp + 1, r[cur] = a[0], t[cur] = 2;
        }
    }
    void gao()
    {
        int cur = 1;
        for (int i = 1; i <= t[0]; i++)
            if (cur <= l[i]) {
                sort(a + l[i], a + r[i] + 1);
                if (t[i] == 2)
                    t[i] = 0;
                if (t[i] == 1 && a[l[i]] == a[r[i]])
                    t[i] = 0;
                if (t[i] == 1)
                    shul[++shul[0]] = l[i], shur[shul[0]] = r[i];
                for (int j = l[i]; j <= r[i]; j++)
                    ans[j] = t[i];
                cur = r[i] + 1;
            }
    }
};
S a, b;
int check()
{
    if (a.a[0] != b.a[0] || a.shul[0] != b.shul[0])
        return 0;
    for (int i = 1; i <= a.a[0]; i++)
        if ((a.ans[i] != b.ans[i]) || (a.ans[i] == 0 && b.ans[i] == 0 && a.a[i] != b.a[i]))
            return 0;

    for (int i = 1; i <= a.shul[0]; i++)
        if (a.shul[i] == b.shul[i] && a.shur[i] == b.shur[i])
            for (int j = a.shul[i]; j <= a.shur[i]; j++)
                if (a.a[j] != b.a[j])
                    return 0;
    return 1;
}

int main()
{
    a.read(), b.read();
    a.solve(), b.solve();
    a.gao(), b.gao();

    if (check())
        printf("equal\n");
    else
        printf("not equal\n");
}