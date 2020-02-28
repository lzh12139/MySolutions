/**
 * Author: lzh12139
 * Time: 2020-02-23 17:08:21
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

int m[500010], ans[500010];
ll dpl[500010], dpr[500010];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> m[i];
    dpl[1] = m[1], dpr[n] = m[n];
    stack<int> st;
    stack<pii> put;
    st.push(1);
    for (int i = 2; i <= n; i++) {
        dpl[i] = dpl[i - 1] + m[i];
        int out = 0, ano = 0;
        while (!st.empty() && m[i] < m[st.top()])
            dpl[i] -= m[st.top()], st.pop(), out++;
        st.push(i);
        if (out) {
            while (!put.empty() && m[i] <= put.top().ff)
                dpl[i] -= 1ll * put.top().ff * put.top().ss, ano += put.top().ss, put.pop();
            put.push({ m[i], out + ano });
        }
        dpl[i] += 1ll * (out + ano) * m[i];
    }
    while (!st.empty())
        st.pop();
    while (!put.empty())
        put.pop();
    st.push(n);
    for (int i = n - 1; i >= 1; i--) {
        dpr[i] = dpr[i + 1] + m[i];
        int out = 0, ano = 0;
        while (!st.empty() && m[i] < m[st.top()])
            dpr[i] -= m[st.top()], st.pop(), out++;
        st.push(i);
        if (out) {
            while (!put.empty() && m[i] <= put.top().ff)
                dpr[i] -= 1ll * put.top().ff * put.top().ss, ano += put.top().ss, put.pop();
            put.push({ m[i], out + ano });
        }
        dpr[i] += 1ll * (out + ano) * m[i];
    }
    int ansn;
    ll maxx = max(dpl[n], dpr[1]);
    if (dpl[n] < dpr[1])
        ansn = 1;
    else
        ansn = n;
    for (int i = 2; i <= n - 1; i++)
        if (dpl[i] + dpr[i + 1] > maxx)
            maxx = dpl[i] + dpr[i + 1], ansn = i;
    //printf("?%d %lld\n", ansn, maxx);
    if (ansn == 1) {
        ans[1] = m[1], ans[2] = m[2];
        for (int i = 3; i <= n; i++)
            ans[i] = min(ans[i - 1], m[i]);
    } else if (ansn == n) {
        ans[n - 1] = m[n - 1], ans[n] = m[n];
        for (int i = n - 2; i >= 1; i--)
            ans[i] = min(ans[i + 1], m[i]);
    } else {
        ans[ansn] = m[ansn], ans[ansn + 1] = m[ansn + 1];
        for (int i = ansn - 1; i >= 1; i--)
            ans[i] = min(ans[i + 1], m[i]);
        for (int i = ansn + 2; i <= n; i++)
            ans[i] = min(ans[i - 1], m[i]);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
}