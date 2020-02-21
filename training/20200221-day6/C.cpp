#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> V;

int q[100010], ans[300];
int q1(int x)
{
    printf("1 %d\n", x);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}
V q2(int n)
{
    if (n <= 1)
        return V();
    printf("2 %d ", n);
    for (int i = 1; i <= n; i++)
        printf("%d ", q[i]);
    printf("\n");
    fflush(stdout);
    V res((n - 1) * n / 2);
    for (auto& i : res)
        scanf("%d", &i);
    return res;
}
void q3(int n)
{
    printf("3 ");
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    fflush(stdout);
}
V gao(V a, V b)
{
    map<int, int> mp;
    V res;
    for (auto i : b)
        mp[i]++;
    for (auto i : a)
        mp[i]--;
    for (auto& i : mp)
        for (int j = 1; j <= i.ss; j++)
            res.push_back(i.ff);
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 30) {
        for (int i = 1; i <= n; i++)
            ans[i] = q1(i);
        q3(n);
        return 0;
    }
    for (int i = 1; i <= n; i++)
        q[i] = i;
    V all = q2(n);
    int K = *max_element(all.begin(), all.end());
    int l = 1, r = n;
    while (l <= r) {
        int mid = l + r >> 1;
        if (mid == 1) {
            l = 2;
            break;
        }
        for (int i = 1; i <= mid; i++)
            q[i] = i;
        V res = q2(mid);
        if (K == *max_element(res.begin(), res.end()))
            r = mid - 1;
        else
            l = mid + 1;
    }
    int zuizhi = q1(l), another, f = 0;
    ans[l] = zuizhi;

    for (int i = 1; i <= n; i++)
        if (i != l)
            q[++f] = i;
    V all_expL = q2(f);
    V all_to_L = gao(all_expL, all);

    if (l == 1)
        another = ans[2] = q1(2);
    else
        another = ans[1] = q1(1);
    if (another > zuizhi)
        f = 1;
    else
        f = -1;
    int and_num = 1, tmp = n;
    map<int, int> ansn;
    while (tmp) {
        int num = 0;
        for (int i = 1; i <= n; i++)
            if ((i & and_num) && i != l)
                q[++num] = i;
        V tmp1 = q2(num);
        q[++num] = l;
        V tmp2 = q2(num);
        V ress = gao(tmp1, tmp2);
        for (auto i : ress)
            ansn[i] += and_num;

        tmp >>= 1, and_num <<= 1;
    }
    for (auto i : ansn)
        ans[i.ss] = i.ff * f + zuizhi;
    q3(n);
}