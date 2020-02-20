/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos << 1)
#define rson (curpos << 1 | 1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e6 + 10;
int score[maxn];
set<pair<int, ll>> st[maxn]; // 以分数为下标，first是人的编号，second是
ll lazy[maxn];

struct FastIO {
    static const int LEN = 1 << 18 | 1;
    char buf[LEN], wbuf[LEN];
    int s = 0, t = 0, wpos = 0;
    inline int read()
    {
        return (s == t) && (t = (s = 0) + fread(buf, 1, LEN, stdin)), s == t ? -1 : buf[s++];
    }
    inline void out(int x)
    {
        wpos == LEN ? fwrite(wbuf, 1, LEN, stdout), wpos = 0 : wbuf[wpos++] = x;
    }
    // 有符号：
    inline int rint()
    {
        // 根据读入是int还是long long决定x的类型
        int c = read(), x = 0, s = 1;
        if (c == -1)
            return 0;
        while (c <= 32)
            c = read();
        if (c == '-')
            s = -1, c = read();
        while (isdigit(c))
            x = x * 10 + c - '0', c = read();
        return x * s;
    }
    inline int ruint()
    {
        int c = read(), x = 0;
        while (c <= 32)
            c = read();
        while (isdigit(c))
            x = x * 10 + c - '0', c = read();
        return x;
    }
    inline void rstr(char* str)
    {
        int c = read();
        while (c <= 32)
            c = read();
        while (c > 32)
            *str++ = c, c = getchar();
        *str = 0;
    }
    // 根据类型
    inline void wint(long long x)
    {
        // 如果含有负数，取消注释
        // if(x<0)wchar('-'),x=-x;
        char str[24];
        int n = 0;
        while (x || !n)
            str[n++] = '0' + x % 10, x /= 10;
        while (n--)
            out(str[n]);
    }
    inline void wchar(char str)
    {
        out(str);
    }
    inline void wstr(const char* s)
    {
        while (*s)
            out(*s++);
    }
    inline void over()
    {
        if (wpos)
            fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
    ~FastIO()
    {
        if (wpos)
            fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
} io;

int main()
{
    int n = io.ruint(), week = io.ruint();
    // scanf("%d%d", &n, &week);
    for (int i = 1; i <= n; i++)
        st[0].insert(mp(i, 0));
    set<int> scores = { 0 };
    for (int i = 0; i < week; i++) {
        // int numOfPeople; scanf("%d", &numOfPeople);
        int numOfPeople = io.ruint();
        if (!numOfPeople) {
            int nw = 0;
            for (auto j : scores) {
                int i = -j;
                lazy[i] += nw + 1;
                nw += st[i].size();
            }
            continue;
        }
        for (int j = 0; j < numOfPeople; j++) {
            int currNum = io.ruint();
            // scanf("%d", &currNum);
            int currManScore = score[currNum]; // sc是当前人的分数
            auto it = st[currManScore].upper_bound(mp(currNum, -1));
            st[currManScore + 1].insert(mp(currNum, it->second + lazy[currManScore] - lazy[currManScore + 1]));
            st[currManScore].erase(it);
            score[currNum]++;
            if (scores.count(-score[currNum]) == 0)
                scores.insert(-score[currNum]);
            if (st[currManScore].empty())
                scores.erase(scores.find(-currManScore));
        }
        int nw = 0;
        for (auto j : scores) { // 从高到低处理分数
            int i = -j;
            lazy[i] += nw + 1;
            nw += st[i].size();
        }
    }
    double ans[n];
    for (auto j : scores) {
        int i = -j;
        for (auto p : st[i])
            ans[p.first] = 1.0 * (p.second + lazy[i]) / week;
    }
    for (int i = 1; i <= n; i++)
        printf("%.10f\n", ans[i]);
    return 0;
}