#include <bits/stdc++.h>
using namespace std;

int a[20], b[20], ans = 50;
vector<int> p;
void dfs(int l, int r)
{
    if (l > r) {
        int gg = 0;
        for (int i = p[0]; i <= p[r] + 1; i++)
            if (a[i - 1] > a[i]) {
                gg++;
                break;
            }
        if (!gg) {
            ans = min(ans, p[r] - p[0] + 1 - (r + 1) / 2);
        }
        return;
    }
    for (int i = p[l - 1]; i < p[l]; i++) {
        swap(a[i], b[i + 1]);
        swap(a[i + 1], b[i]);
    }
    dfs(l + 2, r);
    for (int i = p[l] - 1; i >= p[l - 1]; i--) {
        swap(a[i], b[i + 1]);
        swap(a[i + 1], b[i]);
    }
    for (int i = p[l] - 1; i >= p[l - 1]; i--) {
        swap(a[i], b[i + 1]);
        swap(a[i + 1], b[i]);
    }
    dfs(l + 2, r);
    for (int i = p[l - 1]; i < p[l]; i++) {
        swap(a[i], b[i + 1]);
        swap(a[i + 1], b[i]);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    int gg = 0;
    for (int i = 2; i <= n; i++)
        if (a[i - 1] > a[i]) {
            gg++;
            break;
        }
    if (!gg) {
        printf("0\n");
        return 0;
    }
    for (int i = 1; i < (1 << n); i++) {
        int tmp = i, num = 1;
        p.clear();
        while (tmp) {
            if (tmp & 1)
                p.push_back(num);
            num++;
            tmp >>= 1;
        }
        if (p.size() & 1)
            continue;
        gg = 0;
        for (int j = 2; j < p[0]; j++)
            if (a[j - 1] > a[j]) {
                gg++;
                break;
            }
        for (int j = p[p.size() - 1] + 2; j <= n; j++)
            if (a[j - 1] > a[j]) {
                gg++;
                break;
            }
        if (gg)
            continue;
        dfs(1, p.size() - 1);
    }
    printf("%d\n", (ans == 50 ? -1 : ans));
}